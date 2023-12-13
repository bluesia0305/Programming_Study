// 2022-07-18 수업


#include <iostream>
#include <Windows.h>
using namespace std;

// 추상화(Abstraction)
// : 공통된 기능을 모아 추상적으로 표현하는 모델링 기법.
//   객체의 특성과 기능을 정의해두는 것으로 데이터 추상화, 프로세스 추상화로 구분됨.

// 추상 클래스(Abstract class)
// : 순수 가상 함수를 하나 이상으로 포함하거나, 추상화 키워드 abstract를 포함하여 선언된 클래스.
//   * 완전하지 못한 클래스이므로 인스턴스화할 수 없어 객체를 만들지 못하므로 상속으로써만 사용된다.
//   * 추상 클래스의 파생 클래스에서 순수 가상 함수를 재정의하지 않는 경우, 파생 클래스도 추상 클래스가 된다.
//     즉, 인스턴스화가 필요한 파생 클래스일 경우에는 반드시 기반 클래스의 모든 순수 가상 함수에 대한 재정의(override)가 필요하다.
//   * 프로그래밍 편의상 추상 클래스는 모든 멤버 함수가 순수 가상 함수로만 이루어지도록 구성하는 것이 바람직하다(즉, interface로 선언).
//   * 상속 과정에서, 기반 클래스에 커서를 두고 Ctrl + '.' -> '순수 가상 함수 구현' 기능을 통해
//     기반 클래스에 존재하는 모든 순수 가상 함수에 대한 재정의를 편하게 할 수 있음.
//
// <특정 클래스의 인스턴스화를 방지하는 방법>
// 1) 해당 클래스의 생성자를 protected 섹션으로 선언한다.
// 2) 클래스 내에 하나 이상의 순수 가상 함수를 포함하도록 클래스를 선언한다.
// 3) 추상 클래스임을 명시한다(abstract 키워드).

// 순수 가상 함수(Pure virtual function)
// : 함수의 정의 없이 선언만으로 이루어진 가상 함수.
//   해당 클래스에서 함수를 정의하지 않는다는 것을 명시하여 {함수의 선언} = 0; 과 같이 선언한다.

// 추상 클래스 예시1
class Base
{
protected:
	Base() = default;

	// 해당 클래스에서 정의문이 없다는 것을 명시
	virtual void Print() = 0;
};

// 추상 클래스 예시2
class Base_abstract abstract
{
protected:
	virtual void Print1() abstract;		// abstract 키워드를 사용한 순수 가상 함수 선언.
	virtual void Print2() PURE;			// Windows.h 헤더를 포함한 뒤 사용 가능,
										// #define PURE = 0 전처리기를 작성하는 것과 동일함.
};

class Derived : public Base
{
public:
	Derived() : Base() {}

	void Print() override
	{ cout << __FUNCTION__ << endl; }
};

int main()
{
	Derived derived;


	return 0;
}