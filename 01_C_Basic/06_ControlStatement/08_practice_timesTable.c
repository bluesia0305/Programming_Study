// 2022-06-03 �ǽ�


#include <stdio.h>

int main()
{
	// �������� 1�� ~ 9�ܱ��� ���� ���.
	printf("������ 1�� ~ 9�ܱ��� ����ϱ�.\n");
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

	// 1 ~ 10������ ��, ���� ���غ���.
	printf("1���� 10���� ��� ���� ��, ���� ���غ���.\n");
	int i = 0;
	int sum = 0;
	int factorial = 1;
	while (i++ < 10)
	{
		sum += i;
		factorial *= i;
	}
	
	printf("   1���� 10���� ��� ���� ��: %i\n", sum);
	printf("   1���� 10���� ��� ���� ��: %i\n", factorial);

	return 0;
}