#pragma once

#include <iostream>

template<typename T>
class BSTree
{
public:
	struct Node;

public:
	BSTree()
	{
		
	}

	~BSTree()
	{
		DestroyTree(root);
	}

	void Insert(Node* child, Node** parent = nullptr)
	{
		if (parent == nullptr)
			parent = &root;

		if ((*parent)->Data < child->Data)
		{
			if ((*parent)->Right == nullptr)
				(*parent)->Right = child;
			else
				Insert(child, &(*parent)->Right);
		}
		else if ((*parent)->Data > child->Data)
		{
			if ((*parent)->Left == nullptr)
				(*parent)->Left = child;
			else
				Insert(child, &(*parent)->Left);
		}
	}

	Node* Search(Node* node, T data, int* depth)
	{
		if (node == nullptr)
			return nullptr;

		(*depth)++;

		if (node->Data > data)
			return Search(node->Left, data, depth);
		else if (node->Data < data)
			return Search(node->Right, data, depth);

		return node;
	}

	Node* Remove(T data, Node* node = nullptr, Node* parent = nullptr)
	{
		if (node == nullptr)
			node = root;

		Node* remove = nullptr;

		if (node->Data > data)
		{
			remove = Remove(data, node->Left, node);
		}
		else if (node->Data < data)
		{
			remove = Remove(data, node->Right, node);
		}
		else
		{
			remove = node;

			// 자손 노드가 존재하지 않을 때 -> 그냥 제거
			if (remove->Left == nullptr && remove->Right == nullptr)
			{
				if (parent->Left == remove)
					parent->Left = nullptr;
				else
					parent->Right = nullptr;
			}
			// 자손 노드가 모두 존재 -> 우측 자손 노드 중 가장 작은 값으로 지우는 노드를 대체
			else if(remove->Left != nullptr && remove->Right != nullptr)
			{
				Node* minNode = SearchMinValue(remove->Right);

				minNode = Remove(minNode->Data);
				remove->Data = minNode->Data;

				return minNode;
			}
			// 자손 노드가 한 쪽만 존재
			else
			{
				Node* temp = nullptr;

				if (remove->Left != nullptr)
					temp = remove->Left;
				else
					temp = remove->Right;

				if (parent->Left == remove)
					parent->Left = temp;
				else
					parent->Right = temp;
			}
		}
		return remove;
	}

private:
	Node* SearchMinValue(Node* node)
	{
		if (node == nullptr)
			return nullptr;

		if (node->Left == nullptr)
			return node;
		else
			return SearchMinValue(node->Left);
	}

public:
	void Visit(Node* node, int depth)
	{
		std::cout << " " << node->Data << "(d: " << depth << ")";
	}

	void PreOrder(Node* node, int depth)
	{
		if (node == nullptr) return;
		++depth;

		Visit(node, depth);
		PreOrder(node->Left, depth);
		PreOrder(node->Right, depth);
	}

	void InOrder(Node* node, int depth)
	{
		if (node == nullptr) return;
		++depth;

		InOrder(node->Left, depth);
		Visit(node, depth);
		InOrder(node->Right, depth);
	}

	void PostOrder(Node* node, int depth)
	{
		if (node == nullptr) return;
		++depth;

		PostOrder(node->Left, depth);
		PostOrder(node->Right, depth);
		Visit(node, depth);
	}

	Node* Root() { return root; }

public:
	void DestroyTree(Node* node)
	{
		if (node == nullptr) return;

		DestroyTree(node->Left);
		node->Left = nullptr;
		DestroyTree(node->Right);
		node->Right = nullptr;
		DestroyNode(&node);
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = nullptr;
		node->Right = nullptr;

		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = nullptr;
	}

public:
	void SetRoot(Node* node) { root = node; }

public:
	struct Node
	{
		T Data;

		Node* Left;
		Node* Right;
	};

private:
	Node* root;
};