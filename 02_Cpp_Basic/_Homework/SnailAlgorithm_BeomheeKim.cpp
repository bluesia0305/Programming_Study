// 2022-07-25 �ǽ�


// Snail algorithm���� �迭 �ʱ�ȭ�ϱ�
// ��:	1	2	3	4	5
//		12	13	14	15	6
//		11	10	9	8	7

#include <iostream>

int main()
{
	int matrix[5][3] = {};

#pragma region Snail algorithm
	int nColumns = sizeof(matrix[0])/sizeof(int);
	int nRows = sizeof(matrix)/nColumns/sizeof(int);
	int maxNum = nRows * nColumns;		// �ٱ� while ������ �������� ��Ÿ���� ���� ����

	int x = 0;			// �Է��� �� ������(���ǻ� 0���� ����)
	int row = 0;		// �� ��ȣ ������
	int column = -1;	// �� ��ȣ ������(���ǻ� -1���� ����)
	int direction = 0;	// �Է� ������ ��Ÿ���� ���� ����
						// 0: ������ ����	== �� ��ȣ ����
						// 1: �Ʒ��� ����	== �� ��ȣ ����
						// 2: ���� ����		== �� ��ȣ ����
						// 3: ���� ����		== �� ��ȣ ����
	while (x < maxNum)
	{
		switch (direction)
		{
		case 0:	// �� ��ȣ ����
			for (int j = 0; j < nColumns; j++)
			{
				x++;
				column++;
				matrix[row][column] = x;
			}
			nRows--;
			nColumns--;
			direction = 1;
			break;
		case 1:	// �� ��ȣ ����
			for (int j = 0; j < nRows; j++)
			{
				x++;
				row++;
				matrix[row][column] = x;
			}
			direction = 2;
			break;
		case 2:	// �� ��ȣ ����
			for (int j = 0; j < nColumns; j++)
			{
				x++;
				column--;
				matrix[row][column] = x;
			}
			nRows--;
			nColumns--;
			direction = 3;
			break;
		case 3: // �� ��ȣ ����
			for (int j = 0; j < nRows; j++)
			{
				x++;
				row--;
				matrix[row][column] = x;
			}
			direction = 0;
			break;
		}
	}
#pragma endregion

	// ���(Ȯ�ο�)
	nColumns = sizeof(matrix[0]) / sizeof(int);
	nRows = sizeof(matrix) / nColumns / sizeof(int);
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nColumns; j++)
		{
			printf("%i\t", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}