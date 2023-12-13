#include<iostream>
#include "DLinkedList.h"
using namespace std;

typedef DLinkedList<int> List;

int main()
{
	List::Node* node = List::Create(-100);

	List list(node);

	for (int i = 0; i < 5; i++)
	{
		List::Node* temp = List::Create(i);
		list.Push(&node, temp);
	}

	list.InsertHead(&node, List::Create(-2));
	list.InsertHead(&node, List::Create(-1));

	list.Remove(&node, list.GetNode(node, 2));

	for (int i = 0; i < 7; i++)
	{
		printf("index: %i\n", i);
		printf("data : %d\n", *(list.GetNode(node, i)));
		printf("self : %p\n", list.GetNode(node, i));
		printf("prev : %p\n", (list.GetNode(node, i)->Prev));
		printf("next : %p\n", (list.GetNode(node, i)->Next));
		printf("--------------\n");
	}

	return 0;
}