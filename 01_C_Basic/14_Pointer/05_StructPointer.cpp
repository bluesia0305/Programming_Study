// 2022-06-22 수업


// 구조체 포인터(Struct pointer)
// : 구조체 형식을 가리킬 수 있는 포인터.
//   구조체 포인터 형식에서 멤버에 접근을 할 때에는
//   -> (멤버 간접접근 연산자)를 사용함.


#include <iostream>

struct Struct
{
	int a;
	int b;
};

void Swap(Struct* p1, Struct* p2)
{
	// 아래와 같이 멤버들을 일일이 swap 해줄 필요가 없음.
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
	printf("구조체 A: [a: %i] [b: %i]\n", A.a, A.b);
	printf("구조체 B: [a: %i] [b: %i]\n", B.a, B.b);
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

	// p1과 p2를 사용하여 A와 B의 b라는 멤버의 값이 뒤바뀌도록 만들어주세요.
	Struct* p1 = &A;
	Struct* p2 = &B;
	Print(A, B);
	MemberSwap(&p1->b, &p2->b);
	Print(A, B);

	return 0;
}