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

	// 최소 힙 기준, 노드 삭제
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
			// 자손 노드 중 비교 대상의 index
			int selected = 0;

			// 자손 노드가 존재하지 않는 경우 == 현재 노드가 말단 노드일 경우
			if (left >= size)
				break;

			// 자손 노드가 왼쪽만 존재하는 경우
			if (right >= size)
			{
				selected = left;
			}
			// 자손 노드가 둘 다 존재하는 경우
			else
			{
				// 두 자손 노드의 키 값 중에서 더 작은 노드 찾기(최소 힙)
				if (nodes[left].Priority > nodes[right].Priority)
					selected = right;
				else
					selected = left;
			}

			// 현재 노드와 자손 노드 중 더 작은 키를 가지는 노드와 경쟁
			if (nodes[selected].Priority < nodes[parent].Priority)
			{
				SwapNode(selected, parent);
				parent = selected;
			}
			// 힙의 조건을 모두 만족하는 경우이므로 break;
			else
				break;

			left = LeftChild(parent);
			right = RightChild(parent);

		}

		std::cout << "루트에서 추출: " << result.Data << "(priority: " << result.Priority << ")\t";
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

	int depth;		// 트리의 깊이
	int capacity;	// 배열의 총 크기
	int size;		// 현재 배열에 삽입되어있는 노드의 수
};