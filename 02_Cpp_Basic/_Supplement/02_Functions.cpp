// 2022-07-14 ��ȭ


#include <iostream>
#include <string>
using namespace std;

// ȣ�� �Ծ�(cdecl call convention)
// : ȣ����(caller)�� ��ȣ����(callee) ���� �Լ��� ���ڸ� �����ϴ� ��Ŀ� ���� �Ծ�.
//   ȣ�� �Ծ��� ��ǻ�� ���п��� ��� �����ƾ�� �׵��� ȣ���ڷκ��� ������ �ް�, ��� ����� ��ȯ�ϴ����� ���� �Ծ��̴�.
//   * cdecl ȣ�� �Ծ�: C �� C++ ���α׷��� ���� �⺻ ȣ�� �Ծ�.
//     1) �μ� ���� ����			: �����ʿ��� ����.
//     2) ���� ���� ���� å��		: ȣ���ϴ� �Լ�(caller)�� ����(stack)���� �μ��� �����Ѵ�.
//     3) �̸�-���� ������		: C ������ ����ϴ� __cdecl �Լ��� ������ ���� �����ϰ� �̸� �տ� _�� �ٴ´�. (_�Լ���)
//     4) ��ҹ��� ��ȯ ��Ģ		: ������� ����.

// �Լ�(Function)
// : �ߺ��� �ڵ��� ������ �ǿ뼺�� �ְ� ����ϴ� ���.

// �Լ��� �����Ͽ� C++���� ���� �߰��� ���
// 1) �̸�����
// 2) ��� �Լ�
// 3) ������ �Ű�����
// 4) �����ε�
// 5) �������̵�

class Class
{
public:
	string Name = "Return";
	int member1 = 10;

	Class() { cout << "��ü ����" << endl; }

	Class(const Class& a)
	{ cout << "copy ��ü ����" << endl; }

	~Class()
	{ cout << Name << ": A �Ҹ�" << endl; }
};

int Add(int a, int b)
{
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	return a + b;
}

Class Add(Class Object)
{
	cout << "Object.member1 : " << Object.member1 << endl;
	Object.Name = "Parameter";

	return Object;
}

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// �ζ��� �Լ�
// __forceinline
// inline : �����Ϸ����� �ζ��� ���� ����

// �Լ� �����ε�(Function overloading)
// : ���� �̸��� �Լ��� ���Ͽ� �Ű������� ����, �ڷ����� �޸��Ͽ� �������� �� �ִ� ���.
//   * C   : �Լ��� �̸��� ������ �Լ��� ã�´�.
//   * C++ : �Լ��� �̸�, �Ű������� ������ �ڷ����� ���� �Լ��� ã�´�.

void Addition(int   A, int   B, bool P = false)
{
	if (P)
	{
		cout << "A : " << A << endl;
		cout << "B : " << B << endl;
	}
	cout << "Result : " << A + B << endl;
}
void Addition(float C, int   D, bool R = false)
{
	if (R)
	{
		cout << "A : " << C << endl;
		cout << "B : " << D << endl;
	}
	cout << "Result : " << C + D << endl;
}
void Addition(float G, float H, bool N = false)
{
	if (N)
	{
		cout << "A : " << G << endl;
		cout << "B : " << H << endl;
	}
	cout << "Result : " << G + H << endl;
}

// ����Լ�(Recursive function)
// : �Լ��� ���� ������ �ڱ� �ڽ��� ȣ��(��, ���ȣ��)�ϴ� �Լ�.
//   * ���� ������ ������ �ʵ��� ���� �󿡼� �����Ͽ��� �Ѵ�.
//   * ����Լ��� �� ����ϸ� �˰����� �ܼ�ȭ������, ���� ������(Stack frame)�� �����Ͽ� ������ ������.
void Hello(unsigned count)
{
	if (count == 1) return;
	cout << "Hello";
	Hello(count - 1);
}

int main()
{
	Class object_main;
	object_main.Name = "Main";
	cout << Add(10, 20) << endl;
	cout << Add(object_main).member1 + 10 << endl;

	//int a = 10;
	//int b = 20;
	//Swap(&a, &b);
	//cout << a << " : " << b << endl;
	return 0;
}