// 2022-06-14 ����


// �������� �����, �Է¹޴� �ܾ �����ǿ� ������ ��� "Bingo"�� �ٲٴ� ���� �����.


#include <iostream>
#include <string>
// string -> ���ڿ��� ó���ϴ� ���� ����� �����ϴ� ���.
#pragma warning(disable : 4996)

int main()
{
	char bingoPlate[5][5][32] = {};
	char inputStr[32];

	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			n++;
			printf("%i��° ĭ�� ���ڿ� �Է�: ", n);
			std::cin.getline(bingoPlate[i][j], sizeof(bingoPlate[i][j]), '\n');
		}
	}

	while (1)
	{
		n = 0;
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				n++;
				printf("[%2i: %15s]", n, bingoPlate[i][j]);
				if (j % 5 == 4) std::cout << std::endl;
				else std::cout << " ";
			}
		}

		printf("�Է�: ");
		std::cin.getline(inputStr, sizeof(inputStr), '\n');

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				// strcmp(str1, str2); -> string compare (���ڿ� ��)
				// : str1�� str2�� ���ٸ� 0,
				//   �ٸ��ٸ� -1(str1�� ���̰� �� ª�� ��) �Ǵ� +1(str1�� ���̰� �� �� ��)�� ��ȯ�ϴ� �Լ�.
				if (!strcmp(inputStr, bingoPlate[i][j]))
					// strcpy(str1, str2); -> string copy (���ڿ� ����)
					// : str1�� str2�� ������ ���ڿ��� ������ �Լ�.
					strcpy(bingoPlate[i][j], "Bingo");
			}
		}
	}

	return 0;
}