// 2022-05-31 실습2


#include <stdio.h>
#include <windows.h>
// windows.h: windows에서 제공하는 콘솔 명령어 및 랜덤값 명령어 등의 여러가지 명령을 제공하는 헤더.

int main()
{
	// srand 함수 <- srand(time())
	// 난수 시드(랜덤한 값을 어떻게 뽑을 지에 대한 설정)를 설정하는 함수.
	srand(time(NULL));

	// rand 함수(rand() % n)
	// 0부터 n-1까지의 랜덤한 숫자를(int형식) 뽑습니다.
	
	//// 난수 생성을 확인하기(Ctrl + C 누를 시 종료).
	//while (1)
	//{
	//	int random = rand() % 100;
	//	printf("뽑은 수: %i\n", random);
	//	Sleep(500);
	//}

	int user_score = 0;
	int com_score = 0;
	
	int state = rand() % 2;
	int input = 0;

	// 컴퓨터와 5번 대결을 하고 싶고,
	// 더 많이 이긴 쪽을 승자로 결정함.
	
	//1
	printf("<현재 스코어>\n");
	printf("나의 승점\t: %i\n", user_score);
	printf("컴퓨터 승점\t: %i\n\n", com_score);
	Sleep(500);

	printf("컴퓨터가 동전을 던졌습니다!\n");
	Sleep(500);

	printf("동전이 앞면인지, 뒷면인지 맞춰보세요!\n");
	printf("[0 : 뒷면], [1 : 앞면]\n\n");
	Sleep(500);

	printf("입력: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n동전 [ %s ] \n\n", state ? "앞면" : "뒷면");
	Sleep(500);

	if (input == state)
	{
		printf("정답입니다!\n");
		user_score += 1;
	}
	else
	{
		printf("오답입니다...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//2
	printf("<현재 스코어>\n");
	printf("나의 승점\t: %i\n", user_score);
	printf("컴퓨터 승점\t: %i\n\n", com_score);
	Sleep(500);

	printf("컴퓨터가 동전을 던졌습니다!\n");
	Sleep(500);

	printf("동전이 앞면인지, 뒷면인지 맞춰보세요!\n");
	printf("[0 : 뒷면], [1 : 앞면]\n\n");
	Sleep(500);

	printf("입력: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n동전 [ %s ] \n\n", state ? "앞면" : "뒷면");
	Sleep(500);

	if (input == state)
	{
		printf("정답입니다!\n");
		user_score += 1;
	}
	else
	{
		printf("오답입니다...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//3
	printf("<현재 스코어>\n");
	printf("나의 승점\t: %i\n", user_score);
	printf("컴퓨터 승점\t: %i\n\n", com_score);
	Sleep(500);

	printf("컴퓨터가 동전을 던졌습니다!\n");
	Sleep(500);

	printf("동전이 앞면인지, 뒷면인지 맞춰보세요!\n");
	printf("[0 : 뒷면], [1 : 앞면]\n\n");
	Sleep(500);

	printf("입력: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n동전 [ %s ] \n\n", state ? "앞면" : "뒷면");
	Sleep(500);

	if (input == state)
	{
		printf("정답입니다!\n");
		user_score += 1;
	}
	else
	{
		printf("오답입니다...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//4
	printf("<현재 스코어>\n");
	printf("나의 승점\t: %i\n", user_score);
	printf("컴퓨터 승점\t: %i\n\n", com_score);
	Sleep(500);

	printf("컴퓨터가 동전을 던졌습니다!\n");
	Sleep(500);

	printf("동전이 앞면인지, 뒷면인지 맞춰보세요!\n");
	printf("[0 : 뒷면], [1 : 앞면]\n\n");
	Sleep(500);

	printf("입력: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n동전 [ %s ] \n\n", state ? "앞면" : "뒷면");
	Sleep(500);

	if (input == state)
	{
		printf("정답입니다!\n");
		user_score += 1;
	}
	else
	{
		printf("오답입니다...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//5
	printf("<현재 스코어>\n");
	printf("나의 승점\t: %i\n", user_score);
	printf("컴퓨터 승점\t: %i\n\n", com_score);
	Sleep(500);

	printf("컴퓨터가 동전을 던졌습니다!\n\n");
	Sleep(500);

	printf("동전이 앞면인지, 뒷면인지 맞춰보세요!\n");
	printf("[0 : 뒷면], [1 : 앞면]\n\n");
	Sleep(500);

	printf("입력: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n동전 [ %s ] \n\n", state ? "앞면" : "뒷면");
	Sleep(500);

	if (input == state)
	{
		printf("정답입니다!\n");
		user_score += 1;
	}
	else
	{
		printf("오답입니다...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");
	Sleep(500);
	printf("최종 결과는 두구두구두구...\n");
	Sleep(2000);

	if (user_score > com_score) printf("야호! 승리하였습니다!\n");
	else printf("앗... 패배하였습니다...\n");

	return 0;
}