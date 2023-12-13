#include "StackByArray.h"
#include "StackByLinkedList.h"

int main()
{
	StackByArray<int> stack1;

	stack1.Push(10);
	stack1.Push(20);
	stack1.Push(30);
	stack1.Pop();

	stack1.Push(40);
	stack1.Push(50);

	while (stack1.Empty() == false)
		printf("%d\n", stack1.Pop());

	printf("--------------------\n");

	StackByLinkedList stack2;
	stack2.Push(StackByLinkedList::CreateNode("abc"));
	stack2.Push(StackByLinkedList::CreateNode("bcd"));
	stack2.Push(StackByLinkedList::CreateNode("cde"));
	stack2.Push(StackByLinkedList::CreateNode("def"));

	printf("\n");

	int count = stack2.Size();
	printf("Size: %d\n", count);

	for (int i = 0; i < count; i++)
	{
		if (stack2.Empty() == true)
			break;

		Node* temp = stack2.Pop();
		printf("pop: %s\n", temp->Data.c_str());
		StackByLinkedList::DestroyNode(&temp);

		if (stack2.Empty() == false)
			printf("Top: %s\n", stack2.Top()->Data.c_str());
		else
			printf("Empty\n");

		printf("\n");
	}


	return 0;
}