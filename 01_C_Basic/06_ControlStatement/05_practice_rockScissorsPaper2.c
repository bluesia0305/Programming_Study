// 2022-06-02 ���� ����(���� �ٸ��� § �ڵ�)
// -> if�� ���ǽ��� ���º�, �¸�, �й� 3������ ������ �ۼ��Ͽ���.


#include <stdio.h>
#include <windows.h>

int main()
{
	srand(time(NULL));
	int com_state = rand() % 3;
	int user_state;
	int com_score = 0;
	int user_score = 0;

	printf("�Է�: ");
	scanf_s("%i", &user_state);

	// 0: ����, 1: ����, 2: ��
	if (user_state == com_state) printf("���º�\n");
	else if ((user_state == 0 && com_state == 2) ||
		     (user_state == 1 && com_state == 0) ||
		     (user_state == 2 && com_state == 1))
	{
		printf("�¸�\n");
		user_score += 1;
	}
	else
	{
		printf("�й�\n");
		com_score += 1;
	}

	return 0;
}