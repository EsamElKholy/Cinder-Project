#include "MemoryAllocator.h"

MemoryStack::MemoryStack()
{
	Reset();
}

MemoryStack::~MemoryStack()
{
	Destroy();
}

bool MemoryStack::Init(unsigned int totalSize, bool allowResize)
{
	if (RawMemory)
	{
		Destroy();
	}

	TotalSize = totalSize;

	if (GrowMemory())
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

	AllowResize = false;
}

bool MemoryStack::GrowMemory()
{
	unsigned int totalSize = (TotalSize * 2);
	unsigned char *newRawMemory = (unsigned char *)malloc(totalSize);

	if (!newRawMemory)
	{
		return false;
	}
	if (UsedSize > 0)
	{
		memcpy(newRawMemory, RawMemory, UsedSize);
	}

	Front = newRawMemory;
	End = Front + totalSize;

	StackPointer = Front + UsedSize;

	TotalSize = totalSize;

	return true;
}

StackChunk* MemoryStack::Alloc(unsigned int size)
{
	if (StackPointer + size > End)
	{
		if (!AllowResize)
		{
			return NULL;
		}

		GrowMemory();
	}

	StackPointer += size;
	UsedSize += size;

	StackChunk result = StackChunk{ (StackPointer - size), size, (StackPointer - size) };

	return &result;
}

void MemoryStack::Dealloc(StackChunk *chunk)
{
	if (chunk)
	{
		StackPointer = chunk->Bookmark;
		UsedSize -= chunk->size;
	}
}