// 2022-07-14 수업


#include <iostream>
#include <string>
using namespace std;

//  2022-07-13 과제 코딩 개선사항:
//  1) Lv   -> const 키워드 선언
//  2) Name -> protected, const 키워드 선언
//  3) ATK  -> protected 키워드 선언, const 키워드 제외(변경 가능하도록)
//  4) __forceinline 키워드 추가
//  5) print() 메소드 오버라이딩

// 메소드 오버라이딩(Method overriding)
// : 상속 관계에 있는 기반 클래스에 이미 정의된 메소드를
//   파생 클래스에서 동일한 시그니쳐를 갖는 메소드로 다시 정의하는 것.
// 
//   * 오버라이딩(overriding): 파생 클래스의 메소드의 선언부(프로토타입)가 기반 클래스의 메소드와 동일하며 기능만을 재정의한다.
//                            즉, 기반 클래스에서 상속받은 함수만 재정의가 가능하다.
// 
//   * 오버로딩(overloading) : 메서드의 선언부가 다른 여러 메소드를 하나의 이름으로 중복 정의하는 것.
//                            오버로딩할 수 있는 메소드 개수의 제한이 없다.

class Monster
{
private:
	const unsigned Lv;

protected:
	const string Name;
	float HP;
	float ATK;

public:
	Monster() : Name("NULL"), Lv(0), HP(0.0f), ATK(0.0f)
	{};

	Monster(string name, int lv, float hp, float atk) : Name(name), Lv(lv), HP(hp), ATK(atk)
	{};

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

	__forceinline void Jump() const
	{
		printf("%s 가 %.2f 의 높이만큼 점프합니다.\n", Name.c_str(), JumpHeight);
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

	__forceinline void Flying() const
	{
		printf("%s 가 %.2f 의 속도로 날아다닙니다.\n", Name.c_str(), FlyingSpeed);
	}

	__forceinline void Print() const
	{
		Monster::Print();
		printf("FlyingSpeed: %.2f\n", FlyingSpeed);
	}
};

int main()
{
	printf("1) 기본 설정값의 Slime 클래스의 객체 생성.\n");
	Slime slime_default;
	slime_default.Print();
	slime_default.Attack();
	slime_default.Jump();
	printf("\n");

	printf("2) 사용자 설정값을 갖는 Slime 클래스의 객체 생성.\n");
	Slime slime_custom("King Slime", 100, 100000.0f, 1000.0f);
	slime_custom.Print();
	slime_custom.Attack();
	slime_custom.Jump();
	printf("\n");

	printf("3) 기본 설정값의 Fairy 클래스의 객체 생성.\n");
	Fairy fairy_default;
	fairy_default.Print();
	fairy_default.Attack();
	fairy_default.Flying();
	printf("\n");

	printf("4) 사용자 설정값을 갖는 Fairy 클래스의 객체 생성.\n");
	Fairy fairy_custom("Queen Fairy", 120, 150000.0f, 2000.0f);
	fairy_custom.Print();
	fairy_custom.Attack();
	fairy_custom.Flying();
	printf("\n");

	return 0;
}