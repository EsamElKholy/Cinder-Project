#include "MemoryAllocator.h"
namespace Cinder
{
	namespace Memory
	{
		/*
		****************************************************************************************************************************************************
		Courtesy of David Graham and Mike McShaffry
		*****************************************************************************************************************************************************
		*/

		MemoryPool::MemoryPool()
		{
			Reset();
		}


		MemoryPool::~MemoryPool()
		{
			Destroy();
		}

		bool MemoryPool::Init(unsigned int chunkSize, unsigned int chunkCount, bool allowResize)
		{
			if (RawMemory)
			{
				Destroy();
			}

			ChunkSize = chunkSize;
			ChunkCount = chunkCount;
			AllowResize = allowResize;

			if (GrowMemoryArray())
			{
				return true;
			}

			return false;
		}

		void MemoryPool::Destroy()
		{
			for (int i = 0; i < ArrayCount; i++)
			{
				free(RawMemory[i]);
			}

			free(RawMemory);
			Reset();
		}

		void MemoryPool::Reset()
		{
			ChunkSize = 0;
			ChunkCount = 0;
			ArrayCount = 0;
			UsedCount = 0;
			RawMemory = NULL;
			Front = NULL;
			AllowResize = false;
		}

		bool MemoryPool::GrowMemoryArray()
		{
			unsigned int newSize = sizeof(unsigned char *) * ((ArrayCount + 1));
			unsigned char **newRawMemory = (unsigned char **)malloc(newSize);

			if (!newRawMemory)
			{
				return false;
			}

			for (int i = 0; i < ArrayCount; i++)
			{
				newRawMemory[i] = RawMemory[i];
			}

			newRawMemory[ArrayCount] = AllocateBlock();

			if (!newRawMemory[ArrayCount])
			{
				return false;
			}

			if (Front)
			{
				unsigned char *current = Front;
				unsigned char *next = GetNext(current);

				while (next)
				{
					current = next;
					next = GetNext(next);
				}

				SetNext(current, newRawMemory[ArrayCount]);
			}
			else
			{
				Front = newRawMemory[ArrayCount];
			}

			if (RawMemory)
			{
				free(RawMemory);
			}

			RawMemory = newRawMemory;

			ArrayCount++;
			UsedCount++;

			return true;
		}

		unsigned char* MemoryPool::AllocateBlock()
		{
			unsigned int chunkSize = CHUNK_HEADER_SIZE + ChunkSize;
			unsigned int blockSize = chunkSize * ChunkCount;

			unsigned char *newBlock = (unsigned char *)malloc(blockSize);

			if (!newBlock)
			{
				return NULL;
			}

			unsigned char *start = newBlock;
			unsigned char *end = newBlock + blockSize;

			while (start < end)
			{
				unsigned char *next = start + chunkSize;

				unsigned char **header = (unsigned char **)start;

				header[0] = (start < end ? next : NULL);

				start += chunkSize;
			}

			return newBlock;
		}

		unsigned char* MemoryPool::GetNext(unsigned char *next)
		{
			unsigned char **header = (unsigned char **)next;

			return header[0];
		}

		void MemoryPool::SetNext(unsigned char *wanted, unsigned char *next)
		{
			unsigned char **header = (unsigned char **)wanted;

			header[0] = next;
		}

		void* MemoryPool::Alloc()
		{
			if (!Front)
			{
				if (!AllowResize)
				{
					return NULL;
				}

				if (!GrowMemoryArray())
				{
					return NULL;
				}
			}

			unsigned char *result = Front;
			Front = GetNext(Front);

			return (result + CHUNK_HEADER_SIZE);
		}

		void MemoryPool::Dealloc(void *memory)
		{
			if (memory)
			{
				unsigned char *chunk = (unsigned char *)memory - CHUNK_HEADER_SIZE;

				SetNext(chunk, Front);

				Front = chunk;
			}
		}
	}
}