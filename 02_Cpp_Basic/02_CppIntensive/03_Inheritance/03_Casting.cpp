// 2022-07-14 ����


#include <iostream>
#include <string>
using namespace std;

// ��ĳ����(Upcasting)
// : ��� Ŭ������ ����Ű�� ������ �������� �Ļ� Ŭ������ ��ü�� ����Ű�� ���.
//   ��, �Ļ� Ŭ������ ��ü�� ��� Ŭ���� Ÿ������ ����ȯ�Ǵ� ���̴�.

// �ٿ�ĳ����(Downcasting)
// : ��ĳ���õ� ���� �ٽ� �����·� ������ ���� ���Ѵ�.
//   * �ٿ� ĳ������ �� ĳ���ð� �޸� ����� Ÿ�� ��ȯ�� �����ؾ� �Ѵ�.

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
	{ printf("��� Ŭ����(Monster)�� �Ҹ��� ȣ��.\n"); }

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

	~Slime()
	{ printf("�Ļ� Ŭ����(Slime)�� �Ҹ��� ȣ��.\n"); }

	__forceinline void Jump() const
	{
		printf("%.2f �� ���̸�ŭ �����մϴ�.\n", JumpHeight);
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
	{ printf("�Ļ� Ŭ����(Fairy)�� �Ҹ��� ȣ��.\n"); }

	__forceinline void Flying() const
	{
		printf("%.2f �� �ӵ��� ���ƴٴմϴ�.\n", FlyingSpeed);
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
	printf("1) ��ĳ����: Print() �޼ҵ尡 ��� Ŭ������ �޼ҵ�� ȣ��� �Ϳ� ����.\n");
	Monster* pSlime = new Slime();		// ��ĳ����
	pSlime->Print();
	printf("\n");

	printf("2) �ٿ�ĳ����: Print() �޼ҵ尡 �Ļ� Ŭ������ �������̵� �� �޼ҵ�� ȣ��� �Ϳ� ����.\n");
	((Slime*)pSlime)->Print();			// �Ͻ��� �ٿ�ĳ����(ĳ���� ������) -> ������ ����ȯ
	//delete pSlime;					// * ��ĳ���� ������: delete�� ���޹޴� ������ ������ �������� �Ҹ��ڸ� ȣ���ϱ� ������
										//                  �̿� ���� ����ϸ� ��� Ŭ������ �Ҹ��ڰ� ���� ȣ��ǹǷ� �߸��� �����.
	delete (Slime*)pSlime;				// * ��ĳ���� �� �ùٸ� �Ҹ��� ȣ�� ���(�Ļ� Ŭ������ �ٿ�ĳ������ ���� delete ������ ���).
	pSlime = nullptr;


	// C-��Ÿ�� ĳ���� ������(C-Style casting operator)
	// : C�������� �����Ǵ� ĳ���� �����ڷ�,
	//   ���� ���� �ʾƵ� ������ ����ȯ�� �����ϴ� ������(������ ������ ���� ����).
	printf("C-style ĳ���� ������ ()�� ��� ����.\n");
	const char* str1 = "Hello";
	printf("str1     : %p\n", str1);
	printf("(int)str1: %i\n", (int)str1);
	printf("\n");


	// static_cast<type-id>(expression)
	// : �ڷ��� ���� ����ȯ ��, ��� ���迡 �ִ� Ŭ������ ��ü�� ����Ű�� �����Ϳ� ���� ����ȯ�� �����ϴ� ������.
	//   C-��Ÿ�� ĳ���� �����ڿʹ� �ٸ���, �������� ���� ������ ��쿡�� ĳ������ ����Ѵ�.
	//   * ��� ���迡 �ִ� Ŭ���� ���̿��� �Ʒ��� ���� ��ɵ��� ������.
	//     1) ��� Ŭ���� �����Ͱ� ��� Ŭ������ ����Ű�� ���� ����.
	//     2) �Ļ� Ŭ���� �����Ͱ� �Ļ� Ŭ������ ����Ű�� ���� ����.
	//     3) ��� Ŭ���� �����Ͱ� �Ļ� Ŭ������ ����Ű�� ���� ����(= ��ĳ����).
	//     4) �Ļ� Ŭ���� �����Ͱ� ��� Ŭ������ ����Ű�� ���� ����(��, �� ��쿡�� ���� ����).
	const char* str2 = "Hello";
	//static_cast<int>(str2);	- Error -	* �����͸� int �������� �����ϱ� ������ ���� ������ ���� ������ ����.


	// dynamic_cast<type-id>(expression)
	// : ��� ���迡 �ִ� Ŭ�������� ��ü�� ����Ű�� �����͸� ĳ���ÿ����ڷ�,
	//   ����� ��ĳ������ �����ϴ�(��, ��ĳ������ ���������� �ڿ������� ĳ�����̹Ƿ� static_cast�� �� ���� ���ȴ�).
	//   �Ϲ������� dynamic_cast �����ڴ� �ٿ�ĳ������ ������� ������,
	//   ��� Ŭ������ ������ Ŭ������ ��쿡�� ��ĳ���� �Ǿ��ִ� �Ļ� Ŭ���� ��ü�� ������ �ٿ�ĳ����(safe downcasting)�� ��� �����ϴ�.
	//   * ������ ��� : new_type�� value�� ��ȯ.
	//   * ������ ���(new_type = pointer)   : null pointer�� ��ȯ.
    //               (new_type = reference) : bad_cast�� ��ȯ.
	printf("dynamic_cast ��� ����.\n");
	Base* pBase = new Derived();
	pBase->print();
	Derived* pDerived = dynamic_cast<Derived*>(pBase);		// ��� Ŭ������ ������ Ŭ�����̱� ������ ����.
	pDerived->print();
	delete pBase;
	pBase = nullptr;
	printf("\n");


	// reinterpret_cast<type-id>(expression)
	// : ������ ������ Ÿ�Գ����� �������� ����ȯ�� ����ϴ� ������.
	//   * ����� �ڷ��� �Ǵ� �����ϴ� �ڷ��� �� �ϳ� �̻��� �����Ϳ��� �Ѵ�.
	//   ex) int  -> int* �� ���� ��ȯ�� �����ϳ�, �̷��� ������� ����ȯ�� ���� �ּҿ� �����ϴ� ���� �ſ� �����ϴ�.
	//       int* -> void* -> long* �� ���� ��ȯ�� �����ϴ�.


	// const_cast<type-id>(expression)
	// : ������ �Ǵ� �������� ������� �Ͻ������� ������ �� ���Ǵ� ������.
	//   * �Ǵ� volatile Ű���带 �Ͻ������� ������ ������ ��� �����ϴ�.
	printf("const_cast ��� ����.\n");
	const int Const = 10;
	const int* pConst = &Const;
	int* pTemp = const_cast<int*>(pConst);
	*pTemp = 100;
	//*pConst = 100;	- Error -		* pointer to constant �����̹Ƿ� pConst�� �������� ���� ���� ���� �Ұ���
	//Const = 10;		- Error -		* const Ű����� ����Ǿ� ���� ���� �Ұ���.
	printf("Const  : %i\n", Const);
	printf("*pConst: %i\n", *pConst);
	printf("*pTemp : %i\n", *pTemp);
	printf("\n");

	return 0;
}