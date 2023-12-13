#pragma once

template<typename T>
class CircularQueueByLinkedList
{
public:
	struct Node
	{
		T Data;
		Node* Next;
	};

public:
	CircularQueueByLinkedList()
	{
		
	}

	~CircularQueueByLinkedList()
	{
		while (Empty() == false)
		{
			Node* temp = Dequeue();
			DestroyNode(&temp);
		}
	}

	void Enqueue(Node* node)
	{
		if (Empty() == true)
		{
			front = node;
			rear = node;
			capacity++;
		}
		else
		{
			rear->Next = node;
			rear = node;
			capacity++;
		}
	}

	Node* Dequeue()
	{
		Node* node = front;
		if (front->Next == nullptr)
		{
			front = nullptr;
			rear = nullptr;
		}
		else
			front = front->Next;

		capacity--;

		return node;
	}

	int Size() { return capacity; }

	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = nullptr;

		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = nullptr;
	}

	bool Empty() { return front == nullptr;	}

private:
	int capacity = 0;
	Node* front = nullptr;
	Node* rear = nullptr;
};