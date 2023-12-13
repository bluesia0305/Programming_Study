// 2022-06-10 과제
// 5 x 5 빙고판을 만들고
// 문자열을 입력 받아 빙고판을 채워주세요.

// 예시)
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
			printf("%i번째 칸의 문자열 입력: ", n);
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