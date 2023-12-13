// 2022-06-17 과제
// 묵찌빠 게임을 5판 3선승제로 진행하는 프로그램을 만들어주세요.

#include <iostream>
#include <Windows.h>

void converter(int state)
{
	if (state == 1) std::cout << "묵";
	else if (state == 2) std::cout << "찌";
	else std::cout << "빠";
	std::cout << std::endl;
}

int draw(int i, int flag, int pScore, int cScore)
{
	int state = 0;
	while (state < 1 || state > 3)
	{
		system("cls");
		if (flag == 0) std::cout << "<선공권 정하기: 가위바위보>" << std::endl;
		else
		{
			std::cout << "<묵찌빠 게임: " << i << "번째 게임>" << std::endl;
			std::cout << "- 나의 점수    : " << pScore << "점" << std::endl;
			std::cout << "- 컴퓨터의 점수: " << cScore << "점" << std::endl;
			std::cout << std::endl;
			std::cout << "* 현재 공격권: " << ((flag - 1) ? "컴퓨터" : "나") << std::endl;
		}
		std::cout << std::endl;
		std::cout << "[1: 묵] [2: 찌] [3: 빠]" << std::endl;
		std::cout << "입력 [1, 2, 3]: ";
		std::cin >> state;
	}
	return state;
}

void printState(int pState, int cState)
{
	std::cout << std::endl;
	std::cout << "나 : ";
	converter(pState);
	std::cout << "컴퓨터: ";
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
	int flag = 0;		// 공격권 보유 상태 (1: 나, 2: 컴퓨터)
	int pState;			// 나의 묵찌빠 선택 상태 (1: 묵, 2: 찌, 3: 빠)
	int cState;			// 컴퓨터 묵찌빠 선택 상태 (1: 묵, 2: 찌, 3: 빠)

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
			std::cout << "선공권 -> 나" << std::endl;
			flag = 1;
			break;
		case 2:
			std::cout << "선공권 -> 컴퓨터" << std::endl;
			flag = 2;
			break;
		default:
			std::cout << "무승부 (-> 선공권을 가리기 위해 재경기)";
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
				std::cout << "나의 득점 !" << std::endl;
				pScore++;
			}
			else
			{
				std::cout << "컴퓨터의 득점..." << std::endl;
				cScore++;
			}
			flag_new = flag;
			Sleep(500);
		}

		if (flag != flag_new)
		{
			std::cout << "공격권이 변경됩니다." << std::endl;
			Sleep(500);
			if (flag_new == 1) std::cout << "공격권 -> 나" << std::endl;
			else std::cout << "공격권 -> 컴퓨터" << std::endl;
			Sleep(1500);
		}
		else
		{
			std::cout << "공격권이 유지됩니다." << std::endl;
			Sleep(1500);
		}
		flag = flag_new;
	}

	system("cls");
	std::cout << "최종 결과:" << std::endl;
	std::cout << std::endl;
	if (pScore == winScore) std::cout << "나의 승리 !" << std::endl;
	else std::cout << "컴퓨터의 승리..." << std::endl;

	return 0;
}