// 2022-07-20 ����


// (�ǽ�) ���� Ŭ���� ���ø� ������
#pragma once
#include <iostream>

template<typename T> class Vector
{
private:
	T* vector = nullptr;

public:
	virtual ~Vector();
	void PrintAll();
	void Push(T value);
	void Erase(T index);
	void Set(T index, T value);
	T Get(T index);
	T Size();
	T Length();
};

template<typename T>
inline Vector<T>::~Vector() = default;

template<typename T>
inline void Vector<T>::PrintAll()
{
	printf("�迭�� ��� ��ü ���: ");
	for (int i = 0; i < Length(); i++)
	{ printf("%i ", Get(i)); }
	printf("\n");
}

template<typename T>
inline void Vector<T>::Push(T value)
{
	T* pPushed = new T[Length() + 1];
	for (int i = 0; i < Length(); i++)
	{ pPushed[i] = Get(i); }
	pPushed[Length()] = value;
	delete[] vector;
	vector = pPushed;
}

template<typename T>
inline void Vector<T>::Erase(T index)
{
	T* pErased = new T[Length() - 1];
	for (int i = 0; i < index; i++)
	{ pErased[i] = Get(i); }
	for (int i = index; i < Length() - 1; i++)
	{ pErased[i] = Get(i + 1); }
	delete[] vector;
	vector = pErased;
}

template<typename T>
inline void Vector<T>::Set(T index, T value)
{
	if (Length() != 0)
	{
		if (index >= 0 && index < Length())
		{
			printf("�迭�� %i ��° index�� ��Ҹ� %i�� �ʱ�ȭ�Ͽ����ϴ�.\n", index, value);
			vector[index] = value;
		}
		else printf("index�� �ٽ� �Է��ϼ���.\n");
	}
	else printf("�迭 ���� ������ ó�� �ʱ�ȭ�� Push �޼ҵ�� �����ϼ���.\n");
}

template<typename T>
inline T Vector<T>::Get(T index)
{ return vector[index]; }

template<typename T>
inline T Vector<T>::Size()
{
	if (vector == nullptr) return 0;
	else return _msize(vector);
}

template<typename T>
inline T Vector<T>::Length()
{ return Size()/sizeof(T); }
