// 2022-06-10 ����
// 5 x 5 �������� �����
// ���ڿ��� �Է� �޾� �������� ä���ּ���.

// ����)
// [hi]	[hello] [???] [...] [...]
// [...] [...] [...] [...] [...]
// [...] [...] [...] [...] [...]
// [...] [...] [...] [...] [...]
// [...] [...] [...] [...] [...]


#include <iostream>
#pragma warning(disable: 4996)

int main()
{
	char bingoPlate[5][5][32] = {};

	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			n++;
			printf("%i��° ĭ�� ���ڿ� �Է�: ", n);
			scanf("%s", bingoPlate[i][j]);
			while (getchar() != '\n');
		}
	}

	n = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			n++;
			printf("[%i: %s]", n, bingoPlate[i][j]);
			if (j % 5 == 4) std::cout << std::endl;
			else std::cout << "\t";
		}
	}

	return 0;
}