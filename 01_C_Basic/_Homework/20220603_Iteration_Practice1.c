// Q1. 1���� �Է��� ��(���� ����)���� ��� ���� ���� ���ϱ�.
//     (���ǻ�, �Է¹��� �޴� ���� �׻� 1���� ū ���� ������� ����)
// 
// Q2. 1���� �Է��� ��(���� ����)���� ��� ���� ���� ���ϱ�.
//     (���ǻ�, �Է¹��� �޴� ���� �׻� 1���� ū ���� ������� ����)
// 
// Q3. �Ʒ��� ���� ������ ������� ��¹��� ������ �ڵ��غ�����.
//     (�� ��ư� Ǯ��� ������ ����� ���� ���� �Է��� �޾� ���ϵ��� �ڵ��غ�����)
//     * * * * *
//     * * * *
//     * * *
//     * *
//     *
// 
// Q4. �Ʒ��� ���� ������ ������� ��¹��� ������ �ڵ��غ�����.
//     (�� ��ư� Ǯ��� ������ ����� ���� ���� �Է��� �޾� ���ϵ��� �ڵ��غ�����)
//             *
//           * * *
//         * * * * *
//       * * * * * * *
//     * * * * * * * * *
// 
// Q4-X. �Ʒ��� ���� ������ ������� ��¹��� ������ �ڵ��غ�����.
//             *
//           * * *
//         * * * * *
//       * * * * * * *
//     * * * * * * * * *
//       * * * * * * *
//         * * * * *
//           * * *
//             *
// 
// Q5. �������� 3���� ����ϱ�.
//   ex)   1��   2��   3��
//         4��   5��   6��
//         7��   8��   9��
// 
// Q6. ��ī�� ����
//     : 1���� 13������ ������ ���ڸ� �� ���� �̾� �����ϴ� ����.
//       ��ǻ�ʹ� 1 ~ 13���� ������ ���ڸ� �� �� �̾� left, right�� ����.
//       left�� ���� �÷��̾�� �����ָ�, right�� ���� ����.
//       left�� ���� ���� �÷��̾�� right�� �����ִ� ���� �� ū��, ������ ���ߴ� ������.


#include <stdio.h>
#include <Windows.h>

int main()
{
	// Q1
	printf("Q1. 1���� �Է��� ������ ��� ���� ���� ���ϱ�.\n");
	int i = 0;
	int num = 0;

	while (!num || num < 0)
	{
		printf("�Է� [�ڿ���]: ");
		scanf_s("%i", &num);
	}
	
	int sum = 0;
	while (i++ < num)
	{
		sum += i;
	}
	printf("1���� %i������ ��� ���� ��: %i\n\n", num, sum);
	system("pause");
	system("cls");


	// Q2
	printf("Q2. 1���� �Է��� ������ ��� ���� ���� ���ϱ�.\n");
	i = 0;
	num = 0;

	while (!num || num < 0)
	{
		printf("�Է� [�ڿ���]: ");
		scanf_s("%i", &num);
	}
	
	long long product = 1;
	while (i++ < num)
	{
		product *= i;
	}
	printf("1���� %i������ ��� ���� ��: %lli\n\n", num, product);
	system("pause");
	system("cls");


	// Q3
	printf("Q3. ���õ� ����� ����ϱ�1.\n");
	const int n1_lines = 5;
	int j;
	i = 0;

	while (i < n1_lines)
	{
		int j = 0;
		while (j++ < n1_lines - i)
		{
			printf("* ");
		}
		printf("\n");
		i++;
	}
	printf("\n");
	system("pause");
	system("cls");


	// Q4
	printf("Q4. ���õ� ����� ����ϱ�2.\n");
	const int n2_lines = 5;
	int k;

	i = 1;
	while (i <= n2_lines)
	{
		j = 0;
		while (j++ < (2 * n2_lines) - (2 * i))
		{
			printf(" ");
		}

		k = 0;
		while (k++ < 2 * i - 1)
		{
			printf("* ");
		}
		printf("\n");
		i++;
	}
	printf("\n");
	system("pause");
	system("cls");


	// Q5
	printf("Q5. �������� 3���� ����ϼ���.\n");
	const int n_column = 3;
	int column;
	int paragraph;
	int multiplier;

	paragraph = 0;
	while (paragraph++ < 9 / n_column)
	{
		multiplier = 0;
		while (multiplier++ < 9)
		{
			column = 0;
			while (column++ < n_column)
			{
				printf("%i x %i = %i%s",
					n_column * (paragraph - 1) + column,
					multiplier,
					(n_column * (paragraph - 1) + column) * multiplier,
					(column == n_column) ? "\n" : "\t");
			}
		}
		printf("\n");
	}
	system("pause");
	system("cls");


	// Q6
	system("cls");
	int n_game = 0;
	int user_score = 0;
	int com_score = 0;
	int left;
	int right;
	int guess;
	srand(time(NULL));

	while (n_game++ < 10)
	{
		printf("Q6. ��ī�� ���� �����ϱ�.\n");
		printf("1 ~ 13 ������ �ڿ����� �̿��� �����ϴ� ����, 10ȸ ���� (%i / 10).\n\n", n_game);
		printf("<���� ���ھ�>\n");
		printf("����\t: %i\n", user_score);
		printf("��ǻ��\t: %i\n\n", com_score);

		// 1�̳� 13�� ������ ���� ������ ��Ȱ�ϰ� ���� �ʱ� ������ ����
		printf("��ǻ�Ͱ� 1 ~ 13 ������ �ڿ����� �����մϴ� [Left]...\n");
		left = rand() % 13 + 1;
		Sleep(2000);

		printf("��ǻ�Ͱ� 1 ~ 13 ������ �ڿ����� �����մϴ� [Right]...\n\n");
		right = rand() % 13 + 1;
		Sleep(2000);

		printf("[Left: %i], [Right: ?]\n\n", left);

		printf("Left�� Right �߿���, ��� ���� �� Ŭ���?\n");
		printf("[1: Left] [2: Middle] [3: Right]\n");
		printf("�Է� [1~3]: ");
		scanf_s("%i", &guess);
		printf("\n");

		Sleep(2000);
		printf("[Right: %i]\n\n", right);
		Sleep(1000);

		switch (guess)
		{
		case 1: case 3:
			if ((left > right) && (guess == 1) ||
				(left < right) && (guess == 3))
			{
				printf("win ! (������ +1�� ȹ��)\n");
				user_score += 1;
			}
			else
			{
				printf("lose... (��ǻ�Ͱ� +2�� ȹ��)\n");
				com_score += 2;
			}
			break;

		case 2:
			if (left == right)
			{
				printf("win ! (������ +4�� ȹ��)\n");
				user_score += 4;
			}
			else
			{
				printf("lose... (��ǻ�Ͱ� +4�� ȹ��)\n\n");
				com_score += 4;
			}
			break;

		default:
			Sleep(1000);
		}
		Sleep(2000);
		system("cls");
	}

	printf("<���� ���>\n");
	printf("����\t: %i\n", user_score);
	printf("��ǻ��\t: %i\n\n", com_score);

	if (user_score > com_score) printf("WIN !\n");
	else if (user_score < com_score) printf("LOSE...\n");
	else printf("DRAW.\n");

	return 0;
}