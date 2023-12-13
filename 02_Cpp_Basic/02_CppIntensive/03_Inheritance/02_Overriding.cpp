// 2022-07-14 ����


#include <iostream>
#include <string>
using namespace std;

//  2022-07-13 ���� �ڵ� ��������:
//  1) Lv   -> const Ű���� ����
//  2) Name -> protected, const Ű���� ����
//  3) ATK  -> protected Ű���� ����, const Ű���� ����(���� �����ϵ���)
//  4) __forceinline Ű���� �߰�
//  5) print() �޼ҵ� �������̵�

// �޼ҵ� �������̵�(Method overriding)
// : ��� ���迡 �ִ� ��� Ŭ������ �̹� ���ǵ� �޼ҵ带
//   �Ļ� Ŭ�������� ������ �ñ״��ĸ� ���� �޼ҵ�� �ٽ� �����ϴ� ��.
// 
//   * �������̵�(overriding): �Ļ� Ŭ������ �޼ҵ��� �����(������Ÿ��)�� ��� Ŭ������ �޼ҵ�� �����ϸ� ��ɸ��� �������Ѵ�.
//                            ��, ��� Ŭ�������� ��ӹ��� �Լ��� �����ǰ� �����ϴ�.
// 
//   * �����ε�(overloading) : �޼����� ����ΰ� �ٸ� ���� �޼ҵ带 �ϳ��� �̸����� �ߺ� �����ϴ� ��.
//                            �����ε��� �� �ִ� �޼ҵ� ������ ������ ����.

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
		printf("%s >> %.2f �� ���ݷ����� �����մϴ�.\n", Name.c_str(), ATK);
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
		printf("%s �� %.2f �� ���̸�ŭ �����մϴ�.\n", Name.c_str(), JumpHeight);
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
		printf("%s �� %.2f �� �ӵ��� ���ƴٴմϴ�.\n", Name.c_str(), FlyingSpeed);
	}

	__forceinline void Print() const
	{
		Monster::Print();
		printf("FlyingSpeed: %.2f\n", FlyingSpeed);
	}
};

int main()
{
	printf("1) �⺻ �������� Slime Ŭ������ ��ü ����.\n");
	Slime slime_default;
	slime_default.Print();
	slime_default.Attack();
	slime_default.Jump();
	printf("\n");

	printf("2) ����� �������� ���� Slime Ŭ������ ��ü ����.\n");
	Slime slime_custom("King Slime", 100, 100000.0f, 1000.0f);
	slime_custom.Print();
	slime_custom.Attack();
	slime_custom.Jump();
	printf("\n");

	printf("3) �⺻ �������� Fairy Ŭ������ ��ü ����.\n");
	Fairy fairy_default;
	fairy_default.Print();
	fairy_default.Attack();
	fairy_default.Flying();
	printf("\n");

	printf("4) ����� �������� ���� Fairy Ŭ������ ��ü ����.\n");
	Fairy fairy_custom("Queen Fairy", 120, 150000.0f, 2000.0f);
	fairy_custom.Print();
	fairy_custom.Attack();
	fairy_custom.Flying();
	printf("\n");

	return 0;
}