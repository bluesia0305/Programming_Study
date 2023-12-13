// 2022-07-25 실습


// <코드 개선사항>
// 1) 각 loop별로 추가적인 명령줄(x++;) 없이, 요소의 값을 초기화하는 명령줄 내에서 
//    전위증가연산자를 사용하여(matrix[row][column] = ++x;) 코드 단축.
// 
// 2) 동일한 구조의 4개 짜리 반복문 loop를 2개로 압축.
//	  * Snail algorithm의 방식이
//	       1. 열 증가 -----(행,열 방향으로 넣는 숫자의 갯수 1 감소)----->	2. 행 증가
//	       3. 열 감소 -----(행,열 방향으로 넣는 숫자의 갯수 1 감소)----->	4. 행 감소
//	    와 같이 이루어짐에 착안하여,
//	    열 증가 loop와 열 감소 loop 를 합치고
//	    행 증가 loop와 행 감소 loop 를 합칠 수 있음 (direction 대신 in_decrement 변수 사용)
//	    따라서, 압축된 loop로는 아래와 같이 수행됨.
//	       1. 열 증가 -----(행,열 방향으로 넣는 숫자의 갯수 1 감소)----->	2. 행 증가   (이후 loop 밖에서 in_decrement = (-1)^n)
//	    or 3. 열 감소												or	4. 행 감소

#include <iostream>

void SnailAlgorithm(int** matrix)
{
	int nRows = static_cast<int>(_msize(matrix) / sizeof(int));
	int nCols = static_cast<int>(_msize(matrix[0]) / sizeof(int));
	int maxNum = nRows * nCols;		// 바깥 while 루프의 종료점을 나타내기 위한 변수

	int x = 0;			// 입력할 수 시작점(편의상 0에서 시작)
	int row = 0;		// 행 번호 시작점
	int column = -1;	// 열 번호 시작점(편의상 -1에서 시작)
	int in_decrement = 1;	// 입력 방향에 따른 증감치
							// 1: 열 번호 증가 이후 행 번호 증가에 사용
							// -1: 열 번호 감소 이후 행 번호 감소에 사용

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
	unsigned nRows = 10;		// 2차원 배열 행의 갯수 설정
	unsigned nCols = 8;			// 2차원 배열 열의 갯수 설정

	int** matrix = DynamicArray(nRows, nCols);	// 동적할당을 통한 배열 생성
	SnailAlgorithm(matrix);						// Snail algorithm에 따른 배열 초기화
	PrintArray(matrix);							// 출력(확인용)
	DeleteArray(matrix);						// 동적할당 공간 해제
	matrix = nullptr;

	return 0;
}