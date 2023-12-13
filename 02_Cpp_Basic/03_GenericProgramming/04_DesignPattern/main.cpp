// 2022-07-27 ����


#include "01_Singleton.h"

// ���ø� ��� ����(Template recursion)
// : ��� Ŭ���� ���ø��� ������ �ڱ� �ڽ����� �Ͽ� ��ӹ޴� ���ø�.

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
	// Singleton ������ ������ ����
	Singleton_test::GetInstance()->GetInstance()->GetInstance()->GetInstance()->GetInstance();


	// ��� Ŭ������ ��ü�� ����Ű�� �����Ͱ� �Ļ� Ŭ������ ��ü�� ����Ű�� �����ͷ� ĳ����
	printf("sizeof(*(Singleton_test::GetInstance())): %zi\n", sizeof(*(Singleton_test::GetInstance())));
	static_cast<Player_test*>(Singleton_test::GetInstance())->a_base;
	// �Ļ� Ŭ������ ��ü�� ����Ű�� �����Ͱ� �Ļ� Ŭ������ ��ü�� ����Ű�� �����ͷ� ĳ����
	printf("sizeof(*(Player_test::GetInstance())): %zi\n", sizeof(*(Player_test::GetInstance())));
	static_cast<Player_test*>(Player_test::GetInstance())->a_base;


	// ���ø� ���·� ������� singleton ������ ������ Ŭ������ ����, ���ø� ��͸� ���� ���
	//Player::GetInstance()->a_derived;

	return 0;
}