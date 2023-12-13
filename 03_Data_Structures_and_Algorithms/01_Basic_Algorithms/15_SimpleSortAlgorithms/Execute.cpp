#include "../Helpers.h"
#include "../Timer.h"
#include <memory>

void Swap(Data* datas, int i, int j)
{
	Data temp = datas[i];
	datas[i] = datas[j];
	datas[j] = temp;
}

void BubbleSort(Data* datas, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
			if (datas[j].Score > datas[j + 1].Score)
				Swap(datas, j, j + 1);
	}
}

void SelectionSort(Data* datas, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (datas[j].Score < datas[minIndex].Score)
				minIndex = j;
		}

		if (minIndex != i)
			Swap(datas, i, minIndex);
	}
}

void InsertionSort(Data* datas, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (datas[i - 1].Score <= datas[i].Score) continue;

		Data current = datas[i];
		for (int j = 0; j < i; j++)
			if (datas[j].Score > current.Score)
			{
				memmove(&datas[j + 1], &datas[j], sizeof(datas[0]) * (i - j));
				datas[j] = current;
				break;
			}
	}
}

int main()
{
	Timer timer;
	Data datas[USHRT_MAX];


	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	BubbleSort(datas, USHRT_MAX);
	timer.End();
	printf("[ 버블 정렬 ]\n");
	printf("- 정렬 결과(상위 10 개)\n");
	PrintData(datas, 10);
	printf("- 소요 시간: %f ms\n\n", timer.RunningTime());
	WriteData(datas, "15_SimpleSortAlgorithms/Data_Sorted_Bubble.txt");


	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	SelectionSort(datas, USHRT_MAX);
	timer.End();
	printf("[ 선택 정렬 ]\n");
	printf("- 정렬 결과(상위 10 개)\n");
	PrintData(datas, 10);
	printf("- 소요 시간: %f ms\n\n", timer.RunningTime());
	WriteData(datas, "15_SimpleSortAlgorithms/Data_Sorted_Selection.txt");


	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	InsertionSort(datas, USHRT_MAX);
	timer.End();
	printf("[ 삽입 정렬 ]\n");
	printf("- 정렬 결과(상위 10 개)\n");
	PrintData(datas, 10);
	printf("- 소요 시간: %f ms\n", timer.RunningTime());
	WriteData(datas, "15_SimpleSortAlgorithms/Data_Sorted_Insertion.txt");

	return 0;
}