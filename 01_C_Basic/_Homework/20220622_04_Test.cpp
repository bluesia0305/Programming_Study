#include <iostream>

// �迭�� �Ѱ� �迭�� ����� ���� ū ���� ��ȯ�ϴ� �Լ��� �ۼ����ּ���.

int ArrayMax(int* const arr)
{
	int max = arr[0];
	for (int i = 1; i < 8; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

int main()
{
	int Arr[] = { 10, 17, 20, 11, 1, 9, 8, 2 };
	printf("maxValue: %i\n", ArrayMax(Arr));

	return 0;
}