// 2022-07-13 수업


#include <iostream>
using namespace std;

// 상속(Inheritance)
// : 기반 클래스(base, or parent class)의 기능을 확장하여
//   파생 클래스(derived, or child class)를 선언하는 기법으로, 높은 수준의 코드 재활용성을 제공하며,
//	 클래스 간의 계층적 관계를 구성함으로써 다형성의 문법적 토대를 제공한다.
// 
//   class {파생클래스_이름} : {접근제한자} {기반클래스_이름}
//   * 접근제한자의 역할: 상속받은 기반 클래스의 멤버 변수 및 함수들 중,
//						 해당 접근제한자보다 높은 접근성을 갖는 멤버를 어떻게 접근제어할지를 결정한다(생략할 경우, private로 설정).
//   * 다중상속: ','를 이용해 가능하며, 존재하는 기능이나 잘 사용하지는 않음 -> 클래스 당 하나의 기반 클래스만 갖도록 프로그래밍하는 습관.
//
//	 <파생 클래스 특징>
//	 1) 파생 클래스는 반드시 자신만의 생성자를 작성해야 한다.
//	 2) 파생 클래스에는 기본적으로 기반 클래스의 접근 가능한 모든 멤버 변수들이 저장된다.
//	 3) 파생 클래스는 기반 클래스의 접근 가능한 모든 멤버 함수를 사용할 수 있다.
//	 4) 파생 클래스에는 새로운 멤버를 추가할 수 있다.

// 기반 클래스(Base class, 부모(parent) 클래스라고도 함)
// : 기능을 물려주는 클래스.
class Base
{
	// private 접근제어자
	// : 선언된 클래스 내에서만 접근이 가능.
private:
	int base_private = 0;

	// protected 접근제어자
	// : 선언된 클래스의 파생 클래스에서도 접근이 가능하나, 파생 클래스의 외부에서는 접근 불가능.
protected:
	int base_protected = 0;

	// public 접근제어자
	// : 모든 외부에서 접근 가능함.
public:
	int base_public = 0;

	Base() { cout << "constructor of base class" << endl; }
	~Base() { cout << "destructor of base class" << endl; }

	__forceinline void base_print() const
	{
		cout << "base_private     : " << base_private << endl;
		cout << "base_protected   : " << base_protected << endl;
		cout << "base_public      : " << base_public << endl;
	}
};

// 파생 클래스(Derived class, 자식(child) 클래스라고도 함)
// : 특정 기반 클래스의 기능을 물려받은 클래스.
//   * final 키워드를 클래스명 뒤에 선언할 경우, 해당 형식을 기반 클래스로 하는 상속을 금지한다.
class Derived : public Base
{
private:
	int derived_private = 0;

protected:
	int derived_protected = 0;

public:
	int derived_public = 0;

	Derived()
	{
		cout << "constructor of derived class" << endl;
		//base_private = 1;		- Error -
		base_protected = 1;
		base_public = 1;
	}

	~Derived()
	{ cout << "destructor of derived class" << endl; }

	__forceinline void derived_print() const
	{
		cout << "derived_private  : " << derived_private << endl;
		cout << "derived_protected: " << derived_protected << endl;
		cout << "derived_public   : " << derived_public << endl;
	}
};

#pragma region Constructor & Destructor
class Temp1
{
public:
	Temp1() { printf("%s\n", __FUNCTION__); }
	~Temp1() { printf("%s\n", __FUNCTION__); }
};

class Temp2 : public Temp1
{
public:
	Temp2() { printf("%s\n", __FUNCTION__); }
	~Temp2() { printf("%s\n", __FUNCTION__); }
};

class Temp3 : public Temp2
{
public:
	Temp3() { printf("%s\n", __FUNCTION__); }
	~Temp3() { printf("%s\n", __FUNCTION__); }
};

class Temp4 : public Temp3
{
public:
	Temp4() { printf("%s\n", __FUNCTION__); }
	~Temp4() { printf("%s\n", __FUNCTION__); }
};

class Temp5 : public Temp4
{
public:
	Temp5() { printf("%s\n", __FUNCTION__); }
	~Temp5() { printf("%s\n", __FUNCTION__); }
};
#pragma endregion

int main()
{
	cout << "1) 파생 클래스 예시." << endl;
	Derived derived;
	//derived.base_private = 10;	- Error -	* 기반 클래스에서의 접근제한자가 private 이므로, 외부에서 접근 불가능.
	//derived.base_protected = 10;	- Error -	* 기반 클래스에서의 접근제한자가 protected 이므로, 외부에서 접근 불가능.
	derived.base_public = 10;
	derived.derived_public = 10;
	derived.base_print();
	derived.derived_print();
	cout << endl;

	cout << "2) 기반 클래스 예시." << endl;
	Base base;
	base.base_public = 10;
	base.base_print();
	cout << endl;

	// 기반 클래스의 형식에서는 파생 클래스에서 선언된 기능을 사용할 수 없다.
	//base.derived_public;			- Error - 객체가 derived_public이 선언된 클래스보다 상위 클래스의 인스턴스임.
	//base.derived_print();			- Error - 객체가 derived_print()이 선언된 클래스보다 상위 클래스의 인스턴스임.
	

	// 상속에서의 생성자 및 소멸자 호출 순서 규칙
	// : 생성자/소멸자는 기본적으로 특정 클래스의 객체를 생성/소멸할 때,
	//   기반 클래스 또는 파생 클래스들의 생성자/소멸자를 함께 호출하는 기능을 가지고 있다.
	//   이때, 생성자와 소멸자를 호출하는 순서 규칙은 아래와 같다.
	//   1) 생성자: 최상위 기반 클래스부터 최하위 파생 클래스의 순서대로 호출.
	//   2) 소멸자: 최하위 파생 클래스로부터 최상위 기반 클래스의 순서대로 호출.
	cout << "3) 생성자/소멸자 호출 순서 규칙." << endl;
	Temp5* tempClass = new Temp5();
	delete tempClass;
	tempClass = nullptr;
	cout << endl;

	cout << "4) main 함수 종료와 함께 객체들에 대한 소멸자 호출." << endl;

	return 0;
}