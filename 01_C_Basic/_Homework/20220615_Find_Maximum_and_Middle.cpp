// 2022-06-15 ����
// 1) int�� �����͸� ��ȯ�ϸ�, int�� ������ 3 ���� ���� �ϴ� max3��� �Լ��� �����
//    ȣ�� �ÿ� �Ѱ��� ������ �� �ִ��� ���ϴ� �Լ��� ������.

// 2) int�� �����͸� ��ȯ�ϸ�, int�� ������ 3 ���� ���� �ϴ� middle3��� �Լ��� �����
//    ȣ�� �ÿ� �Ѱ��� ������ �� �߰����� ���ϴ� �Լ��� ������.


#include <iostream>

int larger_value(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int max3(int a, int b, int c)
{
	return larger_value(larger_value(a, b), c);
}

int middle3(int a, int b, int c)
{
	int max_value = max3(a, b, c);

	if (max_value == a) return larger_value(b, c);
	else if (max_value == b) return larger_value(a, c);
	else return larger_value(a, b);
}

// ������ 1) 3���� �� ��, �ִ� ���ϱ�
int max3_standard(int a, int b, int c)
{
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

// ������ 2) 3���� �� ��, �߰��� ���ϱ�
int middle3_standard(int a, int b, int c)
{
	if (a >= b)
	{
		if (b >= c) return b;
		else if (a <= c) return a;
		else return c;
	}
	else if (a > c) return a;
	else if (b > c) return c;
	else return b;
}

int main()
{
	int a;
	int b;
	int c;
	
	printf("a �Է�[int]: ");
	std::cin >> a;
	printf("b �Է�[int]: ");
	std::cin >> b;
	printf("c �Է�[int]: ");
	std::cin >> c;

	printf("[a: %i] [b: %i] [c: %i]\n", a, b, c);
	printf("max3 �Լ��� ��ȯ��: %i\n", max3(a, b, c));
	printf("middle3 �Լ��� ��ȯ��: %i\n", middle3(a, b, c));
	
	return 0;
}