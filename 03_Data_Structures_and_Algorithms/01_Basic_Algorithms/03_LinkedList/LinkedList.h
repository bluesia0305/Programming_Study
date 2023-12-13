#pragma once

template<typename T>
class LinkedList
{
public:
	struct Node;

public:
	static Node* Create(T data)
	{
		Node* node = new Node();

		node->Data = data;
		node->Next = nullptr;
		
		return node;
	}

	static void Destroy(Node* node)
	{
		delete node;
		node = nullptr;
	}

public:
	LinkedList(Node* head)
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

	void Insert(int location, Node* node)
	{
		node->Next = GetNode(location)->Next;
		GetNode(location)->Next = node;
	}

	void InsertHead(Node** current, Node* head)
	{
		if (*current == nullptr)
		{
			*current = head;
		}
		else
		{
			head->Next = *current;
			*current = head;
		}
	}

	void Remove(Node** head, Node* remove)
	{
		if (*head == remove)
		{
			*head = remove->Next;
		}
		else
		{
			Node* current = head;
			while (current != nullptr && current->Next != remove)
			{
				current = current->Next;
			}
			if (current != nullptr)
			{
				current->Next = remove->Next;
			}
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

		cout << node->Data << endl;
		Print(node->Next);
	}

public:
	struct Node
	{
		T		Data;
		Node*	Next;
	};

	Node*	head;		// 처음 위치를 가리킬 포인터
};