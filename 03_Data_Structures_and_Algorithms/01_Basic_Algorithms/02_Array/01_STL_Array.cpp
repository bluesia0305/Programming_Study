#include <iostream>
#include <array>

using namespace std;

int main()
{
	int arr[3] = { 1, 2, 3 };
	for (int elem : arr)
	{
		printf("%d\n", elem);
;	}


	// ���� �Ʒ��� ���� STL array������ ����� �� �־��� �����̳�, ���� �߰���.
	array<int, 3> arrSTL;
	for (int b : arrSTL)
	{

	}

	return 0;
}