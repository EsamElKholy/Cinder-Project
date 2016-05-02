#pragma once

#include <stdlib.h>
#include <string.h>

namespace Cinder
{
	namespace Memory
	{
		/*
		****************************************************************************************************************************************************
		Courtesy of David Graham and Mike McShaffry
		*****************************************************************************************************************************************************
		*/

		struct MemoryPool
		{
			MemoryPool();

			~MemoryPool();

			const static unsigned int CHUNK_HEADER_SIZE = sizeof(unsigned char *);
			unsigned int ChunkSize;
			unsigned int ChunkCount;
			unsigned int ArrayCount;
			unsigned int UsedCount;
			unsigned char **RawMemory;
			unsigned char *Front;
			bool AllowResize;

			bool Init(unsigned int chunkSize, unsigned int chunkCount, bool allowResize);

			void Destroy();

			void Reset();

			bool GrowMemoryArray();

			unsigned char* AllocateBlock();

			unsigned char* GetNext(unsigned char *next);

			void SetNext(unsigned char *wanted, unsigned char *next);

			void* Alloc();

			void Dealloc(void *memory);

		private:
			MemoryPool(const MemoryPool &memPool){}
		};

		/*
		****************************************************************************************************************************************************
		*****************************************************************************************************************************************************
		*/

		struct StackChunk
		{
			void *Chunk;
			unsigned int size;
			unsigned char *Bookmark;
		};

		struct MemoryStack
		{
			MemoryStack();

			~MemoryStack();

			unsigned int TotalSize;
			unsigned int UsedSize;
			unsigned char *RawMemory;
			unsigned char *StackPointer;
			unsigned char *Front;
			unsigned char *End;
			bool AllowResize;

			bool Init(unsigned int totalSize, bool allowResize);

			void Destroy();

			void Reset();

			bool GrowMemory();

			StackChunk* Alloc(unsigned int size);

			void Dealloc(StackChunk *chunk);

		private:
			MemoryStack(const MemoryStack &memStack){}
		};

	}
}
