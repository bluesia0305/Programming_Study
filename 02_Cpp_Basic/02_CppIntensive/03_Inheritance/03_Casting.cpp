// 2022-07-14 수업


#include <iostream>
#include <string>
using namespace std;

// 업캐스팅(Upcasting)
// : 기반 클래스를 가리키는 포인터 형식으로 파생 클래스의 객체를 가리키는 방식.
//   즉, 파생 클래스의 객체가 기반 클래스 타입으로 형변환되는 것이다.

// 다운캐스팅(Downcasting)
// : 업캐스팅된 것을 다시 원상태로 돌리는 것을 말한다.
//   * 다운 캐스팅은 업 캐스팅과 달리 명시적 타입 변환을 지정해야 한다.

class Monster
{
private:
	const string Name;
	const unsigned Lv;

protected:
	float HP;
	float ATK;

public:
	Monster() : Name("NULL"), Lv(0), HP(0.0f), ATK(0.0f)
	{};

	Monster(string name, int lv, float hp, float atk) : Name(name), Lv(lv), HP(hp), ATK(atk)
	{};

	~Monster()
	{ printf("기반 클래스(Monster)의 소멸자 호출.\n"); }

	__forceinline void Attack() const
	{
		printf("%s >> %.2f 의 공격력으로 공격합니다.\n", Name.c_str(), ATK);
	}

	__forceinline void Print() const
	{
		printf("Name       : %s\n", Name.c_str());
		printf("Lv         : %i\n", Lv);
		printf("HP         : %.2f\n", HP);
		printf("ATK        : %.2f\n", ATK);
	}
};

class Slime : public Monster
{
private:
	const float JumpHeight;

public:
	Slime() : Monster("Slime", 1, 10.0, 1.0), JumpHeight(5.0)
	{}

	Slime(string name, int lv, float hp, float atk) : Monster(name, lv, hp, atk), JumpHeight(5.0)
	{}

	~Slime()
	{ printf("파생 클래스(Slime)의 소멸자 호출.\n"); }

	__forceinline void Jump() const
	{
		printf("%.2f 의 높이만큼 점프합니다.\n", JumpHeight);
	}

	__forceinline void Print() const
	{
		Monster::Print();
		printf("JumpHeight : %.2f\n", JumpHeight);
	}
};

class Fairy : public Monster
{
private:
	const float FlyingSpeed;

public:
	Fairy() : Monster("Fairy", 3, 20.0, 3.0), FlyingSpeed(20.0)
	{}

	Fairy(string name, int lv, float hp, float atk) : Monster(name, lv, hp, atk), FlyingSpeed(20.0)
	{}

	~Fairy()
	{ printf("파생 클래스(Fairy)의 소멸자 호출.\n"); }

	__forceinline void Flying() const
	{
		printf("%.2f 의 속도로 날아다닙니다.\n", FlyingSpeed);
	}

	__forceinline void Print() const
	{
		Monster::Print();
		printf("FlyingSpeed: %.2f\n", FlyingSpeed);
	}
};

class Base
{
public:
	virtual ~Base() = default;
	void print()
	{ cout << __FUNCTION__ << endl; }
};

class Derived : public Base
{
public:
	void print()
	{ cout << __FUNCTION__ << endl; }
};

