// 2022-06-17 ����(���)


// ��������(Static variables)
// : ������ �Ҵ���� �Ŀ� ���α׷��� ������ ������ ������Ű�� ������ �ǹ���.
//   * static Ű���带 ���� ������ �����ϴ� ��ɹ��� ���α׷� ���� �� �ݺ��ϴ��� ���� 1���� ����.
//   * ���� ���� Ư���� �������� �⺻������ ������ ������ ��������, ���������� ������ ��Ģ�� ���� �����.
//     (ex: �������������� ����� �߰�ȣ�� �ܺο��� ȣ���̳� ���� �ʱ�ȭ �Ұ���.)


#include <iostream>

extern int globalVar;
static int staticGlobalVar = 10;
extern int staticGlobalVar2;		// �ٸ� ���Ͽ��� ����� �������������� extern���� ����� �� ����.

void staticTest()
{
	// ���� ������ ����: static Ű���带 ����� ������.
	// * �� �ѹ��� �ʱ�ȭ�� �̷������, ���� �����͸� ��� ������.
	static int staticLocalVar = 10;
	int localVar = 10;

	localVar += 10;
	globalVar += 10;
	staticLocalVar += 10;
	staticGlobalVar += 10;

	printf("    �������� localVar       �� ��: %i\n", localVar);
	printf("    �������� globalVar      �� ��: %i\n", globalVar);
	printf("������������ staticLocalVar �� ��: %i\n", staticLocalVar);
	printf("������������ staticGlobalVar�� ��: %i\n", staticGlobalVar);
	printf("-------------------------------------\n");
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		staticTest();
	}

	return 0;
}