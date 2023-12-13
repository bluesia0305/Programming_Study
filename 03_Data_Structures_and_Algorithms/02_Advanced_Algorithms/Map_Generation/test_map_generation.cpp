#include <random>
#include <vector>
#include <iostream>
#include <Windows.h>

#define ROW_MAX			15
#define COL_MAX			15
#define ROW_CENTER		(ROW_MAX - 1) / 2
#define COL_CENTER		(COL_MAX - 1) / 2
#define PROB_N_MAX		99
#define PROB_CRIT		50					// 방 생성 포기 확률(백분율)
#define NUM_MAP_MIN		12					// 방 최소 갯수
#define NUM_MAP_MAX		15					// 방 최대 갯수

#define TEST								// ####### 방 생성 무한루프 테스트(필요 없을때 주석처리) #######

#ifdef TEST
#define TRY_AGAIN tryAgain:
#define TEST_BLOCK { Sleep(100); system("cls"); goto tryAgain; }
#else
#define TRY_AGAIN 
#define TEST_BLOCK {}
#endif

enum ROOM_STYLE
{
	ROOM_GENERAL = 1,
	ROOM_SHOP	 = 2,
	ROOM_SPECIAL = 3,
	ROOM_BOSS	 = 4,
	ROOM_START	 = 5,
};

struct Position
{
	int row	= 0;	// Row
	int col	= 0;	// Column
};

void Initialize(int map[][COL_MAX])
{
	for (int i = 0; i < ROW_MAX; ++i)
	{ for (int j = 0; j < COL_MAX; ++j) { map[i][j] = 0; } }
	map[ROW_CENTER][COL_CENTER] = ROOM_START;
}

void Initialize(std::vector<Position>& vector)
{
	vector.clear();
	vector.push_back(Position{ ROW_CENTER, COL_CENTER });
}

int Sum_all(int map[][COL_MAX])
{
	int sum = 0;
	for (int i = 0; i < ROW_MAX; ++i)
	{ for (int j = 0; j < COL_MAX; ++j) { if (map[i][j]) ++sum; }	}
	return sum;
}

int Sum_neighbor(int map[][COL_MAX], Position pos)
{
	int sum = 0;
	if (pos.row	+ 1 <= ROW_MAX && map[pos.row + 1][pos.col]) ++sum;
	if (pos.col	+ 1 <= COL_MAX && map[pos.row][pos.col + 1]) ++sum;
	if (pos.row	- 1 >= 0	   && map[pos.row - 1][pos.col]) ++sum;
	if (pos.col	- 1 >= 0	   && map[pos.row][pos.col - 1]) ++sum;
	return sum;
}

void Print(int map[][COL_MAX])
{
	for (int i = 0; i < ROW_MAX; ++i)
	{
		for (int j = 0; j < COL_MAX; ++j)
		{
			switch (map[i][j])
			{
			case ROOM_GENERAL : printf("* "); break;
			case ROOM_SHOP	  : printf("s "); break;
			case ROOM_SPECIAL : printf("h "); break;
			case ROOM_BOSS	  : printf("b "); break;
			case ROOM_START	  : printf("S "); break;
			case 0			  : printf("  "); break;
			}
		}
		printf("\n");
	}
	printf("\n");
}

void Expand(int map[][COL_MAX], std::vector<Position> positions)
{
	std::vector<Position>				created;
	std::random_device					rd;
	std::mt19937						gen(rd());
	std::uniform_int_distribution<int>	dis(0, PROB_N_MAX);

	int increment = 1;
	auto iter = positions.begin();
	for (; iter != positions.end(); ++iter)
	{
		for (int direction : {1, 2, 3, 4})
		{
			int row;
			int col;

			switch (direction)
			{
			case 1: case 3:
			{
				row	= iter->row + increment;
				col	= iter->col;
				break;
			}
			case 2: case 4:
			{
				row	= iter->row;
				col	= iter->col + increment;
				increment *= -1;
				break;
			}
			}

			if (row < 0 || row > ROW_MAX || col < 0 || col > COL_MAX)	continue;
			if (map[row][col])											continue;
			if (Sum_neighbor(map, Position{ row, col }) >= 2)			continue;
			if (Sum_all(map) == NUM_MAP_MAX)							return;
			if (dis(gen) <= PROB_CRIT)									continue;

			map[row][col] = 1;
			created.push_back(Position{ row, col });
		}
	}
	if (!created.empty()) Expand(map, created);
}

bool Generate_special_rooms(int map[][COL_MAX])
{
	std::vector<Position>	candidates;
	std::random_device		rd;
	std::mt19937			gen(rd());

	for (int i = 0; i < ROW_MAX; ++i)
	{
		for (int j = 0; j < COL_MAX; ++j)
		{
			if (map[i][j] == ROOM_GENERAL && Sum_neighbor(map, Position{ i, j }) == 1)
				candidates.push_back(Position{ i, j });
		}
	}
	if (candidates.size() < 3) return false;

	std::uniform_int_distribution<int> dis(0, static_cast<int>(candidates.size()) - 1);
	while (true)
	{
		int rand1 = dis(gen);
		int rand2 = dis(gen);
		int rand3 = dis(gen);
		if (rand1 != rand2 &&
			rand2 != rand3 &&
			rand3 != rand1)
		{
			map[candidates[rand1].row][candidates[rand1].col] = ROOM_BOSS;
			map[candidates[rand2].row][candidates[rand2].col] = ROOM_SHOP;
			map[candidates[rand3].row][candidates[rand3].col] = ROOM_SPECIAL;
			break;
		}
	}
	return true;
}

int main()
{
TRY_AGAIN

	int						map[ROW_MAX][COL_MAX]	{ 0 };
	std::vector<Position>	created;
	
	while (true)
	{
		Initialize(map);
		Initialize(created);
		Expand(map, created);
		if (Sum_all(map) > NUM_MAP_MIN)
		{
			// 5 = 시작지점
			// 4 = 보스방
			// 3 = 상점		or	 비밀방
			// 2 = 비밀방	or	 상점
			// 1 = 일반방
			if (Generate_special_rooms(map)) break;
		}
	}
	Print(map);
	TEST_BLOCK
	return 0;
}