// 2022-06-09 ����
// 1���� 13������ ���� �� ������ ��ҷ� ���� 4 x 13�� 2���� �迭 �����.


#include <iostream>

int main()
{
	int trump[4][13] = {};

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0: std::cout << "����1";
			break;
		case 1: std::cout << "����2";
			break;
		case 2: std::cout << "����3";
			break;
		case 3: std::cout << "����4";
			break;
		default: break;
		}

		std::cout << ":\t";

		for (int j = 0; j < 13; j++)
		{
			trump[i][j] = j + 1;
			std::cout << trump[i][j];

			if (j == 12) std::cout << std::endl;
			else std::cout << " ";
		}
	}

	return 0;
}