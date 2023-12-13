// 2022-06-21 ����(���)


// ������ ���� �����, const Ű������ ��ġ�� ���� �ۿ� ��� ����.


#include <iostream>

void Print(int a, int b = 0)
{
	printf("A: %i\n", a);
	if (b) printf("B: %i\n", b);
}

int main()
{
	const int Literal = 10;
	//Literal = 11;			- Error - (const Ű���带 �����ϴ� ������ ���� �ʱ�ȭ�� �Ұ���)
	//int* p = &Literal;	- Error - (const Ű���带 �����ϴ� ������ ������ ������ �ݵ�� const Ű���� �����Ͽ� ����)
	const int* p = &Literal;

	int A = 0;
	int B = 0;

	// 1) ���� �⺻���� ������ ���� ����.
	int* p1 = &A;
	*p1 = 10;
	p1 = &B;
	*p1 = 5;
	Print(A, B);

	// 2) ����Ű�� �ִ� ������ ����� ������ ����(pointer to constant).
	const int* p2 = &A;
	//*p2 = 20;		- Error -		* ���������� ���� ���� ���� �Ұ���.
	p2 = &B;	//					* �����ϴ� �ּҰ��� ���� ����.
	printf("*p2 = %i\n", *p2);

	// 3) �����ϰ� �ִ� �ּҰ��� ����� ������ ����(constant pointer).
	int* const p3 = &A;
	*p3 = 20;	//					* ���������� ���� ���� ���� ����.
	//p3 = &B;		- Error -		* �����ϴ� �ּҰ��� ���� �Ұ���.

	// 4) (2)�� ������ - pointer to constant)
	int const* p4 = &A;
	//*p4 = 10;		- Error -		* ���������� ���� ���� ���� �Ұ���.
	p4 = &B;	//					* �����ϴ� �ּҰ��� ���� ����.

	// 5) (2)�� ������ - pointer to constant)
	const int const* p5 = &A;
	//*p5 = 10;		- Error -		* ���������� ���� ���� ���� �Ұ���.
	p5 = &B;	//					* �����ϴ� �ּҰ��� ���� ����.

	// 6) ?
	int const* const p6 = &A;
	//*p6 = 10;		- Error -		* ���������� ���� ���� ���� �Ұ���.
	//p6 = &B;		- Error -		* �����ϴ� �ּҰ��� ���� �Ұ���.

	// 7) (6)�� ������)
	const int const* const p7 = &A;
	//*p7 = 10;		- Error -		* ���������� ���� ���� ���� �Ұ���.
	//p7 = &B;		- Error -		* �����ϴ� �ּҰ��� ���� �Ұ���.

	return 0;
}