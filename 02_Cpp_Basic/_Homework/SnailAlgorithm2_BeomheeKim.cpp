// 2022-07-25 �ǽ�


// Snail algorithm���� �迭 �ʱ�ȭ�ϱ�
// ��:	1	2	3	4	5
//		12	13	14	15	6
//		11	10	9	8	7

#include <iostream>

void SnailAlgorithm(int** matrix)
{
	int nRows = static_cast<int>(_msize(matrix) / sizeof(int));
	int nCols = static_cast<int>(_msize(matrix[0]) / sizeof(int));
	int maxNum = nRows * nCols;		// �ٱ� while ������ �������� ��Ÿ���� ���� ����

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
			for (int j = 0; j < nCols; j++)
			{
				x++;
				column++;
				matrix[row][column] = x;
			}
			nRows--;
			nCols--;
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
			for (int j = 0; j < nCols; j++)
			{
				x++;
				column--;
				matrix[row][column] = x;
			}
			nRows--;
			nCols--;
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
}

int** DynamicArray(unsigned nRows, unsigned nCols)
{
	int** matrix = new int* [nRows];
	for (int i = 0; i < static_cast<int>(nRows); i++)
	{
		for (int j = 0; j < static_cast<int>(nCols); j++)
		{
			matrix[i] = new int[nCols];
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void PrintArray(int** matrix)
{
	int nRows = static_cast<int>(_msize(matrix) / sizeof(int));
	int nCols = static_cast<int>(_msize(matrix[0]) / sizeof(int));
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
			printf("%i\t", matrix[i][j]);
		printf("\n");
	}
}

void DeleteArray(int** matrix)
{
	int nRows = static_cast<int>(_msize(matrix) / sizeof(int));
	for (int i = 0; i < nRows; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[] matrix;
}

int main()
{
	unsigned nRows = 10;		// 2���� �迭 ���� ���� ����
	unsigned nCols = 8;			// 2���� �迭 ���� ���� ����

	int** matrix = DynamicArray(nRows, nCols);	// �����Ҵ��� ���� �迭 ����
	SnailAlgorithm(matrix);						// Snail algorithm�� ���� �迭 �ʱ�ȭ
	PrintArray(matrix);							// ���(Ȯ�ο�)
	DeleteArray(matrix);						// �����Ҵ� ���� ����
	matrix = nullptr;

	return 0;
}