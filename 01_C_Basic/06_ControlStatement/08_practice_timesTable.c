// 2022-06-03 실습


#include <stdio.h>

int main()
{
	// 구구단을 1단 ~ 9단까지 전부 출력.
	printf("구구단 1단 ~ 9단까지 출력하기.\n");
	int multiplicand = 0;
	while (multiplicand++ < 9)
	{
		printf("%i times table.\n", multiplicand);

		int multiplier = 0;
		while (multiplier++ < 9)
		{
			printf("   %i x %i = %i\n", multiplicand, multiplier, multiplicand * multiplier);
		}
	}
	printf("\n");

	// 1 ~ 10까지의 합, 곱을 구해보기.
	printf("1부터 10까지 모든 수의 합, 곱을 구해보기.\n");
	int i = 0;
	int sum = 0;
	int factorial = 1;
	while (i++ < 10)
	{
		sum += i;
		factorial *= i;
	}
	
	printf("   1부터 10까지 모든 수의 합: %i\n", sum);
	printf("   1부터 10까지 모든 수의 곱: %i\n", factorial);

	return 0;
}