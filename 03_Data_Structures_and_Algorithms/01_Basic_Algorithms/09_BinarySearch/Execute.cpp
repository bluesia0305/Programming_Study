#include <iostream>
#include "../Timer.h"
#include "../Helpers.h"

using namespace std;

Data* SequenceSearch(Data* datas, UINT size, UINT target, OUT UINT* count)
{
	*count = 0;
	for (UINT i = 0; i < USHRT_MAX; ++i)
	{
		if (target == datas[i].Index)
		{
			*count = i;
			return &datas[i];
		}
	}

	return nullptr;
}

Data* BinarySearch(Data* datas, UINT size, UINT target, OUT UINT* count)
{
	*count = 0;
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		++(*count);

		int middle = (left + right) / 2;
		if (datas[middle].Index == target)
			return &datas[middle];
		else if (datas[middle].Index > target)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return nullptr;
}

int STLBinarySearchCount;
int main()
{
	Data datas[USHRT_MAX];
	ReadData(datas, "Data_USHRT_MAX.txt");

	//for (int i = 0; i < USHRT_MAX; i++)
	//	printf("%d, %d\n", data[i].Index, data[i].Score);


	UINT count = 0;
	UINT target = 60000;

	Timer timer;
	// ���� Ž��(Sequence search)
	{
		timer.Start();
		Data* result = SequenceSearch(datas, USHRT_MAX, target, &count);
		timer.End();
	}
	printf("���� Ž�� %d���� ã��, �ð�: %f\n", count, timer.RunningTime());

	// ���� Ž��(Binary search)
	{
		timer.Start();
		Data* result = BinarySearch(datas, USHRT_MAX, target, &count);
		timer.End();
	}
	printf("���� Ž�� %d���� ã��, �ð�: %f\n", count, timer.RunningTime());

	// STL ���� Ž�� �Լ�
	{
		timer.Start();
		Data* data = (Data*)bsearch((void*)&target,
									(void*)datas,
									USHRT_MAX,
									sizeof(Data),
									[](void const* a, void const* b)
									{
										++STLBinarySearchCount;
										return (((Data*)a)->Index > ((Data*)b)->Index ? 1 : ((Data*)a)->Index < ((Data*)b)->Index ? -1 : 0);
									});
		timer.End();
	}
	printf("���� Ž�� %d���� ã��, �ð�: %f\n", STLBinarySearchCount, timer.RunningTime());

	return 0;
}