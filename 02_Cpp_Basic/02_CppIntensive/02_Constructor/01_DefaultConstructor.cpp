// 2022-07-11 ����


#include <iostream>
#include <string>
using namespace std;

// ������(Constructor)
// : ��ü�� ������ �� ȣ��Ǵ� �޼���.
//   Ŭ������� ������ �̸��� ������, �Ű����� ����� �����Ͽ� �����ε��� ������.
//   * �ۼ��� ���, �ݵ�� public ���� �ۼ��Ǿ�� �Ѵ�.
//   * ��ȯ���� ���� Ư�� ��� �Լ��̴�.

class Class1
{
	// �⺻ ������(Default constructor, ����Ʈ ������)
	// : �Ű������� ���ų� ��� �Ű������� �ʱ�ȭ�� �Ű�����(������ �Ű�����)�� �������̴�.
	//   * ���� Ŭ���� ���� 2 �� �̻��� �⺻ �����ڸ� �����ϸ�, ��ü ���� �ÿ� ��ȣ��(ambiguous)�� ���� ���� �߻�.
	//   * Ŭ���� ���� ��������� ���ǵ� �����ڰ� �ϳ��� ������ ���, �ݵ�� Ŭ���� ���� �⺻ �����ڸ� �����ؾ� �Ѵ�.
	
	// �Ͻ��� �⺻ ������(Implicit default constructor)
	// : Ŭ���� ���� ��, �����ڸ� �������� ������ �����Ϸ��� ���� �Ͻ������� �����Ǵ� �⺻ �������̸�
	//   Ŭ������() {} �� ������ ������ �ϴ� inline �������̴�.
	//   * Ŭ������() = default; �� ������.
	//   1) Ŭ���� ���� ��, �����ڸ� �������� ������ �����Ϸ��� ���� �Ͻ��� �⺻ �����ڰ� �����ȴ�.
	//   2) Ŭ���� ���� �����ڰ� �ϳ��� ���ǵǸ� �����Ϸ��� ���������� �⺻ �����ڸ� �������� �ʴ´�.
	//   3) �Ͻ��� �⺻ �����ڴ� �⺻������ ��� ����(�ʵ�)�� �������� �����ϸ�, ���� trash value�� �ʱ�ȭ�Ѵ�.
	//      * ��, �̴ϼȶ������� �Բ� ��ü�� ����Ǹ� ���� 0���� �ʱ�ȭ�Ѵ�.
	//   4) �Ͻ��� �⺻ �����ڸ� ����� ��, {Ŭ������} {������}(); �� ���� ������ �� ����(�Լ� �������� �νĵǾ� ���� �߻�).

public:
	Class1()
	{
		cout << "�⺻ ������ ȣ��." << endl;
	}

	Class1(string name, int a, int b)
	{
		Name = name;
		A = a;
		B = b;
		cout << "������(Class(int, int)) ȣ��." << endl;;
	}

	void print() const
	{
		printf("%s::[A: %i, B: %i]\n", Name.c_str(), A, B);
	}

private:
	string Name;
	int A = 10;		// ����) �����ڿ��� A�� �ʱ�ȭ�ϴ� ���, ���� ������� ���ǹ�����.
	int B;
};

class Class2
{
public:
	void print() const
	{
		printf("%s::[A: %i, B: %i]\n", Name.c_str(), A, B);
	}

private:
	string Name;
	int A;
	int B;
};

class Class3
{
public:
	Class3(string name, int a, int b)
	{
		Name = name;
		A = a;
		B = b;
		cout << "������(Class(int, int)) ȣ��." << endl;;
	}

	void print() const
	{
		printf("%s::[A: %i, B: %i]\n", Name.c_str(), A, B);
	}

private:
	string Name = "NULL";
	int A = 0;
	int B = 0;
};

int main()
{
	cout << "1) ����� �⺻ �����ڿ��� �ʱ�ȭ���� ���� ��� ������ ����." << endl;
	cout << "   -> �̴ϼȶ������� ���� ���� �׻� trash value�� �ʱ�ȭ�ȴ�." << endl;
	Class1 myObj1;					// �⺻ �������� �Ͻ��� ȣ��  -> trash value�� �ʱ�ȭ�ȴ�.
	Class1 myObj2 = Class1();		// �⺻ �������� ����� ȣ��	-> trash value�� �ʱ�ȭ�ȴ�.
	myObj1.print();
	myObj2.print();
	cout << endl;

	cout << "2) �Ͻ��� �⺻ �����ڿ����� �ʱ�ȭ���� ���� ��� ������ ����." << endl;
	cout << "   -> �̴ϼȶ������� �Բ� ����Ǹ� 0���� �ʱ�ȭ�ȴ�." << endl;
	Class2 myObj3;					// �⺻ �������� �Ͻ��� ȣ��  -> trash value�� �ʱ�ȭ�ȴ�.
	Class2 myObj4 = Class2();		// �⺻ �������� ����� ȣ��	-> 0���� �ʱ�ȭ�ȴ�.
	myObj3.print();
	myObj4.print();
	cout << endl;
	printf("----------------------------------------------\n");
	cout << endl;

	cout << "3) ������ �����ε��� ����." << endl;
	Class1 myObj5 = Class1("myObj5", 1, 2);			// explicit assignment     �� ���� ������� ������ �� �ִ�.
	Class1 myObj6("myObj6", 1, 2);					// implicit assignment
	myObj5.print();
	myObj6.print();
	cout << endl;
	printf("----------------------------------------------\n");
	cout << endl;

	// *** 4) ������ ���� ���ǻ��� ***
	//Class3 myObj7;	- Error - 		* �����ڰ� �����ϳ�, �⺻ �����ڸ� �������� �ʾ��� ���� �Ű����� ���� ��ü ������ �Ұ����ϴ�.
	//Class3 myObj8();					* �⺻ �������� �Ͻ��� ȣ�⿡�� ()�� ����ϸ� �����Ϸ��� �ش� ��ɹ��� ��ü ������ �ƴ� �Լ� �������� �ν��Ѵ�.

	return 0;
}