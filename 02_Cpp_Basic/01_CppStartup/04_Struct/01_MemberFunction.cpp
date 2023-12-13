// 2022-06-30 ����


#include <iostream>
using namespace std;

// ��� �Լ�(Member function)
// : C++ �������ʹ� ����� ���� �ڷ���(����ü)�� �Լ��� �߰��� �� �ִ�(= ��� �Լ�, �޼ҵ�).

struct STRUCT
{
	// C++ �������ʹ� ��� ������ default ���� �������� �� ����.
	int A = 10;
	int B = 20;

	// ��� �Լ� Print�� �����մϴ�.
	// {��ȯ��} {�Լ���}({�Ű�����}) const: �ش� �Լ��� ���� ������ ��� �������� ���� �������� �ʴ� ���� ���.
	__forceinline void Print() const
	{  	cout << "A: " << A << ", B: " << B << endl; }

	void Print(int integer1, int integer2 = 0)
	{ cout << "integer1: " << integer1 << ", integer2: " << integer2 << endl; }

	void AddA(int integer) // const		- Error -    ��� ������ ���� �����ϹǷ� const ����� ���� �߻���.
	{  A += integer;  }
};

int main()
{
	STRUCT Struct;
	Struct.Print();
	Struct.AddA(10);
	Struct.Print();
	
	// <�����غ���>
	// Q1. ��� �Լ��� ��쿡���� �Լ� ������ ó���� ��� ������ ���� �״�� ������ �Ǵ� ����?
	// Q2. ����ü�� ũ��?

	printf("sizeof(STRUCT) == %zi\n", sizeof(STRUCT));

	return 0;
}