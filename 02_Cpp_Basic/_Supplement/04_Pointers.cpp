#include <iostream>

// ���� �Լ�
void Add(int* Var)
{ *Var += 10; }

// A ��� ����
struct A
{
	// �ɹ� ���� (����)
	int Var = 0;

	// �ɹ� �Լ� (�ൿ)
public:
	void PointerFunc() {}

	void Add()
	{
		// this pointer
		// �ڱ� �ڽ��� ����Ű�� ������
		this->Var += 10;
		printf("%p \n", this);
	}
};

struct Item
{
	std::string Name = "��";
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
		printf("������ ������ \n");
		pItem->Print();
	}

	// ���� �����ͷ� ���� ������ trader�� item�� �ٲ��� ����.
	void Trade(Item** tradeitem)
	{
		printf("Trade �� \n");
		printf("Player : %p \n", pItem);
		printf("Trader : %p \n", tradeitem);

		Item* temp = pItem;
		pItem = *tradeitem;
		*tradeitem = temp;

		printf("Trade �� \n");
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

	player.Equip(new Item());	// �÷��̾�� ��

	Player Trader;
	Item* item = new Item();	// ������ ����
	item->Name = "Ȱ";			// ������ �̸��� Ȱ�� ����
	Trader.pItem = item;		// Ʈ���̴��� Ȱ�� ������ ����.

	printf("%p \n", player.pItem);
	printf("%p \n", Trader.pItem);
	player.Trade(&Trader.pItem);

	std::cout << player.pItem->Name << std::endl;
	std::cout << Trader.pItem->Name << std::endl;

	return 0;
}