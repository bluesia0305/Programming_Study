// 2022-06-17 ����
// ����� ������ 5�� 3�������� �����ϴ� ���α׷��� ������ּ���.

#include <iostream>
#include <Windows.h>

int draw(int i, int rspResult, int pScore, int cScore)
{
	int state = 0;
	while (state < 1 || state > 3)
	{
		system("cls");
		std::cout << "<" << i << "��° ����>" << std::endl;
		std::cout << "- ���� ����    : " << pScore << "��" << std::endl;
		std::cout << "- ��ǻ���� ����: " << cScore << "��" << std::endl;
		std::cout << "============================================" << std::endl;
		if (rspResult == 0) std::cout << "* Phase 1) ������ ���ϱ� (����������)" << std::endl;
		else
		{
			std::cout << "* Phase 2) ����� ���� (";
			std::cout << "���� ���ݱ�: " << ((rspResult - 1) ? "��ǻ��)" : "��)") << std::endl;
		}
		std::cout << "============================================" << std::endl;
		std::cout << "[1: ��] [2: ��] [3: ��] �߿��� ������ ����?" << std::endl;
		std::cout << "�Է� >> ";
		std::cin >> state;
	}
	return state;
}

void convertState(int state)
{
	if (state == 1) std::cout << "��";
	else if (state == 2) std::cout << "��";
	else std::cout << "��";
}

void printState(int pState, int cState)
{
	std::cout << std::endl;
	std::cout << "����, ";
	Sleep(500);
	std::cout << "����, ";
	Sleep(500);
	std::cout << "��!" << std::endl << std::endl;

	std::cout << "��    : ";
	convertState(pState);
	std::cout << std::endl;

	std::cout << "��ǻ��: ";
	convertState(cState);
	std::cout << std::endl << std::endl;
	Sleep(500);
}

void printState2(int rspResult, int pState, int pState_new, int cState, int cState_new)
{
	std::cout << std::endl;
	std::cout << ((rspResult - 1) ? "��ǻ��: " : "��    : ");
	for (int i = 0; i < 2; i++)
	{
		convertState((rspResult - 1) ? cState : pState);
		std::cout << "��, ";
		Sleep(500);
	}
	convertState((rspResult - 1) ? cState_new : pState_new);
	std::cout << " !" << std::endl;

	std::cout << ((rspResult - 1) ? "��    : " : "��ǻ��: ");
	convertState((rspResult - 1) ? pState_new : cState_new);
	std::cout << std::endl << std::endl;
	Sleep(1000);
}

int rspLogic(int pState, int cState)
{
	int result;
	if (pState == cState) { result = 0; }
	else if ((pState == 1 && cState == 2) ||
		     (pState == 2 && cState == 3) ||
	         (pState == 3 && cState == 1)) { result = 1; }
	else { result = 2; }
	return result;
}

int main()
{
	srand(time(NULL));
	const int winScore = 3;
	int pScore = 0;
	int cScore = 0;
	int rspResult;			// ���������� ��� �� ���ݱ� ������ ǥ�� (0: ���º� or ������ ����(�ʱⰪ), 1: ��, 2: ��ǻ��)
	int pState;				// ���� ����� ���� ���� (1: ��, 2: ��, 3: ��)
	int cState;				// ��ǻ�� ����� ���� ���� (1: ��, 2: ��, 3: ��)
	int rspResult_new;
	int pState_new;
	int cState_new;

	int i = 1;
	while (pScore < winScore && cScore < winScore)
	{
		rspResult = 0;
		while (!rspResult)
		{
			pState = draw(i, rspResult, pScore, cScore);
			cState = (rand() % 3) + 1;
			Sleep(500);

			printState(pState, cState);
			Sleep(500);

			rspResult = rspLogic(pState, cState);
			switch (rspResult)
			{
			case 1:
				std::cout << "������ ---> ��";
				break;
			case 2:
				std::cout << "������ ---> ��ǻ��";
				break;
			default:
				std::cout << "���º� ---> �������� ������ ���� ������������ �ٽ� �մϴ�...";
			}
			Sleep(500);
			std::cout << std::endl << std::endl;
			system("pause");
		}

		while (rspResult)
		{
			pState_new = draw(i, rspResult, pScore, cScore);
			cState_new = (rand() % 3) + 1;
			Sleep(500);

			printState2(rspResult, pState, pState_new, cState, cState_new);
			Sleep(500);

			rspResult_new = rspLogic(pState_new, cState_new);
			switch (rspResult_new)
			{
			case 1: case 2:	break;
			default:
				i++;
				if (rspResult == 1)
				{
					std::cout << "���� ���� !" << std::endl;
					pScore++;
				}
				else
				{
					std::cout << "��ǻ���� ����..." << std::endl;
					cScore++;
				}
				Sleep(500);

				if (pScore < winScore && cScore < winScore)
				{
					std::cout << "(���ڰ� �߻��Ͽ� ���� �������� �Ѿ�ϴ�.)" << std::endl;
				}
				else std::cout << "(3�����ڰ� ������ ��⸦ �����մϴ�.)" << std::endl;
				Sleep(500);
			}

			if (rspResult_new != 0)
			{
				if (rspResult != rspResult_new)
				{
					std::cout << "(���ݱ��� \'" << ((rspResult_new - 1) ? "��ǻ��" : "��") << "\'���Է� ����˴ϴ�.)" << std::endl;
				}
				else
				{
					std::cout << "(���� ���ݱ��� ��� �����˴ϴ�.)" << std::endl;
				}
			}
			std::cout << std::endl;
			Sleep(500);

			rspResult = rspResult_new;
			pState = pState_new;
			cState = cState_new;
			system("pause");
		}
		
	}
	system("cls");
	std::cout << "<���� ���>" << std::endl << std::endl;
	if (pScore == winScore) std::cout << "���� �¸� !" << std::endl;
	else std::cout << "��ǻ���� �¸�..." << std::endl;

	return 0;
}