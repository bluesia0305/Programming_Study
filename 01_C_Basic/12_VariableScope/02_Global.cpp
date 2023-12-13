// 2022-06-17 ����


// ��������(Global variables)
// : ��� �߰�ȣ�� �ܺο��� ����� ������, �������� ��� ����.
//   * extern Ű���带 �̿��ϸ� �ٸ� ���Ͽ� �ִ� ���������� ������ ����� ���� ����.
//     (��, ������Ʈ�� ���ԵǾ����� ���� ���Ͽ��� ����� ���������� �ҷ��� �� ����)


#include <iostream>

extern int globalVar;

void globalAddTest()
{
	globalVar += 10;
}

int main()
{
	printf("1) ���������� ���� ����.\n");
	printf("�������� globalVar�� ��: %i\n", globalVar);
	globalAddTest();
	printf("�������� globalVar�� ��: %i\n", globalVar);

	printf("2) ������ ���������� ���������� ���� ��쿡 ���� ����.\n");
	int globalVar = 1;
	printf("�������� globalVar�� ��: %i\n", globalVar);
	printf("�������� globalVar�� ��: %i\n", ::globalVar);		// ������ �̸��� ���� ��, ���������� ȣ���� �� ::�� �տ� ���̸� ��.

	return 0;
}