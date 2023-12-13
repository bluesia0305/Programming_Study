#include "StackByLinkedList.h"

StackByLinkedList::StackByLinkedList()
{

}

StackByLinkedList::~StackByLinkedList()
{
	while (Empty() == true)
	{
		Node* node = Pop();
		DestroyNode(&node);
	}

	list = nullptr;
	top = nullptr;
}

void StackByLinkedList::Push(Node* node)
{
	top = node;

	if (top != nullptr)
	{
		Node* tail = list;
		while (tail->Next != nullptr)
			tail = tail->Next;

		tail->Next = node;
	}
	else
	{
		list = node;
	}
}

Node* StackByLinkedList::Pop()
{
	Node* temp = top;

	if (list == top)
	{
		list = nullptr;
		top = nullptr;
	}
	else
	{
		Node* tail = list;

		while (tail->Next != top)
			tail = tail->Next;

		top = tail;
		tail->Next = nullptr;
	}

	return temp;
}

int StackByLinkedList::Size()
{
	int count = 0;
	Node* node = list;
	while (node != nullptr)
	{
		node = node->Next;
		count++;
	}

	return count;
}

Node* StackByLinkedList::CreateNode(string data)
{
	Node* node = new Node();
	node->Data = data;
	node->Next = nullptr;

	return node;
}

void StackByLinkedList::DestroyNode(Node** node)
{
	delete* node;
	*node = nullptr;
}
