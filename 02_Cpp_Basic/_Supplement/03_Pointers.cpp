// 2022-07-14 심화


#include <iostream>

int main()
{
	unsigned char* pUChar = nullptr;
	signed char* pSChar = nullptr;
	signed short* pShort = nullptr;

	// 자료형에 따라 포인터 변수에 저장된 주소에 간접접근할 경우 어떻게 읽는지 확인.
	// * 데이터 저장 방식이 FILO(first in, last out) 방식이므로 아래와 같은 결과가 나온다.
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