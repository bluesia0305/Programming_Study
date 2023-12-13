#include <iostream>

// ArraySwap �Լ��� �����ô�.
// �迭 �ΰ��� �Ѱ� ������ ��ҵ��� ��� �ٲ�� �Լ��� ������ּ���.

void ArraySwap(int* const a, int* const b)
{
	int temp;
	for (int i = 0; i < 5; i++)
	{
		temp = b[i];
		b[i] = a[i];
		a[i] = temp;
	}
}

void PrintArray(int* const a)
{
	for (int i = 0; i < 5; i++)
		printf("%i ", a[i]);
	printf("\n");
}

int main()
{
	int Arr1[5] = { 1, 2, 3, 4, 5 };
    int Arr2[5] = { 10, 11, 12 ,13 ,14 };

	printf("Arr1: ");
	PrintArray(Arr1);
	printf("Arr2: ");
	PrintArray(Arr2);
	
	ArraySwap(Arr1, Arr2);

	printf("Arr1: ");
	PrintArray(Arr1);
	printf("Arr2: ");
	PrintArray(Arr2);

	return 0;
}