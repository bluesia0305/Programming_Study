// Q4-2 �� ��� ��� �������� (���̾Ƹ�� ���)


#include <stdio.h>
#include <Windows.h>

int main()
{
	printf("Q4-2. ���õ� ����� ����ϱ�3.\n");
	const int n2_lines = 5;
	int i;
	int j;
	int k;
	int l = 1;

	i = 1;
	while (i != 0)
	{
		j = 0;
		while (j++ < (2 * n2_lines) - (2 * i))
		{
			printf(" ");
		}

		k = 0;
		while (k++ < 2 * i - 1)
		{
			printf("* ");
		}
		printf("\n");

		if (l < n2_lines)
		{
			l++;
			i++;
		}
		else
		{
			l++;
			i--;
		}
	}
	printf("\n");
	
	return 0;
}
