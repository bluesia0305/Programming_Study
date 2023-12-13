// 2022-06-23 수업(계속)


// 다중 포인터(Multiple indirection)
// : 포인터 변수를 가리키는 포인터의 형태로 이루어지는 포인터.
//   * 포인터의 형태를 바꾸기 위해 사용됨.


#include <iostream>

void SwapAddress1(int* param1, int* param2)
{
	int* temp = param2;
	param2 = param1;
	param1 = temp;
}

void SwapAddress2(int** param1, int** param2)
{
	int* temp = *param2;
	*param2 = *param1;
	*param1 = temp;
}

int main()
{
#pragma region Pointer
	int A = 10;
	int* p = &A;		// Pointer to int
	int** pp = &p;		// Pointer to pointer to int (이중 포인터)
	int*** ppp = &pp;	// Pointer to pointer to pointer to int (삼중 포인터)

	// 다중 포인터
	printf("A의 값 = p의 역참조값 = pp의 역참조의 역참조값 = ppp의 역참조의 역참조의 역참조값\n");
	printf("A    : %i\n", A);
	printf("*p   : %i\n", *p);
	printf("**p  : %i\n", **pp);
	printf("***p : %i\n\n", ***ppp);

	printf("A의 주소값 = p의 값 = pp의 역참조 값 = ppp의 역참조의 역참조 값\n");
	printf("&A   : %p\n", &A);
	printf("p    : %p\n", p);
	printf("*pp  : %p\n", *pp);
	printf("**ppp: %p\n\n", **ppp);

	printf("p의 주소값 = pp의 값 = ppp의 역참조 값\n");
	printf("&p   : %p\n", &p);
	printf("pp   : %p\n", pp);
	printf("*ppp : %p\n\n", *ppp);

	printf("pp의 주소값 = ppp의 값\n");
	printf("&pp  : %p\n", &pp);
	printf("ppp  : %p\n\n", ppp);

	printf("ppp의 주소값\n");
	printf("&ppp : %p\n", &ppp);
#pragma endregion
	printf("-------------------------\n");

	int var1 = 10, var2 = 20;
	int* p1 = &var1;
	int* p2 = &var2;

	printf("p1: %p\n", p1);
	printf("p2: %p\n\n", p2);

	SwapAddress1(p1, p2);

	printf("SwapAddress1 실행 후\n");
	printf("p1: %p\n", p1);
	printf("p2: %p\n\n", p2);

	SwapAddress2(&p1, &p2);

	printf("SwapAddress2 실행 후\n");
	printf("p1: %p\n", p1);
	printf("p2: %p\n\n", p2);

	return 0;
}