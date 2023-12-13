// 2022-06-21 과제
// Swap 함수를 실행했을 때, A와 B의 값이 뒤바뀌도록 만들어주세요.


#include <iostream>

void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int main()
{
	int A = 10;
	int B = 20;

	Swap(&A, &B);

	printf("A: %i\n", A);
	printf("B: %i\n", B);

	return 0;
}