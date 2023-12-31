// 2022-05-25 수업(계속)


// 메모리 공간 내에는 위치별로 주소값이 정해져 있음.
// 변수를 선언하게 되면 선언한 변수명에 주소를 대응하고, 해당 위치에 자료형과 값을 저장하는 형태.
// 주소 연산자(&, address opreator): 해당 연산자 뒤의 변수명의 주소를 호출하기 위해 사용.

// C언어에서의 입력은 scanf_s 함수를 이용한다.
// scanf_s 함수 사용법
// : scanf_s("입력받을 데이터의 형식 지정자", 입력받은 데이터를 저장할 변수의 주소);
//   * _s 는 safe를 의미함(개발버전 상 안정적으로 작동하는 함수).

// 블록 주석화/해제 방법
// : 주석으로 처리할 영역을 드래그 한 뒤, Ctrl + Shift + / (반복 적용 시, 주석화 해제).


#include <stdio.h>

int main()
{
	//int input;
	//
	//scanf_s("%i", &input);			// scanf_s 함수 호출 뒤 user가 데이터를 입력하여 Enter를 누르는 순간까지의 입력된 데이터를 정해준 주소에 저장함.
	//printf("input: %i\n", input);

	// (실습) 실수 형태의 데이터 3.14를 입력받기
	float input2;

	scanf_s("%f", &input2);
	printf("input2: %f", input2);

	// Q1. 상수 형태의 공간(const)에 값을 입력 받을 수 있을까요? (답: 불가능)
	// Q2. 원하는 소수점 자리까지만 입력 받는 방법이 있을까요? (답: 불가능)

	return 0;
}