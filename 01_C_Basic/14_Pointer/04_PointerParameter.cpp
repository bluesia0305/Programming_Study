// 2022-06-21 ����(���)


// ������ �Ű�����(Pointer parameter)
// : �ּҰ��� ���¸� ���� �� �ִ� �Ű�����.
//   ������ ������ ���·� �Ű������� �̿��ϸ� �Լ��� ����Ǿ ���� �� ��ü�� ������ ��������.

#include <iostream>

void AddTen(int* p)
{
	*p += 10;
}

struct Struct
{
	long long A[100];
	long long B[100];
	long long C[100];
	long long D[100];
	long long E[100];
	long long F[100];
};

int main()
{
	int A = 10;
	AddTen(&A);
	printf("A�� ��: %i\n", A);
	printf("\n");

	// (��ȭ) Call-by-address�� call-by-reference�� �ٸ� ��
	// * Call-by-address  : call-by-value�� �������κ��� value ��� address�� �����ϴ� ��.
	// * Call-by-reference: ȣ��� �Լ��� (main �Լ� �󿡼� �����) ���� ��ü�� ������ �� �ִ�.
	int* ptr = &A;
	printf("(��ȭ) Call-by-address / call-by-reference ������.\n");
	printf("ptr   : %p\n", ptr);
	printf("A�� ��: %i\n", A);
	AddTen(ptr);
	// �Լ� ������ � ����� ����ص� ptr�� ����� ��(A�� �ּ�)�� �ٲ��� �ʴ´�.
	// ��, call-by-address�� �ᱹ call-by-value���� �����ϴ� ���� �ּҰ����� �ϴ� Ư�� ���̽���� �� �� �ִ�.
	// (���� �����͸� �̿��ϸ� ptr�� ����� ���� ������ ���� ������, 
	printf("ptr   : %p\n", ptr);
	printf("A�� ��: %i\n", A);

	// �������� ��� ����: �޸� ����
	// * x86 ���� 4 Byte, x64 ���� 8 Byte�� �ּҸ� ������ �� �ְ�, �̸� �̿��� ������ ������.
	printf("Struct Size: %zi Byte\n", sizeof(Struct));
	printf("Struct* Size: %zi Byte\n", sizeof(Struct*));

	return 0;
}