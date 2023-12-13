#pragma once

// 아래 코드보다 이 코드가 더 똑똑한 코드인 것 같음(문제용으로 작성한 거라 생성자나 등등이 좀 다르다)
class CQueue
{
public:
	CQueue(int N)
	{
		Numbers = new int[N + 1];
		Capacity = Rear = N;
		for (int i = 0; i < N + 1; i++)
			Numbers[i] = i;
	}

	~CQueue()
	{
		delete[] Numbers;
	}

	void Enqueue(int n)
	{
		if (IsFull())
			return;

		Rear = ++Rear % (Capacity + 1);
		Numbers[Rear] = n;
	}

	int Dequeue()
	{
		if (IsEmpty())
			return -1;

		Front = ++Front % (Capacity + 1);
		int temp = Numbers[Front];
		Numbers[Front] = 0;
		return temp;
	}

	bool IsFull() const
	{
		return Front == (Rear + 1) % (Capacity + 1);
	}

	bool IsEmpty() const
	{
		return Front == Rear;
	}

private:
	int* Numbers;
	int Capacity;
	int Front = 0;
	int Rear = 1;
};




template<typename T>
class CircularQueueByArray
{
public:
	CircularQueueByArray(int capacity)
		: capacity(capacity)
	{
		datas = new T[capacity + 1];
	}

	~CircularQueueByArray()
	{
		delete[] datas;
		datas = nullptr;
	}

	void Enqueue(T data)
	{
		int position = 0;

		if (rear == capacity)
		{
			position = rear;
			rear = 0;
		}
		else
			position = rear++;

		datas[position] = data;
	}

	T& Dequeue()
	{
		int position = front;
		if (front == capacity)
			front = 0;
		else
			front++;

		return datas[position];
	}

	int Size()
	{
		if (front <= rear)
			return rear - front;
		else
			return (capacity - front) + rear + 1;
	}

	bool Empty()
	{
		return front == rear;
	}

	bool Full()
	{
		if (front < rear)
			return (rear - front) == capacity;
		else
			return (rear + 1) == front;
	}

	int Capacity() { return capacity; }
	int Front() { return front; }
	int Rear() { return rear; }

private:
	T* datas;

	int capacity;
	int front = 0;
	int rear = 0;
};