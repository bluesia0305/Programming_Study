// 2022-05-27 �ǽ�


// ���� a, b�� �����ϰ� ���� �Է¹޾�
// 1. a + b, a - b, a * b, a / b, a % b�� ������� ������ּ���.
// 2. a + b�� + 5, - 5, * 5, / 5, % 5�� ����� ���� ������ּ���. 


#include <stdio.h>

int main()
{
	int a;
	int b;

	printf("Enter the value of a: ");
	scanf_s("%i", &a);
	printf("Enter the value of b: ");
	scanf_s("%i", &b);

	printf("\na : %i, b : %i\n", a, b);
	printf("a + b = %i\n", a+b);
	printf("a - b = %i\n", a-b);
	printf("a * b = %i\n", a*b);
	printf("a / b = %i\n", a/b);
	printf("a %% b = %i\n\n", a%b);

	int c = a + b;
	printf("a + b + 5 = %i\n", c+5);
	printf("a + b - 5 = %i\n", c-5);
	printf("a + b * 5 = %i\n", c*5);
	printf("a + b / 5 = %i\n", c/5);
	printf("a + b %% 5 = %i\n", c%5);

	return 0;
}