// 2022-06-20 수업(계속)


// 배열을 매개변수로 하는 함수의 선언 및 호출(실행).


#include <iostream>

void PrintArray(int arr[])			// 이때 매개변수에 있는 배열의 길이를 강제로 정하면 해당 길이의 배열만 받을 수 있음.
{
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%i]: %i\n", i, arr[i]);
	}
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	PrintArray(arr);

	return 0;
}