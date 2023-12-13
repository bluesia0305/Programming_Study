// 2022-07-18 수업


#include <iostream>
#include <combaseapi.h>
//using namespace std;		* combaseapi.h 헤더를 사용할 때는 std 사용 안하는 편이 좋음.

// 인터페이스(Interface)
// : 순수 가상 함수와 가상 소멸자만을 가지는 추상 클래스.
//   * 인터페이스의 명명에는 접두사로 영문자 I를 붙여 명명함(암묵적 약속).

// 인터페이스의 선언 예시1: 정의에 맞게 순수 가상 함수와 가상 소멸자만 갖도록 선언.
class IInterface1 abstract
{
public:
	//int a;	* 멤버 변수 및 함수의 선언이 가능함(인터페이스는 본질적으로 추상 클래스의 특수한 경우일 뿐이므로)
	virtual ~IInterface1() = default;
	virtual void Func() abstract;
};

// 인터페이스의 선언 예시2: combaseapi.h 헤더를 포함하면 아래와 같이 선언 가능
//                        (#define interface __STRUCT__ 와 같음, 즉 구조체임)
interface IInterface2
{
	//int a;	* 멤버 변수 및 함수의 선언이 가능함(기본적으로 그냥 구조체이므로)
	virtual ~IInterface2() = default;
	virtual void Func() abstract;
};

// 인터페이스의 선언 예시3: 키워드를 통한 선언.
__interface IInterface3
{
public:
	//int a;	- Error -	* 인터페이스로 작용하기 위해 기본적으로 변수 선언을 차단함.
	
	//키워드 자체적으로 가상 소멸자를 제공하므로 임의의 소멸자 선언을 차단함.
	//virtual ~IInterface3() = default;		- Error -
	virtual void Func() abstract;
};

class Test : public IInterface1//, public IInterface2, public IInterface3
{
public:
	// IInterface1을(를) 통해 상속됨
	void Func() override
	{ std::cout << __FUNCTION__ << std::endl; }

	// 다중 상속에서의 주의사항
	// : 같은 프로토타입으로 선언된 함수를 가지고 있는 여러 기반 클래스를 다중 상속받을 경우,
	//   기반 클래스로부터 오버라이딩이 된 함수들끼리 오버로딩 관계가 자연스럽게 형성되므로
	//   매개변수가 같을 경우 오류가 발생한다(함수 호출의 모호함 발생, 오버로딩에서는 반환형이 고려되지 않음에 주의).
};

int main()
{
	Test sample;
	sample.Func();
	std::cout << std::endl;

	// 업캐스팅 후 기능 사용 예시
	IInterface1* Interface = &sample;
	Interface->Func();

	return 0;
}