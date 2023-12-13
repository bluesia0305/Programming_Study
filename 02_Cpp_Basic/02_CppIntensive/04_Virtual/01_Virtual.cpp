// 2022-07-15 수업


#include <iostream>
using namespace std;

// 다형성(Polymorphism)
// : 서로 다른 객체가 동일한 기능을 서로 다른 방법으로 처리할 수 있는 기능.

// 가상 함수(Virtual function)
// : 가상 함수는 기반 클래스에서 선언되어, 파생 클래스에 의해 재정의되(는 것을 기대하며 선언되)는 멤버 함수이다.
//   포인터(pointer) 또는 기반 클래스에 대한 참조(reference)를 사용하여 파생 클래스의 객체를 참조하면
//   해당 객체에 대해 가상 함수를 호출하고 파생 클래스의 함수를 실행할 수 있다.
//   이는 주로 실행시간(runtime)에 함수의 다형성(polymorphism)을 구현하는데 사용된다.
//   가상 함수는 기반 클래스에서 virtual 키워드로 함수를 선언하며, 아래와 같은 규칙을 지켜 선언이 가능하다.
//
//	 <가상 함수의 선언 규칙>
//	 1) 가상 함수는 정적(static)으로 선언될 수 없으며 다른 클래스의 친구(friend) 함수가 될 수도 없다.
//	 2) 가상 함수는 실행시간 다형성을 얻기위해 기반 클래스의 포인터 또는 참조를 통해 접근(access)해야 한다.
//	 3) 가상 함수의 프로토타입(반환형과 매개변수)은 기본 클래스와 파생 클래스에서 동일하다(function overriding에 기반하므로).
//	 4) 클래스는 가상 소멸자를 가질 수 있지만 가상 생성자를 가질 수 없다.
//	    * 소멸자의 경우, 이름은 다르지만 오버라이딩으로 취급함.
//
//	 <가상 함수의 특징>
//	 1) 기반 클래스에서 가상 함수로 선언된 함수는 파생 클래스에서 재정의될 때 기본적으로 가상 함수로 정의된다(키워드 없이도).
//	 2) 가리키고 있는 자료형이 아닌, 실질적으로 참조하고 있는 자료형을 기준으로 호출된다.
//	 3) 가상 함수에 대해서만 사용 가능한 키워드
//		- override: 기반 클래스에 동일한 이름의 가상 함수가 있는지 소스 코드 상에서 확인할 수 있게 하는 키워드.
//		- final   : 하위 파생 클래스에서부터 재정의(override)할 수 없도록 선언.

// 다형성 클래스(Polymorphic class)
// : 하나 이상의 가상 함수(소멸자 포함)를 포함하는 클래스.
class Base
{
public:
	Base() { cout << "Base Constructor Call" << endl; }
	
	// Base* 형식으로 접근 -> 기반 클래스의 소멸자에 먼저 접근 -> 가상 함수로 선언되어 실질적으로 참조하고 있는 파생 클래스의 소멸자로 접근
	virtual ~Base() { cout << "Base Destructor Call" << endl; }

	void NormalFunc() const
	{ cout << __FUNCTION__ << endl; }

	virtual void VirtualFunc() const
	{ cout << __FUNCTION__ << endl; }
};

class Derived : public Base
{
public:
	Derived() { cout << "Derived Constructor Call" << endl; }

	~Derived() { cout << "Derived Destructor Call" << endl; }

	void NormalFunc() const
	{ cout << __FUNCTION__ << endl; }

	void NormalFunc(int a, int b)
	{ cout << __FUNCTION__ << "(int a, int b)" << endl; }

	void VirtualFunc() const override
	{ cout << __FUNCTION__ << endl; }
};

int main()
{
	Base* pDerived = new Derived();
	cout << endl;

	cout << "1) pDerived->NormalFunc();" << endl;
	pDerived->NormalFunc();
	cout << endl;

	cout << "2) static_cast<Derived*>(pDerived)->NormalFunc();" << endl;
	static_cast<Derived*>(pDerived)->NormalFunc();
	cout << endl;

	cout << "3) pDerived->VirtualFunc();" << endl;
	pDerived->VirtualFunc();
	cout << endl;

	cout << "4) static_cast<Base*>(pDerived)->NormalFunc();" << endl;
	static_cast<Base*>(pDerived)->VirtualFunc();
	cout << endl;

	delete pDerived;
	pDerived = nullptr;

	return 0;
}