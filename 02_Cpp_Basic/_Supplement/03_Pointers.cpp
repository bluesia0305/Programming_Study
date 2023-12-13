// 2022-07-14 ��ȭ


#include <iostream>

int main()
{
	unsigned char* pUChar = nullptr;
	signed char* pSChar = nullptr;
	signed short* pShort = nullptr;

	// �ڷ����� ���� ������ ������ ����� �ּҿ� ���������� ��� ��� �д��� Ȯ��.
	// * ������ ���� ����� FILO(first in, last out) ����̹Ƿ� �Ʒ��� ���� ����� ���´�.
	// 256 == 0000 0000, 0000 0000, 0000 0001, 0000 0000
	int Num = 256;
	pUChar = reinterpret_cast<unsigned char*>(&Num);
	pSChar = reinterpret_cast<signed char*>(&Num);
	pShort = reinterpret_cast<signed short*>(&Num);
	printf("*pUChar: %d\n", *pUChar);
	printf("*pSChar: %d\n", *pSChar);
	printf("*pShort: %d\n", *pShort);
	printf("\n");

	// 128 == 0000 0000, 0000 0000, 0000 0000, 1000 0000
	int* pNum = &Num;
	*pNum = 128;
	pUChar = reinterpret_cast<unsigned char*>(pNum);
	pSChar = reinterpret_cast<signed char*>(pNum);
	pShort = reinterpret_cast<signed short*>(pNum);
	printf("*pUChar: %d\n", *pUChar);
	printf("*pSChar: %d\n", *pSChar);
	printf("*pShort: %d\n", *pShort);
	printf("\n");

	return 0;
}