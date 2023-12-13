// 2022-06-30 수업


#include <iostream>
using namespace std;

// 멤버 함수(Member function)
// : C++ 에서부터는 사용자 정의 자료형(구조체)에 함수를 추가할 수 있다(= 멤버 함수, 메소드).

struct STRUCT
{
	// C++ 에서부터는 멤버 변수에 default 값을 지정해줄 수 있음.
	int A = 10;
	int B = 20;

	// 멤버 함수 Print를 선언합니다.
	// {반환형} {함수명}({매개변수}) const: 해당 함수의 정의 내에서 멤버 변수들의 값을 변경하지 않는 것을 명시.
	__forceinline void Print() const
	{  	cout << "A: " << A << ", B: " << B << endl; }

	void Print(int integer1, int integer2 = 0)
	{ cout << "integer1: " << integer1 << ", integer2: " << integer2 << endl; }

	void AddA(int integer) // const		- Error -    멤버 변수의 값을 변경하므로 const 선언시 오류 발생함.
	{  A += integer;  }
};

int main()
{
	STRUCT Struct;
	Struct.Print();
	Struct.AddA(10);
	Struct.Print();
	
	// <생각해보기>
	// Q1. 멤버 함수의 경우에서는 함수 내에서 처리한 멤버 변수의 값이 그대로 저장이 되는 이유?
	// Q2. 구조체의 크기?

	printf("sizeof(STRUCT) == %zi\n", sizeof(STRUCT));

	return 0;
}