// 2022-06-20 ����(���)


// Call-by-value, call-by-reference�� ���̸� �����ϰ� �����Ͱ� �ʿ��� ������ Ȯ��.


#include <iostream>

struct A
{
	int num1;
	int num2;
};

void StructChange(A Struct)
{
	printf("(StructChange �Լ�) �Ű��������� �޾ƿ� ��\n");
	printf("����ü(�Ű�����)�� ��: { %i, %i }\n\n", Struct.num1, Struct.num2);
	Struct.num1 += 10;
	Struct.num2 += 10;
	printf("(StructChange �Լ�) ���� ���� ��\n");
	printf("����ü(�Ű�����)�� ��: { %i, %i }\n", Struct.num1, Struct.num2);
}

void ArrayChange(int arr[])
{
	printf("(ArrayChange �Լ�) �Ű��������� �޾ƿ� ��\n");
	printf("�迭(�Ű�����)�� ��: { %i, %i, %i, %i, %i }\n\n",
		arr[0], arr[1], arr[2], arr[3], arr[4]);
	for (int i = 0; i < 5; i++)
	{
		arr[i] += 10;
	}
	printf("(ArrayChange �Լ�) ���� ���� ��\n");
	printf("�迭(�Ű�����)�� ��: { %i, %i, %i, %i, %i }\n",
		arr[0], arr[1], arr[2], arr[3], arr[4]);
}

int main()
{
	// 1) �迭�� ������ ����Ǿ��ִ� �迭�� �����Ͽ� ���� ���� ������ �ʱ�ȭ�� �� ����.
	A a = { 10, 20 };
	A b = a;

	int arr1[5] = { 1, 2, 3, 4, 5 };
	//int arr2[5] = arr1;	- Error -

	// 2) ����ü�� �Ű������� �Ѱ��� ��쿡 ���� ������ ������(�Ű������� ������ ������ ��, ���� ������ ���� �����Ͽ� �ʱ�ȭ = call-by-value),
	//    �迭�� �Ű������� �Ѱ��� ���, ������ ������ ���� ����(call-by-reference).

	printf("(main �Լ�) StructChange(), ArrayChange() �Լ��� ���� ��\n");
	printf("����ü a�� ��: { %i, %i }\n", a.num1, a.num2);
	printf("�迭 arr1�� ��: { %i, %i, %i, %i, %i }\n",
		arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);
	printf("\n---------------------------------------\n\n");
	StructChange(a);
	printf("\n");
	ArrayChange(arr1);
	printf("\n---------------------------------------\n\n");
	printf("(main �Լ�) StructChange(), ArrayChange() �Լ��� ���� ��\n");
	printf("����ü a�� ��: { %i, %i }\n", a.num1, a.num2);
	printf("�迭 arr1�� ��: { %i, %i, %i, %i, %i }\n",
		arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);

	return 0;
}