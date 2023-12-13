// 2022-06-22 ����


// ����ü ������(Struct pointer)
// : ����ü ������ ����ų �� �ִ� ������.
//   ����ü ������ ���Ŀ��� ����� ������ �� ������
//   -> (��� �������� ������)�� �����.


#include <iostream>

struct Struct
{
	int a;
	int b;
};

void Swap(Struct* p1, Struct* p2)
{
	// �Ʒ��� ���� ������� ������ swap ���� �ʿ䰡 ����.
	Struct temp = *p2;
	*p2 = *p1;
	*p1 = temp;
}

void MemberSwap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void Print(Struct A, Struct B)
{
	printf("����ü A: [a: %i] [b: %i]\n", A.a, A.b);
	printf("����ü B: [a: %i] [b: %i]\n", B.a, B.b);
}

int main()
{
	Struct A;
	A.a = 10;
	A.b = 20;

	Struct* p = &A;
	(*p).a = 30;
	p->b = 40;
	
	Struct B = { 10, 20 };

	Print(A, B);
	Swap(&A, &B);
	Print(A, B);
	MemberSwap(&A.a, &B.a);
	Print(A, B);

	printf("-------------------\n");

	// p1�� p2�� ����Ͽ� A�� B�� b��� ����� ���� �ڹٲ�� ������ּ���.
	Struct* p1 = &A;
	Struct* p2 = &B;
	Print(A, B);
	MemberSwap(&p1->b, &p2->b);
	Print(A, B);

	return 0;
}