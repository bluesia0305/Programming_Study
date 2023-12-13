// 2022-06-23 수업(계속)


// 함수 포인터 (Function pointer)
// : 함수의 주소값을 저장할 수 있는 포인터.


#include <iostream>

void Hello()
{ printf("Hello\n"); }

float Mul(int a, int b)
{ return a * b; }

int main()
{
	// 함수 호출 연산자 ()
	// : 해당 주소에 선언되어있는 함수를 호출해주는 연산자
	
	// 함수의 이름은 함수가 존재하고 있는 주소를 의미함.
	printf("Hello 함수가 존재하는 위치: %p\n", Hello);
		
	// 함수 포인터의 선언 방법
	// {가리킬 함수의 반환형} ( *{포인터 이름} )( {매개변수의 자료형} ) = 함수의 주소값;
	void (*p)() = Hello;
	float (*pMul)(int, int) = Mul;
	float mul = pMul(3, 4);
	printf("mul: %.2f\n", mul);

	return 0;
}