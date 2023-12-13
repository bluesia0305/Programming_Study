#pragma once

#include <memory>
#include <cassert>
#include <iostream>

#define MAX_STACK_COUNT 20

template<typename T>
class StackByArray
{
public:
	StackByArray()
	{
		memset(values, 0, sizeof(T) * MAX_STACK_COUNT);
	}

	void Push(T value)
	{
		assert(top + 1 < MAX_STACK_COUNT);
		values[++top] = value;
	}

	T Front()
	{
		return values[top];
	}

	T Back()
	{
		assert(top > -1);
		return values[0];
	}

	T& Pop()
	{
		assert(Empty() == false);
		return values[top--];
	}

	bool Empty()
	{
		return top < 0 ? true : false;
	}

private:
	int top = -1;
	T values[MAX_STACK_COUNT];
};