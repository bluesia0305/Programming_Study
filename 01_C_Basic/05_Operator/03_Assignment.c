// 2022-05-27 수업(계속)


// 대입연산자(=, Assignment operator)
// 변수에 값을 초기화할 때 사용되는 연산자.

// 복합대입연산자(Compound assignment operator)
// : 기존의 연산자와 대입 연산자를 복합해놓은 연산자.
//   +=, -=, *=, /=, %=, >>=, <<= 등.
//   * 주의) 변수의 값이 새로운 값으로 초기화되는 것이므로 주의할 것.

// 참고)
// Ctrl + F: 특정 단어 찾기
// Ctrl + H: 특정 단어 바꾸기 (대소문자 주의)
// ㄴ> Alt + A: 전체 바꾸기
// Ctrl + Shift + F: 특정 단어 찾기 및 바꾸기


#include <stdio.h>

int main()
{
	int a = 10;

	printf("a		: %i\n", a);
	printf("a += 10 result	: %i\n", a+=10);
	printf("a		: %i\n", a);

	return 0;
}