#pragma once
#include <iostream>
#include "PriorityQueue.h"

template<typename T>
class Graph
{
public:
	struct Edge;
	struct Vertex;

public:
	void AddVertex(Vertex* vertex)
	{
		Vertex* verticies = Head;
		if (verticies != nullptr)
		{
			while (verticies->Next != nullptr)
				verticies = verticies->Next;

			verticies->Next = vertex;
		}
		else
			Head = vertex;

		vertex->Index = Count++;
	}

	void AddEdge(Vertex* vertex, Edge* edge)
	{
		if (vertex->Edge != nullptr)
		{
			Edge* edgeList = vertex->Edge;

			while (edgeList->Next != nullptr)
				edgeList = edgeList->Next;

			edgeList->Next = edge;
		}
		else
		{
			vertex->Edge = edge;
		}
	}

	void Print()
	{
		Vertex* vertex = nullptr;
		Edge* edge = nullptr;

		if ((vertex = Head) == nullptr)
			return;

		while (vertex != nullptr)
		{
			std::cout << vertex->Data << ":";

			if ((edge = vertex->Edge) == nullptr)
			{
				vertex = vertex->Next;
				std::cout << std::endl;

				continue;
			}

			while (edge != nullptr)
			{
				std::cout << " " << edge->Dest->Data;
				edge = edge->Next;
			}

			std::cout << std::endl;

			vertex = vertex->Next;
		}

		std::cout << std::endl;
	}

	void Dijksra(Vertex* startVertex, Graph<T>* copyGraph)
	{
		int* weights = new int[Count];				// �ش� index�� ������ �����ϱ������ ���� ����ġ�� ����.
		Vertex** shorts = new Vertex*[Count];		// �ش� index�� ������ ����.
		Vertex** connected = new Vertex*[Count];	// �ش� index�� ������ �̹湮 ����(==nullptr)�� ǥ��.
		Vertex** parents = new Vertex*[Count];		// �ش� index�� �����ϴ� ������ ����.

		// ��� ������ ���Ͽ� ����ġ = MAX, �ִ� ���� ����, ���� ����, ���� ��带 �ʱ�ȭ�Ѵ�.
		Vertex* currentVertex = Head;
		for (int index = 0; currentVertex != nullptr; ++index)
		{
			Vertex* newVertex = CreateVertex(currentVertex->Data);
			copyGraph->AddVertex(newVertex);

			weights[index] = INT_MAX;
			shorts[index] = newVertex;
			connected[index] = nullptr;
			parents[index] = nullptr;

			currentVertex = currentVertex->Next;
		}

		// �켱���� ť�� ����Ͽ�
		// 1) ���� ������ ���� ���� ����̸�,
		// 2) �ش� ������ ����Ǿ� �ִ� ����ġ ���� ���� ������ ����ġ + ������ ����ġ ���� ū ���
		// �� �� ������ �����ϸ� �ش� ������ ����ġ�� �����ϰ� �����Ѵ�.
		PriorityQueueByArray<Vertex*> queue(10);
		typename PriorityQueueByArray<Vertex*>::Node startNode = typename PriorityQueueByArray<Vertex*>::Node(startVertex, 0);
		queue.Insert(startNode);

		weights[startVertex->Index] = 0;
		Edge* currentEdge = nullptr;
		while (queue.Empty() == false)
		{
			typename PriorityQueueByArray<Vertex*>::Node popped = queue.Remove();
			currentVertex = popped.Data;
			connected[currentVertex->Index] = currentVertex;

			currentEdge = currentVertex->Edge;
			while (currentEdge != nullptr)
			{
				Vertex* dest = currentEdge->Dest;

				if (connected[dest->Index] == nullptr &&
					weights[currentVertex->Index] + currentEdge->Weight < weights[dest->Index])
				{
					weights[dest->Index] = weights[currentVertex->Index] + currentEdge->Weight;
					parents[dest->Index] = currentVertex;

					typename PriorityQueueByArray<Vertex*>::Node newNode = typename PriorityQueueByArray<Vertex*>::Node(dest, weights[dest->Index]);
					queue.Insert(newNode);
				}
				currentEdge = currentEdge->Next;
			}
		}

		for (int i = 0; i < Count; ++i)
		{
			if (parents[i] == nullptr)
				continue;

			int from = parents[i]->Index;
			int dest = i;

			copyGraph->AddEdge(shorts[from], Graph<T>::CreateEdge(shorts[from], shorts[dest], weights[dest]));

			std::cout << shorts[from]->Data << ", " << shorts[dest]->Data << ", " << weights[dest] << std::endl;
		}
		std::cout << std::endl << std::endl;

		delete[] shorts;
		delete[] weights;
		delete[] connected;
		delete[] parents;
	}

public:
	static Edge* CreateEdge(Vertex* From, Vertex* dest, int weight)
	{
		Edge* edge = new Edge();
		edge->Weight = weight;
		edge->From = From;
		edge->Dest = dest;

		return edge;
	}

	static Vertex* CreateVertex(T data)
	{
		Vertex* vertex = new Vertex();
		vertex->Data = data;

		return vertex;
	}

public:
	struct Edge
	{
		int Weight = 0;

		Vertex* From = nullptr;
		Vertex* Dest = nullptr;
		Edge* Next = nullptr;
	};

	struct Vertex
	{
		T Data;
		int Index = 0;

		Vertex* Next = nullptr;
		Edge* Edge = nullptr;
	};

private:
	Vertex* Head = nullptr;
	int Count = 0;
};