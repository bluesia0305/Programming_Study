// 2022-06-02 과제 예시(나랑 다르게 짠 코드)
// -> if문 조건식을 무승부, 승리, 패배 3가지로 나누어 작성하였음.


#include <stdio.h>
#include <windows.h>

int main()
{
	srand(time(NULL));
	int com_state = rand() % 3;
	int user_state;
	int com_score = 0;
	int user_score = 0;

	printf("입력: ");
	scanf_s("%i", &user_state);

	// 0: 가위, 1: 바위, 2: 보
	if (user_state == com_state) printf("무승부\n");
	else if ((user_state == 0 && com_state == 2) ||
		     (user_state == 1 && com_state == 0) ||
		     (user_state == 2 && com_state == 1))
	{
		printf("승리\n");
		user_score += 1;
	}
	else
	{
		printf("패배\n");
		com_score += 1;
	}

	return 0;
}