// 2022-05-31 실습


// 철수의 임금은 아래의 조건에 따라 계산됩니다.
// 조건 1. 일하는 시간은 반드시 양의 정수로만 표현 가능함.
// 조건 2. 최저 시급: 9,160 원
// 조건 3. 철수는 8시간 이하로 일할 시에는 최저시급을 받으며,
//               8시간 초과로 일할 시에는 초과수당(최저시급의 10%)을 더 받습니다.

// 철수가 일한 시간을 입력하여 최종 임금을 계산하는 프로그램을 만들어주세요.
// * 단, 철수는 12시간보다 초과하여 근무는 불가능합니다.


#include <stdio.h>

int main()
{
	int worked_time = 0;
	printf("철수가 일한 시간을 입력하세요: ");
	scanf_s("%i", &worked_time);

	int salary = 0;

	if (worked_time < 0)
	{
		printf("철수는 0시간 이상 근무해야 합니다.\n");
	}
	else if (worked_time > 12)
	{
		printf("철수는 12시간보다 초과하여 근무할 수 없습니다.\n");
	}
	else if (worked_time > 8)
	{
		salary = 8 * 9160 + (worked_time - 8) * 9160 * 1.1f;
		printf("철수의 최종 임금: %i 원.\n", salary);
	}
	else
	{
		salary = worked_time * 9160;
		printf("철수의 최종 임금: %i 원.\n", salary);
	}

	return 0;
}