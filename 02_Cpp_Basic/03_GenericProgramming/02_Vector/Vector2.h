// 2022-07-21 ����


// (�ǽ�) ���� Ŭ���� ���ø� �Լ� �߰� ����

// <�ڵ� ��������(���������� �����Ϸ��� ������� ��)>
// 1) ����: �ݵ�� unsigned int �����̾�� �ϴ� ���� �� �Լ� ��ȯ���� int -> unsigned (int)�� ����.
// 2) index�� �ʰ��Ͽ� �Ű������� �޾��� �� ���� ���� �ʵ��� ���� ��.
// 3) �Ϻ� �Լ��� ���� ����ȭ.

#pragma once
#include <iostream>
#include <Windows.h>

template<typename T> class Vector
{
private:
	T* vector = nullptr;

public:
	virtual ~Vector();
	void PrintAll();
	void Push(T value);
	void Erase(unsigned index);
	void Set(unsigned index, T value);
	T Get(unsigned index);
	unsigned Size();
	unsigned Length();

	bool Empty();
	void Clear();
	void Swap(unsigned index1, unsigned index2);
	void Sort();
	void Shuffle();
};

template<typename T>
inline Vector<T>::~Vector() = default;

template<typename T>
inline void Vector<T>::PrintAll()
{
	printf("�迭�� ��� ��ü ���: ");
	for (unsigned i = 0; i < Length(); i++)
		printf("%i ", Get(i));

	printf("\n");
}

template<typename T>
inline void Vector<T>::Push(T value)
{
	T* pPushed = new T[Length() + 1];
	for (unsigned i = 0; i < Length(); i++)
		pPushed[i] = Get(i);

	pPushed[Length()] = value;
	delete[] vector;
	vector = pPushed;
}

template<typename T>
inline void Vector<T>::Erase(unsigned index)
{
	if (index < Length())
	{
		T* pErased = new T[Length() - 1];
		for (unsigned i = 0; i < index; i++)
			pErased[i] = Get(i);

		for (unsigned i = index; i < Length() - 1; i++)
			pErased[i] = Get(i + 1);

		delete[] vector;
		vector = pErased;
	}
	else printf("%s >> �迭�� index �ʰ�: index %i, length %i\n", __FUNCTION__, index, Length());
}

template<typename T>
inline void Vector<T>::Set(unsigned index, T value)
{
	if (Length() != 0)
	{
		if (index < Length()) vector[index] = value;
		else printf("%s >> �迭�� index �ʰ�: index %i, length %i\n", __FUNCTION__, index, Length());
	}
	else
	{
		if (index == 0) Push(value);
		else printf("%s >> �迭 ���� ������ �ʱ�ȭ�� index ���� 0���� �����ؾ��մϴ�.\n", __FUNCTION__);
	}
}

template<typename T>
inline T Vector<T>::Get(unsigned index)
{
	if (index < Length()) return vector[index];
	else
	{
		printf("%s >> �迭�� index �ʰ�: index %i, length %i (return 0)\n", __FUNCTION__, index, Length());
		return 0;
	}
}

template<typename T>
inline unsigned Vector<T>::Size()
{ return (vector == nullptr) ? 0 : static_cast<unsigned>(_msize(vector)); }

template<typename T>
inline unsigned Vector<T>::Length()
{ return Size() / sizeof(T); }



// 2022-07-21 �Լ� �߰� ����

template<typename T>
inline bool Vector<T>::Empty()
{ return !Length() ? true : false; }

template<typename T>
inline void Vector<T>::Clear()
{
	if (Empty()) printf("%s >> �迭�� �̹� Empty �����Դϴ�.\n", __FUNCTION__);
	else
	{
		delete[] vector;
		vector = nullptr;
		printf("%s >> �迭�� Clear �Ͽ����ϴ�.\n", __FUNCTION__);
	}
}

template<typename T>
inline void Vector<T>::Swap(unsigned index1, unsigned index2)
{
	if (index1 < Length() && index2 < Length())
	{
		T temp = vector[index1];
		Set(index1, vector[index2]);
		Set(index2, temp);
	}
	else printf("%s >> �迭�� index �ʰ�: index1 %i, index2 %i, length %i\n", __FUNCTION__, index1, index2, Length());
	// Ȯ�ο� �ڵ�
	//printf("%s >> %i �� �ε��� ��ҿ� %i �� �ε��� ����� ��ġ�� ��ȯ�Ͽ����ϴ�.\n", __FUNCTION__, index1, index2);
}

template<typename T>
inline void Vector<T>::Sort()
{
	for (unsigned i = 0; i < Length() - 1; i++)
		for (unsigned j = 0; j < Length() - (i + 1); j++)
			if (Get(j) > Get(j + 1)) Swap(j, j + 1);

	printf("%s >> �迭�� �������� �Ͽ����ϴ�.\n", __FUNCTION__);
}

template<typename T>
inline void Vector<T>::Shuffle()
{
	srand(GetTickCount64());
	for (unsigned i = Length() - 1; i > 0; i--)
	{
		unsigned tempIndex = rand() % (i + 1);		// 0 ~ i ������ ���� �� �����ϰ� �ϳ� ����
		Swap(i, tempIndex);
	}
	printf("%s >> �迭�� Shuffle �Ͽ����ϴ�.\n", __FUNCTION__);
}