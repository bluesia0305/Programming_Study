// 2022-06-09 과제
// 1부터 13까지의 수를 네 쌍으로 요소로 갖는 4 x 13의 2차원 배열 만들기.


#include <iostream>

int main()
{
	int trump[4][13] = {};

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0: std::cout << "문양1";
			break;
		case 1: std::cout << "문양2";
			break;
		case 2: std::cout << "문양3";
			break;
		case 3: std::cout << "문양4";
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