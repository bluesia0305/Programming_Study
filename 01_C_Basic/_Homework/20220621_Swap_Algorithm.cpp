// 2022-06-21 ����
// Swap �Լ��� �������� ��, A�� B�� ���� �ڹٲ�� ������ּ���.


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