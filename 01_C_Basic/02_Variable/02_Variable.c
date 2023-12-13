// 2022-05-25 ����


// ��ǻ�Ϳ����� �Ǽ��� ǥ��: �����Ҽ��� / �ε��Ҽ��� ������� ����.
// 1) �����Ҽ���(fixed point) ���: �Ǽ���, ������, �����ο� ����� �޸𸮸� ����.
// 2) �ε��Ҽ���(floating point) ���: �Ǽ���, ������, �����ο� ����� �޸𸮸� �������� ����.
// * �Ǽ��� bit state ��ȯ�� �־�� ������ �߻��� �� ���� (�Ϻ��� ���� ����� �� ���� �� ����).

// �Ǽ� ǥ�� �ڷ���
// float	4 byte (32 bit)		3.4 * 10^-37	~	3.4 * 10^38
// double	8 byte (64 bit)		1.7 * 10^-307	~	3.4 * 10^308
// * float, double ��� unsigned Ű���带 �������� ���� (������ ��ȣ�� ����).

// ��������
// float:	�Ҽ��� 7�ڸ����� ������ ���� �߻����� ����.
// double:	�Ҽ��� 15�ڸ����� ������ ���� �߻����� ����.

// �������� ���� ǥ���:
// 1) Camel: warriorCharacter	<- ù���ڴ� �ҹ���, �ܾ �ٲ� ������ �빮��
// 2) Pascal: WarriorCharacter	<- �ܾ� ��� ù���ڸ� �빮�ڷ�
// 3) Hungarian: fWarriorHP		<- �������� ù���ڸ� �ڷ�������
// 4) Snake: warrior_character	<- �ܾ �ٲ� ������ _(underbar)�� ����


#include <stdio.h>

int main()
{
	float myFloat = 3.14f;		// float �ڷ����� ���� �ʱ�ȭ�� ��, f�� ���̻�� �ٿ��ִ� ���� ����.
	double myDouble = 1.234;

	printf("myFloat: %f\n", myFloat);
	printf("myFloat: %.14f\n", myFloat);
	printf("myDouble: %lf\n", myDouble);
	printf("myDouble: %.14lf\n", myDouble);    // �Ҽ��� ���� 14�ڸ����� ���
	printf("myDouble: %.50lf\n", myDouble);    // �Ҽ��� ���� 50�ڸ����� ���

	return 0;
}