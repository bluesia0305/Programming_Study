// 2022-06-20 수업


// 구조체를 매개변수로 하는 함수의 선언 및 호출(실행).


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