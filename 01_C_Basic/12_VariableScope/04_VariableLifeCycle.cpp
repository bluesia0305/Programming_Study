// 2022-06-17 수업(계속)


// 생명주기(Life cycle)
// : 변수가 할당받은 메모리에 대한 생명 주기를 의미함.

// 메모리 영역(Memory Area)
// : 아래와 같은 4개 영역으로 나뉨.
// 
//   Code  |  Data
//   --------------
//   Heap  |  Stack
//
//   * Code: 소스 코드, 함수의 정의 등을 저장하는 영역.
//   * Data: 프로그램 시작 ~ 끝까지 저장되는 데이터(정적변수, 전역변수 등)를 저장하는 영역.
//   * Stack: 지역변수와 같이 일시적으로만 저장했다 사라지는 데이터(반환값, 매개변수, 지역변수 등)를 저장하는 영역.
//   * Heap: 사용자 정의 공간.

#include <iostream>

struct A
{
	std::string Name = "Local";
	A() { printf("%s가 생성됩니다.\n", Name.c_str()); }

	A(std::string name)
	{
		Name = name;
		printf("%s가 생성됩니다.\n", Name.c_str());
	}

	A(const A & a)
	{
		Name = "copy " + a.Name;
		printf("%s가 생성됩니다.\n", Name.c_str());
	}

	~A() { printf("%s가 해제됩니다.\n", Name.c_str()); }
};

// 이하의 소스 코드를 실행할 때,
// 전역/지역변수들이 어떤 순서로 생겨나고 사라지는 지 확인.
A global_a("Global");					// 전역변수(global_a) - Global
static A global_s_a("Global Static");	// 정적전역변수(global_s_a) - Global Static
										// * 상기 2개의 변수는 프로그램 시작과 동시에 절차지향에 따라 생성.
void LocalStatic()
{
	static A a("Local Static");			// 정적지역변수(a) - Local Static
										// * 정적지역변수의 경우에는 프로그램이 종료될 때 해제되지만, 전역변수보다는 반드시 먼저 해제됨.
}

A Local(A param)						// 매개변수(param) - copy (main) Local
{
	A a("(function) Local");			// 지역변수(a) - (function) Local
	return a;							// 반환값(a) - copy (function) Local
}

int main()
{
	A a("(main) Local");				// 지역변수(a) - (main) Local

	{
		A b("b");
	}

	printf("--> void 형식의 LocalStatic 함수 실행.\n");
	LocalStatic();
	printf("--> A 형식(반환값 있음)의 Local 함수 실행.\n");
	Local(a);



	return 0;
}