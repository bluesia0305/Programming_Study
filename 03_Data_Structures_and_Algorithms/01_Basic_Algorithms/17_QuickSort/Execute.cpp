#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "../Timer.h"
#include "../Helpers.h"

int Partition(Data* datas, int left, int right)
{
	UINT first = left;
	UINT pivot = datas[first].Score;

	left++;
	while (left <= right)
	{
		while (datas[left].Score <= pivot && left < right)
			left++;

		while (datas[right].Score > pivot && left <= right)
			right--;

		if (left < right)
			Swap(&datas[left], &datas[right]);
		else
			break;
	}

	Swap(&datas[first], &datas[right]);
	return right;
}

void QuickSort(Data* datas, int left, int right)
{
	if (left < right)
	{
		int index = Partition(datas, left, right);

		QuickSort(datas, left, index - 1);
		QuickSort(datas, index + 1, right);
	}
}

int Compare(const void* val1, const void* val2)
{
	Data* data1 = (Data*)val1;
	Data* data2 = (Data*)val2;

	// 오름차순 정렬
	if (data1->Score > data2->Score)
		return 1;
	else if (data1->Score < data2->Score)
		return -1;
	else
		return 0;
}

int Compare2(const Data& val1, const Data& val2)
{
	// 오름차순 정렬
	return val1.Score < val2.Score;
}

int main()
{
	Timer timer;
	Data datas[USHRT_MAX];
	int count = USHRT_MAX;


	// 직접 구현한 퀵 소트(Quick sort)
	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	QuickSort(datas, 0, USHRT_MAX - 1);
	timer.End();
	printf("[ 직접 구현 퀵 정렬 ]\n");
	printf("- 정렬 결과(상위 10 개)\n");
	PrintData(datas, 10);
	printf("- 소요 시간: %f ms\n\n", timer.RunningTime());
	WriteData(datas, "17_QuickSort/Data_Sorted.txt");


	//// C-style 퀵 소트
	//ReadData(datas, "Data_USHRT_MAX.txt");
	//timer.Start();
	//qsort(datas, USHRT_MAX, sizeof(Data), Compare);
	//timer.End();
	//printf("[ C-style 퀵 정렬 qsort ]\n");
	//printf("- 정렬 결과(상위 10 개)\n");
	//PrintData(datas, 10);
	//printf("- 소요 시간: %f ms\n\n", timer.RunningTime());


	// STL 퀵 소트
	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	std::sort(datas, datas + USHRT_MAX, Compare2);
	timer.End();
	printf("[ STL 퀵 정렬 std::sort ]\n");
	printf("- 정렬 결과(상위 10 개)\n");
	PrintData(datas, 10);
	printf("- 소요 시간: %f ms\n", timer.RunningTime());

	return 0;
}