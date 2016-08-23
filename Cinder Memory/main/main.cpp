#include <iostream>
#include <Cinder\CinderMemory.h>

using namespace Cinder::Memory;

int main()
{
	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	tmpFlag |= _CRTDBG_ALLOC_MEM_DF;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	tmpFlag |= _CRTDBG_CHECK_ALWAYS_DF;
	tmpFlag |= _CRTDBG_CHECK_CRT_DF;
	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;

	
	DoubleLinkedPool pool(sizeof(int), 2, true);
	unsigned int ci = pool.MAX;

	ci = pool.Alloc();
	ci = pool.Alloc();
	ci = pool.Alloc();
	ci = pool.Alloc();
	ci = pool.Alloc();

	ci = pool.Alloc();
	ci = pool.Alloc();
	ci = pool.Alloc();
	ci = pool.Alloc();
	ci = pool.Alloc();
	std::cout << "current index: " << ci << ", next index: " << pool.GetNextIndex(ci) << ", prev index: " << pool.GetPrevIndex(ci) << std::endl;
	std::cout << "current pool: " << pool.GetPool(ci) << ", next pool: " << pool.GetPool(pool.GetNextIndex(ci)) << ", prev pool: " << pool.GetPool(pool.GetPrevIndex(ci)) << std::endl;

	std::cout << "\n";
	std::cout << "*********************************\n";
	std::cout << "\n";

	int *x = (int*)pool.GetAddress(ci);
	*x = 5;
	int y = sizeof(unsigned char *);

	pool.Dealloc(0);
	pool.Dealloc(1);
	pool.Dealloc(0 | (1 << 16));
	pool.Alloc();
	//PoolHeader chunk1 = pool.Alloc();
	//ci = pool.GetIndex(chunk1.Current);
	//ni = pool.GetIndex(chunk1.Next);
	//pi = pool.GetIndex(chunk1.Previous);
	//cp = pool.GetPool(chunk1.Current);
	//np = pool.GetPool(chunk1.Next);
	//pp = pool.GetPool(chunk1.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	//std::cout << "\n";
	//std::cout << "*********************************\n";
	//std::cout << "\n";

	//PoolHeader chunk2 = pool.Alloc(); 
	//ci = pool.GetIndex(chunk2.Current);
	//ni = pool.GetIndex(chunk2.Next);
	//pi = pool.GetIndex(chunk2.Previous);
	//cp = pool.GetPool(chunk2.Current);
	//np = pool.GetPool(chunk2.Next);
	//pp = pool.GetPool(chunk2.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	//std::cout << "\n";
	//std::cout << "*********************************\n";
	//std::cout << "\n";

	//PoolHeader chunk3 = pool.Alloc();
	//ci = pool.GetIndex(chunk3.Current);
	//ni = pool.GetIndex(chunk3.Next);
	//pi = pool.GetIndex(chunk3.Previous);
	//cp = pool.GetPool(chunk3.Current);
	//np = pool.GetPool(chunk3.Next);
	//pp = pool.GetPool(chunk3.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	//std::cout << "\n";
	//std::cout << "*********************************\n";
	//std::cout << "\n";

	//

	///*
	//
	//PoolHeader chunk4 = pool.Alloc();
	//ci = pool.GetIndex(chunk4.Current);
	//ni = pool.GetIndex(chunk4.Next);
	//pi = pool.GetIndex(chunk4.Previous);
	//cp = pool.GetPool(chunk4.Current);
	//np = pool.GetPool(chunk4.Next);
	//pp = pool.GetPool(chunk4.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	//std::cout << "\n";
	//std::cout << "*********************************\n";
	//std::cout << "\n";

	//PoolHeader chunk5 = pool.Alloc();
	//ci = pool.GetIndex(chunk5.Current);
	//ni = pool.GetIndex(chunk5.Next);
	//pi = pool.GetIndex(chunk5.Previous);
	//cp = pool.GetPool(chunk5.Current);
	//np = pool.GetPool(chunk5.Next);
	//pp = pool.GetPool(chunk5.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	//std::cout << "\n";
	//std::cout << "*********************************\n";
	//std::cout << "\n";

	//PoolHeader chunk6 = pool.Alloc();
	//ci = pool.GetIndex(chunk6.Current);
	//ni = pool.GetIndex(chunk6.Next);
	//pi = pool.GetIndex(chunk6.Previous);
	//cp = pool.GetPool(chunk6.Current);
	//np = pool.GetPool(chunk6.Next);
	//pp = pool.GetPool(chunk6.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	//std::cout << "\n";
	//std::cout << "*********************************\n";
	//std::cout << "\n";
	//PoolHeader chunk7 = pool.Alloc();
	//ci = pool.GetIndex(chunk7.Current);
	//ni = pool.GetIndex(chunk7.Next);
	//pi = pool.GetIndex(chunk7.Previous);
	//cp = pool.GetPool(chunk7.Current);
	//np = pool.GetPool(chunk7.Next);
	//pp = pool.GetPool(chunk7.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;
	//PoolHeader chunk8 = pool.Alloc();
	//ci = pool.GetIndex(chunk8.Current);
	//ni = pool.GetIndex(chunk8.Next);
	//pi = pool.GetIndex(chunk8.Previous);
	//cp = pool.GetPool(chunk8.Current);
	//np = pool.GetPool(chunk8.Next);
	//pp = pool.GetPool(chunk8.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;
	//PoolHeader chunk9 = pool.Alloc();
	//ci = pool.GetIndex(chunk9.Current);
	//ni = pool.GetIndex(chunk9.Next);
	//pi = pool.GetIndex(chunk9.Previous);
	//cp = pool.GetPool(chunk9.Current);
	//np = pool.GetPool(chunk9.Next);
	//pp = pool.GetPool(chunk9.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;*/
	//pool.Dealloc(0 | (0 << 16));
	//pool.Dealloc(1 | (0 << 16));
	//PoolHeader chunk = pool.Alloc();
	//pool.Dealloc(1 | (1 << 16));
	//pool.Dealloc(0 | (1 << 16));
	//chunk = pool.Alloc();
	//chunk = pool.Alloc();
	//chunk = pool.Alloc();
	//ci = pool.GetIndex(chunk.Current);
	//ni = pool.GetIndex(chunk.Next);
	//pi = pool.GetIndex(chunk.Previous);
	//cp = pool.GetPool(chunk.Current);
	//np = pool.GetPool(chunk.Next);
	//pp = pool.GetPool(chunk.Previous);
	//std::cout << "current index: " << ci << ", next index: " << ni << ", prev index: " << pi << std::endl;
	//std::cout << "current pool: " << cp << ", next pool: " << np << ", prev pool: " << pp << std::endl;

	/*std::set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	std::set<int>::iterator it = s.lower_bound(2);
	std::set<int>::iterator it1 = s.upper_bound(1);*/


	system("PAUSE");
	return 0;
}