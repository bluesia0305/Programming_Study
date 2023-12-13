// 2022-06-21 수업(계속)


// 포인터 변수 선언시, const 키워드의 위치에 따른 작용 방식 이해.


#include <iostream>

void Print(int a, int b = 0)
{
	printf("A: %i\n", a);
	if (b) printf("B: %i\n", b);
}

int main()
{
	const int Literal = 10;
	//Literal = 11;			- Error - (const 키워드를 포함하는 변수의 값은 초기화가 불가능)
	//int* p = &Literal;	- Error - (const 키워드를 포함하는 변수의 포인터 변수는 반드시 const 키워드 포함하여 선언)
	const int* p = &Literal;

	int A = 0;
	int B = 0;

	// 1) 가장 기본적인 포인터 변수 선언.
	int* p1 = &A;
	*p1 = 10;
	p1 = &B;
	*p1 = 5;
	Print(A, B);

	// 2) 가리키고 있는 공간이 상수인 포인터 변수(pointer to constant).
	const int* p2 = &A;
	//*p2 = 20;		- Error -		* 간접접근을 통한 값의 변경 불가능.
	p2 = &B;	//					* 저장하는 주소값의 변경 가능.
	printf("*p2 = %i\n", *p2);

	// 3) 저장하고 있는 주소값이 상수인 포인터 변수(constant pointer).
	int* const p3 = &A;
	*p3 = 20;	//					* 간접접근을 통한 값의 변경 가능.
	//p3 = &B;		- Error -		* 저장하는 주소값의 변경 불가능.

	// 4) (2)와 동일함 - pointer to constant)
	int const* p4 = &A;
	//*p4 = 10;		- Error -		* 간접접근을 통한 값의 변경 불가능.
	p4 = &B;	//					* 저장하는 주소값의 변경 가능.

	// 5) (2)와 동일함 - pointer to constant)
	const int const* p5 = &A;
	//*p5 = 10;		- Error -		* 간접접근을 통한 값의 변경 불가능.
	p5 = &B;	//					* 저장하는 주소값의 변경 가능.

	// 6) ?
	int const* const p6 = &A;
	//*p6 = 10;		- Error -		* 간접접근을 통한 값의 변경 불가능.
	//p6 = &B;		- Error -		* 저장하는 주소값의 변경 불가능.

	// 7) (6)과 동일함)
	const int const* const p7 = &A;
	//*p7 = 10;		- Error -		* 간접접근을 통한 값의 변경 불가능.
	//p7 = &B;		- Error -		* 저장하는 주소값의 변경 불가능.

	return 0;
}