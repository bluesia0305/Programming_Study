#include <iostream>

// 배열을 넘겨 배열의 요소중 가장 큰 값을 반환하는 함수를 작성해주세요.

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