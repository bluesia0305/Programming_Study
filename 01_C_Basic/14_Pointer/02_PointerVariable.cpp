// 2022-06-21 수업


// 포인터 변수(Pointer variable)
// : 변수의 주소값을 저장하는 변수.
//   * 주소값을 가지고 있다는 것은, 해당 주소공간에 접근이 가능하다는 것을 의미함.


#include <iostream>

int main()
{
	int a = 10;
	// 포인터 변수의 선언 방법
	// {자료형}* {식별자};
	// : 포인터의 자료형은 해당 포인터 변수가 저장하는 주소에 해당하는 공간의 원래 자료형과 일치시키는 것이 좋음.
	//   * 나중에 간접접근을 통하여 값에 접근할 때, 자료형의 크기가 불일치하면 잘못 값을 읽을 수 있기 때문.
	int* p;		// int pointer p를 선언
	p = &a;		// 주소 연산자 &

	printf("a의 값   : %i\n", a);
	printf("a의 주소 : %p\n", &a);
	printf("p의 값   : %p\n", p);
	printf("p의 주소 : %p\n", &p);
	printf("*p       : %i\n", *p);			// 역참조(간접접근) 연산자 *
	// 역참조 연산자 -> *{포인터_변수};
	// 간접접근 연산자라고도 하며, 포인터가 저장하고 있는 주소에 해당하는 공간에 접근하는 연산자.
	*p = 20;
	printf("a의 값   : %i\n", a);

	return 0;
}