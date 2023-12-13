// 2022-06-17 ����(���)


// �����ֱ�(Life cycle)
// : ������ �Ҵ���� �޸𸮿� ���� ���� �ֱ⸦ �ǹ���.

// �޸� ����(Memory Area)
// : �Ʒ��� ���� 4�� �������� ����.
// 
//   Code  |  Data
//   --------------
//   Heap  |  Stack
//
//   * Code: �ҽ� �ڵ�, �Լ��� ���� ���� �����ϴ� ����.
//   * Data: ���α׷� ���� ~ ������ ����Ǵ� ������(��������, �������� ��)�� �����ϴ� ����.
//   * Stack: ���������� ���� �Ͻ������θ� �����ߴ� ������� ������(��ȯ��, �Ű�����, �������� ��)�� �����ϴ� ����.
//   * Heap: ����� ���� ����.

#include <iostream>

struct A
{
	std::string Name = "Local";
	A() { printf("%s�� �����˴ϴ�.\n", Name.c_str()); }

	A(std::string name)
	{
		Name = name;
		printf("%s�� �����˴ϴ�.\n", Name.c_str());
	}

	A(const A & a)
	{
		Name = "copy " + a.Name;
		printf("%s�� �����˴ϴ�.\n", Name.c_str());
	}

	~A() { printf("%s�� �����˴ϴ�.\n", Name.c_str()); }
};

// ������ �ҽ� �ڵ带 ������ ��,
// ����/������������ � ������ ���ܳ��� ������� �� Ȯ��.
A global_a("Global");					// ��������(global_a) - Global
static A global_s_a("Global Static");	// ������������(global_s_a) - Global Static
										// * ��� 2���� ������ ���α׷� ���۰� ���ÿ� �������⿡ ���� ����.
void LocalStatic()
{
	static A a("Local Static");			// ������������(a) - Local Static
										// * �������������� ��쿡�� ���α׷��� ����� �� ����������, �����������ٴ� �ݵ�� ���� ������.
}

A Local(A param)						// �Ű�����(param) - copy (main) Local
{
	A a("(function) Local");			// ��������(a) - (function) Local
	return a;							// ��ȯ��(a) - copy (function) Local
}

int main()
{
	A a("(main) Local");				// ��������(a) - (main) Local

	{
		A b("b");
	}

	printf("--> void ������ LocalStatic �Լ� ����.\n");
	LocalStatic();
	printf("--> A ����(��ȯ�� ����)�� Local �Լ� ����.\n");
	Local(a);



	return 0;
}