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

	// �������� ����
	if (data1->Score > data2->Score)
		return 1;
	else if (data1->Score < data2->Score)
		return -1;
	else
		return 0;
}

int Compare2(const Data& val1, const Data& val2)
{
	// �������� ����
	return val1.Score < val2.Score;
}

int main()
{
	Timer timer;
	Data datas[USHRT_MAX];
	int count = USHRT_MAX;


	// ���� ������ �� ��Ʈ(Quick sort)
	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	QuickSort(datas, 0, USHRT_MAX - 1);
	timer.End();
	printf("[ ���� ���� �� ���� ]\n");
	printf("- ���� ���(���� 10 ��)\n");
	PrintData(datas, 10);
	printf("- �ҿ� �ð�: %f ms\n\n", timer.RunningTime());
	WriteData(datas, "17_QuickSort/Data_Sorted.txt");


	//// C-style �� ��Ʈ
	//ReadData(datas, "Data_USHRT_MAX.txt");
	//timer.Start();
	//qsort(datas, USHRT_MAX, sizeof(Data), Compare);
	//timer.End();
	//printf("[ C-style �� ���� qsort ]\n");
	//printf("- ���� ���(���� 10 ��)\n");
	//PrintData(datas, 10);
	//printf("- �ҿ� �ð�: %f ms\n\n", timer.RunningTime());


	// STL �� ��Ʈ
	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	std::sort(datas, datas + USHRT_MAX, Compare2);
	timer.End();
	printf("[ STL �� ���� std::sort ]\n");
	printf("- ���� ���(���� 10 ��)\n");
	PrintData(datas, 10);
	printf("- �ҿ� �ð�: %f ms\n", timer.RunningTime());

	return 0;
}