int main()
{
	printf("1) 업캐스팅: Print() 메소드가 기반 클래스의 메소드로 호출된 것에 초점.\n");
	Monster* pSlime = new Slime();		// 업캐스팅
	pSlime->Print();
	printf("\n");

	printf("2) 다운캐스팅: Print() 메소드가 파생 클래스의 오버라이딩 된 메소드로 호출된 것에 초점.\n");
	((Slime*)pSlime)->Print();			// 일시적 다운캐스팅(캐스팅 연산자) -> 강제적 형변환
	//delete pSlime;					// * 업캐스팅 주의점: delete는 전달받는 인자의 형식을 기준으로 소멸자를 호출하기 때문에
										//                  이와 같이 사용하면 기반 클래스의 소멸자가 먼저 호출되므로 잘못된 방식임.
	delete (Slime*)pSlime;				// * 업캐스팅 후 올바른 소멸자 호출 방법(파생 클래스로 다운캐스팅한 다음 delete 연산자 사용).
	pSlime = nullptr;


	// C-스타일 캐스팅 연산자(C-Style casting operator)
	// : C언어에서부터 제공되는 캐스팅 연산자로,
	//   논리와 맞지 않아도 강제적 형변환을 수행하는 연산자(컴파일 오류가 나지 않음).
	printf("C-style 캐스팅 연산자 ()의 사용 예시.\n");
	const char* str1 = "Hello";
	printf("str1     : %p\n", str1);
	printf("(int)str1: %i\n", (int)str1);
	printf("\n");


	// static_cast<type-id>(expression)
	// : 자료형 간의 형변환 및, 상속 관계에 있는 클래스의 객체를 가리키는 포인터에 대한 형변환을 수행하는 연산자.
	//   C-스타일 캐스팅 연산자와는 다르게, 논리적으로 변경 가능한 경우에만 캐스팅을 허용한다.
	//   * 상속 관계에 있는 클래스 사이에서 아래와 같은 기능들이 가능함.
	//     1) 기반 클래스 포인터가 기반 클래스를 가리키는 것이 가능.
	//     2) 파생 클래스 포인터가 파생 클래스를 가리키는 것이 가능.
	//     3) 기반 클래스 포인터가 파생 클래스를 가리키는 것이 가능(= 업캐스팅).
	//     4) 파생 클래스 포인터가 기반 클래스를 가리키는 것이 가능(단, 이 경우에는 오류 주의).
	const char* str2 = "Hello";
	//static_cast<int>(str2);	- Error -	* 포인터를 int 형식으로 변경하기 때문에 논리적 오류로 인한 컴파일 에러.


	// dynamic_cast<type-id>(expression)
	// : 상속 관계에 있는 클래스들의 객체를 가리키는 포인터를 캐스팅연산자로,
	//   명시적 업캐스팅이 가능하다(단, 업캐스팅은 본질적으로 자연스러운 캐스팅이므로 static_cast가 더 많이 사용된다).
	//   일반적으로 dynamic_cast 연산자는 다운캐스팅을 허용하지 않으나,
	//   기반 클래스가 다형성 클래스인 경우에는 업캐스팅 되어있는 파생 클래스 객체의 안전한 다운캐스팅(safe downcasting)에 사용 가능하다.
	//   * 성공할 경우 : new_type의 value를 반환.
	//   * 실패할 경우(new_type = pointer)   : null pointer를 반환.
    //               (new_type = reference) : bad_cast를 반환.
	printf("dynamic_cast 사용 예시.\n");
	Base* pBase = new Derived();
	pBase->print();
	Derived* pDerived = dynamic_cast<Derived*>(pBase);		// 기반 클래스가 다형성 클래스이기 때문에 가능.
	pDerived->print();
	delete pBase;
	pBase = nullptr;
	printf("\n");


	// reinterpret_cast<type-id>(expression)
	// : 임의의 포인터 타입끼리의 강제적인 형변환을 허용하는 연산자.
	//   * 변경될 자료형 또는 변경하는 자료형 중 하나 이상이 포인터여야 한다.
	//   ex) int  -> int* 와 같은 변환이 가능하나, 이러한 방식으로 형변환을 통해 주소에 접근하는 것은 매우 위험하다.
	//       int* -> void* -> long* 과 같은 변환이 가능하다.


	// const_cast<type-id>(expression)
	// : 포인터 또는 참조형의 상수성을 일시적으로 제거할 때 사용되는 연산자.
	//   * 또는 volatile 키워드를 일시적으로 제거할 때에도 사용 가능하다.
	printf("const_cast 사용 예시.\n");
	const int Const = 10;
	const int* pConst = &Const;
	int* pTemp = const_cast<int*>(pConst);
	*pTemp = 100;
	//*pConst = 100;	- Error -		* pointer to constant 형식이므로 pConst의 역참조를 통해 값의 수정 불가능
	//Const = 10;		- Error -		* const 키워드로 선언되어 값의 수정 불가능.
	printf("Const  : %i\n", Const);
	printf("*pConst: %i\n", *pConst);
	printf("*pTemp : %i\n", *pTemp);
	printf("\n");

	return 0;
}