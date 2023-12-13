// 2022-06-08 수업(계속)


// C++ 표준 형식을 이용한 출력.
// iostream: C++ 표준 입출력 데이터 요소를 다루는 헤더
// i: Input
// o: Output
// stream: 데이터 요소


#include <iostream>

int main()
{
	printf("Hello world.\n");					// C 표준 출력 형식(printf 함수)을 이용한 문자열 출력.
	std::cout << "Hello World" << std::endl;	// C++ 표준 출력 형식을 이용한 문자열 출력.
	// cout: Console Out의 약자로, 콘솔 창에 출력하겠다는 것을 의미함.
	// <<: 콘솔 창에 출력할 데이터를 전달하겠다는 것을 의미하는 명령어.
	// endl: 개행("\n")을 의미함.
	
	int A = 10;
	printf("A: %i\n", A);

	// cout의 경우에는 특수 문자의 사용은 가능하지만, 형식 지정자의 사용은 불가능함.
	// (C++에서는 자동적으로 변수의 출력 시, 자료형을 판단하여 출력하므로 형식지정자 사용 안 함).
	// * C++ 표준 형식으로 출력하면 굉장히 알아보기가 힘듬... 잘 사용하지 않음.
	std::cout << "A: " << A << "\n";

	return 0;
}