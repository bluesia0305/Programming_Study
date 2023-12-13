// 2022-06-17 ����
// ����� ������ 5�� 3�������� �����ϴ� ���α׷��� ������ּ���.

#include <iostream>
#include <Windows.h>

void converter(int state)
{
	if (state == 1) std::cout << "��";
	else if (state == 2) std::cout << "��";
	else std::cout << "��";
	std::cout << std::endl;
}

int draw(int i, int flag, int pScore, int cScore)
{
	int state = 0;
	while (state < 1 || state > 3)
	{
		system("cls");
		if (flag == 0) std::cout << "<������ ���ϱ�: ����������>" << std::endl;
		else
		{
			std::cout << "<����� ����: " << i << "��° ����>" << std::endl;
			std::cout << "- ���� ����    : " << pScore << "��" << std::endl;
			std::cout << "- ��ǻ���� ����: " << cScore << "��" << std::endl;
			std::cout << std::endl;
			std::cout << "* ���� ���ݱ�: " << ((flag - 1) ? "��ǻ��" : "��") << std::endl;
		}
		std::cout << std::endl;
		std::cout << "[1: ��] [2: ��] [3: ��]" << std::endl;
		std::cout << "�Է� [1, 2, 3]: ";
		std::cin >> state;
	}
	return state;
}

void printState(int pState, int cState)
{
	std::cout << std::endl;
	std::cout << "�� : ";
	converter(pState);
	std::cout << "��ǻ��: ";
	converter(cState);
	std::cout << std::endl;
	Sleep(500);
}

int rspGame(int pState, int cState)
{
	int result;
	if (pState == cState) { result = 0; }
	else if ((pState == 1 && cState == 2) ||
		     (pState == 2 && cState == 3) ||
		     (pState == 3 && cState == 1)){ result = 1; }
	else { result = 2; }
	return result;
}

int main()
{
	srand(time(NULL));
	const int winScore = 3;
	int pScore = 0;
	int cScore = 0;
	int flag = 0;		// ���ݱ� ���� ���� (1: ��, 2: ��ǻ��)
	int pState;			// ���� ����� ���� ���� (1: ��, 2: ��, 3: ��)
	int cState;			// ��ǻ�� ����� ���� ���� (1: ��, 2: ��, 3: ��)

	while (!flag)
	{
		pState = draw(0, flag, pScore, cScore);
		cState = rand() % 3;
		Sleep(500);

		printState(pState, cState);
		Sleep(500);

		switch (rspGame(pState, cState))
		{
		case 1:
			std::cout << "������ -> ��" << std::endl;
			flag = 1;
			break;
		case 2:
			std::cout << "������ -> ��ǻ��" << std::endl;
			flag = 2;
			break;
		default:
			std::cout << "���º� (-> �������� ������ ���� ����)";
		}
		Sleep(1500);
	}

	int i = 1;
	while (pScore < winScore && cScore < winScore)
	{
		int flag_new;

		pState = draw(i, flag, pScore, cScore);
		cState = rand() % 3;
		Sleep(500);

		printState(pState, cState);
		Sleep(500);

		switch (rspGame(pState, cState))
		{
		case 1:
			flag_new = 1;
			break;
		case 2:
			flag_new = 2;
			break;
		default:
			i++;
			if (flag == 1)
			{
				std::cout << "���� ���� !" << std::endl;
				pScore++;
			}
			else
			{
				std::cout << "��ǻ���� ����..." << std::endl;
				cScore++;
			}
			flag_new = flag;
			Sleep(500);
		}

		if (flag != flag_new)
		{
			std::cout << "���ݱ��� ����˴ϴ�." << std::endl;
			Sleep(500);
			if (flag_new == 1) std::cout << "���ݱ� -> ��" << std::endl;
			else std::cout << "���ݱ� -> ��ǻ��" << std::endl;
			Sleep(1500);
		}
		else
		{
			std::cout << "���ݱ��� �����˴ϴ�." << std::endl;
			Sleep(1500);
		}
		flag = flag_new;
	}

	system("cls");
	std::cout << "���� ���:" << std::endl;
	std::cout << std::endl;
	if (pScore == winScore) std::cout << "���� �¸� !" << std::endl;
	else std::cout << "��ǻ���� �¸�..." << std::endl;

	return 0;
}