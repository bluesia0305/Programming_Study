#include <iostream>

// Swap �̶�� �Լ��� ����� ������ �Ű������� �̿��Ͽ�
// Swap �� �����ϰ� �ȴٸ� �� ������ ���� ���� �ڹٲ�� ������ּ���.

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