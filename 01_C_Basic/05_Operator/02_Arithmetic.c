// 2022-05-27 ����


// ���������(Arithmetic operator)
// : ���� ������ ������� ������� ��ȯ���ִ� ������.
//   1) +(����, addition)
//   2) -(����, subtraction)
//   3) *(����, multiplication)
//   4) /(������, division)
//      : ����, ������ �� �ϳ��� �Ǽ����� ���, ������ ���� ����� �Ǽ��� ������� ��ȯ,
//        �� �� �������� ���, ������ ���� ��� �� ���� ������ ������� ��ȯ.
//   5) %(������, remainder)
//      : ������ �ǿ����� �������� int ���ĸ� ��� ������.


#include <stdio.h>

int main()
{
	
	int a = 10;
	int b = 7;
	int num1 = a + b;
	int num2 = a - b;
	int num3 = a * b;
	int num4 = a / b;
	int num5 = a % b;
	printf("a = %i, b = %i\n", a, b);
	printf("num1: a + b = %i\n", num1);
	printf("num2: a - b = %i\n", num2);
	printf("num3: a * b = %i\n", num3);
	printf("num4: a / b = %i\n", num4);
	printf("num5: a %% b = %i\n", num5);

	return 0;
}