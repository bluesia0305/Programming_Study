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

// ��͸� ���� ���ϴ� ���
int LCS_Recursion(const char* x, const char* y, int i, int j, Table* table)
{
	if (i == 0 || j == 0)
	{
		table->Data[i][j] = 0;
		//printf("%d, i == %d, j == %d, %c == %c\n", table->Data[i][j], i, j, x[i - 1], y[j - 1]);
	}
	// ���ڿ��� ������ �ڸ��� ������ +1
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

// ������ȹ��: ���� �ܰ��� ���� �̿��Ͽ� ���� �ܰ��� �� ��� -> �տ������� ����
int LCS_DynamicProgramming(const char* x, const char* y, int i, int j, Table* table)
{
	// ���� �ٿ� 0 ����
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

// ���� ��ȹ���� ���� ���ڿ� ã��
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
		// ���ڿ� ����
		char temp[100];
		strcpy(temp, lcs);
		sprintf(lcs, "%c%s", x[m - 1], temp);

		// �밢������ �����̱�
		LCS_DynamicProgramming_Trackback(x, y, m - 1, n - 1, table, lcs);
	}
	else if (conditionB)
	{
		// ���η� �����̱�
		LCS_DynamicProgramming_Trackback(x, y, m, n - 1, table, lcs);
	}
	else
	{
		// ���η� �����̱�
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



	// ��� ȣ��
	printf("[ ��� ȣ�� ]\n");
	Supplement::ZeroSet(&table, lengthA, lengthB);

	timer.Start();
	result = LCS_Recursion(a, b, lengthA, lengthB, &table);
	timer.End();

	Supplement::PrintTable(table, a, b, lengthA, lengthB);
	printf("\n");
	printf("- �����: %d\n", result);
	printf("- �ҿ� �ð�: %f ms\n\n", timer.RunningTime());



	// ���� ��ȹ��
	printf("[ ���� ��ȹ�� ]\n");
	Supplement::ZeroSet(&table, lengthA, lengthB);

	timer.Start();
	result = LCS_DynamicProgramming(a, b, lengthA, lengthB, &table);
	timer.End();

	Supplement::PrintTable(table, a, b, lengthA, lengthB);
	printf("\n");
	printf("- �����: %d\n", result);
	printf("- �ҿ� �ð�: %f ms\n\n\n", timer.RunningTime());



	// ���� ��ȹ�� �̿��� ���ڿ� ã��
	printf("[ ���� ��ȹ�� - ���ڿ� ã�� ]\n");

	timer.Start();
	char* lcs = (char*)malloc(sizeof(char) * (table.Data[lengthA][lengthB] + 1));
	lcs[0] = '\0';
	LCS_DynamicProgramming_Trackback(a, b, lengthA, lengthB, &table, lcs);
	timer.End();

	printf("- ��ġ�ϴ� ���ڿ�: %s\n", lcs);
	printf("- ��ġ�ϴ� ������ ��: %d\n", result);
	printf("- �ҿ� �ð�: %f ms\n", timer.RunningTime());
	free(lcs);
	return 0;
}