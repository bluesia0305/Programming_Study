// 2022-05-30 수업(계속)


// 기타 연산자 및 함수


#include <stdio.h>

int main()
{
	int a = 100;

	// sizeof 함수
	// : 변수, 자료형, 상수의 크기를 반환해주는 연산자.
	printf("sizeof 함수\n");
	printf("a의 size: %zi Byte\n", sizeof(a));
	printf("char(자료형)의 size: %zi Byte\n", sizeof(char));
	printf("3.14의 size: %zi Byte\n\n", sizeof(3.14));

	// 주소연산자(&)
	// : 해당 변수의 위치(주소)를 반환해주는 연산자.
	printf("주소연산자\n");
	printf("a의 주소: %p\n\n", &a);		// %p: 주소를 출력하기 위한 형식지정자.

	// 캐스팅연산자((), Casting operator)
	// : 일시적으로 데이터의 형식을 변경하기 위해 사용하는 연산자.
	printf("캐스팅연산자\n");
	printf("(double)a의 size: %zi\n", sizeof((double)a));
	printf("(3 / 2) : %.1f\n", (3 / 2));					// 둘 다 정수이면 정수 나눗셈으로 계산됨, int형의 값(=1)을 %f로 받아서 0으로 출력됨.
	printf("(float)(3 / 2) : %.1f\n", (float)(3 / 2));		// (3 / 2)가 먼저 계산된 뒤(=1), 결과값이 float형으로 바뀜.
	printf("((float)3 / 2) : %.1f\n", ((float)3 / 2));		// (3.0f / 2)와 동일한 값으로 계산됨.

	// 연산자 우선순위 (일부 중요한 연산자에 대해서만 다룸)
	// 1) (), [], ->, .
	// 2) 단항연산자(!, ~, ++, --, *, &, sizeof() 등)
	// 3) 곱셈, 나눗셈
	// 4) 덧셈, 뺄셈

	return 0;
}