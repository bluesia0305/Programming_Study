#pragma once
#include <iostream>
#include <stack>
#include <queue>

template<typename T>
class Tree
{
public:
	struct Node;

public:
	void AddChild(Node* parent, Node* child)
	{
		child->Parent = parent;

		if (parent->LeftChild == nullptr)
		{
			parent->LeftChild = child;
		}
		else
		{
			Node* node = parent->LeftChild;
			while (node->RightSibling != nullptr)
				node = node->RightSibling;

			node->RightSibling = child;
		}
	}
	
public:
	// 그냥 혼자 짠 부분임
	void RemoveNode(Node** node)
	{
		// child node가 있을 경우, child node를 우측부터 모두 제거
		Node* child = (*node)->LeftChild;
		while (child != nullptr)
		{
			while (child->RightSibling)
				child = child->RightSibling;
			RemoveNode(&child);
		}

		// 부모 노드가 있을 경우(== root가 아닐 경우 연결 해제해야할 것들)
		if ((*node)->Parent != nullptr)
		{
			Node* leftSibling = (*node)->Parent->LeftChild;
			if (leftSibling != *node)
			{
				while (leftSibling->RightSibling != *node)
					leftSibling = leftSibling->RightSibling;

				leftSibling->RightSibling = (*node)->RightSibling;
			}
			else
				(*node)->Parent->LeftChild = nullptr;
		}

		DestroyNode(node);
	}

	void PrintNode(Node* node, int depth)
	{
		for (int i = 0; i < depth; i++)
			std::cout << "-";

		std::cout << node->Data << std::endl;
		stack.push(node);
		queue.push(node);

		if (node->LeftChild != nullptr)
			PrintNode(node->LeftChild, depth + 1);

		if (node->RightSibling != nullptr)
			PrintNode(node->RightSibling, depth);
	}

public:
	std::stack<Node*>* Stack() { return &stack; }
	std::queue<Node*>* Queue() { return &queue; }
	
public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->LeftChild = nullptr;
		node->RightSibling = nullptr;

		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete *node;
		*node = nullptr;
	}

public:
	struct Node
	{
		T Data;

		Node* Parent;
		Node* LeftChild;
		Node* RightSibling;

		~Node()
		{
			Data = 0;

			Parent = nullptr;
			LeftChild = nullptr;
			RightSibling = nullptr;
		}
	};

private:
	std::stack<Node*> stack;
	std::queue<Node*> queue;
};