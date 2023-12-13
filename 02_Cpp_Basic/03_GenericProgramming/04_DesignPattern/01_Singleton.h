// 2022-07-27 ����


#pragma once
#include <iostream>
using namespace std;

// ������ ����(Design pattern)
// : ���� ����ϴ� �ڵ带 ����ȭ ��Ų ���� �ǹ���.

// <�ܺο��� �ش� Ŭ������ ��ü�� ������ �� ������ ����� ���>
// 1) �����ڸ� private �Ǵ� protected ���ǿ��� ����.
// 2) ���� ���� �Լ��� �ϳ� �̻����� �����ϴ� Ŭ������ ����(��, �߻� Ŭ����).
// 3) �߻� Ŭ������ ����(abstract Ű����).

// �̱��� ������ ����(Singleton ~)
// : ���α׷� ���� �� �ش� Ŭ������ �ν��Ͻ��� �� �ϳ��� ������ �� �ֵ����ϴ� ������ ����.
//   * �ַ� ���ø� ���·� ���������, ������ ������ �Ʒ��� ���� ���� ��� �Լ��� ���� ���� ������ Ư���� �̿��Ѵ�.
class Singleton_test
{
public:
	int a_base;
	int b_base;

private:
	Singleton_test();

public:
	// ���� ��� �Լ��� ��쿡�� ������ �����ص� ��� �Լ��� ȣ���� �����ϹǷ�
	// �ش� Ŭ������ ���� ��ü�� ���� ���¿����� ��� �Լ� ȣ���� �����ϴ�.
	static Singleton_test* GetInstance()
	{
		static Singleton_test* single = new Singleton_test();
		return single;
	}
};

template<typename T>
class Singleton
{
public:
	int a_base;
	int b_base;

private:
	Singleton();

public:
	// ���� ��� �Լ��� ��쿡�� ������ �����ص� ��� �Լ��� ȣ���� �����ϹǷ�
	// �ش� Ŭ������ ���� ��ü�� ���� ���¿����� ��� �Լ� ȣ���� �����ϴ�.
	static T* GetInstance()
	{
		static T* single = new T();
		return single;
	}
};