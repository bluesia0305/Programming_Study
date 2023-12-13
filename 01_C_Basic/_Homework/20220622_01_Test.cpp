#include <iostream>

// Swap 이라는 함수를 만들고 포인터 매개변수를 이용하여
// Swap 을 실행하게 된다면 두 변수의 값이 서로 뒤바뀌도록 만들어주세요.

void Swap(int* num1, int* num2)
{
	int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}

int main()
{
	int A = 10;
	int B = 20;

	printf("A: %i\n", A);
	printf("B: %i\n", B);

	Swap(&A, &B);

	printf("A: %i\n", A);
	printf("B: %i\n", B);

	return 0;
}