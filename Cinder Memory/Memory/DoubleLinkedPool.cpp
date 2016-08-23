#include <CinderMemory.h>

namespace Cinder
{
	namespace Memory
	{
		DoubleLinkedPool::DoubleLinkedPool(unsigned int chunkSize, unsigned int chunkCount, bool allowResize)
		{
			if (chunkCount < (1 << 16))
			{
				FixedChunkCount = 8;
				ChunkSize = chunkSize;

				if (chunkCount < FixedChunkCount)
				{
					ChunkCount = FixedChunkCount;
				}
				else
				{
					ChunkCount = chunkCount;
				}

				TotalChunkCount = ChunkCount;				
				PoolCount = 0;
				GrowUsedTimes = 0;				
				AllowResize = allowResize;
				UsedChunks = 0;
				MemPools = 0; 
				UsedCount = 0;
				FirstUsed = MAX;

				TotalSize = ChunkSize * ChunkCount;
				TotalChunkCount = ChunkCount;
				
				Init();
			}			
		}

		DoubleLinkedPool::~DoubleLinkedPool()
		{
		//	Destroy();
		}

		bool DoubleLinkedPool::Init()
		{
			if (MemPools)
			{
				Destroy();
			}

			if (!GrowMemory())
			{
				return false;
			}

			return true;
		}

		void DoubleLinkedPool::Destroy()
		{
			if (MemPools)
			{
				for (unsigned int i = 0; i < PoolCount; i++)
				{					
					free(MemPools[i]);
					free(UsedChunks[i]);
				}

				free(MemPools);
				free(UsedChunks);
				free(PoolNodes);

				UsedPools.clear();
				UnusedChunks.clear();
			}

			Reset();
		}

		void DoubleLinkedPool::Reset()
		{
			ChunkSize = 0;
			ChunkCount = 0;
			TotalChunkCount = 0;
			PoolCount = 0;
			GrowUsedTimes = 0;
			PoolNodes = 0;
			AllowResize = false;
			FixedChunkCount = 0;
			UsedCount = 0;

			UsedChunks = 0;
			MemPools = 0;

			FirstUsed = MAX;
			TotalSize = 0;
		}

