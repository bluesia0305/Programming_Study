// 2022-06-29 수업


#include <iostream>
using namespace std;

// 타입 추론형 자료형 auto
// : 선언시 초기화하고 있는 데이터에 따라 자료형이 결정되며 따라서 반드시 선언과 동시에 초기화 해야함.
//   * 컴파일 타임에 타입이 결정되므로, 프로그램의 성능 저하가 없음.

// auto는 반환형으로도 사용 가능함.
auto Add(int a, int b) { return a + b; }

// 단 아래와 같이 매개변수의 타입으로는 사용할 수 없음.
//auto Add2(auto a, auto b) { return a + b; }

int main()
{
	auto myInt = 3;
	auto myFloat = 3.14f;
	auto myDouble = 3.1415464657687;
	auto myChar = 'A';
	auto myStr = "ABC";
	auto myPointer = &myInt;

	cout << Add(1, 2) << " " << sizeof(Add(1, 2)) << endl;

}
