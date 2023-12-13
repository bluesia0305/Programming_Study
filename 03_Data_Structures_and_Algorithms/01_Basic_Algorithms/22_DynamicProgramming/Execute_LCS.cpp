#include <iostream>
#include <string>
#include "../Timer.h"

using namespace std;

struct Table
{
	int** Data;
};

namespace Supplement
{
	void ZeroSet(Table* table, int lengthA, int lengthB)
	{
		for (int i = 0; i < lengthA + 1; ++i)
		{
			table->Data[i] = new int[lengthB + 1];
			memset(table->Data[i], 0, sizeof(int) * (lengthB + 1));
		}
	}

	void PrintTable(Table& table, const char* a, const char* b, int lengthA, int lengthB)
	{
		printf("\n%-04s", " ");


		for (int i = 0; i <= lengthA; ++i)
			printf("%c ", b[i]);
		printf("\n ");

		for (int i = 0; i <= lengthA; ++i)
		{
			printf("%c ", a[i - 1]);

			for (int j = 0; j <= lengthB; ++j)
				printf("%d ", table.Data[i][j]);

			printf("\n");
		}
	}
}

// 재귀를 통해 구하는 방법
int LCS_Recursion(const char* x, const char* y, int i, int j, Table* table)
{
	if (i == 0 || j == 0)
	{
		table->Data[i][j] = 0;
		//printf("%d, i == %d, j == %d, %c == %c\n", table->Data[i][j], i, j, x[i - 1], y[j - 1]);
	}
	// 문자열의 마지막 자리가 같으면 +1
	else if (x[i - 1] == y[j - 1])
	{
		table->Data[i][j] = LCS_Recursion(x, y, i - 1, j - 1, table) + 1;
		//printf("%d, i == %d, j == %d, %c == %c\n", table->Data[i][j], i, j, x[i - 1], y[j - 1]);
	}
	else
	{
		int a = LCS_Recursion(x, y, i - 1, j, table);
		int b = LCS_Recursion(x, y, i, j - 1, table);

		if (a > b)
			table->Data[i][j] = a;
		else
			table->Data[i][j] = b;
		//printf("%d, i == %d, j == %d, %c == %c\n", table->Data[i][j], i, j, x[i - 1], y[j - 1]);
	}

	return table->Data[i][j];
}

// 동적계획법: 이전 단계의 값을 이용하여 다음 단계의 값 계산 -> 앞에서부터 시작
int LCS_DynamicProgramming(const char* x, const char* y, int i, int j, Table* table)
{
	// 더미 줄에 0 대입
	for (int m = 0; m <= i; ++m)
		table->Data[m][0] = 0;

	for (int n = 0; n <= j; ++n)
		table->Data[0][n] = 0;

	for (int m = 1; m <= i; ++m)
	{
		for (int n = 1; n <= j; ++n)
		{
			if (x[m - 1] != y[n - 1])
				table->Data[m][n] = max(table->Data[m][n - 1], table->Data[m - 1][n]);
			else
				table->Data[m][n] = table->Data[m - 1][n - 1] + 1;
		}
	}

	return table->Data[i][j];
}

// 동적 계획법을 통해 문자열 찾기
void LCS_DynamicProgramming_Trackback(const char* x, const char* y, int m, int n, Table* table, char* lcs)
{
	if (m == 0 || n == 0)
		return;

	bool conditionA = true;
	conditionA &= table->Data[m][n] > table->Data[m][n - 1];
	conditionA &= table->Data[m][n] > table->Data[m - 1][n];
	conditionA &= table->Data[m][n] > table->Data[m - 1][n - 1];

	bool conditionB = true;
	conditionB &= table->Data[m][n] == table->Data[m][n - 1];
	conditionB &= table->Data[m][n] > table->Data[m - 1][n];

	if (conditionA)
	{
		// 문자열 저장
		char temp[100];
		strcpy(temp, lcs);
		sprintf(lcs, "%c%s", x[m - 1], temp);

		// 대각선으로 움직이기
		LCS_DynamicProgramming_Trackback(x, y, m - 1, n - 1, table, lcs);
	}
	else if (conditionB)
	{
		// 세로로 움직이기
		LCS_DynamicProgramming_Trackback(x, y, m, n - 1, table, lcs);
	}
	else
	{
		// 가로로 움직이기
		LCS_DynamicProgramming_Trackback(x, y, m - 1, n, table, lcs);
	}
}

int main()
{
	Timer timer;
	const char* a = "GOOD MORNING.";
	const char* b = "GUTEN MORGEN.";

	int lengthA = (int)strlen(a);
	int lengthB = (int)strlen(b);
	int result = 0;

	Table table;
	table.Data = new int*[lengthA + 1];



	// 재귀 호출
	printf("[ 재귀 호출 ]\n");
	Supplement::ZeroSet(&table, lengthA, lengthB);

	timer.Start();
	result = LCS_Recursion(a, b, lengthA, lengthB, &table);
	timer.End();

	Supplement::PrintTable(table, a, b, lengthA, lengthB);
	printf("\n");
	printf("- 결과값: %d\n", result);
	printf("- 소요 시간: %f ms\n\n", timer.RunningTime());



	// 동적 계획법
	printf("[ 동적 계획법 ]\n");
	Supplement::ZeroSet(&table, lengthA, lengthB);

	timer.Start();
	result = LCS_DynamicProgramming(a, b, lengthA, lengthB, &table);
	timer.End();

	Supplement::PrintTable(table, a, b, lengthA, lengthB);
	printf("\n");
	printf("- 결과값: %d\n", result);
	printf("- 소요 시간: %f ms\n\n\n", timer.RunningTime());



	// 동적 계획법 이용해 문자열 찾기
	printf("[ 동적 계획법 - 문자열 찾기 ]\n");

	timer.Start();
	char* lcs = (char*)malloc(sizeof(char) * (table.Data[lengthA][lengthB] + 1));
	lcs[0] = '\0';
	LCS_DynamicProgramming_Trackback(a, b, lengthA, lengthB, &table, lcs);
	timer.End();

	printf("- 일치하는 문자열: %s\n", lcs);
	printf("- 일치하는 문자의 수: %d\n", result);
	printf("- 소요 시간: %f ms\n", timer.RunningTime());
	free(lcs);
	return 0;
}