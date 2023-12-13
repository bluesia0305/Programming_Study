// 2022-06-23 ����(���)


// ���� ������(Multiple indirection)
// : ������ ������ ����Ű�� �������� ���·� �̷������ ������.
//   * �������� ���¸� �ٲٱ� ���� ����.


#include <iostream>

void SwapAddress1(int* param1, int* param2)
{
	int* temp = param2;
	param2 = param1;
	param1 = temp;
}

void SwapAddress2(int** param1, int** param2)
{
	int* temp = *param2;
	*param2 = *param1;
	*param1 = temp;
}

int main()
{
#pragma region Pointer
	int A = 10;
	int* p = &A;		// Pointer to int
	int** pp = &p;		// Pointer to pointer to int (���� ������)
	int*** ppp = &pp;	// Pointer to pointer to pointer to int (���� ������)

	// ���� ������
	printf("A�� �� = p�� �������� = pp�� �������� �������� = ppp�� �������� �������� ��������\n");
	printf("A    : %i\n", A);
	printf("*p   : %i\n", *p);
	printf("**p  : %i\n", **pp);
	printf("***p : %i\n\n", ***ppp);

	printf("A�� �ּҰ� = p�� �� = pp�� ������ �� = ppp�� �������� ������ ��\n");
	printf("&A   : %p\n", &A);
	printf("p    : %p\n", p);
	printf("*pp  : %p\n", *pp);
	printf("**ppp: %p\n\n", **ppp);

	printf("p�� �ּҰ� = pp�� �� = ppp�� ������ ��\n");
	printf("&p   : %p\n", &p);
	printf("pp   : %p\n", pp);
	printf("*ppp : %p\n\n", *ppp);

	printf("pp�� �ּҰ� = ppp�� ��\n");
	printf("&pp  : %p\n", &pp);
	printf("ppp  : %p\n\n", ppp);

	printf("ppp�� �ּҰ�\n");
	printf("&ppp : %p\n", &ppp);
#pragma endregion
	printf("-------------------------\n");

	int var1 = 10, var2 = 20;
	int* p1 = &var1;
	int* p2 = &var2;

	printf("p1: %p\n", p1);
	printf("p2: %p\n\n", p2);

	SwapAddress1(p1, p2);

	printf("SwapAddress1 ���� ��\n");
	printf("p1: %p\n", p1);
	printf("p2: %p\n\n", p2);

	SwapAddress2(&p1, &p2);

	printf("SwapAddress2 ���� ��\n");
	printf("p1: %p\n", p1);
	printf("p2: %p\n\n", p2);

	return 0;
}