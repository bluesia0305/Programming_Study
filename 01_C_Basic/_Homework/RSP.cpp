#include <iostream>
#include <string>
#include <Windows.h>
#pragma warning (disable : 4996)

// enum class: ������ ���
//             ������(���) �����Ϳ� ���� �ĺ��ڸ� ������.
enum class State
{
	ROCK = 1,		// �⺻���� ������ ������ State::ROCK == 0; ���� �����ϰ�
	SCISSOR,		// ������ State::SCISSOR == 1; , State::PAPER == 2; �� ���� 1�� �����Ͽ� �ڵ� ������.
	PAPER
};

State ComputerRSP()
{
	static State rsp[3] = { State::ROCK, State::SCISSOR, State::PAPER };
	unsigned random = rand() % 3;

	switch (random)
	{
	case 0: printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
		break;
	case 1: printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
		break;
	case 2: printf("��ǻ�ʹ� ���� �½��ϴ�.\n");
		break;
	}
	return rsp[random];
}

State PlayerRSP()
{
	while (1)
	{
		char input[32] = "";
		printf("�Է�: ");
		scanf("%s", input);
		system("cls");

		if (!strcmp(input, "����")) return State::SCISSOR;
		else if (!strcmp(input, "����")) return State::ROCK;
		else if (!strcmp(input, "��")) return State::PAPER;
		else
		{
			printf("���� �߸� �Է��ϼ̽��ϴ�.\n");
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
	//srand(time(NULL));		// ���� �ð��� �������� ���� �õ� ����.
	srand(GetTickCount64());	// ���α׷��� ������ ���� ���� �ð��� �������� ���� �õ� ����.
	Result result;
	bool flag;
	unsigned score[2] = { 0 };

	while ((score[0] < 3) && (score[1] < 3))
	{
		printf("������������ �����մϴ�.\n");
		while (1)
		{
			result = RSP(ComputerRSP(), PlayerRSP());	// stack ���� ������ PlayerRSP�� ���� ����� (�ں��� ����).
			switch (result)
			{
			case Result::WIN:
				printf("�÷��̾��� �����Դϴ�.\n");
				flag = 1;
				break;
			case Result::LOSE:
				printf("��ǻ���� �����Դϴ�.\n");
				flag = 0;
				break;
			default:
				printf("���º��Դϴ�.\n");
				Sleep(1000);
				system("cls");
			}
		}
	}
	Sleep(1000);

	printf("������� �����մϴ�.\n");
	while (1)
	{
		result = Match(ComputerRSP(), PlayerRSP(), &flag);
		if (result == Result::WIN)
		{
			printf("�÷��̾ �̹� ������ �̰���ϴ�.\n");
			score[0]++;
			break;
		}
		else
		{
			printf("��ǻ�Ͱ� �̹� ������ �̰���ϴ�.\n");
			score[1]++;
			break;
		}
		Sleep(1000);
	}

	if (score[0] > score[1]) printf("�÷��̾��� �¸��Դϴ�.\n");
	else printf("��ǻ���� �¸��Դϴ�.\n");

	return 0;
}