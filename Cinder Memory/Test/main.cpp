#include <iostream>
#include <MemoryAllocator.h>

using namespace Cinder::Memory;

int main()
{
	MemoryPool pool;
	pool.Init(sizeof(int), 10, true);

	void *chunk = pool.Alloc();

	system("PAUSE");
	return 0;
}