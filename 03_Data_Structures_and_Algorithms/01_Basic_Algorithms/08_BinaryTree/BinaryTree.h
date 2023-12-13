#pragma once

#include <iostream>

template<typename T>
class BTree
{
public:
	struct Node;

public:
	BTree()
	{
		
	}

	~BTree()
	{
		DestroyTree(root);
	}

public:
	void Visit(Node* node)
	{
		std::cout << " " << node->Data;
	}

	void PreOrder(Node* node)
	{
		if (node == nullptr) return;

		Visit(node);
		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	void InOrder(Node* node)
	{
		if (node == nullptr) return;

		InOrder(node->Left);
		Visit(node);
		InOrder(node->Right);
	}

	void PostOrder(Node* node)
	{
		if (node == nullptr) return;

		PostOrder(node->Left);
		PostOrder(node->Right);
		Visit(node);
	}

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