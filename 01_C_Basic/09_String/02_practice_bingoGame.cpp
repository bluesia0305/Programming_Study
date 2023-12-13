// 2022-06-14 수업


// 빙고판을 만들고, 입력받는 단어가 빙고판에 존재할 경우 "Bingo"로 바꾸는 게임 만들기.


#include <iostream>
#include <string>
// string -> 문자열을 처리하는 여러 기능을 제공하는 헤더.
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
			printf("%i번째 칸의 문자열 입력: ", n);
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

		printf("입력: ");
		std::cin.getline(inputStr, sizeof(inputStr), '\n');

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				// strcmp(str1, str2); -> string compare (문자열 비교)
				// : str1과 str2가 같다면 0,
				//   다르다면 -1(str1의 길이가 더 짧을 때) 또는 +1(str1의 길이가 더 길 때)을 반환하는 함수.
				if (!strcmp(inputStr, bingoPlate[i][j]))
					// strcpy(str1, str2); -> string copy (문자열 복사)
					// : str1을 str2와 동일한 문자열로 덮어씌우는 함수.
					strcpy(bingoPlate[i][j], "Bingo");
			}
		}
	}

	return 0;
}