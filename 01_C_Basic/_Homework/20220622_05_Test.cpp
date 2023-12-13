#include <iostream>

// ���������� �������ּ��� !
// ���������̶� ?
// ���� ������������ �����ϴ� �˰����� �ǹ��մϴ�.
// ex ) before ) 4, 32, 17, 5
//      after  ) 4, 5, 17, 32

// �迭�� �ѱ�ٸ� �迭�� ��ҵ��� ���������� �� �� �ֵ���
// �Լ��� ������ּ��� !

void BubbleSort(int* const arr)
{
	printf("���������� �����մϴ�.\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void PrintArr(int* const arr)
{
	printf("�迭 ���: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int Arr[10] = { 4, 7, 9, 3, 1, 5, 6, 8, 0, 2 };
	PrintArr(Arr);
	BubbleSort(Arr);
	PrintArr(Arr);
	

	return 0;
}