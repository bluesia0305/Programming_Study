// 2022-06-20 ����


// ����ü�� �Ű������� �ϴ� �Լ��� ���� �� ȣ��(����).


#include <iostream>

struct Monster
{
	char name[32];
	int hp;
	int atk;
};

void PrintMonster(Monster monster)
{
	printf("Name: %s\n", monster.name);
	printf("HP: %i\n", monster.hp);
	printf("ATK: %i\n", monster.atk);
}

int main()
{
	Monster slime = { "Slime", 100, 10 };
	PrintMonster(slime);

	return 0;
}