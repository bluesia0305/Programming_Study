// 2022-06-09 수업(계속)


#include <iostream>

struct Monster
{
	int hp;
	int atk;
};

int main()
{
	// 사용자 정의 자료형을 이용한 배열의 선언 및 배열의 각 요소별 멤버 호출하기.
	Monster myArray1[2] = {};		// 초기화하지 않은 요소의 모든 멤버의 값이 0으로 지정됨.
	std::cout << "1) 사용자 정의 자료형을 이용한 배열." << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << i + 1 << "번째 요소" << std::endl;
		std::cout << myArray1[i].hp << std::endl;
		std::cout << myArray1[i].atk << std::endl << std::endl;
	}
	
	// 선언과 동시에 모든 요소의 모든 멤버들에 대한 초기화 하는 방법.
	Monster myArray2[2] = { { 10, 1 }, { 20, 2 } };

	return 0;
}