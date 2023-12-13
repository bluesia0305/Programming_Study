#include <iostream>
#include <string>
#include <Windows.h>
#pragma warning (disable : 4996)

// enum class: 열거형 방식
//             정수형(양수) 데이터에 대한 식별자를 지정함.
enum class State
{
	ROCK = 1,		// 기본값을 정하지 않으면 State::ROCK == 0; 부터 시작하고
	SCISSOR,		// 이후의 State::SCISSOR == 1; , State::PAPER == 2; 와 같이 1씩 증가하여 자동 지정됨.
	PAPER
};

State ComputerRSP()
{
	static State rsp[3] = { State::ROCK, State::SCISSOR, State::PAPER };
	unsigned random = rand() % 3;

	switch (random)
	{
	case 0: printf("컴퓨터는 바위를 냈습니다.\n");
		break;
	case 1: printf("컴퓨터는 가위를 냈습니다.\n");
		break;
	case 2: printf("컴퓨터는 보를 냈습니다.\n");
		break;
	}
	return rsp[random];
}

State PlayerRSP()
{
	while (1)
	{
		char input[32] = "";
		printf("입력: ");
		scanf("%s", input);
		system("cls");

		if (!strcmp(input, "가위")) return State::SCISSOR;
		else if (!strcmp(input, "바위")) return State::ROCK;
		else if (!strcmp(input, "보")) return State::PAPER;
		else
		{
			printf("값을 잘못 입력하셨습니다.\n");
			Sleep(500);
			system("cls");
			continue;
		}
	}
}

enum class Result
{
	WIN,
	LOSE,
	DRAW
};

Result RSP(State computer, State player)
{
	if (player == computer) return Result::DRAW;
	else if ((player == State::ROCK && computer == State::SCISSOR) ||
		     (player == State::SCISSOR && computer == State::PAPER) ||
		     (player == State::PAPER && computer == State::ROCK))
	{
		return Result::WIN;
	}
	else return Result::LOSE;
}

Result Match(State computer, State player, bool* p)
{
	if (player == computer)
	{
		if (*p) return Result::WIN;
		else return Result::LOSE;
	}
	else if ((player == State::ROCK && computer == State::SCISSOR) ||
		(player == State::SCISSOR && computer == State::PAPER) ||
		(player == State::PAPER && computer == State::ROCK)) { *p = 1; }
	else { *p = 0; };
	
	return Result::DRAW;
}

int main()
{
	//srand(time(NULL));		// 현재 시간을 기준으로 난수 시드 생성.
	srand(GetTickCount64());	// 프로그램이 시작한 이후 지난 시간을 기준으로 난수 시드 생성.
	Result result;
	bool flag;
	unsigned score[2] = { 0 };

	while ((score[0] < 3) && (score[1] < 3))
	{
		printf("가위바위보를 시작합니다.\n");
		while (1)
		{
			result = RSP(ComputerRSP(), PlayerRSP());	// stack 연산 순서상 PlayerRSP가 먼저 실행됨 (뒤부터 실행).
			switch (result)
			{
			case Result::WIN:
				printf("플레이어의 선공입니다.\n");
				flag = 1;
				break;
			case Result::LOSE:
				printf("컴퓨터의 선공입니다.\n");
				flag = 0;
				break;
			default:
				printf("무승부입니다.\n");
				Sleep(1000);
				system("cls");
			}
		}
	}
	Sleep(1000);

	printf("묵찌빠를 시작합니다.\n");
	while (1)
	{
		result = Match(ComputerRSP(), PlayerRSP(), &flag);
		if (result == Result::WIN)
		{
			printf("플레이어가 이번 게임을 이겼습니다.\n");
			score[0]++;
			break;
		}
		else
		{
			printf("컴퓨터가 이번 게임을 이겼습니다.\n");
			score[1]++;
			break;
		}
		Sleep(1000);
	}

	if (score[0] > score[1]) printf("플레이어의 승리입니다.\n");
	else printf("컴퓨터의 승리입니다.\n");

	return 0;
}