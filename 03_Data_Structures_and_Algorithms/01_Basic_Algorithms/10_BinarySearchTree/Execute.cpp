#include "BinarySearchTree.h"

using namespace std;

typedef BSTree<short> Tree;

int main()
{
	Tree tree;
	Tree::Node* root = Tree::CreateNode(12);
	tree.SetRoot(root);

	tree.Insert(Tree::CreateNode(22));
	tree.Insert(Tree::CreateNode(99));
	tree.Insert(Tree::CreateNode(42));
	tree.Insert(Tree::CreateNode(17));
	tree.Insert(Tree::CreateNode(3));
	tree.Insert(Tree::CreateNode(98));
	tree.Insert(Tree::CreateNode(34));
	tree.Insert(Tree::CreateNode(75));
	tree.Insert(Tree::CreateNode(32));
	tree.Insert(Tree::CreateNode(1));

	tree.InOrder(root, 0);

	int depth = 0;
	Tree::Node* node = tree.Search(root, 98, &depth);
	cout << endl << endl << "찾기: " << depth << "번에 찾음" << endl;

	Tree::Node* remove = tree.Remove(22);
	Tree::DestroyNode(&remove);
	tree.InOrder(root, 0);

	return 0;
}