#include <iostream>
#include <vector>
#include <memory>
#include "../Helpers.h"
#include "../Timer.h"

using namespace std;

void RadixSort(Data* datas, Data* sorted, int radix, int length)
{
	for (int i = 0; i < radix; i++)
	{
		int counts[10] = { 0, };
		int divisor = (int)pow(10, i);

		// �տ������� bucket�� �ִ� ������ ���
		for (int j = 0; j < length; j++)
		{
			int digit = (datas[j].Score / divisor) % 10;
			counts[digit]++;
		}

		for (int j = 1; j < 10; j++)
			counts[j] += counts[j - 1];
		
		// �ڿ������� bucket���� ������ ������ ���
		for (int j = length - 1; j >= 1; j--)
		{
			int digit = (datas[j].Score / divisor) % 10;
			sorted[counts[digit] - 1] = datas[j];
			counts[digit]--;
		}

		memcpy(datas, sorted, sizeof(Data) * USHRT_MAX);
	}
}

int main()
{
	Timer timer;
	Data* datas = new Data[USHRT_MAX];
	Data* sorted = new Data[USHRT_MAX];

	ReadData(datas, "Data_USHRT_MAX.txt");
	timer.Start();
	RadixSort(datas, sorted, 5, USHRT_MAX);
	timer.End();
	printf("[ ��� ���� ]\n");
	printf("- ���� ���(���� 10 ��)\n");
	PrintData(datas, 10);
	printf("- �ҿ� �ð�: %f ms\n", timer.RunningTime());
	WriteData(datas, "18_RadixSort/Data_Sorted.txt");

	delete[] sorted;
	delete[] datas;

	return 0;
}