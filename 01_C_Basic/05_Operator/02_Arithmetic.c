// 2022-05-27 수업


// 산술연산자(Arithmetic operator)
// : 각각 다음의 연산들의 결과값을 반환해주는 연산자.
//   1) +(덧셈, addition)
//   2) -(뺄셈, subtraction)
//   3) *(곱셈, multiplication)
//   4) /(나눗셈, division)
//      : 제수, 피제수 중 하나라도 실수형일 경우, 나눗셈 연산 결과의 실수형 결과값을 반환,
//        둘 다 정수형일 경우, 나눗셈 연산 결과 중 몫의 정수형 결과값을 반환.
//   5) %(나머지, remainder)
//      : 오른쪽 피연산자 형식으로 int 형식만 사용 가능함.


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