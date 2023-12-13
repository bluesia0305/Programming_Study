#pragma once

#include <memory>
#include <cassert>
#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Node
{
	string Data;
	Node* Next;
};

class StackByLinkedList
{
public:
	StackByLinkedList();
	~StackByLinkedList();

	void Push(Node* node);
	Node* Pop();
	Node* Top() { return top; };
	int Size();
	bool Empty() { return list == nullptr; };
	static Node* CreateNode(string data);
	static void DestroyNode(Node** node);

private:
	Node* list = nullptr;
	Node* top = nullptr;
};