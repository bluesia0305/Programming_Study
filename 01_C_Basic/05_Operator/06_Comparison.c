// 2022-05-27 ����(���)


// �񱳿�����(Comparison operator)
// : �� ���� ���Ͽ� ������(1: true, 0: false)�� ��ȯ�ϴ� ������.
//   A < B    ->  A�� ���� B �̸��̶�� 1, �ƴ϶�� 0�� ��ȯ��.
//   A <= B   ->  A�� ���� B ���϶�� 1, �ƴ϶�� 0�� ��ȯ��.
//   A > B    ->  A�� ���� B �ʰ���� 1, �ƴ϶�� 0�� ��ȯ��.
//   A >= B   ->  A�� ���� B �̻��̶�� 1, �ƴ϶�� 0�� ��ȯ��.
//   A == B   ->  A�� �� B�� ���� ������ 1, �ƴ϶�� 0�� ��ȯ��.
//   A != B   ->  A�� ���� B�� ���� �ٸ��� 1, �ƴ϶�� 0�� ��ȯ��.


#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	printf("a = %i, b = %i\n", a, b);
	printf("a < b : %i\n", a < b);
	printf("b <= a : %i\n", b <= a);
	printf("a > b : %i\n", a > b);
	printf("b >= a : %i\n", b >= a);
	printf("a == b : %i\n", a == b);
	printf("a != b : %i\n", a != b);

	return 0;
}