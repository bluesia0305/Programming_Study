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

		// 앞에서부터 bucket에 넣는 과정을 모사
		for (int j = 0; j < length; j++)
		{
			int digit = (datas[j].Score / divisor) % 10;
			counts[digit]++;
		}

		for (int j = 1; j < 10; j++)
			counts[j] += counts[j - 1];
		
		// 뒤에서부터 bucket에서 꺼내는 과정을 모사
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
	printf("[ 기수 정렬 ]\n");
	printf("- 정렬 결과(상위 10 개)\n");
	PrintData(datas, 10);
	printf("- 소요 시간: %f ms\n", timer.RunningTime());
	WriteData(datas, "18_RadixSort/Data_Sorted.txt");

	delete[] sorted;
	delete[] datas;

	return 0;
}