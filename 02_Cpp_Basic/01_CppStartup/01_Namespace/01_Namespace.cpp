// 2022-06-29 수업


#include <iostream>

// 네임 스페이스(이름공간, Namespace)
// : 이름을 가진 코드블럭을 만들 수 있는 키워드.
//   Namespace 내의 데이터(변수 및 함수 등)에 접근할 때 '::' (스코프 연산자, scope operator)를 이용함.

// 스코프 연산자(Scope operator)
// : 범위 접근 연산자라고도 불리며 구조체, 클래스, 네임스페이스 등의
//   이름을 지정할 수 있는 범위에 접근할 수 있는 연산자.

namespace Namespace1
{
	int A = 10;		// 전역변수
	void Print()
	{
		printf("abc\n");
	}

}

namespace Namespace2
{
	int A = 20;		// 전역변수
}

int A = 30;			// 전역변수

namespace Namespace3
{
	int A = 1;
	namespace Namespace4
	{
		int A = 2;
	}
}

// using namespace {namespace};
// : 해당 {namespace}를 생략하여 사용하도록 명령하는 명령어.
//   * 네임 스페이스의 이름을 생략했을 때, 중복되는 변수 이름이나 함수가 있을 시 오류 발생함.
//     위와 같은 경우가 아니라면, 여러 개의 구문이 적용되어도 알아서 생략된 네임 스페이스를 찾아서 해당 변수 및 함수를 찾아 호출함.
//   * using namespace 구문은 중괄호 내에서 선언되면, 중괄호 외부에서는 적용되지 않음.
using namespace std;

// 익명 네임 스페이스 -> 이름이 없는 네임 스페이스에서 선언된 변수는 정적변수로 취급되어 선언됨.
namespace
{
	int a;
	int b;
	int c;
}
//static int a, b, c;

int main()
{
	int A = 40;

	// 네임 스페이스가 다르면 변수 이름을 중복되게 선언이 가능함.
	std::cout << Namespace1::A << std::endl;
	std::cout << Namespace2::A << std::endl;
	std::cout << ::A << std::endl;
	std::cout << A << std::endl;

	// 중첩된 네임 스페이스 내의 변수 호출 방법.
	std::cout << Namespace3::A << std::endl;
	std::cout << Namespace3::Namespace4::A << std::endl;
	
	// 네임 스페이스 내에서 선언된 함수 호출 방법.
	Namespace1::Print();


	return 0;
}