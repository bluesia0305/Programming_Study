#include <iostream>

// 전역 함수
void Add(int* Var)
{ *Var += 10; }

// A 라는 구조
struct A
{
	// 맴버 변수 (성분)
	int Var = 0;

	// 맴버 함수 (행동)
public:
	void PointerFunc() {}

	void Add()
	{
		// this pointer
		// 자기 자신을 가리키는 포인터
		this->Var += 10;
		printf("%p \n", this);
	}
};

struct Item
{
	std::string Name = "검";
	int Atk = 10;
	int Durability = 40;

	void Print() { std::cout << Name << " : " << Atk << std::endl; }
	void Destory() { delete this; }
};

class Player
{
public:
	std::string Name = "Player";
	Item* pItem = nullptr;

	void Equip(Item* item)
	{
		pItem = item;
		printf("장착한 아이템 \n");
		pItem->Print();
	}

	// 이중 포인터로 하지 않으면 trader의 item은 바뀌지 않음.
	void Trade(Item** tradeitem)
	{
		printf("Trade 전 \n");
		printf("Player : %p \n", pItem);
		printf("Trader : %p \n", tradeitem);

		Item* temp = pItem;
		pItem = *tradeitem;
		*tradeitem = temp;

		printf("Trade 전 \n");
		printf("Player : %p \n", pItem);
		pItem->Print();
	}

	void Attack()
	{
		if (--pItem->Durability == 0)
		{
			pItem->Destory();
			pItem = nullptr;
		}
	}
};

int main()
{
	Player player;

	player.Equip(new Item());	// 플레이어에게 검

	Player Trader;
	Item* item = new Item();	// 아이템 생성
	item->Name = "활";			// 아이템 이름을 활로 설정
	Trader.pItem = item;		// 트레이더가 활을 가지고 있음.

	printf("%p \n", player.pItem);
	printf("%p \n", Trader.pItem);
	player.Trade(&Trader.pItem);

	std::cout << player.pItem->Name << std::endl;
	std::cout << Trader.pItem->Name << std::endl;

	return 0;
}