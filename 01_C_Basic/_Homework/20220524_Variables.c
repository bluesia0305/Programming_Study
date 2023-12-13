// 2022-05-24 과제


// 모든 자료형을 사용하여 변수를 사용하고, 값을 초기화한 후
// 해당 공간이 저장하고 있는 값을 모두 출력해주세요(종류별 1개씩).

#include <stdio.h>

int main()
{
	// 편의상 signed type   = 음수를 초기화
	//        unsigned type = 양수를 초기화 하였음.
	signed char sChar = -20;
	signed short sShort = -651;
	signed int sInt = -65536;
	signed long sLong = -745186;
	signed long long sLLong = -46848676354;

	unsigned char uChar = 32;
	unsigned short uShort = 2457;
	unsigned int uInt = 84354;
	unsigned long uLong = 674985;
	unsigned long long uLLong = 354657687615;

	printf("init_value in sChar\t: %d\n", sChar);
	printf("init_value in sShort\t: %d\n", sShort);
	printf("init_value in sInt\t: %d\n", sInt);
	printf("init_value in sLong\t: %ld\n", sLong);
	printf("init_value in sLLong\t: %lld\n", sLLong);
	printf("init_value in uChar\t: %d\n", uChar);
	printf("init_value in uShort\t: %d\n", uShort);
	printf("init_value in uInt\t: %d\n", uInt);
	printf("init_value in uLong\t: %ld\n", uLong);
	printf("init_value in uLLong\t: %lld\n", uLLong);

	// 이하는 수업 내용 X 개인적으로 궁금한 것
	signed char a = 2;		// 00000010 (2)
	signed char b = -6;		// 11111010 (2) (= 00000110의 2의 보수)
	signed char c;
	c = a + b;				// 11111100 (2) (= 4의 2의 보수 = -4 = -124 ?)
	printf("%d", c);		// 결과값: -4

	// 01111100 = 124
	// 124의 보수 = -124 = 10000011 + 1 = 10000100

	return 0;
}