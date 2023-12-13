#pragma once

template<typename T>
class DLinkedList
{
public:
	struct Node;

public:
	static Node* Create(T data)
	{
		Node* node = new Node();

		node->Data = data;
		node->Prev = nullptr;
		node->Next = nullptr;
		
		return node;
	}

	static void Destroy(Node** node)
	{
		delete *node;
		*node = nullptr;
	}

public:
	DLinkedList(Node* head)
	{
		this->head = head;
	}

	Node* GetHead() { return head; }

	void Push(Node** head, Node* node)
	{
		if (*head != nullptr)
		{
			Node* tail = (*head);

			while (tail->Next != nullptr)
				tail = tail->Next;

			tail->Next = node;
			node->Prev = tail;
		}
		else
		{
			*head = new Node();
		}
	}

	void Insert(Node* current, Node* node)
	{
		node->Next = current->Next;
		current->Next = node;
	}

	void Insert(int index, Node* node)
	{
		node->Next = GetNode(index)->Next;
		GetNode(index)->Next = node;
	}

	void InsertHead(Node** head, Node* node)
	{
		if (*head == nullptr)
		{
			*head = node;
		}
		else
		{
			(*head)->Prev = node;
			node->Next = *head;
			*head = node;
		}
	}

	Node* GetNode(Node* head, int index)
	{
		Node* current = head;

		while (current != nullptr && (--index) >= 0)
			current = current->Next;

		return current;
	}

	int GetNodeCount(Node* head)
	{
		int count = 0;
		Node* current = head;

		while (current != nullptr)
		{
			current = current->Next;
			++count;
		}

		return count;
	}

	void Print(Node* node)
	{
		if (node == nullptr)
			return;

		std::cout << node->Data << std::endl;
		Print(node->Next);
	}

	void Remove(Node** head, Node* remove)
	{
		if (*head == remove)
		{
			*head = remove->Next;
			if (*head != nullptr)
				(*head)->Prev = nullptr;

			remove->Prev = nullptr;
			remove->Next = nullptr;
		}
		else
		{
			remove->Prev->Next = remove->Next;
			remove->Next->Prev = remove->Prev;

			remove->Prev = nullptr;
			remove->Next = nullptr;
		}
	}


public:
	struct Node
	{
		T		Data;
		Node*	Prev;
		Node*	Next;
	};

	Node*	head;		// 처음 위치를 가리킬 포인터
};