#include <CinderMemory.h>

namespace Cinder
{
	namespace Memory
	{
		MemoryPool::MemoryPool()
		{
			Reset();
		}

		MemoryPool::MemoryPool(size_t size, size_t count, bool resize)
		{
			Reset();

			ChunkSize = size;
			ChunkCount = count;
			AllowResize = resize;

			Init();
		}

		MemoryPool::~MemoryPool()
		{
			//Destroy();
		}

		bool MemoryPool::Init()
		{
			if (RawPools)
			{
				Destroy();
			}

			if (!GrowMemory())
			{
				return false;
			}

			return true;
		}

		void MemoryPool::Destroy()
		{
			if (RawPools)
			{
				for (unsigned int i = 0; i < PoolCount; i++)
				{
					free(RawPools[i]);
				}

				free(RawPools);
			}			

			Reset();
		}

		void MemoryPool::Reset()
		{
			RawPools = 0;
			Head = 0;
			ChunkSize = 0;
			ChunkCount = 0;
			PoolCount = 0;
			AllowResize = 0;
			UsedCount = 0;
			First = 0;
		}

		unsigned char* MemoryPool::GetNext(unsigned char *address)
		{
			unsigned char **header = (unsigned char **)address;
			return header[0];
		}

		void* MemoryPool::GetNextUsed(void* address)
		{
			if (address)
			{
				unsigned char *chunk = (unsigned char *)address - sizeof(unsigned char *);

				return (GetNext(chunk) + sizeof(unsigned char *));
			}

			return NULL;
		}

		void MemoryPool::SetNext(unsigned char *current, unsigned char *next)
		{
			unsigned char **header = (unsigned char **)current;
			header[0] = next;
		}

		bool MemoryPool::GrowMemory()
		{
			size_t totalSize = sizeof(unsigned char *) * (PoolCount + 1);
			unsigned char **newRawPool = (unsigned char **)malloc(totalSize);

			if (!newRawPool)
			{
				return false;
			}

			for (size_t i = 0; i < PoolCount; i++)
			{
				newRawPool[i] = RawPools[i];
			}

			newRawPool[PoolCount] = AllocatePool();

			if (Head)
			{
				unsigned char *current = Head;
				unsigned char *next = GetNext(Head);

				while (next)
				{
					current = next;
					next = GetNext(current);
				}

				SetNext(current, newRawPool[PoolCount]);
			}
			else
			{
				Head = newRawPool[PoolCount];
			}

			if (RawPools)
			{
				free(RawPools);
			}

			RawPools = newRawPool;

			PoolCount++;

			return true;
		}

		unsigned char* MemoryPool::AllocatePool()
		{
			size_t chunkSize = ChunkSize + sizeof(unsigned char *);
			size_t totalSize = chunkSize * ChunkCount;

			unsigned char *newPool = (unsigned char *)malloc(totalSize);

			if (!newPool)
			{
				return NULL;
			}

			unsigned char *end = newPool + totalSize;
			unsigned char *current = newPool;

			while (current < end)
			{
				unsigned char *next = current + chunkSize;
				unsigned char **header = (unsigned char **)current;
				header[0] = (next < end) ? next : NULL;
				current = next;
			}

			return newPool;
		}

		void* MemoryPool::Alloc()
		{
			if (!Head)
			{
				if (!AllowResize)
				{
					return NULL;
				}
				if (!GrowMemory())
				{
					return NULL;
				}
			}

			unsigned char *result = Head;

			Head = GetNext(Head);
			UsedCount++;

			return (result + sizeof(unsigned char *));
		}

		void MemoryPool::Free(void *address)
		{
			if (address)
			{
				unsigned char *chunk = (unsigned char *)address - sizeof(unsigned char *);

				SetNext(chunk, Head);

				Head = chunk;
				UsedCount--;
			}
		}

		void* MemoryPool::GetChunk(void* address)
		{
			if (address)
			{
				return (unsigned char *)address + sizeof(unsigned char *);
			}

			return NULL;
		}
	}
}