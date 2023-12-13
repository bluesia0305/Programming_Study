// Q1. 1부터 입력한 수(양의 정수)까지 모든 수의 합을 구하기.
//     (편의상, 입력받을 받는 수는 항상 1보다 큰 양의 정수라고 가정)
// 
// Q2. 1부터 입력한 수(양의 정수)까지 모든 수의 곱을 구하기.
//     (편의상, 입력받을 받는 수는 항상 1보다 큰 양의 정수라고 가정)
// 
// Q3. 아래의 모양과 동일한 모양으로 출력문이 나오게 코딩해보세요.
//     (더 어렵게 풀어보고 싶으면 출력할 줄의 수도 입력을 받아 정하도록 코딩해보세요)
//     * * * * *
//     * * * *
//     * * *
//     * *
//     *
// 
// Q4. 아래의 모양과 동일한 모양으로 출력문이 나오게 코딩해보세요.
//     (더 어렵게 풀어보고 싶으면 출력할 줄의 수도 입력을 받아 정하도록 코딩해보세요)
//             *
//           * * *
//         * * * * *
//       * * * * * * *
//     * * * * * * * * *
// 
// Q4-X. 아래의 모양과 동일한 모양으로 출력문이 나오게 코딩해보세요.
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
// Q5. 구구단을 3열로 출력하기.
//   ex)   1단   2단   3단
//         4단   5단   6단
//         7단   8단   9단
// 
// Q6. 바카라 게임
//     : 1부터 13까지의 랜덤한 숫자를 두 가지 뽑아 진행하는 게임.
//       컴퓨터는 1 ~ 13까지 랜덤한 숫자를 두 개 뽑아 left, right에 저장.
//       left의 값은 플레이어에게 보여주며, right의 값은 숨김.
//       left의 값을 보고 플레이어는 right에 숨어있는 값이 더 큰지, 작은지 맞추는 게임임.


#include <stdio.h>
#include <Windows.h>

int main()
{
	// Q1
	printf("Q1. 1부터 입력한 수까지 모든 수의 합을 구하기.\n");
	int i = 0;
	int num = 0;

	while (!num || num < 0)
	{
		printf("입력 [자연수]: ");
		scanf_s("%i", &num);
	}
	
	int sum = 0;
	while (i++ < num)
	{
		sum += i;
	}
	printf("1부터 %i까지의 모든 수의 합: %i\n\n", num, sum);
	system("pause");
	system("cls");


	// Q2
	printf("Q2. 1부터 입력한 수까지 모든 수의 곱을 구하기.\n");
	i = 0;
	num = 0;

	while (!num || num < 0)
	{
		printf("입력 [자연수]: ");
		scanf_s("%i", &num);
	}
	
	long long product = 1;
	while (i++ < num)
	{
		product *= i;
	}
	printf("1부터 %i까지의 모든 수의 곱: %lli\n\n", num, product);
	system("pause");
	system("cls");


	// Q3
	printf("Q3. 제시된 모양대로 출력하기1.\n");
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
	printf("Q4. 제시된 모양대로 출력하기2.\n");
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
	printf("Q5. 구구단을 3열로 출력하세요.\n");
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
		printf("Q6. 바카라 게임 구현하기.\n");
		printf("1 ~ 13 사이의 자연수를 이용해 진행하는 게임, 10회 진행 (%i / 10).\n\n", n_game);
		printf("<현재 스코어>\n");
		printf("유저\t: %i\n", user_score);
		printf("컴퓨터\t: %i\n\n", com_score);

		// 1이나 13이 나오면 게임 진행이 원활하게 되지 않기 때문에 배제
		printf("컴퓨터가 1 ~ 13 사이의 자연수를 추출합니다 [Left]...\n");
		left = rand() % 13 + 1;
		Sleep(2000);

		printf("컴퓨터가 1 ~ 13 사이의 자연수를 추출합니다 [Right]...\n\n");
		right = rand() % 13 + 1;
		Sleep(2000);

		printf("[Left: %i], [Right: ?]\n\n", left);

		printf("Left와 Right 중에서, 어느 것이 더 클까요?\n");
		printf("[1: Left] [2: Middle] [3: Right]\n");
		printf("입력 [1~3]: ");
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
				printf("win ! (유저가 +1점 획득)\n");
				user_score += 1;
			}
			else
			{
				printf("lose... (컴퓨터가 +2점 획득)\n");
				com_score += 2;
			}
			break;

		case 2:
			if (left == right)
			{
				printf("win ! (유저가 +4점 획득)\n");
				user_score += 4;
			}
			else
			{
				printf("lose... (컴퓨터가 +4점 획득)\n\n");
				com_score += 4;
			}
			break;

		default:
			Sleep(1000);
		}
		Sleep(2000);
		system("cls");
	}

	printf("<최종 결과>\n");
	printf("유저\t: %i\n", user_score);
	printf("컴퓨터\t: %i\n\n", com_score);

	if (user_score > com_score) printf("WIN !\n");
	else if (user_score < com_score) printf("LOSE...\n");
	else printf("DRAW.\n");

	return 0;
}