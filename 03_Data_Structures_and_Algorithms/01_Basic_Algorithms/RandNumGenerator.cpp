#include "Helpers.h"
#include <ctime>

int main()
{
	srand((UINT)time(0));

	Data* datas = new Data[USHRT_MAX];
	for (int i = 0; i < USHRT_MAX; ++i)
	{
		datas[i].Index = i;
		datas[i].Score = rand();
	}

	WriteData(datas, "Data_USHRT_MAX.txt");

	return 0;
}