// 2022-07-14 심화


#include <iostream>
#include <string>
using namespace std;

// 호출 규약(cdecl call convention)
// : 호출자(caller)와 피호출자(callee) 간의 함수의 인자를 전달하는 방식에 대한 규약.
//   호출 규약은 컴퓨터 과학에서 어떻게 서브루틴이 그들의 호출자로부터 변수를 받고, 어떻게 결과를 반환하는지에 대한 규약이다.
//   * cdecl 호출 규약: C 및 C++ 프로그램에 대한 기본 호출 규약.
//     1) 인수 전달 순서			: 오른쪽에서 왼쪽.
//     2) 스택 유지 관리 책임		: 호출하는 함수(caller)가 스택(stack)에서 인수를 정리한다.
//     3) 이름-수식 컨벤션		: C 연결을 사용하는 __cdecl 함수를 내보낼 때를 제외하고 이름 앞에 _가 붙는다. (_함수명)
//     4) 대소문자 변환 규칙		: 수행되지 않음.

// 함수(Function)
// : 중복된 코드의 재사용을 실용성이 있게 사용하는 기능.

// 함수와 관련하여 C++에서 새로 추가된 기능
// 1) 이름공간
// 2) 멤버 함수
// 3) 선택적 매개변수
// 4) 오버로딩
// 5) 오버라이딩

class Class
{
public:
	string Name = "Return";
	int member1 = 10;

	Class() { cout << "객체 생성" << endl; }

	Class(const Class& a)
	{ cout << "copy 객체 생성" << endl; }

	~Class()
	{ cout << Name << ": A 소멸" << endl; }
};

int Add(int a, int b)
{
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	return a + b;
}

Class Add(Class Object)
{
	cout << "Object.member1 : " << Object.member1 << endl;
	Object.Name = "Parameter";

	return Object;
}

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// 인라인 함수
// __forceinline
// inline : 컴파일러에게 인라인 여부 결정

// 함수 오버로딩(Function overloading)
// : 같은 이름의 함수에 대하여 매개변수의 개수, 자료형을 달리하여 재정의할 수 있는 기능.
//   * C   : 함수의 이름만 가지고 함수를 찾는다.
//   * C++ : 함수의 이름, 매개변수의 개수와 자료형에 따라 함수를 찾는다.

void Addition(int   A, int   B, bool P = false)
{
	if (P)
	{
		cout << "A : " << A << endl;
		cout << "B : " << B << endl;
	}
	cout << "Result : " << A + B << endl;
}
void Addition(float C, int   D, bool R = false)
{
	if (R)
	{
		cout << "A : " << C << endl;
		cout << "B : " << D << endl;
	}
	cout << "Result : " << C + D << endl;
}
void Addition(float G, float H, bool N = false)
{
	if (N)
	{
		cout << "A : " << G << endl;
		cout << "B : " << H << endl;
	}
	cout << "Result : " << G + H << endl;
}

// 재귀함수(Recursive function)
// : 함수의 정의 내에서 자기 자신을 호출(즉, 재귀호출)하는 함수.
//   * 무한 루프에 빠지지 않도록 정의 상에서 주의하여야 한다.
//   * 재귀함수를 잘 사용하면 알고리즘이 단순화되지만, 스택 프레임(Stack frame)과 관련하여 단점도 존재함.
void Hello(unsigned count)
{
	if (count == 1) return;
	cout << "Hello";
	Hello(count - 1);
}

int main()
{
	Class object_main;
	object_main.Name = "Main";
	cout << Add(10, 20) << endl;
	cout << Add(object_main).member1 + 10 << endl;

	//int a = 10;
	//int b = 20;
	//Swap(&a, &b);
	//cout << a << " : " << b << endl;
	return 0;
}