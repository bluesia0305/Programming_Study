// 2022-06-09 ����(���)


// �������迭(Multiarray)
// : �ڽź��� �� ���� ���� �迭�� ��ҷ� ���� �迭�� ������ �� ����.


#include <iostream>

int main()
{
	// 2���� �迭�� ���� (����: 3 x 3 �迭).
	int multiArr[3][3];

	std::cout << "1) ������ �迭�� ���� �� ���." << std::endl;
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