// 2022-07-25 실습


// Snail algorithm으로 배열 초기화하기
// 예:	1	2	3	4	5
//		12	13	14	15	6
//		11	10	9	8	7

#include <iostream>

void SnailAlgorithm(int** matrix)
{
	int nRows = static_cast<int>(_msize(matrix) / sizeof(int));
	int nCols = static_cast<int>(_msize(matrix[0]) / sizeof(int));
	int maxNum = nRows * nCols;		// 바깥 while 루프의 종료점을 나타내기 위한 변수

	int x = 0;			// 입력할 수 시작점(편의상 0에서 시작)
	int row = 0;		// 행 번호 시작점
	int column = -1;	// 열 번호 시작점(편의상 -1에서 시작)
	int direction = 0;	// 입력 방향을 나타내기 위한 변수
						// 0: 오른쪽 방향	== 열 번호 증가
						// 1: 아래쪽 방향	== 행 번호 증가
						// 2: 왼쪽 방향		== 열 번호 감소
						// 3: 위쪽 방향		== 행 번호 감소
	while (x < maxNum)
	{
		switch (direction)
		{
		case 0:	// 열 번호 증가
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
		case 1:	// 행 번호 증가
			for (int j = 0; j < nRows; j++)
			{
				x++;
				row++;
				matrix[row][column] = x;
			}
			direction = 2;
			break;
		case 2:	// 열 번호 감소
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
		case 3: // 행 번호 감소
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
	unsigned nRows = 10;		// 2차원 배열 행의 갯수 설정
	unsigned nCols = 8;			// 2차원 배열 열의 갯수 설정

	int** matrix = DynamicArray(nRows, nCols);	// 동적할당을 통한 배열 생성
	SnailAlgorithm(matrix);						// Snail algorithm에 따른 배열 초기화
	PrintArray(matrix);							// 출력(확인용)
	DeleteArray(matrix);						// 동적할당 공간 해제
	matrix = nullptr;

	return 0;
}