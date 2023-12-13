#include "PriorityQueue.h"

using namespace std;

typedef PriorityQueueByArray<string> PQueue;

int main()
{
	PQueue queue(2);

	queue.Insert(*PQueue::CreateNode("È«±æµ¿", 34));
	queue.Insert(*PQueue::CreateNode("ÀÌ¼ø½Å", 12));
	queue.Insert(*PQueue::CreateNode("¼¼Á¾´ë¿Õ", 87));
	queue.Insert(*PQueue::CreateNode("À»Áö¹®´ö", 45));
	queue.Insert(*PQueue::CreateNode("¹Ú¹®¼ö", 35));
	queue.Insert(*PQueue::CreateNode("À¯°ü¼ø", 66));
	queue.Insert(*PQueue::CreateNode("À±ºÀ±æ", 5));

	queue.Print();

	while (queue.Empty() == false)
	{
		queue.Remove();
		queue.Print();
	}

	return 0;
}