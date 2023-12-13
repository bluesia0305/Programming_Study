// 2022-07-27 수업


#include "01_Singleton.h"

// 템플릿 재귀 패턴(Template recursion)
// : 기반 클래스 템플릿의 형식을 자기 자신으로 하여 상속받는 템플릿.

class Player_test : public Singleton_test
{
public:
	int a_derived;
	int b_derived;
	int c_derived;
};

class Player : public Singleton<Player>
{
public:
	int a_derived;
	int b_derived;
};

int main()
{
	Singleton_test::GetInstance()->a_base;
	Singleton_test::GetInstance()->b_base;
	// Singleton 디자인 패턴의 단점
	Singleton_test::GetInstance()->GetInstance()->GetInstance()->GetInstance()->GetInstance();


	// 기반 클래스의 객체를 가리키는 포인터가 파생 클래스의 객체를 가리키는 포인터로 캐스팅
	printf("sizeof(*(Singleton_test::GetInstance())): %zi\n", sizeof(*(Singleton_test::GetInstance())));
	static_cast<Player_test*>(Singleton_test::GetInstance())->a_base;
	// 파생 클래스의 객체를 가리키는 포인터가 파생 클래스의 객체를 가리키는 포인터로 캐스팅
	printf("sizeof(*(Player_test::GetInstance())): %zi\n", sizeof(*(Player_test::GetInstance())));
	static_cast<Player_test*>(Player_test::GetInstance())->a_base;


	// 템플릿 형태로 만들어진 singleton 디자인 패턴의 클래스에 대해, 템플릿 재귀를 통한 상속
	//Player::GetInstance()->a_derived;

	return 0;
}