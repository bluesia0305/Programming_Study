// 2022-06-16 ����(���)


// return (��);
// : ���� ���� ���� �Լ��� ������ �����ϰ�, ���� ��ȯ�ϴ� ����� �����ϴ� ���� ����.


#include <iostream>

int test(int a)
{
	printf("test(%i); �� ��� >>", a);
	if (a == 1) return 1;
	printf("a�� 1�� �ƴմϴ�.\n");
}

void test2()
{
	return;			// ��ȯ���� ���� void �������� ����� �Լ������� ��ȯ�� ���� return; ������.
	printf("test2(); �� ��� >>");
}

int main()
{
	printf("1) int �������� ����� �Լ��� ���.\n");
	test(1);
	printf("\n");
	test(2);
	printf("\n\n");

	printf("2) void �������� ����� �Լ��� ���.\n");
	test2();

	return 0;
}