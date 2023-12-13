// 2022-06-21 수업(계속)


// 포인터 매개변수(Pointer parameter)
// : 주소값의 형태를 받을 수 있는 매개변수.
//   포인터 변수의 형태로 매개변수를 이용하면 함수가 종료되어도 변수 값 자체의 변경이 가능해짐.

#include <iostream>

void AddTen(int* p)
{
	*p += 10;
}

struct Struct
{
	long long A[100];
	long long B[100];
	long long C[100];
	long long D[100];
	long long E[100];
	long long F[100];
};

int main()
{
	int A = 10;
	AddTen(&A);
	printf("A의 값: %i\n", A);
	printf("\n");

	// (심화) Call-by-address가 call-by-reference와 다른 점
	// * Call-by-address  : call-by-value의 개념으로부터 value 대신 address를 전달하는 것.
	// * Call-by-reference: 호출된 함수가 (main 함수 상에서 선언된) 인자 자체에 접근할 수 있다.
	int* ptr = &A;
	printf("(심화) Call-by-address / call-by-reference 차이점.\n");
	printf("ptr   : %p\n", ptr);
	printf("A의 값: %i\n", A);
	AddTen(ptr);
	// 함수 내에서 어떤 방법을 사용해도 ptr에 저장된 값(A의 주소)은 바뀌지 않는다.
	// 즉, call-by-address는 결국 call-by-value에서 전달하는 값을 주소값으로 하는 특수 케이스라고 볼 수 있다.
	// (이중 포인터를 이용하면 ptr에 저장된 값을 변경할 수는 있으나, 
	printf("ptr   : %p\n", ptr);
	printf("A의 값: %i\n", A);

	// 포인터의 사용 이유: 메모리 절약
	// * x86 기준 4 Byte, x64 기준 8 Byte로 주소를 저장할 수 있고, 이를 이용한 접근이 가능함.
	printf("Struct Size: %zi Byte\n", sizeof(Struct));
	printf("Struct* Size: %zi Byte\n", sizeof(Struct*));

	return 0;
}