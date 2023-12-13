// 2022-07-18 ����


#include <iostream>
#include <combaseapi.h>
//using namespace std;		* combaseapi.h ����� ����� ���� std ��� ���ϴ� ���� ����.

// �������̽�(Interface)
// : ���� ���� �Լ��� ���� �Ҹ��ڸ��� ������ �߻� Ŭ����.
//   * �������̽��� ����� ���λ�� ������ I�� �ٿ� �����(�Ϲ��� ���).

// �������̽��� ���� ����1: ���ǿ� �°� ���� ���� �Լ��� ���� �Ҹ��ڸ� ������ ����.
class IInterface1 abstract
{
public:
	//int a;	* ��� ���� �� �Լ��� ������ ������(�������̽��� ���������� �߻� Ŭ������ Ư���� ����� ���̹Ƿ�)
	virtual ~IInterface1() = default;
	virtual void Func() abstract;
};

// �������̽��� ���� ����2: combaseapi.h ����� �����ϸ� �Ʒ��� ���� ���� ����
//                        (#define interface __STRUCT__ �� ����, �� ����ü��)
interface IInterface2
{
	//int a;	* ��� ���� �� �Լ��� ������ ������(�⺻������ �׳� ����ü�̹Ƿ�)
	virtual ~IInterface2() = default;
	virtual void Func() abstract;
};

// �������̽��� ���� ����3: Ű���带 ���� ����.
__interface IInterface3
{
public:
	//int a;	- Error -	* �������̽��� �ۿ��ϱ� ���� �⺻������ ���� ������ ������.
	
	//Ű���� ��ü������ ���� �Ҹ��ڸ� �����ϹǷ� ������ �Ҹ��� ������ ������.
	//virtual ~IInterface3() = default;		- Error -
	virtual void Func() abstract;
};

class Test : public IInterface1//, public IInterface2, public IInterface3
{
public:
	// IInterface1��(��) ���� ��ӵ�
	void Func() override
	{ std::cout << __FUNCTION__ << std::endl; }

	// ���� ��ӿ����� ���ǻ���
	// : ���� ������Ÿ������ ����� �Լ��� ������ �ִ� ���� ��� Ŭ������ ���� ��ӹ��� ���,
	//   ��� Ŭ�����κ��� �������̵��� �� �Լ��鳢�� �����ε� ���谡 �ڿ������� �����ǹǷ�
	//   �Ű������� ���� ��� ������ �߻��Ѵ�(�Լ� ȣ���� ��ȣ�� �߻�, �����ε������� ��ȯ���� ������� ������ ����).
};

int main()
{
	Test sample;
	sample.Func();
	std::cout << std::endl;

	// ��ĳ���� �� ��� ��� ����
	IInterface1* Interface = &sample;
	Interface->Func();

	return 0;
}