#include <iostream>
#include <MemoryAllocator.h>

int main()
{
	MemoryPool pool;
	pool.Init(sizeof(int), 10, true);

	void *chunk = pool.Alloc();

	system("PAUSE");
	return 0;
}