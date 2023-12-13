// 2022-05-27 실습


// 변수 a, b를 선언하고 값을 입력받아
// 1. a + b, a - b, a * b, a / b, a % b의 결과값을 출력해주세요.
// 2. a + b에 + 5, - 5, * 5, / 5, % 5의 결과값 또한 출력해주세요. 


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