// 2022-07-20 수업


// (실습) 벡터 클래스 템플릿 만들어보기
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
	printf("배열의 요소 전체 출력: ");
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
			printf("배열의 %i 번째 index의 요소를 %i로 초기화하였습니다.\n", index, value);
			vector[index] = value;
		}
		else printf("index를 다시 입력하세요.\n");
	}
	else printf("배열 생성 직후의 처음 초기화는 Push 메소드로 설정하세요.\n");
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
