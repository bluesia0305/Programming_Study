// 2022-05-25 수업(계속)

// 상수(const) 키워드
// : 변수공간의 값을 상수화 시키는 키워드.
//   값이 변하지 않는 공간을 선언하기 위해 사용하며 반드시 초기화를 동시에 수행하여야 함.


#include <stdio.h>

int main()
{
	// 상수 표기법
	10;			// 정수
	3.14f;		// float형 상수
	1.23;		// double형 상수
	'A';		// 문자
	"ABC";		// 문자열 상수

	int myVar = 10;
	myVar = 20;
	printf("myVar: %i\n", myVar);

	const int trashVar;			// 선언 동시에 초기화하지 않으면 변수 자리에 쓰레기 값을 저장하게 됨.
	//printf("%i", trashVar);	// !! 주의) 출력하려고 하면 오류 발생함(오류 무시 후 실행해도 콘솔 중단됨).

	const int constVar = 10;
	//constVar = 20;	<- 상수 변수의 값을 초기화하면 오류가 발생하여 소스 코드가 실행되지 않음.

	printf("constVar: %i\n", constVar);

	return 0;
}