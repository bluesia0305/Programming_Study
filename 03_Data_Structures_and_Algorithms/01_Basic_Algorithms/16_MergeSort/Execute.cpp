#include <iostream>
#include "../Helpers.h"
#include "../Timer.h"

using namespace std;

void Merge(Data* datas, int start, int middle, int end)
{
	int left = start;
	int right = middle + 1;

	int destIndex = 0;
	Data* dest = new Data[end - start + 1];

	// ���� �κ� ���հ� ������ �κ� ���տ� ���� ������ ��
	while (left <= middle && right <= end)
	{
		if (datas[left].Score < datas[right].Score)
			dest[destIndex++] = datas[left++];
		else
			dest[destIndex++] = datas[right++];
	}

	// ������ �����ʹ� �״�� �̵�
	while (left <= middle)
		dest[destIndex++] = datas[left++];

	// ������ �����ʹ� �״�� �̵�
	while (right <= end)
		dest[destIndex++] = datas[right++];

	destIndex = 0;
	for (int i = start; i <= end; ++i)
		datas[i] = dest[destIndex++];

	delete[] dest;
}

void MergeSort(Data* datas, int start, int end)
{
	if (end - start < 1)
		return;

	int middle = (start + end) / 2;

	MergeSort(datas, start, middle);
	MergeSort(datas, middle + 1, end);
	Merge(datas, start, middle, end);
}

int main()
{
	Timer timer;
	Data datas[USHRT_MAX];

	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	MergeSort(datas, 0, USHRT_MAX - 1);
	timer.End();
	printf("[ �պ� ���� ]\n");
	printf("- ���� ���(���� 10 ��)\n");
	PrintData(datas, 10);
	printf("- �ҿ� �ð�: %f ms\n", timer.RunningTime());
	WriteData(datas, "16_MergeSort/Data_Sorted.txt");

	return 0;
}