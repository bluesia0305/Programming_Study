// 2022-05-31 과제


// 컴퓨터와 가위바위보를 5판 진행하여,
// 더 많이 이긴 쪽이 승리하는 프로그램을 만들어주세요(아래의 rule 참고).

// <Game rule>
// 1. 각 가위바위보 단판은 일반적인 가위바위보와 동일한 규칙.
// 2. 무승부가 났을 경우에도 게임의 횟수는 소요됨
// 3. 최종 결과는 승리, 패배, 무승부 중 하나로 처리됨.


#include <stdio.h>
#include <windows.h>

int main()
{
	srand(time(NULL));

	int user_score = 0;
	int com_score = 0;
	int user_state = 0;
	int com_state = 0;
	
	// 1
	printf("[ 가위바위보 게임 ] : 5번의 승부에서 컴퓨터를 이겨라!\n\n");
	printf("<현재 점수>\n");
	printf("나\t: %i 점.\n", user_score);
	printf("컴퓨터\t: %i 점.\n\n", com_score);
	Sleep(1000);

	printf("<1번째 게임>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("컴퓨터가 가위, 바위, 보 중에서 무엇을 낼 지 정했습니다.\n");
	Sleep(1000);

	printf("컴퓨터와 승부하기 위해 가위, 바위, 보를 숫자로 제시하세요.\n");
	Sleep(1000);
	printf("([0 : 가위], [1: 바위], [2: 보]).\n\n");
	Sleep(1000);
	printf("숫자 입력: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("나\t: 가위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("무승부입니다.\n");
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("나\t: 바위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("무승부입니다.\n");
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("나\t: 보\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("무승부입니다.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 2
	printf("[ 가위바위보 게임 ] : 5번의 승부에서 컴퓨터를 이겨라!\n\n");
	printf("<현재 점수>\n");
	printf("나\t: %i 점.\n", user_score);
	printf("컴퓨터\t: %i 점.\n\n", com_score);
	Sleep(1000);

	printf("<2번째 게임>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("컴퓨터가 가위, 바위, 보 중에서 무엇을 낼 지 정했습니다.\n");
	Sleep(1000);

	printf("컴퓨터와 승부하기 위해 가위, 바위, 보를 숫자로 제시하세요.\n");
	Sleep(1000);
	printf("([0 : 가위], [1: 바위], [2: 보]).\n\n");
	Sleep(1000);
	printf("숫자 입력: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("나\t: 가위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("무승부입니다.\n");
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("나\t: 바위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("무승부입니다.\n");
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("나\t: 보\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("무승부입니다.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 3
	printf("[ 가위바위보 게임 ] : 5번의 승부에서 컴퓨터를 이겨라!\n\n");
	printf("<현재 점수>\n");
	printf("나\t: %i 점.\n", user_score);
	printf("컴퓨터\t: %i 점.\n\n", com_score);
	Sleep(1000);

	printf("<3번째 게임>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("컴퓨터가 가위, 바위, 보 중에서 무엇을 낼 지 정했습니다.\n");
	Sleep(1000);

	printf("컴퓨터와 승부하기 위해 가위, 바위, 보를 숫자로 제시하세요.\n");
	Sleep(1000);
	printf("([0 : 가위], [1: 바위], [2: 보]).\n\n");
	Sleep(1000);
	printf("숫자 입력: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("나\t: 가위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("무승부입니다.\n");
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("나\t: 바위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("무승부입니다.\n");
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("나\t: 보\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("무승부입니다.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 4
	printf("[ 가위바위보 게임 ] : 5번의 승부에서 컴퓨터를 이겨라!\n\n");
	printf("<현재 점수>\n");
	printf("나\t: %i 점.\n", user_score);
	printf("컴퓨터\t: %i 점.\n\n", com_score);
	Sleep(1000);

	printf("<4번째 게임>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("컴퓨터가 가위, 바위, 보 중에서 무엇을 낼 지 정했습니다.\n");
	Sleep(1000);

	printf("컴퓨터와 승부하기 위해 가위, 바위, 보를 숫자로 제시하세요.\n");
	Sleep(1000);
	printf("([0 : 가위], [1: 바위], [2: 보]).\n\n");
	Sleep(1000);
	printf("숫자 입력: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("나\t: 가위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("무승부입니다.\n");
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("나\t: 바위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("무승부입니다.\n");
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("나\t: 보\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("무승부입니다.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 5
	printf("[ 가위바위보 게임 ] : 5번의 승부에서 컴퓨터를 이겨라!\n\n");
	printf("<현재 점수>\n");
	printf("나\t: %i 점.\n", user_score);
	printf("컴퓨터\t: %i 점.\n\n", com_score);
	Sleep(1000);

	printf("<5번째 게임>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("컴퓨터가 가위, 바위, 보 중에서 무엇을 낼 지 정했습니다.\n");
	Sleep(1000);

	printf("컴퓨터와 승부하기 위해 가위, 바위, 보를 숫자로 제시하세요.\n");
	Sleep(1000);
	printf("([0 : 가위], [1: 바위], [2: 보]).\n\n");
	Sleep(1000);
	printf("숫자 입력: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("나\t: 가위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("무승부입니다.\n");
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("나\t: 바위\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("무승부입니다.\n");
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("나\t: 보\n");
		if (com_state == 0)
		{
			printf("컴퓨터\t: 가위\n\n");
			printf("컴퓨터가 이번 게임에서 이겼습니다.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("컴퓨터\t: 바위\n\n");
			printf("내가 이번 게임에서 이겼습니다.\n");
			user_score += 1;
		}
		else
		{
			printf("컴퓨터\t: 보\n\n");
			printf("무승부입니다.\n");
		}
	}
	Sleep(2000);
	system("cls");


	// 게임 5회 진행 후 최종 결과 발표
	printf("최종 결과는? 두구두구두구...\n\n");
	Sleep(2000);

	printf("나\t: %i 점.\n", user_score);
	printf("컴퓨터\t: %i 점.\n\n", com_score);
	Sleep(1000);

	if (user_score > com_score) printf("야호! 승리하였습니다!\n");
	else if (user_score < com_score) printf("앗... 패배하였습니다...\n");
	else printf("이런, 무승부입니다.\n");

	return 0;
}