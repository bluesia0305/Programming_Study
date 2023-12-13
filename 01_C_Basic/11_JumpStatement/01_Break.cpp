// 2022-06-16 ����


// ���� ����(Jump statement)
// : ���α׷����� ���� �������� ����� �ߴ��ϰ� ���ϴ� �������� �ǳʶٴ� ����� �����ϴ� ����.
//   * ���� ������ ����: break, continue, return, goto

// break;
// : switch~case �Ǵ� �ݺ����� ������ �ߴ��ϰ�, ���� ����� �����ϱ� ���� ����ϴ� ���� ����.


#include <iostream>

int main()
{
	printf("1) switch ~ case ���������� break; ��� ����.\n");
	switch (1)
	{
	case 1:	printf("Case1.\n");
	case 2:	printf("Case2.\n");
	case 3:	printf("Case3.\n"); break;
	case 4: printf("Case4.\n");			// �ش� ��ɹ��� break;�� ���� ������� ����.
	default: printf("Default.\n");		// �ش� ��ɹ��� break;�� ���� ������� ����.
	}
	
	printf("\n");
	printf("2) �ݺ��������� break; ��� ����.\n");
	int Count = 0;
	while (Count < 10)
	{
		Count++;
		if (Count == 3) break;
		printf("while ������ ���� %i��° ���� ���Դϴ�.\n", Count);
	}

	printf("\n");
	printf("3) ��ø �ݺ��������� break; ��� ����.\n");
	for (int i = 0; i < 7; i++)
	{
		printf("i: %i // j: ", i);
		for (int j = 0; j < 5; j++)
		{
			printf("%i ", j);
			if (j == 3) break;
		}
		printf("\n");
	}

	return 0;
}