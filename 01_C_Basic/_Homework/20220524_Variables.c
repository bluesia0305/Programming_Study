// 2022-05-24 ����


// ��� �ڷ����� ����Ͽ� ������ ����ϰ�, ���� �ʱ�ȭ�� ��
// �ش� ������ �����ϰ� �ִ� ���� ��� ������ּ���(������ 1����).

#include <stdio.h>

int main()
{
	// ���ǻ� signed type   = ������ �ʱ�ȭ
	//        unsigned type = ����� �ʱ�ȭ �Ͽ���.
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

	// ���ϴ� ���� ���� X ���������� �ñ��� ��
	signed char a = 2;		// 00000010 (2)
	signed char b = -6;		// 11111010 (2) (= 00000110�� 2�� ����)
	signed char c;
	c = a + b;				// 11111100 (2) (= 4�� 2�� ���� = -4 = -124 ?)
	printf("%d", c);		// �����: -4

	// 01111100 = 124
	// 124�� ���� = -124 = 10000011 + 1 = 10000100

	return 0;
}