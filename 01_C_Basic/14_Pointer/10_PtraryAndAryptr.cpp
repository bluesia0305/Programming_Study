// 2022-06-23 수업(계속)


// 포인터 배열(Pointer array)
// : 포인터를 요소로 갖는 배열을 의미함.

// 배열 포인터(Array pointer)
// : 배열을 가리키는 포인터를 의미함.


#include <iostream>

struct A
{
	int a;
};

int main()
{
	// 포인터 배열
	int num1 = 10, num2 = 20, num3 = 30;
	int* pArr1[3] = { &num1, &num2, &num3 };

	for (int i = 0; i < 3; i++)
	{
		printf("pArr1[%i]: %p\n", i, pArr1[i]);
		printf("*pArr1[%i]: %i\n", i, *pArr1[i]);
	}
	printf("\n");

	A a = { 1 }, b = { 2 }, c = { 3 };
	A* pArr2[3] = { &a, &b, &c };
	for (int i = 0; i < 3; i++)
	{
		printf("pArr2[%i]: %p\n", i, pArr2[i]);
		printf("*pArr2[%i]: %i\n", i, pArr2[i]->a);
	}
	printf("\n");

	// 배열 포인터
	int arr[2][3] =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	int(*pArr3)[3] = arr;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%i ", pArr3[i][j]);
		}
	}

	return 0;
}