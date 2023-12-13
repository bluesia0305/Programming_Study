// 2022-06-08 ����


// ����� ���� �ڷ���(����ü, Struct)
// : VS���� �⺻������ �����ϴ� C����� �ڷ���(��)�� ����Ͽ� ���ǵ� �ڷ���.


#include <stdio.h>

// Player ��� �̸��� ����ü�� �Ʒ��� ���� ����
// (����(unsigned char), ü��(float), ���ݷ�(float)�� 3 ���� �ڷ����� ���� ����� ���� �ڷ���).
struct Player
{
	// �Ʒ��� ���� ����ü�� �̷�� �� �ڷ��� ��Ҹ� ������ �θ�.
	unsigned char lv;
	float hp;
	float atk;
};

struct Monster
{
	unsigned char lv;
	float hp;
	float atk;
	float def = 57.0f;
	float def2;
};

int main()
{
	// ��� �����͸� ������ ������ ������ �� �Ʒ��� ���� {�ڷ���} {������}; �� ���·� �����ϸ�
	// �ʱ�ȭ�� ������ {�ĺ���(������)} = {��}; �� ���·� �ʱ�ȭ �Ѵ�.
	int variableName = 4;
	int variableName2 = variableName;

	// ����ü�� �������� ������ {����ü��} {������}; �� ���·� �����.
	// �ʱ�ȭ�� ������ �������� ������ {������.�ĺ���} = {��}; �� ���·� �ʱ�ȭ�� �� �ִ�.
	// * ��� �������ٿ�����(.)
	//   : ����ü�� �̷�� �ִ� Ư�� ����� ������ �� �ְ� ���ִ� ������.
	// * ����) C++�� �ƴ� C���� ����ü�� ������ ������ struct {����ü��} {������}; �� ���·� �����ؾ���.
	Player player1;
	player1.hp = 100.0f;
	player1.atk = 10.0f;
	player1.lv = 10;

	printf("Player1 [Lv : %i] [HP : %.1f] [ATK : %.1f]\n", player1.lv, player1.hp, player1.atk);

	// ��, ����ü ��ü ������� ���� �ѹ��� �ʱ�ȭ�ϰ� ���� ������
	// �Ʒ��� ���� �߰�ȣ({,})�� �̿��Ѵ�.
	// �̶�, �Է��� ������ ���� ����ü ���� ���� ����� ������ �°� ���� ����ȴ�.
	Player player2 = { 2, 20.0f, 2.0f };
	printf("Player2 [Lv : %i] [HP : %.1f] [ATK : %.1f]\n", player2.lv, player2.hp, player2.atk);

	// ����, ������ ����Ǿ��ִ� ������ ����Ǿ��ִ� �����͸� �״�� �����ϴ� �͵� ���������� ������.
	player2 = player1;
	printf("Player2 [Lv : %i] [HP : %.1f] [ATK : %.1f]\n\n", player2.lv, player2.hp, player2.atk);

	// ����ü�� ������ �Ҵ��ϴ� ����� ���� Ȯ���غ���.
	printf("int �ڷ����� size: %zi\n", sizeof(int));				// int�� ��� 4 Byte.
	printf("Player �ڷ����� size: %zi\n\n", sizeof(Player));		// ����ü�� ��쿡�� ����� �� ���� ū size�� ���� �ڷ����� size x ����� �� ��ŭ�� ũ�⸦ ����.


	// 2022-06-08 �ǽ�
	// Monster�� ������ ����� ������� ���� ������ּ���.
	// Monster�� Lv, HP, ATK, DEF ����� ������ �ֽ��ϴ�.

	Monster monster = { 10, 1000.0f, 100.0f };					// DEF, DEF2�� ���� �������� ������ ��� �ɱ�?

	// �������� ���� �����ʹ� ����ü ���𹮿��� �ʱ�ȭ�� ������ �ڵ� �����ȴ�(���ÿ��� DEF�� ��).
	// ����ü������ �ʱ�ȭ���� ���� ����� ���, 0���� �ʱ�ȭ ��(���ÿ��� DEF2�� ��).
	printf("Monster [Lv : %i] [HP : %.1f] [ATK : %.1f] [DEF : %.1f] [DEF2 : %.1f]\n",
		monster.lv, monster.hp, monster.atk, monster.def, monster.def2);
	// ����) ����ü�� �ƴ� ���Ϻ����� ��쿡�� ���� �� �ʱ�ȭ���� ���� ���� ����Ϸ��� �ϸ� ������ �߻���.
	/*int myVar;
	printf("%i", myVar);	- error -*/

	// typedef: �ڷ����� ���� ��Ī�� ������ �� �ֵ��� ���ִ� ��ɾ�.
	typedef unsigned char UINT;
	UINT a = 1;

	return 0;
}