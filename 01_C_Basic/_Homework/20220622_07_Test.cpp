#include <iostream>

// pArr 를 이용하여 주소 연산을 통하여
// Arr(배열)에 저장된 값 중 짝수인 요소만 출력하는
// 프로그램을 만들어주세요.
// 조건 : [] 사용 금지

void PrintEven(int* const arr)
{
	printf("배열의 요소 중 짝수들: ");
	for (int i = 0; i < 10; i++)
	{
		if (*(arr + i) % 2 == 0) printf("%i ", *(arr + i));
	}
	printf("\n");
}

int main()
{
	int Arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	PrintEven(Arr);

	return 0;
}