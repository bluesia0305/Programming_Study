// 2022-07-08 ����


#include <iostream>
using namespace std;

// Ŭ����(Class)
// : C++ �������� ��� ������ ����� ���� �ڷ���.
//   ���� C������ ����� ���� �ڷ����� ����ü(struct)�� �ſ� �����ϴ�.

struct Struct
{
// ����ü�� ���, ���������ڸ� ������� ������ public���� ���ֵ�.
private:
	int A = 10;
	int B;

	Struct()
	{
		cout << "Struct Constructor call.";
		B = 20;
	}

	~Struct()
	{
		cout << "Struct Destructor call." << endl;
	}
};

class Class
{
// Ŭ������ ���, ���������ڸ� ������� ������ private�� ���ֵ�.
public:
	int A = 10;
	int B;

	Class()
	{
		cout << "Class Constructor call.";
		B = 20;
	}

	~Class()
	{ cout << "Class Destructor call." << endl; }
};

// ����ü�� Ŭ���� ������
// : ����ü�� ��� ���������ڸ� ������� ������ �⺻������ public ����,
//   Ŭ������ ��� ���������ڸ� ������� ������ �⺻������ private ���� �����.

int main()
{
	// ���������� ���ο� ���� �Ʒ��� ���� ���� �����غ���.
	// * ������, �Ҹ��ڸ� �������� ������ (��, �⺻ ������/�Ҹ��� �̿�) private���� ����Ǿ ����ü ������ ���� or ��ü�� ���� ��ü�� ������.
	//Struct myStruct;
	//myStruct.A;
	//
	//Class myClass;
	//myClass.A;

	return 0;
}