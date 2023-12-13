#include "BinaryHeapByArray.h"

using namespace std;

int main()
{
	BinaryHeapByArray<int> heap(1);

	heap.Insert(37);
	heap.Insert(88);
	heap.Insert(43);
	heap.Insert(17);
	heap.Insert(161);
	heap.Insert(67);
	heap.Insert(8);
	heap.Insert(13);
	heap.Insert(52);
	heap.Insert(7);
	heap.Insert(2);

	heap.Print();

	while (heap.Empty() == false)
	{
		heap.Remove();
		heap.Print();
	}

	return 0;
}