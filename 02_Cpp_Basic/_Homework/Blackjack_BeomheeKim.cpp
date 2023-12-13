#include <iostream>
#include <string>
#include <Windows.h>

struct Trump
{
	std::string suit = "";
	int rank = 0;

	void print() const
	{
		std::string rankToStr;
		if (rank == 1) { rankToStr = "A"; }
		else if (rank == 11) { rankToStr = "J"; }
		else if (rank == 12) { rankToStr = "Q"; }
		else if (rank == 13) { rankToStr = "K"; }
		else rankToStr = std::to_string(rank);
		printf("%s%s", suit.c_str(), rankToStr.c_str());
	}
};

struct Participant
{
	// �̷л� ���� ���� ���� �� �ִ� ī���� �� = 11��.
	// * ���� ���� �̴� ���: (A) x 4��, (2) x 4��, (3) x 3�� = ���� 21.
	Trump cards[11] = {};			// ���� ���� ī���� ������
	std::string role = "Player";	// ���� (player, dealer)
	int numCards = 0;				// ī�� �� ���� ����
	bool holdA = false;				// A ī���� ���� ����
	int sum = 0;					// ���� ���� ī�忡 ���� ������ ����
								    // (��, A�� �����ϸ� 1, 11 ���� ������ �Ǵ�)

	Participant(std::string roleName)
	{ role = roleName; }

	void setCard(int index, Trump card)
	{
		if (numCards < 2)
		{
			printf("%s�� Ʈ���� ī�带 �� �� �޽��ϴ�: ", role.c_str());
			card.print();
			printf("\n");
		}
		else printf("%s >> HIT\n", role.c_str());
		Sleep(1000);
		
		cards[index] = card;
		numCards++;

		if (cards[index].rank < 10) sum += cards[index].rank;
		else sum += 10;

		if (card.rank == 1 && holdA == false) holdA = true;
	}

	void showCards() const
	{
		printf("%s >> ", role.c_str());
		if (numCards > 0)
		{
			for (int i = 0; i < numCards; i++)
			{
				cards[i].print();
				printf(" ");
			}
			printf("\n");
		}		
	}

	int getNumCards() const
	{ return numCards; }

	int decision() const
	{
		if (holdA)
		{
			if ((sum + 10) > 21) return sum;
			else return (sum + 10);
		}
		return sum;
	}
};

void makeTrumps(Trump* const trumps)
{
	printf("Ʈ���� ī�� 52���� �����մϴ�.\n");
	system("pause");

	std::string suit;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			suit = "��";
			break;
		case 1:
			suit = "��";
			break;
		case 2:
			suit = "��";
			break;
		case 3:
			suit = "��";
			break;
		}

		for (int j = 0; j < 13; j++)
		{
			trumps[13 * i + j].suit = suit;
			trumps[13 * i + j].rank = j + 1;
		}
	}
}

void shuffle(Trump* const trumps)
{
	printf("Ʈ���� ī�� 52���� ������ ���Ƿ� �����ϴ�.\n");
	system("pause");

	srand(GetTickCount64());
	Trump temp;
	for (int i = 51; i > 0; i--)
	{
		int num = rand() % (i + 1);
		temp = trumps[i];
		trumps[i] = trumps[num];
		trumps[num] = temp;
	}
	printf("\n");
}

void printTrumps(Trump* const trumps)
{
	for (int i = 0; i < 52; i++)
	{
		trumps[i].print();
		printf(" ");
		if (i % 13 == 12) printf("\n");
	}
	printf("\n");
}

void printBlackjack(std::string roleName)
{
	printf("\n");
	Sleep(500);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	Sleep(500);
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	Sleep(500);
	printf("�ڡ١�  %s\'s BLACKJACK !  �١ڡ�\n", roleName.c_str());
	Sleep(500);
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n");
	Sleep(500);
	printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�\n\n");
	Sleep(2000);
}

int main()
{
#pragma region TRUMPS
	Trump trumps[52] = {};
	static int index = 0;
	makeTrumps(trumps);
	Sleep(2000);
	printTrumps(trumps);
	shuffle(trumps);
#pragma endregion

#pragma region PLAYER
	Participant player("Player");
	std::string choice;
	printf("[Player ��]\n");
	Sleep(2000);
	while (true)
	{
		player.setCard(player.getNumCards(), trumps[index]);
		index++;
		if (player.getNumCards() >= 2)
		{
			player.showCards();

			if (player.getNumCards() == 2 &&
				player.decision() == 21)
			{
				printBlackjack("Player");
				printf("[Result] Player�� �¸��Ͽ����ϴ�.\n");
				return 0;
			}
			else if (player.decision() == 21)
			{
				Sleep(1000);
				printf("* Player�� ī���� ���� ������ 21�� �Ǿ� �ڵ����� STAY �մϴ�.\n");
				Sleep(1000);
				printf("Player >> STAY\n");
				break;
			}
			else if	(player.decision() > 21) break;
		}

		if (player.getNumCards() >= 2)
		{
			while (true)
			{
				printf("ī�带 �߰��� �����ðڽ��ϱ�(HIT)? �Է�[y, n]: ");
				std::cin >> choice;
				if (choice == "y" || choice == "n") break;
			}

			if (choice == "n")
			{
				printf("Player >> STAY\n");
				break;
			}
		}
	}
	Sleep(1000);
	printf("* Player�� ī���� ���� ����: %i\n", player.decision());

	Sleep(1000);
	if (player.decision() > 21)
	{
		printf("Player >> BUST\n\n");
		Sleep(2000);
		printf("[Result] Player�� �й��Ͽ����ϴ�.\n");
		return 0;
	}
#pragma endregion

#pragma region DEALER
	else
	{
		Sleep(1000);
		printf("\n");
		printf("[Dealer ��]\n");
		Sleep(2000);
		Participant dealer("Dealer");
		while (true)
		{
			dealer.setCard(dealer.getNumCards(), trumps[index]);
			index++;
			
			if (dealer.getNumCards() >= 2)
			{
				Sleep(1000);
				dealer.showCards();
				Sleep(2000);

				if (dealer.getNumCards() == 2 &&
					dealer.decision() == 21)
				{
					printBlackjack("Dealer");
					printf("[Result] Player�� �й��Ͽ����ϴ�.\n");
					return 0;
				}
				else if (dealer.decision() > 21) break;
				else if (dealer.decision() >= 17)
				{
					printf("Dealer >> STAY\n");
					break;
				}
			}
		}
		Sleep(1000);
		printf("* Dealer�� ī���� ���� ����: %i\n", dealer.decision());
#pragma endregion

#pragma region RESULT
		Sleep(1000);
		if (dealer.decision() > 21)
		{
			printf("Dealer >> BUST\n\n");
			Sleep(2000);
			printf("[Result] Player�� �¸��Դϴ�.\n");
			return 0;
		}
		else
		{
			printf("\n");
			Sleep(1000);
			if (player.decision() > dealer.decision())
				printf("[Result] Player�� ī���� ���� ������ 21�� �� �����Ƿ�, Player�� �¸��Դϴ�.\n");
			else if (player.decision() < dealer.decision())
				printf("[Result] Dealer�� ī���� ���� ������ 21�� �� �����Ƿ�, Player�� �й��Դϴ�.\n");
			else
				printf("[Result] Player�� Dealer�� ī���� ���� ������ �����Ƿ�, Player�� �й��Դϴ�.\n");
		}
	}
#pragma endregion

	return 0;
}