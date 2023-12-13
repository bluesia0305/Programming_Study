#pragma once
#include <iostream>
#include <queue>
#include <list>

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

	void ResetVisited()
	{
		Vertex* vertex = Head;
		while (vertex != nullptr)
		{
			vertex->Visited = false;
			vertex = vertex->Next;
		}
	}

	void DFS(Vertex* vertex)
	{
		if (vertex->Visited == false)
		{
			std::cout << vertex->Data << " ";
			vertex->Visited = true;
		}

		Edge* edge = vertex->Edge;
		while (edge != nullptr)
		{
			Vertex* nextVertex = edge->Dest;
			if (nextVertex != nullptr && nextVertex->Visited == false)
				DFS(nextVertex);

			edge = edge->Next;
		}
	}

	void DFS_Sort(Vertex* vertex)
	{
		if (vertex->Visited == false)
			vertex->Visited = true;

		Edge* edge = vertex->Edge;
		while (edge != nullptr)
		{
			Vertex* nextVertex = edge->Dest;
			if (nextVertex != nullptr && nextVertex->Visited == false)
				DFS_Sort(nextVertex);
			
			edge = edge->Next;
		}
		List.push_front(vertex);
	}

	void BFS(Vertex* vertex)
	{
		Queue.push(vertex);

		Edge* edge = nullptr;
		while (Queue.empty() == false)
		{
			Vertex* popped = Queue.front();
			Queue.pop();

			if (popped->Visited == false)
			{
				popped->Visited = true;
				std::cout << popped->Data << " ";
			}

			edge = popped->Edge;
			while (edge != nullptr && edge->Dest->Visited == false)
			{
				Queue.push(edge->Dest);
				edge = edge->Next;
			}
		}
	}

	void TopologicalSortByDFS(Vertex* vertex)
	{
		while (vertex != nullptr && vertex->Visited == false)
		{
			DFS_Sort(vertex);
			vertex = vertex->Next;
		}
	}

	void PrintList()
	{
		while (List.empty() == false)
		{
			std::cout << List.front()->Data << " ";
			List.pop_front();
		}
	}

public:
	static Edge* CreateEdge(Vertex* From, Vertex* dest)
	{
		Edge* edge = new Edge();
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

	std::queue<Vertex*> Queue;
	std::list<Vertex*> List;
};