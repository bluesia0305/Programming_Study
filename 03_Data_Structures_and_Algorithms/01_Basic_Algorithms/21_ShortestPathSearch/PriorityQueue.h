#pragma once

#include <cmath>
#include <string>
#include <iostream>

template<typename T>
class PriorityQueueByArray
{
public:
	struct Node;

	PriorityQueueByArray(int depth)
		: depth(depth), capacity((int)(pow(2, depth + 1) - 1))
	{
		nodes = new Node[capacity];
		size = 0;
	}

	~PriorityQueueByArray()
	{
		delete[] nodes;
		nodes = nullptr;
	}

	void Insert(Node data)
	{
		int current = size;
		int parent = Parent(current);

		if (size == capacity)
		{
			depth++;
			int capacityOld = capacity;
			capacity = (int)(pow(2, depth + 1) - 1);
			Node* temp = new Node[capacity];

			//memcpy(temp, nodes, sizeof(int) * capacityOld);
			for (int i = 0; i < capacityOld; ++i)
				temp[i] = nodes[i];

			delete[] nodes;
			nodes = temp;
			temp = nullptr;
		}

		nodes[current] = data;

		while (current > 0 && nodes[current].Priority < nodes[parent].Priority)
		{
			SwapNode(current, parent);
			current = parent;
			parent = Parent(current);
		}

		size++;
	}

	// �ּ� �� ����, ��� ����
	Node Remove()
	{
		int parent = 0;
		int left = 0;
		int right = 0;

		//memcpy(&result, &nodes[0], sizeof(Node));
		Node result = nodes[0];

		size--;
		SwapNode(0, size);

		left = LeftChild(0);
		right = RightChild(0);

		while (true)
		{
			// �ڼ� ��� �� �� ����� index
			int selected = 0;

			// �ڼ� ��尡 �������� �ʴ� ��� == ���� ��尡 ���� ����� ���
			if (left >= size)
				break;

			// �ڼ� ��尡 ���ʸ� �����ϴ� ���
			if (right >= size)
			{
				selected = left;
			}
			// �ڼ� ��尡 �� �� �����ϴ� ���
			else
			{
				// �� �ڼ� ����� Ű �� �߿��� �� ���� ��� ã��(�ּ� ��)
				if (nodes[left].Priority > nodes[right].Priority)
					selected = right;
				else
					selected = left;
			}

			// ���� ���� �ڼ� ��� �� �� ���� Ű�� ������ ���� ����
			if (nodes[selected].Priority < nodes[parent].Priority)
			{
				SwapNode(selected, parent);
				parent = selected;
			}
			// ���� ������ ��� �����ϴ� ����̹Ƿ� break;
			else
				break;

			left = LeftChild(parent);
			right = RightChild(parent);

		}

		//std::cout << "��Ʈ���� ����: " << result.Data << "(priority: " << result.Priority << ")\t";
		return result;
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			int parent = -1;
			if (i > 0)
				parent = Parent(i);

			std::cout << nodes[i].Data << "(priority: " << nodes[i].Priority << ") ";
		}

		std::cout << std::endl << std::endl;
	}

	bool Empty() { return size == 0; }
	int Parent(int index) { return (int)(index - 1) / 2; }
	int LeftChild(int index) { return 2 * index + 1; }
	int RightChild(int index) { return 2 * index + 2; }
	void SwapNode(int index1, int index2)
	{
		//Node* temp = new Node();
		//memcpy(temp, &nodes[index1], sizeof(Node));
		//memcpy(&nodes[index1], &nodes[index2], sizeof(Node));
		//memcpy(&nodes[index2], temp, sizeof(Node));

		Node temp;
		temp = nodes[index1];
		nodes[index1] = nodes[index2];
		nodes[index2] = temp;
	}

public:
	static Node* CreateNode(T data, int priority)
	{
		Node* node = new Node(data, priority);
		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = nullptr;
	}

public:
	struct Node
	{
		T Data;
		int Priority;

		Node() {};
		Node(T data, int priority) { Data = data; Priority = priority; }
	};

private:
	Node* nodes;

	int depth;		// Ʈ���� ����
	int capacity;	// �迭�� �� ũ��
	int size;		// ���� �迭�� ���ԵǾ��ִ� ����� ��
};