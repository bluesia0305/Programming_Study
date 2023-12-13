#include "Graph.h"

using namespace std;

typedef Graph<char> G;

int main()
{
	G graph;
	G::Vertex* v1 = G::CreateVertex('A');
	G::Vertex* v2 = G::CreateVertex('B');
	G::Vertex* v3 = G::CreateVertex('C');
	G::Vertex* v4 = G::CreateVertex('D');
	G::Vertex* v5 = G::CreateVertex('E');
	G::Vertex* v6 = G::CreateVertex('F');
	G::Vertex* v7 = G::CreateVertex('G');
	G::Vertex* v8 = G::CreateVertex('H');

	graph.AddVertex(v1);
	graph.AddVertex(v2);
	graph.AddVertex(v3);
	graph.AddVertex(v4);
	graph.AddVertex(v5);
	graph.AddVertex(v6);
	graph.AddVertex(v7);
	graph.AddVertex(v8);

	graph.AddEdge(v1, G::CreateEdge(v1, v3));
	graph.AddEdge(v1, G::CreateEdge(v1, v4));
	
	graph.AddEdge(v2, G::CreateEdge(v2, v3));
	graph.AddEdge(v2, G::CreateEdge(v2, v5));

	graph.AddEdge(v3, G::CreateEdge(v3, v6));

	graph.AddEdge(v4, G::CreateEdge(v4, v6));
	graph.AddEdge(v4, G::CreateEdge(v4, v7));

	graph.AddEdge(v5, G::CreateEdge(v5, v7));

	graph.AddEdge(v6, G::CreateEdge(v6, v8));
	
	graph.AddEdge(v7, G::CreateEdge(v7, v8));
	
	graph.Print();

	graph.DFS(v1);
	cout << endl << endl;

	graph.ResetVisited();

	graph.BFS(v1);
	cout << endl << endl;

	graph.ResetVisited();

	graph.TopologicalSortByDFS(v1);
	graph.PrintList();

	return 0;
}