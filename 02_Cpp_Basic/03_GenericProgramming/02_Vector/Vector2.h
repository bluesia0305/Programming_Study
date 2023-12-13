// 2022-07-21 수업


// (실습) 벡터 클래스 템플릿 함수 추가 구현

// <코드 개선사항(개인적으로 공부하려고 적어놓은 것)>
// 1) 변수: 반드시 unsigned int 형식이어야 하는 변수 및 함수 반환형을 int -> unsigned (int)로 수정.
// 2) index를 초과하여 매개변수를 받았을 때 오류 나지 않도록 수정 등.
// 3) 일부 함수의 정의 간소화.

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
	printf("배열의 요소 전체 출력: ");
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
	else printf("%s >> 배열의 index 초과: index %i, length %i\n", __FUNCTION__, index, Length());
}

template<typename T>
inline void Vector<T>::Set(unsigned index, T value)
{
	if (Length() != 0)
	{
		if (index < Length()) vector[index] = value;
		else printf("%s >> 배열의 index 초과: index %i, length %i\n", __FUNCTION__, index, Length());
	}
	else
	{
		if (index == 0) Push(value);
		else printf("%s >> 배열 생성 직후의 초기화는 index 값을 0으로 제공해야합니다.\n", __FUNCTION__);
	}
}

template<typename T>
inline T Vector<T>::Get(unsigned index)
{
	if (index < Length()) return vector[index];
	else
	{
		printf("%s >> 배열의 index 초과: index %i, length %i (return 0)\n", __FUNCTION__, index, Length());
		return 0;
	}
}

template<typename T>
inline unsigned Vector<T>::Size()
{ return (vector == nullptr) ? 0 : static_cast<unsigned>(_msize(vector)); }

template<typename T>
inline unsigned Vector<T>::Length()
{ return Size() / sizeof(T); }



// 2022-07-21 함수 추가 구현

template<typename T>
inline bool Vector<T>::Empty()
{ return !Length() ? true : false; }

template<typename T>
inline void Vector<T>::Clear()
{
	if (Empty()) printf("%s >> 배열이 이미 Empty 상태입니다.\n", __FUNCTION__);
	else
	{
		delete[] vector;
		vector = nullptr;
		printf("%s >> 배열을 Clear 하였습니다.\n", __FUNCTION__);
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
	else printf("%s >> 배열의 index 초과: index1 %i, index2 %i, length %i\n", __FUNCTION__, index1, index2, Length());
	// 확인용 코드
	//printf("%s >> %i 번 인덱스 요소와 %i 번 인덱스 요소의 위치를 교환하였습니다.\n", __FUNCTION__, index1, index2);
}

template<typename T>
inline void Vector<T>::Sort()
{
	for (unsigned i = 0; i < Length() - 1; i++)
		for (unsigned j = 0; j < Length() - (i + 1); j++)
			if (Get(j) > Get(j + 1)) Swap(j, j + 1);

	printf("%s >> 배열을 버블정렬 하였습니다.\n", __FUNCTION__);
}

template<typename T>
inline void Vector<T>::Shuffle()
{
	srand(GetTickCount64());
	for (unsigned i = Length() - 1; i > 0; i--)
	{
		unsigned tempIndex = rand() % (i + 1);		// 0 ~ i 까지의 정수 중 랜덤하게 하나 뽑음
		Swap(i, tempIndex);
	}
	printf("%s >> 배열을 Shuffle 하였습니다.\n", __FUNCTION__);
}