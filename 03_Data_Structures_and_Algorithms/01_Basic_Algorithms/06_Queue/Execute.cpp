#include <iostream>
#include "CircularQueueByArray.h"
#include "CircularQueueByLinkedList.h"

int main()
{
	printf("<circular queue by array>\n");

	CircularQueueByArray<int> queue1(10);
	queue1.Enqueue(1);
	queue1.Enqueue(2);
	queue1.Enqueue(3);
	queue1.Enqueue(4);

	for (int i = 0; i < 3; i++)
	{
		printf("Dequeue: %d\t", queue1.Dequeue());
		printf("Front: %d, Rear: %d\n", queue1.Front(), queue1.Rear());
	}

	int count = 100;
	while (queue1.Full() == false)
	{
		queue1.Enqueue(count++);
	}

	printf("Capacity: %d\t", queue1.Capacity());
	printf("Front: %d, Rear: %d\n", queue1.Front(), queue1.Rear());

	printf("\n(전부 출력)\n");


	while (queue1.Empty() == false)
	{
		printf("Dequeue: %d\t", queue1.Dequeue());
		printf("Front: %d, Rear: %d\n", queue1.Front(), queue1.Rear());
	}

	printf("-------------------------------\n");
	printf("<circular queue by linked list>\n");


	typedef CircularQueueByLinkedList<int> QueueByList;
	QueueByList queue2;
	queue2.Enqueue(QueueByList::CreateNode(1));
	queue2.Enqueue(QueueByList::CreateNode(2));
	queue2.Enqueue(QueueByList::CreateNode(3));
	queue2.Enqueue(QueueByList::CreateNode(4));

	printf("Size: %d\n", queue2.Size());

	while (queue2.Empty() == false)
	{
		QueueByList::Node* node = queue2.Dequeue();
		printf("Dequeue: %d\n", node->Data);

		QueueByList::DestroyNode(&node);
	}

	return 0;
}