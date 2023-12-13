#include <iostream>

using namespace std;

template<typename T>
void Print(T data)
{
	cout << "�Ϲ� ���ø� �Լ� : " << data << endl;
}

template<>
void Print(float data)
{
	cout << "Ư��ȭ �Լ� : " << data << endl;
}

template<typename T>
void Print(T* data)
{
	cout << "�����ε� ���ø� �Լ�(������) : " << data << endl;
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