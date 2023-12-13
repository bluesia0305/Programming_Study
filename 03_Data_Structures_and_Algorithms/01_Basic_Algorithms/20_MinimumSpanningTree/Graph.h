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

		int* weights = new int[Count];				// 현재 index에 해당하는 정점으로 진입하는 간선의 가중치들 중 가장 작은 것
		Vertex** mstVertices = new Vertex*[Count];	// 정점 자신의 주소를 저장할 배열
		Vertex** connected = new Vertex*[Count];	// 현재 정점에 대해 최소 가중치 간선을 찾았는지의 여부 확인용
		Vertex** parents = new Vertex*[Count];		// 현재 정점으로 진입하는 최소 가중치 간선의 시작 정점(From)

		// weights, connected, parents, mstVertices 배열 초기화
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

		while(queue.Empty() == false)																				// 1) 최대 |V| 정점만큼 반복 (= O(|V|))
		{
			// 현재 우선순위 큐에 들어있는 최소 가중치 간선의 Dest 정점을 currentVertex로 설정(시작할 때는 startVertex)
			typename PQueue::Node popped = queue.Remove();
			currentVertex = popped.Data;
			connected[currentVertex->Index] = currentVertex;														// 2) 우선순위 큐 제거 함수 (= O(log|V|)

			std::cout << currentVertex->Data;

			// currentVertex에 연결된 모든 간선들에 대해 수행
			currentEdge = currentVertex->Edge;
			while (currentEdge != nullptr)																			// 3) 정점 하나 당 모든 간선 탐색 (= O(|E|/|V|), 평균 간선 수)
			{
				Vertex* destVertex = currentEdge->Dest;
				if (connected[destVertex->Index] == nullptr && currentEdge->Weight < weights[destVertex->Index])
				{
					typename PQueue::Node newNode = typename PQueue::Node(destVertex, currentEdge->Weight);			// 4) 정점을 우선순위 큐에 삽입
					queue.Insert(newNode);																			//    -> O(log|V|)

					parents[destVertex->Index] = currentEdge->From;
					weights[destVertex->Index] = currentEdge->Weight;
				}
				currentEdge = currentEdge->Next;
			}
		}

		// 시간 복잡도:
		// 1), 2)에 의해 O(|V|log|V|)
		// 1), 3), 4)에 의해 O(|E|log|V|)
		// 따라서, 최종적으로 O((|E|+|V|)log|V|) = O(|E|log|V|)     (일반적으로 E >> V 이므로)
		


		//// Weight 출력 확인 목적
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

			//// 간선 확인
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
	
		// 그래프 내에 존재하는 모든 간선을 우선순위 큐에 넣어 정렬
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

		// 우선순위 큐 내에 존재하는 간선들에 대하여 하나씩 추출해가며 포함
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