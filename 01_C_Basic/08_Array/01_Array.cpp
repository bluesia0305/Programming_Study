// 2022-06-08 수업(계속)


// 배열(Array)
// {배열의 이름}[배열의 길이]
// : 동일한 자료형의 공간을 여러 개 동시에 선언할 때, 사용하는 기능.
//   * 배열의 이름: 변수명.
//   * 배열의 길이: 몇 개의 공간을 생성할 지 결정(음이 아닌 정수).

#include <iostream>

int main()
{
	int myArray[5];
	
	// 배열의 요소에 접근할 때에는 인덱스(배열의 요소를 구분하는 숫자) 연산자를 사용함.
	// 인덱스는 0에서 시작하여 (배열의 길이 - 1)로 끝남.
	// 배열의 길이를 넘는 인덱스를 갖는 요소를 호출하는 경우는 오류가 발생함.
	myArray[0] = 0;
	myArray[1] = 1;
	myArray[2] = 2;
	myArray[3] = 3;
	myArray[4] = 4;
	
	std::cout << "1) 배열의 선언 실습1" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << myArray[i] << std::endl;
	}
	std::cout << std::endl;

	// 배열의 선언과 동시에 요소들을 초기화할 수 있음.
	// 이때, 선언 당시에 초기화되지 않은 배열의 요소들의 값은 모두 0으로 초기화 됨.
	int myArray2[6] = { 10, 20, 30, 40, 50 };
	
	// 단, 아래와 같이 배열의 선언 이후 모든 요소들을 동시에 초기화하는 것은 불가능함.
	// myArray2 = { 1, 2, 3, 4, 5, 6 };   - Error -
	std::cout << "2) 배열의 선언 실습2" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << myArray2[i] << std::endl;
	}
	std::cout << std::endl;

	// 배열의 선언 시에 모든 요소의 값을 초기화하지 않는 경우(아래 두 가지의 경우에서 결과가 서로 다름 확인해보기)
	std::cout << "3) 배열 선언 시, 값을 초기화하지 않는 경우(중괄호로만 선언)" << std::endl;
	int myArray3[5] = {};
	for (int i = 0; i < 5; i++)
	{
		std::cout << myArray3[i] << std::endl;		// 0으로 초기화 됨.
	}
	std::cout << std::endl;

	std::cout << "4) 배열 선언 시, 아예 중괄호도 없이 이름만 선언하는 경우" << std::endl;
	int myArray4[5];
	for (int i = 0; i < 5; i++)
	{
		std::cout << myArray4[i] << std::endl;		// trash value로 초기화 됨.
	}
	std::cout << std::endl;


	// 2022-06-09 실습
	// int형 정수 100개를 저장할 수 있는 배열을 만들고, 배열의 요소를 1부터 100까지 저장해주세요.
	// 이후 모든 요소를 출력해주세요.
	std::cout << "5) (실습) int 자료형 100개 데이터를 저장할 수 있는 배열을 만든 뒤, 출력." << std::endl;
	int pracArray[100] = {};
	for (int i = 0; i < 100; i++)
	{
		pracArray[i] = i + 1;
		std::cout << pracArray[i];
		if (i != 0 && i % 10 == 9) std::cout << std::endl;
		else std::cout << "\t";
	}
	std::cout << std::endl;
	
	return 0;
}