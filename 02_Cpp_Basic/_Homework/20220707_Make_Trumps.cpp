#include <iostream>
#include <string>
using namespace std;

struct Trump
{
	string suit = "";
	int rank = 0;

	void print() const
	{
		string rankToStr;
		if (rank == 1) { rankToStr = "A"; }
		else if (rank == 11) { rankToStr = "J"; }
		else if (rank == 12) { rankToStr = "Q"; }
		else if (rank == 13) { rankToStr = "K"; }
		else rankToStr = to_string(rank);
		printf("%s%s", suit.c_str(), rankToStr.c_str());
	}
};

void makeTrumps(Trump* const trumps)
{
	string suit;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			suit = "♤";
			break;
		case 1:
			suit = "◇";
			break;
		case 2:
			suit = "♧";
			break;
		case 3:
			suit = "♡";
			break;
		}

		for (int j = 0; j < 13; j++)
		{
			trumps[13 * i + j].suit = suit;
			trumps[13 * i + j].rank = j + 1;
			trumps[13 * i + j].print();
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

void shuffle(Trump* const trumps)
{
	printf("트럼프 카드 52장의 순서를 임의로 섞습니다.\n");
	system("pause");

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

int main()
{
	srand(time(NULL));
	Trump trumps[52] = {};

	makeTrumps(trumps);
	shuffle(trumps);
	printTrumps(trumps);

	return 0;
}