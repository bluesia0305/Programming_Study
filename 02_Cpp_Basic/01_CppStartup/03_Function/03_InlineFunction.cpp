// 2022-06-30 수업


#include <iostream>
using namespace std;

// 인라인 함수(Inline function)
// : 함수 호출에서의 오버헤드(overhead)로 인한 프로그램의 성능 저하를 막기 위해 C++에서부터 도입된 기능.
//   함수의 반환형 앞에 inline 또는 __forceinline 키워드를 작성하여 선언.
//   * 오버헤드(Overhead): 프로그램의 실행 흐름 도중에 동떨어진 위치의 코드를 실행시켜야할 때,
//                        추가적으로 시간, 메모리, 자원 등이 사용되는 현상.

// inline : 컴파일러에게 인라인 여부를 결정하라 지시합니다.
inline void Print()
{ cout << "Hello World" << endl; }

// __forceinline : 컴파일러에게 인라인 강제로 선언하라 지시합니다.
__forceinline void Add(int a, int b)
{ cout << a + b << endl; }

int main()
{
	Print();
	Add(10, 20);

	return 0;
}