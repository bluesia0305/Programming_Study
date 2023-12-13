// 2022-05-26 ����


// ������(Operator)
// : Ư�� �����Ϳ� ���� ���� ����� ��ȯ���ִ� ����� ����.
//   * ��ȯ: ���� ����� ���� �����͸� �����ִ� ���� �ǹ���.

// ��Ʈ������(Bit operator)
// : Bit�� ���� ������ ���ִ� ������.


#include <stdio.h>
#include <string.h>

#pragma region Binary
#pragma warning(disable : 4996) // �����ڵ� 4996�� �ش��ϴ� ������ �����ϱ� ���� �ҽ� �ڵ�.

void GetBinary(char value)		// �������� �������� ��ȯ�Ͽ� �ܼ� �� ������ִ� �Լ�.
{
	static char b[9];
	b[0] = '\0';

	// for loop
	// for ( (initialization_statement); (test_expression); (update_statement) );
	for (int z = 128; z > 0; z >>= 1)
		// ���׿�����(ternary operator)
		// (����) ? (�� A) : (�� B)
		// : (����)�� true�� ��� (�� A), false�� ��� (�� B)�� �����.
		
		// strcat(variable, string);
		// : string variable�� �Է¹��� string�� �̾���̴� �Լ�.
		strcat(b, ((value & z) == z) ? "1" : "0");

	printf("%d\t== %s\n", value, b);
}
#pragma endregion

int main()
{
	// ����, ������ ����Ʈ ������ (<<, >>)
	// : value�� ��Ʈ�� ����(�Ǵ� ������)���� n��ŭ �̵���.
	
	// ������ ����Ʈ �������� ���,
	// �̵����� �� �ڸ��� �Ѿ�� ��Ʈ�� �����ʹ� ������ �������
	// �̶�, ä������ �κ��� ����� ��� 0, ������ ��� 1�� ä����(��ȣ ��Ʈ ���� ��å).
	// * ��, unsigned �ڷ����� ��쿡�� ������ 0���θ� ä����.
	char value_1 = 3;				// signed �ڷ������� ����� ��� ��� ������ �Ǵ��� Ȯ��.
	GetBinary(value_1);
	GetBinary(value_1 >> 1);
	printf("\n");

	char value_2 = -3;				// signed �ڷ������� ������ ��� ��� ������ �Ǵ��� Ȯ��.
	GetBinary(value_2);
	GetBinary(value_2 >> 2);
	printf("\n");

	unsigned char value_3 = 255;	// unsigned �ڷ������� ��� ������ �Ǵ��� Ȯ��.
	GetBinary(value_3);
	GetBinary(value_3 >> 2);
	printf("-------------------\n");

	// ���� ����Ʈ �������� ��쿡�� �׻� 0���� ä����.
	// * ��ȣ ��Ʈ ���� ��å�� �������� ����.
	char value_4 = 10;
	GetBinary(value_4);
	GetBinary(value_4 << 4);
	printf("-------------------\n");

	// NOT ������(~): �־��� value�� ��Ʈ�� 0�� 1��, 1�� 0���� ������Ű�� ����� ��.
	// * ��ȣ ��Ʈ ���� ��å�� �������� ����.
	char value_5 = -1;
	GetBinary(value_5);
	GetBinary(~value_5);
	printf("-------------------\n");


	// (�ǽ�)
	// * ��Ʈ �̵������� ������ �� �������� ������, ��� ������ ����.
	signed char mySigned = 1;
	unsigned char myUnsigned = 1;
	// ���� mySigned, myUnsigned, ��Ʈ �����ڸ� ����Ͽ�
	// signed char�� unsigned char�� �ִ��� ������ּ���.
	// ����, signed char�� �ּڰ��� ������ּ���.
	
	// signed char�� �ִ� (= 127 = 01111111 (2)).
	GetBinary(~(mySigned << 7));
	// unsigned char�� �ִ� (= 255 = 11111111 (2)).
	GetBinary(~(myUnsigned >> 1));
	// signed char�� �ּڰ� (= -128 = 10000000 (2)).
	GetBinary(mySigned << 7);
	printf("-------------------\n");

	// ��Ʈ AND ������(= ���� AND ������, &)
	// �� �ڸ��� ��Ʈ�� ���Ͽ� �� �� 1�̶�� 1��, �ϳ��� 1�� �ƴ϶�� 0�� ��ȯ�ϴ� ������.
	GetBinary(50);
	GetBinary(70);
	GetBinary(50 & 70);
	printf("-------------------\n");

	// ��Ʈ OR ������(= ���� OR ������, |)
	// �� �ڸ��� ��Ʈ �� ��� �ϳ��� 1�� ��� 1��, �� �� 0�� ��� 0�� ��ȯ�ϴ� ������.
	GetBinary(50);
	GetBinary(70);
	GetBinary(50 | 70);
	printf("-------------------\n");

	// ��Ÿ�� ���� XOR ������(^)
	// �� �ڸ��� ��Ʈ�� ���Ͽ� �ٸ��ٸ� 1, ���ٸ� 0���� ��ȯ�ϴ� ������.
	GetBinary(50);
	GetBinary(70);
	GetBinary(50 ^ 70);
	printf("-------------------\n");

	return 0;
}