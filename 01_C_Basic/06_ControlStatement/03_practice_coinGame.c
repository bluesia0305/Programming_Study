// 2022-05-31 �ǽ�2


#include <stdio.h>
#include <windows.h>
// windows.h: windows���� �����ϴ� �ܼ� ��ɾ� �� ������ ��ɾ� ���� �������� ����� �����ϴ� ���.

int main()
{
	// srand �Լ� <- srand(time())
	// ���� �õ�(������ ���� ��� ���� ���� ���� ����)�� �����ϴ� �Լ�.
	srand(time(NULL));

	// rand �Լ�(rand() % n)
	// 0���� n-1������ ������ ���ڸ�(int����) �̽��ϴ�.
	
	//// ���� ������ Ȯ���ϱ�(Ctrl + C ���� �� ����).
	//while (1)
	//{
	//	int random = rand() % 100;
	//	printf("���� ��: %i\n", random);
	//	Sleep(500);
	//}

	int user_score = 0;
	int com_score = 0;
	
	int state = rand() % 2;
	int input = 0;

	// ��ǻ�Ϳ� 5�� ����� �ϰ� �Ͱ�,
	// �� ���� �̱� ���� ���ڷ� ������.
	
	//1
	printf("<���� ���ھ�>\n");
	printf("���� ����\t: %i\n", user_score);
	printf("��ǻ�� ����\t: %i\n\n", com_score);
	Sleep(500);

	printf("��ǻ�Ͱ� ������ �������ϴ�!\n");
	Sleep(500);

	printf("������ �ո�����, �޸����� ���纸����!\n");
	printf("[0 : �޸�], [1 : �ո�]\n\n");
	Sleep(500);

	printf("�Է�: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n���� [ %s ] \n\n", state ? "�ո�" : "�޸�");
	Sleep(500);

	if (input == state)
	{
		printf("�����Դϴ�!\n");
		user_score += 1;
	}
	else
	{
		printf("�����Դϴ�...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//2
	printf("<���� ���ھ�>\n");
	printf("���� ����\t: %i\n", user_score);
	printf("��ǻ�� ����\t: %i\n\n", com_score);
	Sleep(500);

	printf("��ǻ�Ͱ� ������ �������ϴ�!\n");
	Sleep(500);

	printf("������ �ո�����, �޸����� ���纸����!\n");
	printf("[0 : �޸�], [1 : �ո�]\n\n");
	Sleep(500);

	printf("�Է�: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n���� [ %s ] \n\n", state ? "�ո�" : "�޸�");
	Sleep(500);

	if (input == state)
	{
		printf("�����Դϴ�!\n");
		user_score += 1;
	}
	else
	{
		printf("�����Դϴ�...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//3
	printf("<���� ���ھ�>\n");
	printf("���� ����\t: %i\n", user_score);
	printf("��ǻ�� ����\t: %i\n\n", com_score);
	Sleep(500);

	printf("��ǻ�Ͱ� ������ �������ϴ�!\n");
	Sleep(500);

	printf("������ �ո�����, �޸����� ���纸����!\n");
	printf("[0 : �޸�], [1 : �ո�]\n\n");
	Sleep(500);

	printf("�Է�: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n���� [ %s ] \n\n", state ? "�ո�" : "�޸�");
	Sleep(500);

	if (input == state)
	{
		printf("�����Դϴ�!\n");
		user_score += 1;
	}
	else
	{
		printf("�����Դϴ�...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//4
	printf("<���� ���ھ�>\n");
	printf("���� ����\t: %i\n", user_score);
	printf("��ǻ�� ����\t: %i\n\n", com_score);
	Sleep(500);

	printf("��ǻ�Ͱ� ������ �������ϴ�!\n");
	Sleep(500);

	printf("������ �ո�����, �޸����� ���纸����!\n");
	printf("[0 : �޸�], [1 : �ո�]\n\n");
	Sleep(500);

	printf("�Է�: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n���� [ %s ] \n\n", state ? "�ո�" : "�޸�");
	Sleep(500);

	if (input == state)
	{
		printf("�����Դϴ�!\n");
		user_score += 1;
	}
	else
	{
		printf("�����Դϴ�...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");

	//5
	printf("<���� ���ھ�>\n");
	printf("���� ����\t: %i\n", user_score);
	printf("��ǻ�� ����\t: %i\n\n", com_score);
	Sleep(500);

	printf("��ǻ�Ͱ� ������ �������ϴ�!\n\n");
	Sleep(500);

	printf("������ �ո�����, �޸����� ���纸����!\n");
	printf("[0 : �޸�], [1 : �ո�]\n\n");
	Sleep(500);

	printf("�Է�: ");
	scanf_s("%i", &input);
	Sleep(500);

	printf("\n���� [ %s ] \n\n", state ? "�ո�" : "�޸�");
	Sleep(500);

	if (input == state)
	{
		printf("�����Դϴ�!\n");
		user_score += 1;
	}
	else
	{
		printf("�����Դϴ�...\n");
		com_score += 1;
	}
	Sleep(1000);
	system("cls");
	Sleep(500);
	printf("���� ����� �α��α��α�...\n");
	Sleep(2000);

	if (user_score > com_score) printf("��ȣ! �¸��Ͽ����ϴ�!\n");
	else printf("��... �й��Ͽ����ϴ�...\n");

	return 0;
}