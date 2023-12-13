// 2022-07-15 ����


#include <iostream>
using namespace std;

// ������(Polymorphism)
// : ���� �ٸ� ��ü�� ������ ����� ���� �ٸ� ������� ó���� �� �ִ� ���.

// ���� �Լ�(Virtual function)
// : ���� �Լ��� ��� Ŭ�������� ����Ǿ�, �Ļ� Ŭ������ ���� �����ǵ�(�� ���� ����ϸ� �����)�� ��� �Լ��̴�.
//   ������(pointer) �Ǵ� ��� Ŭ������ ���� ����(reference)�� ����Ͽ� �Ļ� Ŭ������ ��ü�� �����ϸ�
//   �ش� ��ü�� ���� ���� �Լ��� ȣ���ϰ� �Ļ� Ŭ������ �Լ��� ������ �� �ִ�.
//   �̴� �ַ� ����ð�(runtime)�� �Լ��� ������(polymorphism)�� �����ϴµ� ���ȴ�.
//   ���� �Լ��� ��� Ŭ�������� virtual Ű����� �Լ��� �����ϸ�, �Ʒ��� ���� ��Ģ�� ���� ������ �����ϴ�.
//
//	 <���� �Լ��� ���� ��Ģ>
//	 1) ���� �Լ��� ����(static)���� ����� �� ������ �ٸ� Ŭ������ ģ��(friend) �Լ��� �� ���� ����.
//	 2) ���� �Լ��� ����ð� �������� ������� ��� Ŭ������ ������ �Ǵ� ������ ���� ����(access)�ؾ� �Ѵ�.
//	 3) ���� �Լ��� ������Ÿ��(��ȯ���� �Ű�����)�� �⺻ Ŭ������ �Ļ� Ŭ�������� �����ϴ�(function overriding�� ����ϹǷ�).
//	 4) Ŭ������ ���� �Ҹ��ڸ� ���� �� ������ ���� �����ڸ� ���� �� ����.
//	    * �Ҹ����� ���, �̸��� �ٸ����� �������̵����� �����.
//
//	 <���� �Լ��� Ư¡>
//	 1) ��� Ŭ�������� ���� �Լ��� ����� �Լ��� �Ļ� Ŭ�������� �����ǵ� �� �⺻������ ���� �Լ��� ���ǵȴ�(Ű���� ���̵�).
//	 2) ����Ű�� �ִ� �ڷ����� �ƴ�, ���������� �����ϰ� �ִ� �ڷ����� �������� ȣ��ȴ�.
//	 3) ���� �Լ��� ���ؼ��� ��� ������ Ű����
//		- override: ��� Ŭ������ ������ �̸��� ���� �Լ��� �ִ��� �ҽ� �ڵ� �󿡼� Ȯ���� �� �ְ� �ϴ� Ű����.
//		- final   : ���� �Ļ� Ŭ������������ ������(override)�� �� ������ ����.

// ������ Ŭ����(Polymorphic class)
// : �ϳ� �̻��� ���� �Լ�(�Ҹ��� ����)�� �����ϴ� Ŭ����.
class Base
{
public:
	Base() { cout << "Base Constructor Call" << endl; }
	
	// Base* �������� ���� -> ��� Ŭ������ �Ҹ��ڿ� ���� ���� -> ���� �Լ��� ����Ǿ� ���������� �����ϰ� �ִ� �Ļ� Ŭ������ �Ҹ��ڷ� ����
	virtual ~Base() { cout << "Base Destructor Call" << endl; }

	void NormalFunc() const
	{ cout << __FUNCTION__ << endl; }

	virtual void VirtualFunc() const
	{ cout << __FUNCTION__ << endl; }
};

class Derived : public Base
{
public:
	Derived() { cout << "Derived Constructor Call" << endl; }

	~Derived() { cout << "Derived Destructor Call" << endl; }

	void NormalFunc() const
	{ cout << __FUNCTION__ << endl; }

	void NormalFunc(int a, int b)
	{ cout << __FUNCTION__ << "(int a, int b)" << endl; }

	void VirtualFunc() const override
	{ cout << __FUNCTION__ << endl; }
};

int main()
{
	Base* pDerived = new Derived();
	cout << endl;

	cout << "1) pDerived->NormalFunc();" << endl;
	pDerived->NormalFunc();
	cout << endl;

	cout << "2) static_cast<Derived*>(pDerived)->NormalFunc();" << endl;
	static_cast<Derived*>(pDerived)->NormalFunc();
	cout << endl;

	cout << "3) pDerived->VirtualFunc();" << endl;
	pDerived->VirtualFunc();
	cout << endl;

	cout << "4) static_cast<Base*>(pDerived)->NormalFunc();" << endl;
	static_cast<Base*>(pDerived)->VirtualFunc();
	cout << endl;

	delete pDerived;
	pDerived = nullptr;

	return 0;
}