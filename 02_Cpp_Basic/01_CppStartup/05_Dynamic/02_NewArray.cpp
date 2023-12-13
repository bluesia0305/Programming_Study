// 2022-07-01 수업


#include <iostream>
using namespace std;

int main()
{
	// (실습) int 자료형 데이터를 5개 저장할 수 있는 배열을 동적할당하고,
	//        배열의 요소를 1, 2, 3, 4, 5로 초기화하여 출력해주세요.
	printf("1) malloc()을 이용한 1차원 배열의 동적할당.\n");
	int* p1 = (int*) malloc(sizeof(int) * 5);
	printf("p1 >> ");
	for (int i = 0; i < 5; i++)
	{
		p1[i] = i + 1;
		printf("%i ", p1[i]);
	}
	free(p1);
	p1 = nullptr;
	printf("\n\n");
	

	printf("2) new를 이용한 1차원 배열의 동적할당.\n");
	int* p2 = new int[5];
	// initialization operator {,}를 사용하여 아래와 같이 선언과 동시에 초기화 가능.
	//int* p2 = new int[5]{ 1, 2, 3, 4, 5 };
	printf("p2 >> ");
	for (int i = 0; i < 5; i++)
	{
		p2[i] = i + 1;
		printf("%i ", p2[i]);
	}
	delete[] p2;		// 배열로 선언된 동적할당 공간의 해제 시에는 delete[] 연산자를 사용.
	p2 = nullptr;
	printf("\n");
	

	printf("3) new를 이용한 2차원 배열의 동적할당.\n");
	int** p2d1 = new int* [5];
	int z = 0;
	for (int i = 0; i < 5; i++)
	{
		p2d1[i] = new int[5];

		for (int j = 0; j < 5; ++j)
		{
			z++;
			p2d1[i][j] = z;
			printf("p2d1[%i][%i] address: %p\n", i, j, &p2d1[i][j]);
			printf("p2d1[%i][%i] value  : %i\n", i, j, p2d1[i][j]);
		}
		delete[] p2d1[i];
		p2d1[i] = nullptr;
	}
	delete[] p2d1;
	p2d1 = nullptr;
	printf("\n");


	printf("4) new의 연산자 오버로딩을 이용한 2차원 배열의 동적할당.\n");
	int* p2d2 = new int[5, 5];
	printf("p2d2 >> \n");
	z = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			z++;
			p2d2[i, j] = z;
			printf("p2d2[%i, %i] address: %p\n", i, j, &p2d2[i, j]);
			printf("p2d2[%i, %i] value  : %i\n", i, j, p2d2[i, j]);
		}
	}
	delete[] p2d2;
	p2d2 = nullptr;

	return 0;
}