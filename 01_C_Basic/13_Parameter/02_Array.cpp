// 2022-06-20 ����(���)


// �迭�� �Ű������� �ϴ� �Լ��� ���� �� ȣ��(����).


#include <iostream>

void PrintArray(int arr[])			// �̶� �Ű������� �ִ� �迭�� ���̸� ������ ���ϸ� �ش� ������ �迭�� ���� �� ����.
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