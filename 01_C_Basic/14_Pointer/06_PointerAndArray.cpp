// 2022-06-22 ����(���)


// 1. �迭�� ���� ���� �� �迭�� �������� ���� �˾ƺ���.
// 2. �ּҿ��꿡 ���� �˾ƺ���.


#include <iostream>

void PrintArray(int* const p)
{
	for (int i = 0; i < 5; i++)
		printf("%i ", p[i]);
	printf("\n");
}

int main()
{
	int A = 0;
	int B = 0;
	int* const p1 = &A;
	//p1 = &B;		- Error -	* ��� ������(constant pointer)�̹Ƿ� �ּҰ��� ������ �Ұ�����.

	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 0 };
	//arr1 = arr2;	- Error -	* �迭�� ��쿡�� �� �̷��� �ʱ�ȭ�ϴ� ���� �ȵɱ�?

	// ���� �ּҸ� ǥ���ϱ� ���� ���������ڴ� %p ������ �ּ��� �۵� ������ Ȯ���ϱ� ���� ������ ���ÿ��� %lld�� �ּҸ� �����.
	printf("arr1          : %lld\n", arr1);
	printf("arr2          : %lld\n", arr2);			// �迭�� �̸��� �� �迭�� ù��° ��Ҹ� ����Ű�� �����͸� �ǹ���.
	printf("*arr1         : %lld\n", *arr1);		// �迭�� �̸��� �������ϸ�? -> �迭�� ���� ù��° ����� ���� ��µ�.
	for (int i = 0; i < 5; i++)	printf("arr1[%i]�� �ּ�: %i\n", i, &arr1[i]);
	printf("\n");
	
	// �ּҿ���: �ּҰ� + (n * (�ش� �ּҰ����� ũ��));
	for (int i = 0; i < 5; i++)	printf("arr1 + %i      : %i\n", i, arr1 + i);
	for (int i = 0; i < 5; i++)	printf("*(arr1 + %i)   : %i\n", i, *(arr1 + i));
	for (int i = 0; i < 5; i++)	printf("arr1[%i]       : %i\n", i, arr1[i]);
	// -> ��, �ε��� �����ڴ� �̷��� �ּҿ����� �����ϰ� ǥ���ϰ�
	//    �̷��� �ּҿ����� ������ �� ����Ű�� ������ �����Ϳ� �����ϱ� ���� ����ϴ� ��������.
	printf("\n");

	// (��ȭ) �迭�� �������� ����
	printf("arr1          : %lld\n", arr1);			// 1. �迭�� �̸��� �� ù��° ���(�迭�� ������)�� ����Ű�� �����͸� �ǹ���.
	printf("arr1 + 1      : %lld\n", arr1 + 1);		//    ��, arr1�� ������ int* �� (��, �迭 ����� ���ÿ� �̸��� ����Ű�� �ּ��� ������ �ȵǹǷ� int* const �����̴�).
	printf("&arr1         : %lld\n", &arr1);		// 2. �ּҿ������� �ǿ����ڰ� �迭�� �̸��� ��쿡�� �迭 ��ü�� ����Ű�� �����͸� ��ȯ��(�������� ����).
	printf("&arr1 + 1     : %lld\n", &arr1 + 1);	//    ��, &arr1�� ������ int(*)[5] �̸� ����, �� ��쿡�� �ּҿ����� ���� �迭�� ũ�⸸ŭ �ּҰ��� ������ �Ͼ��.
	printf("sizeof(arr1)  : %zi\n", sizeof(arr1));	// (����) sizeof ������ ���� �ǿ����ڰ� �迭�� �̸��� ��쿡�� �迭�� ù ��Ұ� �ƴ�, �迭 ��ü�� ũ�⸦ ��ȯ�Ѵ�.
	printf("\n");

	// �ٸ� ��� ������ ������ ���� ��, �迭�� �̸��� ���Կ��� �ع����� �Ʒ��� ���� ��� �������� Ȯ�� ����.
	int* pArr = arr1;
	printf("pArr          : %i\n", pArr);
	printf("*pArr         : %i\n", *pArr);
	for (int i = 0; i < 5; i++)	printf("pArr[%i]�� �ּ�: %i\n", i, &pArr[i]);
	for (int i = 0; i < 5; i++)	printf("pArr + %i      : %i\n", i, pArr + i);
	for (int i = 0; i < 5; i++)	printf("*(pArr + %i)   : %i\n", i, *(pArr + i));
	for (int i = 0; i < 5; i++)	printf("pArr[%i]       : %i\n", i, pArr[i]);

	PrintArray(arr1);

	return 0;
}