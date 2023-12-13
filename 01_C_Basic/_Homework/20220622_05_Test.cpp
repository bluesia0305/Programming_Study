#include <iostream>

// 버블정렬을 구현해주세요 !
// 버블정렬이란 ?
// 값을 오름차순으로 정렬하는 알고리즘을 의미합니다.
// ex ) before ) 4, 32, 17, 5
//      after  ) 4, 5, 17, 32

// 배열을 넘긴다면 배열의 요소들이 버블정렬이 될 수 있도록
// 함수를 만들어주세요 !

void BubbleSort(int* const arr)
{
	printf("버블정렬을 수행합니다.\n");
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
	printf("배열 출력: ");
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