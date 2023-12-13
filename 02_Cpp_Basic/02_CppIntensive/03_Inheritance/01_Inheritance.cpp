// 2022-07-13 ����


#include <iostream>
using namespace std;

// ���(Inheritance)
// : ��� Ŭ����(base, or parent class)�� ����� Ȯ���Ͽ�
//   �Ļ� Ŭ����(derived, or child class)�� �����ϴ� �������, ���� ������ �ڵ� ��Ȱ�뼺�� �����ϸ�,
//	 Ŭ���� ���� ������ ���踦 ���������ν� �������� ������ ��븦 �����Ѵ�.
// 
//   class {�Ļ�Ŭ����_�̸�} : {����������} {���Ŭ����_�̸�}
//   * ������������ ����: ��ӹ��� ��� Ŭ������ ��� ���� �� �Լ��� ��,
//						 �ش� ���������ں��� ���� ���ټ��� ���� ����� ��� �������������� �����Ѵ�(������ ���, private�� ����).
//   * ���߻��: ','�� �̿��� �����ϸ�, �����ϴ� ����̳� �� ��������� ���� -> Ŭ���� �� �ϳ��� ��� Ŭ������ ������ ���α׷����ϴ� ����.
//
//	 <�Ļ� Ŭ���� Ư¡>
//	 1) �Ļ� Ŭ������ �ݵ�� �ڽŸ��� �����ڸ� �ۼ��ؾ� �Ѵ�.
//	 2) �Ļ� Ŭ�������� �⺻������ ��� Ŭ������ ���� ������ ��� ��� �������� ����ȴ�.
//	 3) �Ļ� Ŭ������ ��� Ŭ������ ���� ������ ��� ��� �Լ��� ����� �� �ִ�.
//	 4) �Ļ� Ŭ�������� ���ο� ����� �߰��� �� �ִ�.

// ��� Ŭ����(Base class, �θ�(parent) Ŭ������� ��)
// : ����� �����ִ� Ŭ����.
class Base
{
	// private ����������
	// : ����� Ŭ���� �������� ������ ����.
private:
	int base_private = 0;

	// protected ����������
	// : ����� Ŭ������ �Ļ� Ŭ���������� ������ �����ϳ�, �Ļ� Ŭ������ �ܺο����� ���� �Ұ���.
protected:
	int base_protected = 0;

	// public ����������
	// : ��� �ܺο��� ���� ������.
public:
	int base_public = 0;

	Base() { cout << "constructor of base class" << endl; }
	~Base() { cout << "destructor of base class" << endl; }

	__forceinline void base_print() const
	{
		cout << "base_private     : " << base_private << endl;
		cout << "base_protected   : " << base_protected << endl;
		cout << "base_public      : " << base_public << endl;
	}
};

// �Ļ� Ŭ����(Derived class, �ڽ�(child) Ŭ������� ��)
// : Ư�� ��� Ŭ������ ����� �������� Ŭ����.
//   * final Ű���带 Ŭ������ �ڿ� ������ ���, �ش� ������ ��� Ŭ������ �ϴ� ����� �����Ѵ�.
class Derived : public Base
{
private:
	int derived_private = 0;

protected:
	int derived_protected = 0;

public:
	int derived_public = 0;

	Derived()
	{
		cout << "constructor of derived class" << endl;
		//base_private = 1;		- Error -
		base_protected = 1;
		base_public = 1;
	}

	~Derived()
	{ cout << "destructor of derived class" << endl; }

	__forceinline void derived_print() const
	{
		cout << "derived_private  : " << derived_private << endl;
		cout << "derived_protected: " << derived_protected << endl;
		cout << "derived_public   : " << derived_public << endl;
	}
};

#pragma region Constructor & Destructor
class Temp1
{
public:
	Temp1() { printf("%s\n", __FUNCTION__); }
	~Temp1() { printf("%s\n", __FUNCTION__); }
};

class Temp2 : public Temp1
{
public:
	Temp2() { printf("%s\n", __FUNCTION__); }
	~Temp2() { printf("%s\n", __FUNCTION__); }
};

class Temp3 : public Temp2
{
public:
	Temp3() { printf("%s\n", __FUNCTION__); }
	~Temp3() { printf("%s\n", __FUNCTION__); }
};

class Temp4 : public Temp3
{
public:
	Temp4() { printf("%s\n", __FUNCTION__); }
	~Temp4() { printf("%s\n", __FUNCTION__); }
};

class Temp5 : public Temp4
{
public:
	Temp5() { printf("%s\n", __FUNCTION__); }
	~Temp5() { printf("%s\n", __FUNCTION__); }
};
#pragma endregion

int main()
{
	cout << "1) �Ļ� Ŭ���� ����." << endl;
	Derived derived;
	//derived.base_private = 10;	- Error -	* ��� Ŭ���������� ���������ڰ� private �̹Ƿ�, �ܺο��� ���� �Ұ���.
	//derived.base_protected = 10;	- Error -	* ��� Ŭ���������� ���������ڰ� protected �̹Ƿ�, �ܺο��� ���� �Ұ���.
	derived.base_public = 10;
	derived.derived_public = 10;
	derived.base_print();
	derived.derived_print();
	cout << endl;

	cout << "2) ��� Ŭ���� ����." << endl;
	Base base;
	base.base_public = 10;
	base.base_print();
	cout << endl;

	// ��� Ŭ������ ���Ŀ����� �Ļ� Ŭ�������� ����� ����� ����� �� ����.
	//base.derived_public;			- Error - ��ü�� derived_public�� ����� Ŭ�������� ���� Ŭ������ �ν��Ͻ���.
	//base.derived_print();			- Error - ��ü�� derived_print()�� ����� Ŭ�������� ���� Ŭ������ �ν��Ͻ���.
	

	// ��ӿ����� ������ �� �Ҹ��� ȣ�� ���� ��Ģ
	// : ������/�Ҹ��ڴ� �⺻������ Ư�� Ŭ������ ��ü�� ����/�Ҹ��� ��,
	//   ��� Ŭ���� �Ǵ� �Ļ� Ŭ�������� ������/�Ҹ��ڸ� �Բ� ȣ���ϴ� ����� ������ �ִ�.
	//   �̶�, �����ڿ� �Ҹ��ڸ� ȣ���ϴ� ���� ��Ģ�� �Ʒ��� ����.
	//   1) ������: �ֻ��� ��� Ŭ�������� ������ �Ļ� Ŭ������ ������� ȣ��.
	//   2) �Ҹ���: ������ �Ļ� Ŭ�����κ��� �ֻ��� ��� Ŭ������ ������� ȣ��.
	cout << "3) ������/�Ҹ��� ȣ�� ���� ��Ģ." << endl;
	Temp5* tempClass = new Temp5();
	delete tempClass;
	tempClass = nullptr;
	cout << endl;

	cout << "4) main �Լ� ����� �Բ� ��ü�鿡 ���� �Ҹ��� ȣ��." << endl;

	return 0;
}