#include <iostream>

// pArr �� �̿��Ͽ� �ּ� ������ ���Ͽ�
// Arr(�迭)�� ����� �� �� ¦���� ��Ҹ� ����ϴ�
// ���α׷��� ������ּ���.
// ���� : [] ��� ����

void PrintEven(int* const arr)
{
	printf("�迭�� ��� �� ¦����: ");
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