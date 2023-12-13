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


	// 원래 아래와 같이 STL array에서만 사용할 수 있었던 문법이나, 새로 추가됨.
	array<int, 3> arrSTL;
	for (int b : arrSTL)
	{

	}

	return 0;
}