// 2022-05-27 ����


// int�� ���� num�� �����ϰ�, ���� �Է¹޾�
// �Է� ���� ���� ¦������, Ȧ������ ����ϴ� ���α׷��� ������ּ���.

// ex)
// Num�� �Է��ϼ��� : 10
// Num�� ¦���Դϴ�.

// Num�� �Է��ϼ��� : 11
// Num�� Ȧ���Դϴ�.


#include <stdio.h>

int main()
{
	int num;
	
	printf("num�� �Է��ϼ���: ");
	scanf_s("%i", &num);
	printf("num�� %s\n", (num % 2) ? "Ȧ���Դϴ�." : "¦���Դϴ�.");

	return 0;
}