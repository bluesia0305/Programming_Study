// 2022-06-07 ����


// �Ʒ��� ������ for �ݺ����� �̿��Ͽ� ���
//
// Q1. *
//     * *
//     * * *
//     * * * *
//     * * * * *             <- �� ����� ����ϱ�
// 
// Q2. * * * * *
//     * * * *
//     * * *
//     * *
//     *                     <- �� ����� ����ϱ�
// 
// Q3.         *
//           * * *
//         * * * * *
//       * * * * * * *
//     * * * * * * * * *     <- �� ����� ����ϱ�


#include <stdio.h>
#include <Windows.h>

int main()
{
	// Q1
	printf("Q1. ���õ� ����� ����ϱ�.\n");
	const int n1_lines = 5;
	for (int i = 0; i < n1_lines; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
	system("cls");


	// Q2
	printf("Q2. ���õ� ����� ����ϱ�.\n");
	const int n2_lines = 5;
	for (int i = 0; i < n2_lines; i++)
	{
		for (int j = 0; j < n2_lines - i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
	system("cls");


	// Q3
	printf("Q3. ���õ� ����� ����ϱ�.\n");
	const int n3_lines = 5;
	for (int i = 0; i < n3_lines; i++)
	{
		for (int j = 0; j < (2 * n3_lines) - (2 * (i + 1)); j++)
		{
			printf(" ");
		}

		for (int k = 0; k < 2 * i + 1; k++)
		{
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}