// 2022-06-08 수업(계속)


// C++ 표준 형식을 이용한 입력.


#include <iostream>

int main()
{
	int A = 0;
	// cin: Console input의 약자로, 콘솔창에서 입력받겠다는 것을 의미함.
	// >>: 입력받은 데이터를 해당 공간에 전달하겠다는 것을 의미하는 명령어.
	// * cout에서와 마찬가지로 형식 지정자를 사용하지 않아도 자동적으로 자료형을 검사하여 저장함.
	std::cout << "A를 입력하세요: ";
	std::cin >> A;
	std::cout << "A: " << A << std::endl;

	// float 자료형 변수를 선언해도 정수를 입력하면 정수로 저장됨.
	float B = 0;
	std::cout << "B를 입력하세요: ";
	std::cin >> B;
	std::cout << "B: " << B << std::endl;

	return 0;
}