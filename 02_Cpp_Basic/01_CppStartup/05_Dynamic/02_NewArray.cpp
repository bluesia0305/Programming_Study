// 2022-07-01 ����


#include <iostream>
using namespace std;

int main()
{
	// (�ǽ�) int �ڷ��� �����͸� 5�� ������ �� �ִ� �迭�� �����Ҵ��ϰ�,
	//        �迭�� ��Ҹ� 1, 2, 3, 4, 5�� �ʱ�ȭ�Ͽ� ������ּ���.
	printf("1) malloc()�� �̿��� 1���� �迭�� �����Ҵ�.\n");
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
	

	printf("2) new�� �̿��� 1���� �迭�� �����Ҵ�.\n");
	int* p2 = new int[5];
	// initialization operator {,}�� ����Ͽ� �Ʒ��� ���� ����� ���ÿ� �ʱ�ȭ ����.
	//int* p2 = new int[5]{ 1, 2, 3, 4, 5 };
	printf("p2 >> ");
	for (int i = 0; i < 5; i++)
	{
		p2[i] = i + 1;
		printf("%i ", p2[i]);
	}
	delete[] p2;		// �迭�� ����� �����Ҵ� ������ ���� �ÿ��� delete[] �����ڸ� ���.
	p2 = nullptr;
	printf("\n");
	

	printf("3) new�� �̿��� 2���� �迭�� �����Ҵ�.\n");
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


	printf("4) new�� ������ �����ε��� �̿��� 2���� �迭�� �����Ҵ�.\n");
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