// 2022-05-31 ����


// ��ǻ�Ϳ� ������������ 5�� �����Ͽ�,
// �� ���� �̱� ���� �¸��ϴ� ���α׷��� ������ּ���(�Ʒ��� rule ����).

// <Game rule>
// 1. �� ���������� ������ �Ϲ����� ������������ ������ ��Ģ.
// 2. ���ºΰ� ���� ��쿡�� ������ Ƚ���� �ҿ��
// 3. ���� ����� �¸�, �й�, ���º� �� �ϳ��� ó����.


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
	printf("[ ���������� ���� ] : 5���� �ºο��� ��ǻ�͸� �̰ܶ�!\n\n");
	printf("<���� ����>\n");
	printf("��\t: %i ��.\n", user_score);
	printf("��ǻ��\t: %i ��.\n\n", com_score);
	Sleep(1000);

	printf("<1��° ����>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("��ǻ�Ͱ� ����, ����, �� �߿��� ������ �� �� ���߽��ϴ�.\n");
	Sleep(1000);

	printf("��ǻ�Ϳ� �º��ϱ� ���� ����, ����, ���� ���ڷ� �����ϼ���.\n");
	Sleep(1000);
	printf("([0 : ����], [1: ����], [2: ��]).\n\n");
	Sleep(1000);
	printf("���� �Է�: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("��\t: ��\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���º��Դϴ�.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 2
	printf("[ ���������� ���� ] : 5���� �ºο��� ��ǻ�͸� �̰ܶ�!\n\n");
	printf("<���� ����>\n");
	printf("��\t: %i ��.\n", user_score);
	printf("��ǻ��\t: %i ��.\n\n", com_score);
	Sleep(1000);

	printf("<2��° ����>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("��ǻ�Ͱ� ����, ����, �� �߿��� ������ �� �� ���߽��ϴ�.\n");
	Sleep(1000);

	printf("��ǻ�Ϳ� �º��ϱ� ���� ����, ����, ���� ���ڷ� �����ϼ���.\n");
	Sleep(1000);
	printf("([0 : ����], [1: ����], [2: ��]).\n\n");
	Sleep(1000);
	printf("���� �Է�: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("��\t: ��\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���º��Դϴ�.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 3
	printf("[ ���������� ���� ] : 5���� �ºο��� ��ǻ�͸� �̰ܶ�!\n\n");
	printf("<���� ����>\n");
	printf("��\t: %i ��.\n", user_score);
	printf("��ǻ��\t: %i ��.\n\n", com_score);
	Sleep(1000);

	printf("<3��° ����>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("��ǻ�Ͱ� ����, ����, �� �߿��� ������ �� �� ���߽��ϴ�.\n");
	Sleep(1000);

	printf("��ǻ�Ϳ� �º��ϱ� ���� ����, ����, ���� ���ڷ� �����ϼ���.\n");
	Sleep(1000);
	printf("([0 : ����], [1: ����], [2: ��]).\n\n");
	Sleep(1000);
	printf("���� �Է�: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("��\t: ��\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���º��Դϴ�.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 4
	printf("[ ���������� ���� ] : 5���� �ºο��� ��ǻ�͸� �̰ܶ�!\n\n");
	printf("<���� ����>\n");
	printf("��\t: %i ��.\n", user_score);
	printf("��ǻ��\t: %i ��.\n\n", com_score);
	Sleep(1000);

	printf("<4��° ����>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("��ǻ�Ͱ� ����, ����, �� �߿��� ������ �� �� ���߽��ϴ�.\n");
	Sleep(1000);

	printf("��ǻ�Ϳ� �º��ϱ� ���� ����, ����, ���� ���ڷ� �����ϼ���.\n");
	Sleep(1000);
	printf("([0 : ����], [1: ����], [2: ��]).\n\n");
	Sleep(1000);
	printf("���� �Է�: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("��\t: ��\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���º��Դϴ�.\n");
		}
	}
	Sleep(1000);
	system("cls");

	// 5
	printf("[ ���������� ���� ] : 5���� �ºο��� ��ǻ�͸� �̰ܶ�!\n\n");
	printf("<���� ����>\n");
	printf("��\t: %i ��.\n", user_score);
	printf("��ǻ��\t: %i ��.\n\n", com_score);
	Sleep(1000);

	printf("<5��° ����>\n");
	Sleep(1000);

	com_state = rand() % 3;
	printf("��ǻ�Ͱ� ����, ����, �� �߿��� ������ �� �� ���߽��ϴ�.\n");
	Sleep(1000);

	printf("��ǻ�Ϳ� �º��ϱ� ���� ����, ����, ���� ���ڷ� �����ϼ���.\n");
	Sleep(1000);
	printf("([0 : ����], [1: ����], [2: ��]).\n\n");
	Sleep(1000);
	printf("���� �Է�: ");
	scanf_s("%i", &user_state);
	Sleep(2000);
	printf("\n");
	if (user_state == 0)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
	}
	else if (user_state == 1)
	{
		printf("��\t: ����\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���º��Դϴ�.\n");
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
	}
	else
	{
		printf("��\t: ��\n");
		if (com_state == 0)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("��ǻ�Ͱ� �̹� ���ӿ��� �̰���ϴ�.\n");
			com_score += 1;
		}
		else if (com_state == 1)
		{
			printf("��ǻ��\t: ����\n\n");
			printf("���� �̹� ���ӿ��� �̰���ϴ�.\n");
			user_score += 1;
		}
		else
		{
			printf("��ǻ��\t: ��\n\n");
			printf("���º��Դϴ�.\n");
		}
	}
	Sleep(2000);
	system("cls");


	// ���� 5ȸ ���� �� ���� ��� ��ǥ
	printf("���� �����? �α��α��α�...\n\n");
	Sleep(2000);

	printf("��\t: %i ��.\n", user_score);
	printf("��ǻ��\t: %i ��.\n\n", com_score);
	Sleep(1000);

	if (user_score > com_score) printf("��ȣ! �¸��Ͽ����ϴ�!\n");
	else if (user_score < com_score) printf("��... �й��Ͽ����ϴ�...\n");
	else printf("�̷�, ���º��Դϴ�.\n");

	return 0;
}