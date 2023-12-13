// 2022-06-09 수업(계속)


// 다차원배열(Multiarray)
// : 자신보다 한 차원 낮은 배열을 요소로 갖는 배열을 선언할 수 있음.


#include <iostream>

int main()
{
	// 2차원 배열의 선언 (예시: 3 x 3 배열).
	int multiArr[3][3];

	std::cout << "1) 다차원 배열의 선언 및 출력." << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			multiArr[i][j] = 3 * i + j + 1;
			std::cout << multiArr[i][j];
			if (j == 2) std::cout << std::endl;
			else std::cout << " ";
		}
	}

	return 0;
}