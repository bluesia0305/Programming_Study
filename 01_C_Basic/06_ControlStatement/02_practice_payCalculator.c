// 2022-05-31 �ǽ�


// ö���� �ӱ��� �Ʒ��� ���ǿ� ���� ���˴ϴ�.
// ���� 1. ���ϴ� �ð��� �ݵ�� ���� �����θ� ǥ�� ������.
// ���� 2. ���� �ñ�: 9,160 ��
// ���� 3. ö���� 8�ð� ���Ϸ� ���� �ÿ��� �����ñ��� ������,
//               8�ð� �ʰ��� ���� �ÿ��� �ʰ�����(�����ñ��� 10%)�� �� �޽��ϴ�.

// ö���� ���� �ð��� �Է��Ͽ� ���� �ӱ��� ����ϴ� ���α׷��� ������ּ���.
// * ��, ö���� 12�ð����� �ʰ��Ͽ� �ٹ��� �Ұ����մϴ�.


#include <stdio.h>

int main()
{
	int worked_time = 0;
	printf("ö���� ���� �ð��� �Է��ϼ���: ");
	scanf_s("%i", &worked_time);

	int salary = 0;

	if (worked_time < 0)
	{
		printf("ö���� 0�ð� �̻� �ٹ��ؾ� �մϴ�.\n");
	}
	else if (worked_time > 12)
	{
		printf("ö���� 12�ð����� �ʰ��Ͽ� �ٹ��� �� �����ϴ�.\n");
	}
	else if (worked_time > 8)
	{
		salary = 8 * 9160 + (worked_time - 8) * 9160 * 1.1f;
		printf("ö���� ���� �ӱ�: %i ��.\n", salary);
	}
	else
	{
		salary = worked_time * 9160;
		printf("ö���� ���� �ӱ�: %i ��.\n", salary);
	}

	return 0;
}