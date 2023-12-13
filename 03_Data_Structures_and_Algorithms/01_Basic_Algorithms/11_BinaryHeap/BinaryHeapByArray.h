#pragma once

#include <cmath>
#include <iostream>

template<typename T>
class BinaryHeapByArray
{
public:
	struct Node;

	BinaryHeapByArray(int depth)
		: depth(depth), capacity((int)(pow(2, depth + 1) - 1))
	{
		nodes = new Node[capacity];
		size = 0;
	}

	~BinaryHeapByArray()
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
			memcpy(temp, nodes, sizeof(int) * capacityOld);

			delete[] nodes;
			nodes = temp;
			temp = nullptr;
		}

		nodes[current] = data;

		while (current > 0 && nodes[current].Data < nodes[parent].Data)
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

		Node result;
		memcpy(&result, &nodes[0], sizeof(Node));

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
				if (nodes[left].Data > nodes[right].Data)
					selected = right;
				else
					selected = left;
			}

			// ���� ���� �ڼ� ��� �� �� ���� Ű�� ������ ���� ����
			if (nodes[selected].Data < nodes[parent].Data)
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

		std::cout << "��Ʈ���� ����: " << result.Data << "\t";
		return result;
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			int parent = -1;
			if (i > 0)
				parent = Parent(i);

			std::cout << nodes[i].Data << "|" << parent << " ";
		}

		std::cout << std::endl << std::endl;
	}

	bool Empty() { return size == 0; }
	int Parent(int index) { return (int)(index - 1) / 2; }
	int LeftChild(int index) { return 2 * index + 1; }
	int RightChild(int index) { return 2 * index + 2; }
	void SwapNode(int index1, int index2)
	{
		Node* temp = new Node();
		memcpy(temp, &nodes[index1], sizeof(Node));
		memcpy(&nodes[index1], &nodes[index2], sizeof(Node));
		memcpy(&nodes[index2], temp, sizeof(Node));

		delete temp;
	}
	
public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node(data);
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

		Node() {};
		Node(T data) { Data = data; }
	};

private:
	Node* nodes;

	int depth;		// Ʈ���� ����
	int capacity;	// �迭�� �� ũ��
	int size;		// ���� �迭�� ���ԵǾ��ִ� ����� ��
};