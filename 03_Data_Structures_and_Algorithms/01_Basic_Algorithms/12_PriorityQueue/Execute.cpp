#include "PriorityQueue.h"

using namespace std;

typedef PriorityQueueByArray<string> PQueue;

int main()
{
	PQueue queue(2);

	queue.Insert(*PQueue::CreateNode("ȫ�浿", 34));
	queue.Insert(*PQueue::CreateNode("�̼���", 12));
	queue.Insert(*PQueue::CreateNode("�������", 87));
	queue.Insert(*PQueue::CreateNode("��������", 45));
	queue.Insert(*PQueue::CreateNode("�ڹ���", 35));
	queue.Insert(*PQueue::CreateNode("������", 66));
	queue.Insert(*PQueue::CreateNode("������", 5));

	queue.Print();

	while (queue.Empty() == false)
	{
		queue.Remove();
		queue.Print();
	}

	return 0;
}