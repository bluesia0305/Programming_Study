// Monster Slime과 Fairy를 만들어주세요
// * 단, 상속 기능을 이용하며, 각 멤버의 접근제한자를 고려하여 구현(무조건 public으로 구현 X).
//
// 1) Slime: Name, HP, Lv, ATK, JumpHeight, Attack(), Print(), Jump()
// 2) Fairy: Name, HP, Lv, ATK, FlyingSpeed, Attack(), Print(), Flying()

#include <iostream>
#include <string>
using namespace std;

class Monster
{
private:
	const int Lv;
	const float ATK;
	
protected:
	string Name;
	float HP;

public:
	Monster() : Name("NULL"), Lv(0), HP(0.0f), ATK(0.0f)
	{};

	Monster(string name, int lv, float hp, float atk) : Name(name), Lv(lv), HP(hp), ATK(atk)
	{};

	void Attack()
	{ printf("%s >> %.2f 의 공격력으로 공격합니다.\n", Name.c_str(), ATK); }

	void Print() const
	{ printf("%s [Lv: %i], [HP: %.2f], [ATK: %.2f]\n", Name.c_str(), Lv, HP, ATK); }
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

	void Jump() const
	{ printf("%s >> %.2f 의 높이만큼 점프합니다.\n", Name.c_str(), JumpHeight); }
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

	void Flying() const
	{ printf("%s >> %.2f 의 속도로 날아다닙니다.\n", Name.c_str(), FlyingSpeed); }
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