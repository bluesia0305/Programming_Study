#include <iostream>
#include <string>
#include "../Timer.h"

#define MAX		1024
#define INIT	-1

#define START	'S'
#define GOAL	'G'
#define WAY		' '
#define WALL	'#'
#define MARKED	'+'

using namespace std;

enum class Direction
{
	North = 0,
	South,
	East,
	West
};

struct Position
{
	int X, Y;
};

struct MazeDesc
{
	int Rows;
	int Columns;

	char** Data;
};

void ReadMaze(const char* path, MazeDesc* desc)
{
	FILE* fp;
	fopen_s(&fp, path, "r");

	int rows = 0, columns = INIT;
	char buffer[MAX];

	while (fgets(buffer, MAX, fp) != nullptr)
	{
		rows++;

		if (columns == INIT)
			columns = (int)strlen(buffer) - 1;
	}

	desc->Rows = rows;
	desc->Columns = columns;
	desc->Data = new char*[rows];

	for (int i = 0; i < rows; i++)
		desc->Data[i] = new char[columns];

	rewind(fp);

	for (int i = 0; i < rows; i++)
	{
		fgets(buffer, MAX, fp);

		for (int j = 0; j < columns; j++)
			desc->Data[i][j] = buffer[j];
	}

	fclose(fp);
}

bool GetNextStep(MazeDesc* desc, Position* curr, Direction direction, Position* next)
{
	switch (direction)
	{
		case Direction::North:
		{
			next->X = curr->X;
			next->Y = curr->Y - 1;

			if (next->Y == -1)
				return false;

			break;
		}

		case Direction::South:
		{
			next->X = curr->X;
			next->Y = curr->Y + 1;
			if (next->Y == desc->Rows)
				return false;

			break;
		}

		case Direction::East:
		{
			next->X = curr->X + 1;
			next->Y = curr->Y;

			if (next->X == desc->Columns)
				return false;

			break;
		}

		case Direction::West:
		{
			next->X = curr->X - 1;
			next->Y = curr->Y;

			if (next->X == -1)
				return false;

			break;
		}
	}

	if (desc->Data[next->Y][next->X] == WALL) return false;
	if (desc->Data[next->Y][next->X] == MARKED) return false;

	return true;
}

bool MoveTo(MazeDesc* desc, Position* curr, Direction direction)
{
	Position next;

	if (desc->Data[curr->Y][curr->X] == GOAL)
		return true;

	desc->Data[curr->Y][curr->X] = MARKED;

	for (int i = 0; i < 4; i++)
	{
		if (GetNextStep(desc, curr, (Direction)i, &next) == false)
			continue;

		if (MoveTo(desc, &next, Direction::North) == true)
			return true;
	}

	desc->Data[curr->Y][curr->X] = WAY;

	return false;
}

bool Solve(MazeDesc* desc)
{
	bool startFound = false;
	bool result = false;

	Position start;
	for (int y = 0; y < desc->Rows; y++)
	{
		for (int x = 0; x < desc->Columns; x++)
		{
			if (desc->Data[y][x] == START)
			{
				start.X = x;
				start.Y = y;
				startFound = true;

				break;
			}
		}
	}

	if ((startFound) == false)
	{
		printf("출발 지점을 찾지 못함\n");

		return false;
	}

	result |= MoveTo(desc, &start, Direction::North);
	result |= MoveTo(desc, &start, Direction::South);
	result |= MoveTo(desc, &start, Direction::East);
	result |= MoveTo(desc, &start, Direction::West);

	desc->Data[start.Y][start.X] = START;

	return result;
}

void PrintMaze(const MazeDesc& desc)
{
	for (int y = 0; y < desc.Rows; y++)
	{
		for (int x = 0; x < desc.Columns; x++)
			printf("%c", desc.Data[y][x]);

		printf("\n");
	}
}

int main()
{
	Timer timer;
	MazeDesc desc;

	printf("[ 백트래킹 - 길 찾기 1: maze_small.txt ]\n\n");
	const char* path = "23_Backtracking/maze_small.txt";
	ReadMaze(path, &desc);

	timer.Start();
	if (Solve(&desc) == false)
		return 0;
	PrintMaze(desc);
	timer.End();

	printf("\n");
	printf("- 소요 시간: %f ms\n\n\n", timer.RunningTime());



	printf("[ 백트래킹 - 길 찾기 2: maze_big.txt ]\n\n");
	path = "23_Backtracking/maze_big.txt";
	ReadMaze(path, &desc);

	timer.Start();
	if (Solve(&desc) == false)
		return 0;
	PrintMaze(desc);
	timer.End();
	
	printf("\n");
	printf("- 소요 시간: %f ms\n", timer.RunningTime());

	return 0;
}