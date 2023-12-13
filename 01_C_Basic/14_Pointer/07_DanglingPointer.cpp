// 2022-06-23 수업


// 댕글링 포인터(Dangling pointer)
// : 존재하지 않는 공간의 주소를 가리키는 포인터.
//   * 사용하지 않는 프로그래밍 방식임.


#include <iostream>

int* Pointer()
{
	int a = 10;
	return &a;
}

int main()
{
	int* p = Pointer();
	// 위와 같은 코드에서 p는 함수의 종료와 함께 사라지게 되는 지역변수(Pointer 함수 내의 a)의
	// 주소를 저장하므로 댕글링 포인터가 됨.

	return 0;
}