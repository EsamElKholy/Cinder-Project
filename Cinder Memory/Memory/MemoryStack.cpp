#include <CinderMemory.h>

namespace Cinder
{
	namespace Memory
	{
		MemoryStack::MemoryStack(unsigned int totalSize, bool allowResize)
		{
			Reset();

			AllowResize = allowResize;
			TotalSize = totalSize;

			Init(totalSize, allowResize);
		}

		MemoryStack::MemoryStack()
		{
			Reset();
		}

		MemoryStack::~MemoryStack()
		{
			//Destroy();
		}

		bool MemoryStack::Init(unsigned int totalSize, bool allowResize)
		{
			if (RawMemory)
			{
				if (TotalSize > 0)
				{
					Destroy();
				}
				else
				{
					Reset();
				}
			}

			AllowResize = allowResize;
			TotalSize = totalSize;

			if (GrowMemory(0))
			{
				return true;
			}

			return false;
		}

		void MemoryStack::Destroy()
		{
			if (RawMemory)
			{
				free(RawMemory);
			}

			Reset();
		}

		void MemoryStack::Reset()
		{
			UsedSize = 0;
			TotalSize = 0;

			RawMemory = NULL;
			StackPointer = NULL;

			Front = NULL;
			End = NULL;

			LastUsed = NULL;

			AllowResize = false;
		}

		bool MemoryStack::GrowMemory(unsigned int size)
		{
			unsigned int totalSize = (TotalSize + (size * 2));
			unsigned char *newRawMemory = (unsigned char *)malloc(totalSize);

			if (!newRawMemory)
			{
				return false;
			}			

			if (RawMemory)
			{
				if (UsedSize > 0)
				{
					memcpy(newRawMemory, RawMemory, UsedSize);
				}
			}

			Front = newRawMemory;
			End = Front + UsedSize;

			if (End)
			{
				StackPointer = End;
			}
			else
			{
				StackPointer = Front;
			}

			End = Front + totalSize;
			
			TotalSize = totalSize;

			free(RawMemory);

			RawMemory = newRawMemory;

			return true;
		}

		StackChunk MemoryStack::Alloc(unsigned int size)
		{
			StackChunk result = {};

			if ((unsigned char *)StackPointer + size >= (unsigned char *)End)
			{
				if (!AllowResize)
				{
					return result;
				}

				GrowMemory(size);
			}

			LastUsed = StackPointer;
			StackPointer = (unsigned char *)StackPointer + size;
			UsedSize += size;

			result = StackChunk{ ((unsigned char *)StackPointer - size), size, ((unsigned char *)StackPointer - size) };

			return result;
		}

		void MemoryStack::Dealloc(unsigned char *bookmark, unsigned int size)
		{
			if ((unsigned char *)bookmark >= (unsigned char *)Front	&& 
				(unsigned char *)bookmark <= (unsigned char *)End)
			{
				if (size > 0 && size <= UsedSize && size == (unsigned int)(StackPointer - bookmark))
				{
					UsedSize -= size;
					StackPointer = bookmark;
					if (UsedSize > 0)
					{
						LastUsed = (bookmark - size);
					}
					else
					{
						LastUsed = NULL;
					}
				}				
			}
		}

		void MemoryStack::Pop(unsigned int size)
		{
			Dealloc(LastUsed, size);
		}

		unsigned char* MemoryStack::GetTop()
		{			
			return LastUsed;
		}

		unsigned char* MemoryStack::GetBottom()
		{
			return Front;
		}

		StackChunk MemoryStack::PushBack(unsigned int size)
		{
			unsigned int oldSize = UsedSize;
			StackChunk chunk = Alloc(size);

			memcpy(RawMemory + size, RawMemory, oldSize);
			chunk.size = size;
			chunk.Bookmark = NULL;
			chunk.Chunk = Front;

			return chunk;
		}		
	}
}