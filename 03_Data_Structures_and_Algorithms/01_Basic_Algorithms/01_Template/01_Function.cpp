#include <iostream>

using namespace std;

template<typename T>
void Print(T data)
{
	cout << "일반 템플릿 함수 : " << data << endl;
}

template<>
void Print(float data)
{
	cout << "특수화 함수 : " << data << endl;
}

template<typename T>
void Print(T* data)
{
	cout << "오버로딩 템플릿 함수(포인터) : " << data << endl;
}

int main()
{
	int i = 10;
	float j = 20.0f;
	double k = 30.0;

	Print<int>(i);
	Print<float>(j);
	Print<double>(k);

	int* p = &i;
	Print<int>(p);

	return 0;
}