		bool DoubleLinkedPool::GrowMemory()
		{
			if (PoolCount < 65536)
			{
				if (GrowUsedTimes == 0)
				{
					MemPools = (void**)malloc(sizeof(void*) * ((ChunkCount / FixedChunkCount) * 2));
					UsedChunks = (ChunkNode**)malloc(sizeof(ChunkNode *) * ((ChunkCount / FixedChunkCount) * 2));
					PoolNodes = (ChunkNode *)malloc(sizeof(ChunkNode) * ((ChunkCount / FixedChunkCount) * 2));

					for (unsigned int i = 0; i < ((ChunkCount / FixedChunkCount) * 2); i++)
					{
						void *newPool = malloc(ChunkCount * ChunkSize);
						ChunkNode *newUsed = (ChunkNode *)malloc(sizeof(ChunkNode) * ChunkCount);

						MemPools[i] = newPool;
						UsedChunks[i] = newUsed;
					}			

					PoolCount = ((ChunkCount / FixedChunkCount) * 2);
				}
				else
				{
					MemPools = (void**)realloc(MemPools, sizeof(void*) * (PoolCount * 2));
					UsedChunks = (ChunkNode**)realloc(UsedChunks, sizeof(ChunkNode *) * (PoolCount * 2));
					PoolNodes = (ChunkNode *)realloc(PoolNodes, sizeof(ChunkNode) * (PoolCount * 2));

					for (unsigned int i = PoolCount; i < (PoolCount * 2); i++)
					{
						void *newPool = malloc(ChunkCount * ChunkSize);
						ChunkNode *newUsed = (ChunkNode *)malloc(sizeof(ChunkNode) * ChunkCount);

						MemPools[i] = newPool;
						UsedChunks[i] = newUsed;
					}
					
					PoolCount *= 2;
				}

				if (MemPools && UsedChunks)
				{
					TotalChunkCount = ChunkCount * PoolCount;
					if (GrowUsedTimes == 0)
					{
						AddChunks(0);
					}
					else
					{
						AddChunks(PoolCount);
					}

					GrowUsedTimes++;

					TotalSize = TotalChunkCount * ChunkSize;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			
		}

		void DoubleLinkedPool::AddChunks(unsigned int poolIndex)
		{
			for (unsigned int i = poolIndex; i < PoolCount; i++)
			{
				PoolNodes[i].First = MAX;
				PoolNodes[i].Middle = MAX;
				PoolNodes[i].Last = MAX;

				for (unsigned int j = 0; j < ChunkCount; j++)
				{
					UsedChunks[i][j].Current = MAX;
					UsedChunks[i][j].Next = MAX;
					UsedChunks[i][j].Previous = MAX;

					UnusedChunks.insert((j | (i << 16)));
				}				
			}
		}

		unsigned int DoubleLinkedPool::Alloc()
		{
			unsigned int result = MAX;

			if (UnusedChunks.size() == 0)
			{
				if (AllowResize)
				{
					if (!GrowMemory())
					{
						return result;
					}

					return result;
				}
			}

			unsigned int unused = *UnusedChunks.begin();
			UnusedChunks.erase(unused);

			unsigned int unusedIndex = GetIndex(unused);
			unsigned int unusedPool = GetPool(unused);

			unsigned int nextPool = MAX;
			unsigned int prevPool = MAX;

			UsedPools.insert(unusedPool);

			std::set<unsigned int>::iterator current = UsedPools.find(unusedPool);
			std::set<unsigned int>::iterator before = UsedPools.lower_bound(unusedPool);
			std::set<unsigned int>::iterator after = UsedPools.upper_bound(unusedPool);

			if (after == UsedPools.end() && before != UsedPools.begin())
			{
				before--;
				prevPool = *before;
			}
			else if (after != UsedPools.end() && before != UsedPools.begin())
			{
				nextPool = *after;
				before--;
				prevPool = *before;
			}
			else if (after != UsedPools.end() && before == UsedPools.begin())
			{
				nextPool = *after;
			}

			unsigned int firstIndex = PoolNodes[unusedPool].First;
			unsigned int middleIndex = PoolNodes[unusedPool].Middle;
			unsigned int lastIndex = PoolNodes[unusedPool].Last;

			UsedChunks[unusedPool][unusedIndex].Current = unusedIndex | (unusedPool << 16);

			if (FirstUsed == MAX)
			{
				FirstUsed = UsedChunks[unusedPool][unusedIndex].Current;
			}
			else if (FirstUsed >= UsedChunks[unusedPool][unusedIndex].Current)
			{
				FirstUsed = UsedChunks[unusedPool][unusedIndex].Current;
			}

			if (firstIndex == MAX)
			{				
				UsedChunks[unusedPool][unusedIndex].Next = MAX;
				UsedChunks[unusedPool][unusedIndex].Previous = MAX;

				PoolNodes[unusedPool].First = UsedChunks[unusedPool][unusedIndex].Current;
				PoolNodes[unusedPool].Last = UsedChunks[unusedPool][unusedIndex].Current;

				firstIndex = PoolNodes[unusedPool].First;
				lastIndex = PoolNodes[unusedPool].Last;				

				if (nextPool != MAX)
				{
					unsigned int firstNextIndex = GetIndex(PoolNodes[nextPool].First);
					unsigned int lastINextndex = GetIndex(PoolNodes[nextPool].Last);
					
					UsedChunks[nextPool][firstNextIndex].Previous = UsedChunks[unusedPool][unusedIndex].Current;
					UsedChunks[unusedPool][unusedIndex].Next = UsedChunks[nextPool][firstNextIndex].Current;
				}

				if (prevPool != MAX)
				{					
					unsigned int firstPrevIndex = GetIndex(PoolNodes[prevPool].First);
					unsigned int lastIPrevndex = GetIndex(PoolNodes[prevPool].Last);

					UsedChunks[prevPool][lastIPrevndex].Next = UsedChunks[unusedPool][unusedIndex].Current;
					UsedChunks[unusedPool][unusedIndex].Previous = UsedChunks[prevPool][lastIPrevndex].Current;
				}

				UsedCount++;

				return UsedChunks[unusedPool][unusedIndex].Current;
			}
			else if (firstIndex == lastIndex)
			{
				UsedChunks[unusedPool][unusedIndex].Next = MAX;
				UsedChunks[unusedPool][unusedIndex].Previous = firstIndex;
				UsedChunks[unusedPool][GetIndex(firstIndex)].Next = unusedIndex | (unusedPool << 16);
				
				PoolNodes[unusedPool].Last = UsedChunks[unusedPool][unusedIndex].Current;

				firstIndex = PoolNodes[unusedPool].First;
				lastIndex = PoolNodes[unusedPool].Last;

				if (nextPool != MAX)
				{
					unsigned int firstNextIndex = GetIndex(PoolNodes[nextPool].First);
					unsigned int lastINextndex = GetIndex(PoolNodes[nextPool].Last);

					UsedChunks[nextPool][firstNextIndex].Previous = UsedChunks[unusedPool][unusedIndex].Current;
					UsedChunks[unusedPool][unusedIndex].Next = UsedChunks[nextPool][firstNextIndex].Current;
				}

				UsedCount++;

				return UsedChunks[unusedPool][unusedIndex].Current;
			}			
			else if (lastIndex != MAX && GetIndex(lastIndex) <= unusedIndex)
			{
				UsedChunks[unusedPool][unusedIndex].Next = UsedChunks[unusedPool][GetIndex(lastIndex)].Next;
				UsedChunks[unusedPool][GetIndex(lastIndex)].Next = UsedChunks[unusedPool][unusedIndex].Current;
				UsedChunks[unusedPool][unusedIndex].Previous = PoolNodes[unusedPool].Last;

				PoolNodes[unusedPool].Last = UsedChunks[unusedPool][unusedIndex].Current;

				firstIndex = PoolNodes[unusedPool].First;
				lastIndex = PoolNodes[unusedPool].Last;

				if (nextPool != MAX)
				{
					unsigned int firstNextIndex = GetIndex(PoolNodes[nextPool].First);
					unsigned int lastINextndex = GetIndex(PoolNodes[nextPool].Last);

					UsedChunks[nextPool][firstNextIndex].Previous = UsedChunks[unusedPool][unusedIndex].Current;
					UsedChunks[unusedPool][unusedIndex].Next = UsedChunks[nextPool][firstNextIndex].Current;
				}

				UsedCount++;

				return UsedChunks[unusedPool][unusedIndex].Current;
			}
			else if (firstIndex != MAX && GetIndex(firstIndex) >= unusedIndex)
			{
				UsedChunks[unusedPool][unusedIndex].Next = firstIndex;
				UsedChunks[unusedPool][GetIndex(firstIndex)].Previous = UsedChunks[unusedPool][unusedIndex].Current;
				UsedChunks[unusedPool][unusedIndex].Previous = MAX;

				PoolNodes[unusedPool].First = UsedChunks[unusedPool][unusedIndex].Current;

				firstIndex = PoolNodes[unusedPool].First;
				lastIndex = PoolNodes[unusedPool].Last;				
			

				if (prevPool != MAX)
				{
					unsigned int firstPrevIndex = GetIndex(PoolNodes[prevPool].First);
					unsigned int lastIPrevndex = GetIndex(PoolNodes[prevPool].Last);

					UsedChunks[prevPool][lastIPrevndex].Next = UsedChunks[unusedPool][unusedIndex].Current;
					UsedChunks[unusedPool][unusedIndex].Previous = UsedChunks[prevPool][lastIPrevndex].Current;
				}

				UsedCount++;

				return UsedChunks[unusedPool][unusedIndex].Current;
			}
			else
			{
				unsigned int diffFirst = unusedIndex - GetIndex(firstIndex);
				unsigned int diffLast = GetIndex(lastIndex) - unusedIndex;

				if (diffFirst <= diffLast)
				{
					unsigned int before = GetBefore(unused);

					unsigned int beforeIndex = GetIndex(before);

					UsedChunks[unusedPool][unusedIndex].Previous = before;
					UsedChunks[unusedPool][unusedIndex].Next = UsedChunks[unusedPool][beforeIndex].Next;
					UsedChunks[unusedPool][GetIndex(UsedChunks[unusedPool][beforeIndex].Next)].Previous = unused;
					UsedChunks[unusedPool][beforeIndex].Next = unused;
				}
				else
				{
					unsigned int after = GetAfter(unused);

					unsigned int afterIndex = GetIndex(after);

					UsedChunks[unusedPool][unusedIndex].Previous = UsedChunks[unusedPool][afterIndex].Previous;
					UsedChunks[unusedPool][unusedIndex].Next = afterIndex;
					UsedChunks[unusedPool][GetIndex(UsedChunks[unusedPool][afterIndex].Previous)].Next = unused;
					UsedChunks[unusedPool][afterIndex].Previous = unused;
				}

				UsedCount++;

				return UsedChunks[unusedPool][unusedIndex].Current;
			}

			return result;
		}

		void DoubleLinkedPool::Dealloc(unsigned int value)
		{
			UnusedChunks.insert(value);

			unsigned int usedPool = GetPool(value);
			unsigned int usedIndex = GetIndex(value);

			unsigned int nextPool = MAX;
			unsigned int prevPool = MAX;

			std::set<unsigned int>::iterator current = UsedPools.find(usedPool);

			if (current != UsedPools.end())
			{
				unsigned int firstIndex = PoolNodes[usedPool].First;
				unsigned int middleIndex = PoolNodes[usedPool].Middle;
				unsigned int lastIndex = PoolNodes[usedPool].Last;
				
				if (FirstUsed == value)
				{
					FirstUsed = UsedChunks[usedPool][usedIndex].Next;
				}

				if (firstIndex == value && lastIndex == value)
				{
					PoolNodes[usedPool].First = MAX;
					PoolNodes[usedPool].Last = MAX;
				}
				else if (firstIndex != lastIndex)
				{
					if (UsedChunks[usedPool][GetIndex(firstIndex)].Current == UsedChunks[usedPool][usedIndex].Current)
					{
						PoolNodes[usedPool].First = UsedChunks[usedPool][usedIndex].Next;
					}
					else if (UsedChunks[usedPool][GetIndex(lastIndex)].Current == UsedChunks[usedPool][usedIndex].Current)
					{
						PoolNodes[usedPool].Last = UsedChunks[usedPool][usedIndex].Previous;
					}
				}

				unsigned int nextIndex = GetIndex(UsedChunks[usedPool][usedIndex].Next);
				unsigned int nextPool = GetPool(UsedChunks[usedPool][usedIndex].Next);

				unsigned int prevIndex = GetIndex(UsedChunks[usedPool][usedIndex].Previous);
				unsigned int prevPool = GetPool(UsedChunks[usedPool][usedIndex].Previous);

				if (UsedChunks[usedPool][usedIndex].Next != MAX)
				{
					if (UsedChunks[usedPool][usedIndex].Previous != MAX)
					{
						UsedChunks[prevPool][prevIndex].Next = UsedChunks[usedPool][usedIndex].Next;
						UsedChunks[nextPool][nextIndex].Previous = UsedChunks[usedPool][usedIndex].Previous;
					}
					else
					{
						UsedChunks[nextPool][nextIndex].Previous = UsedChunks[usedPool][usedIndex].Previous;
					}
				}
				else
				{
					if (UsedChunks[usedPool][usedIndex].Previous != MAX)
					{
						UsedChunks[prevPool][prevIndex].Next = UsedChunks[usedPool][usedIndex].Next;
					}
				}

				UsedChunks[usedPool][usedIndex].Current = MAX;
				UsedChunks[usedPool][usedIndex].Next = MAX;
				UsedChunks[usedPool][usedIndex].Previous = MAX;	

				UsedCount--;
			}
		}

		unsigned int DoubleLinkedPool::GetIndex(unsigned int value)
		{
			return (value << 16) >> 16;
		}

		unsigned int DoubleLinkedPool::GetPool(unsigned int value)
		{
			return (value) >> 16;
		}

		unsigned int DoubleLinkedPool::GetNextIndex(unsigned int value)
		{
			unsigned int index = GetIndex(value);
			unsigned int pool = GetPool(value);

			if (index < (ChunkCount) && pool < PoolCount)
			{
				return UsedChunks[pool][index].Next;
			}

			return MAX;
		}

		unsigned int DoubleLinkedPool::GetPrevIndex(unsigned int value)
		{
			unsigned int index = GetIndex(value);
			unsigned int pool = GetPool(value);

			if (index < (ChunkCount) && pool < PoolCount)
			{
				return UsedChunks[pool][index].Previous;
			}

			return MAX;
		}

		void* DoubleLinkedPool::GetAddress(unsigned int value)
		{
			unsigned int index = GetIndex(value);
			unsigned int pool = GetPool(value);

			if (index < (ChunkCount) && pool < PoolCount)
			{
				return ((unsigned char *)MemPools[pool]) + (index * ChunkSize);
			}

			return NULL;
		}

		void* DoubleLinkedPool::GetNextAddress(unsigned int value)
		{
			unsigned int index = GetNextIndex(value);
			unsigned int pool = GetNextIndex(value);

			if (index < (ChunkCount) && pool < PoolCount)
			{
				return (unsigned char *)MemPools[pool] + (index * ChunkSize);
			}

			return NULL;
		}

		void* DoubleLinkedPool::GetPrevAddress(unsigned int value)
		{
			unsigned int index = GetPrevIndex(value);
			unsigned int pool = GetPrevIndex(value);

			if (index < (ChunkCount) && pool < PoolCount)
			{
				return (unsigned char *)MemPools[pool] + (index * ChunkSize);
			}

			return NULL;
		}

		unsigned int DoubleLinkedPool::GetBefore(unsigned int value)
		{
			unsigned int index = GetIndex(value);
			unsigned int pool = GetPool(value);

			unsigned int first = PoolNodes[pool].First;

			while (first < value)
			{
				first = UsedChunks[pool][GetIndex(first)].Next;
			}

			return first;
		}

		unsigned int DoubleLinkedPool::GetAfter(unsigned int value)
		{
			unsigned int index = GetIndex(value);
			unsigned int pool = GetPool(value);

			unsigned int last = PoolNodes[pool].Last;

			while (last > value)
			{
				last = UsedChunks[pool][GetIndex(last)].Previous;
			}

			return last;
		}

		bool DoubleLinkedPool::IsEmpty()
		{
			if (FirstUsed == MAX)
			{
				return true;
			}

			return false;
		}
	}
}