#pragma once
#include <iostream>
#include <queue>
#include <list>

#include "PriorityQueue.h"
#include "DisjointSet.h"

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

	void Prim(Vertex* startVertex, Graph<T>* copyGraph)
	{
		typedef PriorityQueueByArray<Vertex*> PQueue;

		Vertex* currentVertex = nullptr;
		Edge* currentEdge = nullptr;

		int* weights = new int[Count];				// ���� index�� �ش��ϴ� �������� �����ϴ� ������ ����ġ�� �� ���� ���� ��
		Vertex** mstVertices = new Vertex*[Count];	// ���� �ڽ��� �ּҸ� ������ �迭
		Vertex** connected = new Vertex*[Count];	// ���� ������ ���� �ּ� ����ġ ������ ã�Ҵ����� ���� Ȯ�ο�
		Vertex** parents = new Vertex*[Count];		// ���� �������� �����ϴ� �ּ� ����ġ ������ ���� ����(From)

		// weights, connected, parents, mstVertices �迭 �ʱ�ȭ
		int index = 0;
		currentVertex = Head;
		while (currentVertex != nullptr)
		{
			Vertex* newVertex = CreateVertex(currentVertex->Data);
			copyGraph->AddVertex(newVertex);

			connected[index] = nullptr;
			mstVertices[index] = newVertex;
			parents[index] = nullptr;
			weights[index] = INT_MAX;

			currentVertex = currentVertex->Next;
			index++;
		}

		PQueue queue(6);
		typename PQueue::Node startNode = typename PQueue::Node(startVertex, 0);

		queue.Insert(startNode);
		weights[startVertex->Index] = 0;

		while(queue.Empty() == false)																				// 1) �ִ� |V| ������ŭ �ݺ� (= O(|V|))
		{
			// ���� �켱���� ť�� ����ִ� �ּ� ����ġ ������ Dest ������ currentVertex�� ����(������ ���� startVertex)
			typename PQueue::Node popped = queue.Remove();
			currentVertex = popped.Data;
			connected[currentVertex->Index] = currentVertex;														// 2) �켱���� ť ���� �Լ� (= O(log|V|)

			std::cout << currentVertex->Data;

			// currentVertex�� ����� ��� �����鿡 ���� ����
			currentEdge = currentVertex->Edge;
			while (currentEdge != nullptr)																			// 3) ���� �ϳ� �� ��� ���� Ž�� (= O(|E|/|V|), ��� ���� ��)
			{
				Vertex* destVertex = currentEdge->Dest;
				if (connected[destVertex->Index] == nullptr && currentEdge->Weight < weights[destVertex->Index])
				{
					typename PQueue::Node newNode = typename PQueue::Node(destVertex, currentEdge->Weight);			// 4) ������ �켱���� ť�� ����
					queue.Insert(newNode);																			//    -> O(log|V|)

					parents[destVertex->Index] = currentEdge->From;
					weights[destVertex->Index] = currentEdge->Weight;
				}
				currentEdge = currentEdge->Next;
			}
		}

		// �ð� ���⵵:
		// 1), 2)�� ���� O(|V|log|V|)
		// 1), 3), 4)�� ���� O(|E|log|V|)
		// ����, ���������� O((|E|+|V|)log|V|) = O(|E|log|V|)     (�Ϲ������� E >> V �̹Ƿ�)
		


		//// Weight ��� Ȯ�� ����
		//std::cout << std::endl << std::endl;
		//for (int i = 0; i < Count; ++i)
		//{
		//	std::cout << i << ", " << weights[i] << " / ";
		//}
		//std::cout << std::endl;

		std::cout << std::endl << std::endl;
		for (int i = 0; i < Count; ++i)
		{
			int start, target;
			if (parents[i] == nullptr)
				continue;

			start = parents[i]->Index;
			target = i;

			copyGraph->AddEdge(mstVertices[start], Graph<T>::CreateEdge(mstVertices[start], mstVertices[target], weights[i]));
			copyGraph->AddEdge(mstVertices[target], Graph<T>::CreateEdge(mstVertices[target], mstVertices[start], weights[i]));

			//// ���� Ȯ��
			//std::cout << mstVertices[start]->Data << " -> " << mstVertices[target]->Data << ", " << weights[i] << std::endl;
		}
		std::cout << std::endl;

		delete[] weights;
		delete[] mstVertices;
		delete[] connected;
		delete[] parents;
	}

	void Kruskal(Graph<T>* copyGraph)
	{
		Vertex** mstVertices = new Vertex*[Count];
		PriorityQueueByArray<Edge*> queue(10);
	
		typename DisjointSet<Vertex*>::Set** sets = new typename DisjointSet<Vertex*>::Set*[Count];
		int index = 0;
	
		// �׷��� ���� �����ϴ� ��� ������ �켱���� ť�� �־� ����
		Vertex* currentVertex = Head;
		Edge* currentEdge = nullptr;
		while (currentVertex != nullptr)
		{
			sets[index] = DisjointSet<Vertex*>::CreateSet(currentVertex);
			mstVertices[index] = CreateVertex(currentVertex->Data);
			copyGraph->AddVertex(mstVertices[index]);
	
			currentEdge = currentVertex->Edge;
			while (currentEdge != nullptr)
			{
				typename PriorityQueueByArray<Edge*>::Node newNode = typename PriorityQueueByArray<Edge*>::Node(currentEdge, currentEdge->Weight);
				queue.Insert(newNode);
	
				currentEdge = currentEdge->Next;
			}
	
			currentVertex = currentVertex->Next;
			index++;
		}

		// �켱���� ť ���� �����ϴ� �����鿡 ���Ͽ� �ϳ��� �����ذ��� ����
		while (queue.Empty() == false)
		{
			typename PriorityQueueByArray<Edge*>::Node popped = queue.Remove();
			currentEdge = popped.Data;
	
			int from = currentEdge->From->Index;
			int dest = currentEdge->Dest->Index;
	
			if (DisjointSet<Vertex*>::FindSet(sets[from]) == DisjointSet<Vertex*>::FindSet(sets[dest]))
				continue;
	
			DisjointSet<Vertex*>::UnionSet(sets[from], sets[dest]);
			copyGraph->AddEdge(mstVertices[from], Graph<T>::CreateEdge(mstVertices[from], mstVertices[dest], currentEdge->Weight));
			copyGraph->AddEdge(mstVertices[dest], Graph<T>::CreateEdge(mstVertices[dest], mstVertices[from], currentEdge->Weight));
		}
	
		delete[] sets;
		delete[] mstVertices;
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
		bool Visited = false;
	};

private:
	Vertex* Head = nullptr;
	int Count = 0;
};