#include <memory>
#include <string>
#include "BinaryTree.h"

using namespace std;

void Expression(const char* postfix, BTree<char>::Node** node)
{
	char* str = const_cast<char*>(postfix);

	size_t length = strlen(str);
	char token = str[length - 1];
	str[length - 1] = '\0';

	switch (token)
	{
		case '+': case '-': case '*': case '/': case '%':
		{
			*node = BTree<char>::CreateNode(token);

			Expression(postfix, &(*node)->Right);
			Expression(postfix, &(*node)->Left);
			break;
		}

		default:
		{
			*node = BTree<char>::CreateNode(token);
			break;
		}
	}
}

float Evaluate(BTree<char>::Node* node)
{
	if (node == nullptr) return 0.0f;

	switch (node->Data)
	{
		case '+': case '-': case '*': case '/': case '%':
		{
			float left = Evaluate(node->Left);
			float right = Evaluate(node->Right);

			switch (node->Data)
			{
				case '+': return left + right;
				case '-': return left - right;
				case '*': return left * right;
				case '/': return left / right;
				case '%': return (int)left % (int)right;
			}
		}

		default:
		{
			char temp[4];
			memset(temp, 0, sizeof(temp));
			temp[0] = node->Data;

			return atof(temp);
		}
	}
}

int main()
{
	BTree<char>::Node* root = nullptr;

	string postfix = "34*12+32/+-";
	Expression(postfix.c_str(), &root);

	BTree<char> tree;
	tree.SetRoot(root);

	cout << "[ Pre-order ]" << endl;
	tree.PreOrder(root);
	cout << endl << endl;

	cout << "[ In-order ]" << endl;
	tree.InOrder(root);
	cout << endl << endl;

	cout << "[ Post-order ]" << endl;
	tree.PostOrder(root);
	cout << endl << endl;

	cout << endl << Evaluate(root) << endl;

	return 0;
}