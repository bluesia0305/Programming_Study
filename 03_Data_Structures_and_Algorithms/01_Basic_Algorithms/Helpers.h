#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

struct Data
{
	UINT Index;
	UINT Score;
};

void ReadData(Data* data, const char* path)
{
	FILE* file;
	fopen_s(&file, path, "r");
	{
		for (UINT i = 0; i < USHRT_MAX; ++i)
		{
			fscanf_s(file, "%d, %d", &data[i].Index, &data[i].Score);
		}
	}
	fclose(file);
}

void WriteData(Data* data, const char* path)
{
	FILE* file;
	fopen_s(&file, path, "w");
	{
		for (int i = 0; i < USHRT_MAX; ++i)
		{
			fprintf(file, "%d, %d\n", data[i].Index, data[i].Score);
		}
	}
	fclose(file);
}

void PrintData(Data* datas, int length)
{
	for (int i = 0; i < length; ++i)
		printf("   %d, %d\n", datas[i].Index, datas[i].Score);
}

void Swap(Data* a, Data* b)
{
	Data temp = *a;
	*a = *b;
	*b = temp;
}