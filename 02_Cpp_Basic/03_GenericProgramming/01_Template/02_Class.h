// 2022-07-19 ����


#pragma once
#include <iostream>
using namespace std;

// Ŭ���� ���ø�(Class template)
// : Ŭ������ �Ϲ�ȭ �� ����. �����Ϸ��� ���� �����Ǳ� ������ ������ Ŭ����(generated class)��� �Ҹ���.
//	 * �Լ� ���ø����� �ٸ��� ���� Ư��ȭ �̿ܿ� �κ� Ư��ȭ(partial specialization)�� �����ϴ�.
//	 * Ŭ���� ���ø� ���� Ŭ���� ���ø��� ������ �����ϴ�(nested class template).

// �κ� Ư��ȭ(Partial specialization)
// : ���ø� �μ��� 2�� �̻��� ��쿡 ���Ͽ�, �Ϻ� �Ű������� Ư��ȭ�ϴ� ��츦 �ǹ��Ѵ�.
//	 * �Լ� ���ø������� �������� ������ Ŭ���� ���ø������� �����Ǵ� ���.
template<typename T>
class Template
{
private:
	T Num1;
	T Num2;

public:
	Template(T num1, T num2);
	void Print();
	T GetNum1() const;
};

// Ŭ���� ���ø��� ��� �Լ��� Ŭ���� ���ø��� �ܺο��� ���ǵ� ���, �Լ� ���ø�ó�� ���ǵȴ�.
// * Ŭ���� ���ø��� �޼ҵ� ���� �� ���Ǵ� ��� ���ϰ� CPP ���Ϸ� ���� �ۼ��� �Ұ����ϹǷ� ��� ���Ͽ� ���� �ۼ��ؾ��Ѵ�.
//   (��� ���Ϻ��� ���� ���� �ڷ����� ���������� �����Ƿ� �����Ϸ��� ���� �ν��Ͻ�ȭ�� �Ұ����ϴ�)
// * Ŭ���� ���ø��� ��� �Լ��� �� ��ü�� �Լ� ���ø��� �� �ִ�.
template<typename T>
inline Template<T>::Template(T num1, T num2)
{
	cout << "sizeof(T): " << sizeof(T) << endl;
	Num1 = num1;
	Num2 = num2;
}

template<typename T>
inline void Template<T>::Print()
{ cout << "Num1: " << Num1 << ", Num2: " << Num2 << endl; }

template<typename T>
inline T Template<T>::GetNum1() const
{ return Num1; }
