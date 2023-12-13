#include <iostream>

int main()
{
	// 아래의 해당 변수들은 어떠한 공간인지 서술해주세요.

	int A;
	// 답 : 정수자료형을 저장하고 4Byte 를 차지하며 직접접근을 통하여 값의 변경이 가능한 공간

	const int A1;
	// 답 : 정수형의 4 Byte 크기의 자료공간이며, 직접접근을 통한 값의 변경이 불가능한 공간 A1

	int const A2;
	// 답 : 직접접근을 통한 값의 변경이 불가능하며 정수형의 4 Byte 크기의 자료공간 A2

	int* P1;
	// 답 : 정수형의 4 Byte 크기의 자료공간을 가리키는 포인터 변수 P1

	const int* P2;
	// 답 : 가리키는 주소값의 변경이 가능하고,
	//      가리키는 공간이 정수형의 4 Byte 크기의 자료공간이면서 간접접근을 통한 값의 변경이 불가능한 포인터 P2 (pointer to constant)

	int* const P3;
	// 답 : 가리키는 주소값의 변경이 불가능하고,
	//      가리키는 공간이 정수형의 4 Byte 크기의 자료공간이면서 간접접근을 통한 값의 변경이 가능한 포인터 P3 (constant pointer)

	const int* const P4;
	// 답 : 가리키는 주소값의 변경이 불가능하며,
	//      가리키는 공간이 정수형의 4 Byte 크기의 자료공간이면서 간접접근을 통한 값의 변경이 불가능한 포인터 P4 (constant pointer to constant)

	return 0;
}