// 2022-07-25 �ǽ�


// <�ڵ� ��������>
// 1) �� loop���� �߰����� �����(x++;) ����, ����� ���� �ʱ�ȭ�ϴ� ����� ������ 
//    �������������ڸ� ����Ͽ�(matrix[row][column] = ++x;) �ڵ� ����.
// 
// 2) ������ ������ 4�� ¥�� �ݺ��� loop�� 2���� ����.
//	  * Snail algorithm�� �����
//	       1. �� ���� -----(��,�� �������� �ִ� ������ ���� 1 ����)----->	2. �� ����
//	       3. �� ���� -----(��,�� �������� �ִ� ������ ���� 1 ����)----->	4. �� ����
//	    �� ���� �̷������ �����Ͽ�,
//	    �� ���� loop�� �� ���� loop �� ��ġ��
//	    �� ���� loop�� �� ���� loop �� ��ĥ �� ���� (direction ��� in_decrement ���� ���)
//	    ����, ����� loop�δ� �Ʒ��� ���� �����.
//	       1. �� ���� -----(��,�� �������� �ִ� ������ ���� 1 ����)----->	2. �� ����   (���� loop �ۿ��� in_decrement = (-1)^n)
//	    or 3. �� ����												or	4. �� ����

#include <iostream>

void SnailAlgorithm(int** matrix)
{
	int nRows = static_cast<int>(_msize(matrix) / sizeof(int));
	int nCols = static_cast<int>(_msize(matrix[0]) / sizeof(int));
	int maxNum = nRows * nCols;		// �ٱ� while ������ �������� ��Ÿ���� ���� ����

	int x = 0;			// �Է��� �� ������(���ǻ� 0���� ����)
	int row = 0;		// �� ��ȣ ������
	int column = -1;	// �� ��ȣ ������(���ǻ� -1���� ����)
	int in_decrement = 1;	// �Է� ���⿡ ���� ����ġ
							// 1: �� ��ȣ ���� ���� �� ��ȣ ������ ���
							// -1: �� ��ȣ ���� ���� �� ��ȣ ���ҿ� ���

	while (x < maxNum)
	{
		for (int j = 0; j < nCols; j++)
		{
			column += in_decrement;
			matrix[row][column] = ++x;
		}
		nRows--;
		nCols--;

		for (int j = 0; j < nRows; j++)
		{
			row += in_decrement;
			matrix[row][column] = ++x;
		}
		in_decrement *= -1;
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