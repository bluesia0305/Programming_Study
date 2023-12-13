// 2022-06-17 과제
// 묵찌빠 게임을 5판 3선승제로 진행하는 프로그램을 만들어주세요.

#include <iostream>
#include <Windows.h>

int draw(int i, int rspResult, int pScore, int cScore)
{
	int state = 0;
	while (state < 1 || state > 3)
	{
		system("cls");
		std::cout << "<" << i << "번째 게임>" << std::endl;
		std::cout << "- 나의 점수    : " << pScore << "점" << std::endl;
		std::cout << "- 컴퓨터의 점수: " << cScore << "점" << std::endl;
		std::cout << "============================================" << std::endl;
		if (rspResult == 0) std::cout << "* Phase 1) 선공권 정하기 (가위바위보)" << std::endl;
		else
		{
			std::cout << "* Phase 2) 묵찌빠 게임 (";
			std::cout << "현재 공격권: " << ((rspResult - 1) ? "컴퓨터)" : "나)") << std::endl;
		}
		std::cout << "============================================" << std::endl;
		std::cout << "[1: 묵] [2: 찌] [3: 빠] 중에서 무엇을 낼까?" << std::endl;
		std::cout << "입력 >> ";
		std::cin >> state;
	}
	return state;
}

void convertState(int state)
{
	if (state == 1) std::cout << "묵";
	else if (state == 2) std::cout << "찌";
	else std::cout << "빠";
}

void printState(int pState, int cState)
{
	std::cout << std::endl;
	std::cout << "가위, ";
	Sleep(500);
	std::cout << "바위, ";
	Sleep(500);
	std::cout << "보!" << std::endl << std::endl;

	std::cout << "나    : ";
	convertState(pState);
	std::cout << std::endl;

	std::cout << "컴퓨터: ";
	convertState(cState);
	std::cout << std::endl << std::endl;
	Sleep(500);
}

void printState2(int rspResult, int pState, int pState_new, int cState, int cState_new)
{
	std::cout << std::endl;
	std::cout << ((rspResult - 1) ? "컴퓨터: " : "나    : ");
	for (int i = 0; i < 2; i++)
	{
		convertState((rspResult - 1) ? cState : pState);
		std::cout << "에, ";
		Sleep(500);
	}
	convertState((rspResult - 1) ? cState_new : pState_new);
	std::cout << " !" << std::endl;

	std::cout << ((rspResult - 1) ? "나    : " : "컴퓨터: ");
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
	int rspResult;			// 가위바위보 결과 및 공격권 보유자 표시 (0: 무승부 or 선공권 없음(초기값), 1: 나, 2: 컴퓨터)
	int pState;				// 나의 묵찌빠 선택 상태 (1: 묵, 2: 찌, 3: 빠)
	int cState;				// 컴퓨터 묵찌빠 선택 상태 (1: 묵, 2: 찌, 3: 빠)
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
				std::cout << "선공권 ---> 나";
				break;
			case 2:
				std::cout << "선공권 ---> 컴퓨터";
				break;
			default:
				std::cout << "무승부 ---> 선공권을 가리기 위해 가위바위보를 다시 합니다...";
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
					std::cout << "나의 득점 !" << std::endl;
					pScore++;
				}
				else
				{
					std::cout << "컴퓨터의 득점..." << std::endl;
					cScore++;
				}
				Sleep(500);

				if (pScore < winScore && cScore < winScore)
				{
					std::cout << "(승자가 발생하여 다음 게임으로 넘어갑니다.)" << std::endl;
				}
				else std::cout << "(3선승자가 정해져 경기를 종료합니다.)" << std::endl;
				Sleep(500);
			}

			if (rspResult_new != 0)
			{
				if (rspResult != rspResult_new)
				{
					std::cout << "(공격권이 \'" << ((rspResult_new - 1) ? "컴퓨터" : "나") << "\'에게로 변경됩니다.)" << std::endl;
				}
				else
				{
					std::cout << "(현재 공격권이 계속 유지됩니다.)" << std::endl;
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
	std::cout << "<최종 결과>" << std::endl << std::endl;
	if (pScore == winScore) std::cout << "나의 승리 !" << std::endl;
	else std::cout << "컴퓨터의 승리..." << std::endl;

	return 0;
}