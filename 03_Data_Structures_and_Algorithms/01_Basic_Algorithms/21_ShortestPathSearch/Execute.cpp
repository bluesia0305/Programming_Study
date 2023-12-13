#include "Graph.h"

using namespace std;

typedef Graph<char> G;

int main()
{
	G graph, dijkstra;
	G::Vertex* A = G::CreateVertex('A');
	G::Vertex* B = G::CreateVertex('B');
	G::Vertex* C = G::CreateVertex('C');
	G::Vertex* D = G::CreateVertex('D');
	G::Vertex* E = G::CreateVertex('E');
	G::Vertex* F = G::CreateVertex('F');
	G::Vertex* G = G::CreateVertex('G');
	G::Vertex* H = G::CreateVertex('H');
	G::Vertex* I = G::CreateVertex('I');

	graph.AddVertex(A);
	graph.AddVertex(B);
	graph.AddVertex(C);
	graph.AddVertex(D);
	graph.AddVertex(E);
	graph.AddVertex(F);
	graph.AddVertex(G);
	graph.AddVertex(H);
	graph.AddVertex(I);


	graph.AddEdge(A, G::CreateEdge(A, E, 247));

	graph.AddEdge(B, G::CreateEdge(B, A, 35));
	graph.AddEdge(B, G::CreateEdge(B, C, 126));
	graph.AddEdge(B, G::CreateEdge(B, F, 150));

	graph.AddEdge(C, G::CreateEdge(C, D, 117));
	graph.AddEdge(C, G::CreateEdge(C, F, 162));
	graph.AddEdge(C, G::CreateEdge(C, G, 220));

	graph.AddEdge(E, G::CreateEdge(E, H, 98));

	graph.AddEdge(F, G::CreateEdge(F, E, 82));
	graph.AddEdge(F, G::CreateEdge(F, G, 154));
	graph.AddEdge(F, G::CreateEdge(F, H, 120));

	graph.AddEdge(G, G::CreateEdge(G, I, 106));

	graph.Print();

	cout << "다익스트라 알고리즘 (최단 경로)" << endl;
	graph.Dijksra(B, &dijkstra);
	dijkstra.Print();

	return 0;
}