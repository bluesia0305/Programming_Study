// 2022-06-23 ����(���)


// �Լ� ������ (Function pointer)
// : �Լ��� �ּҰ��� ������ �� �ִ� ������.


#include <iostream>

void Hello()
{ printf("Hello\n"); }

float Mul(int a, int b)
{ return a * b; }

int main()
{
	// �Լ� ȣ�� ������ ()
	// : �ش� �ּҿ� ����Ǿ��ִ� �Լ��� ȣ�����ִ� ������
	
	// �Լ��� �̸��� �Լ��� �����ϰ� �ִ� �ּҸ� �ǹ���.
	printf("Hello �Լ��� �����ϴ� ��ġ: %p\n", Hello);
		
	// �Լ� �������� ���� ���
	// {����ų �Լ��� ��ȯ��} ( *{������ �̸�} )( {�Ű������� �ڷ���} ) = �Լ��� �ּҰ�;
	void (*p)() = Hello;
	float (*pMul)(int, int) = Mul;
	float mul = pMul(3, 4);
	printf("mul: %.2f\n", mul);

	return 0;
}