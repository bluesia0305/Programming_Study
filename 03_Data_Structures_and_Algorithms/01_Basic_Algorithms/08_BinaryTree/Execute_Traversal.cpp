#include "BinaryTree.h"

using namespace std;

int main()
{
	BTree<char> tree;
	BTree<char>::Node* A = BTree<char>::CreateNode('A');
	BTree<char>::Node* B = BTree<char>::CreateNode('B');
	BTree<char>::Node* C = BTree<char>::CreateNode('C');
	BTree<char>::Node* D = BTree<char>::CreateNode('D');
	BTree<char>::Node* E = BTree<char>::CreateNode('E');
	BTree<char>::Node* F = BTree<char>::CreateNode('F');
	BTree<char>::Node* G = BTree<char>::CreateNode('G');
	BTree<char>::Node* H = BTree<char>::CreateNode('H');
	BTree<char>::Node* I = BTree<char>::CreateNode('I');
	BTree<char>::Node* J = BTree<char>::CreateNode('J');
	BTree<char>::Node* K = BTree<char>::CreateNode('K');

	tree.SetRoot(A);

	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	cout << "[ Pre-order ]" << endl;
	tree.PreOrder(A);
	cout << endl;

	cout << "[ In-order ]" << endl;
	tree.InOrder(A);
	cout << endl;

	cout << "[ Post-order ]" << endl;
	tree.PostOrder(A);
	cout << endl;

	return 0;
}