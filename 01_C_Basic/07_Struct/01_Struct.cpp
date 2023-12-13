// 2022-06-08 수업


// 사용자 정의 자료형(구조체, Struct)
// : VS에서 기본적으로 제공하는 C언어의 자료형(들)을 사용하여 정의된 자료형.


#include <stdio.h>

// Player 라는 이름의 구조체를 아래와 같이 선언
// (레벨(unsigned char), 체력(float), 공격력(float)의 3 개의 자료형을 갖는 사용자 정의 자료형).
struct Player
{
	// 아래와 같이 구조체를 이루는 각 자료형 요소를 멤버라고 부름.
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
	// 어떠한 데이터를 저장할 공간을 선언할 때 아래와 같이 {자료형} {변수명}; 의 형태로 선언하며
	// 초기화할 때에는 {식별자(변수명)} = {값}; 의 형태로 초기화 한다.
	int variableName = 4;
	int variableName2 = variableName;

	// 구조체도 마찬가지 원리로 {구조체명} {변수명}; 의 형태로 선언됨.
	// 초기화할 때에도 마찬가지 원리로 {변수명.식별자} = {값}; 의 형태로 초기화할 수 있다.
	// * 멤버 직접접근연산자(.)
	//   : 구조체를 이루고 있는 특정 멤버에 접근할 수 있게 해주는 연산자.
	// * 참고) C++가 아닌 C언어에서 구조체를 선언할 때에는 struct {구조체명} {변수명}; 의 형태로 선언해야함.
	Player player1;
	player1.hp = 100.0f;
	player1.atk = 10.0f;
	player1.lv = 10;

	printf("Player1 [Lv : %i] [HP : %.1f] [ATK : %.1f]\n", player1.lv, player1.hp, player1.atk);

	// 단, 구조체 전체 멤버들의 값을 한번에 초기화하고 싶을 때에는
	// 아래와 같이 중괄호({,})를 이용한다.
	// 이때, 입력한 순서에 따라 구조체 선언문 내의 멤버의 순서에 맞게 값이 저장된다.
	Player player2 = { 2, 20.0f, 2.0f };
	printf("Player2 [Lv : %i] [HP : %.1f] [ATK : %.1f]\n", player2.lv, player2.hp, player2.atk);

	// 또한, 기존에 선언되어있는 변수에 저장되어있는 데이터를 그대로 복사하는 것도 마찬가지로 가능함.
	player2 = player1;
	printf("Player2 [Lv : %i] [HP : %.1f] [ATK : %.1f]\n\n", player2.lv, player2.hp, player2.atk);

	// 구조체가 공간을 할당하는 방법에 대해 확인해보기.
	printf("int 자료형의 size: %zi\n", sizeof(int));				// int의 경우 4 Byte.
	printf("Player 자료형의 size: %zi\n\n", sizeof(Player));		// 구조체의 경우에는 멤버들 중 가장 큰 size를 갖는 자료형의 size x 멤버의 수 만큼의 크기를 가짐.


	// 2022-06-08 실습
	// Monster형 변수를 만들어 멤버들의 값을 출력해주세요.
	// Monster는 Lv, HP, ATK, DEF 멤버를 가지고 있습니다.

	Monster monster = { 10, 1000.0f, 100.0f };					// DEF, DEF2의 값을 지정하지 않으면 어떻게 될까?

	// 선언하지 않은 데이터는 구조체 선언문에서 초기화한 값으로 자동 지정된다(예시에서 DEF의 값).
	// 구조체에서도 초기화되지 않은 멤버의 경우, 0으로 초기화 됨(예시에서 DEF2의 값).
	printf("Monster [Lv : %i] [HP : %.1f] [ATK : %.1f] [DEF : %.1f] [DEF2 : %.1f]\n",
		monster.lv, monster.hp, monster.atk, monster.def, monster.def2);
	// 참고) 구조체가 아닌 단일변수의 경우에는 선언 후 초기화하지 않은 값을 출력하려고 하면 오류가 발생함.
	/*int myVar;
	printf("%i", myVar);	- error -*/

	// typedef: 자료형에 대한 별칭을 선언할 수 있도록 해주는 명령어.
	typedef unsigned char UINT;
	UINT a = 1;

	return 0;
}