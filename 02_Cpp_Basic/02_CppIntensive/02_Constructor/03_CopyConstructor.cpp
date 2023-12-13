// 2022-07-11 ����


#include <iostream>
#include <string>
using namespace std;

// ���� ������(Copy constructor)
// : ��ü�� ���纻�� ������ �� ȣ��Ǵ� ������.
//   ���� �������� ������ {class_name} ( const {class_name}& {param_name} ) {} �̴�.

class Shallow
{
public:
	Shallow(int a = 0, int b = 0)
	{
		A = new int(a);
		B = new int(b);
	}

	// ���� ����(Shallow copy)
	// : ��� ������ �����ϰ� �ִ� ���� �����ϴ� ����.

	// ���� ����(Deep copy)
	// : ��� ������ �����ϰ� �ִ� �� �Ӹ��� �ƴ϶�,
	//   ����Ű�� �ִ� �������� �����ϴ� ����.

	// �⺻ ���� ������(Default copy constructor)
	// : ���� �����ڸ� ������� �ʾ��� ��, �����Ϸ��� �����ϴ� ���� ������.
	//   ���� ������ ��ü�� '����'�Ͽ� ���� �����Ѵ� -> ���� ����.
	//   * ����, �Ϲ������� ��ü ������ �޸� ������ ��(heap) ������ �����ϴ� ��쿡��
	//     ���� ���簡 �Ͼ���� ���� �����ڸ� ����ϴ� ���� �ٶ����ϴ�.
	// 
	//   <���� ���翡 ���� ������ ����>
	//   -  ������ Ŭ������ ��ü a, b�� ���鶧, a�� ��� ������ �� ������ �����ϸ�
	//      b�� �⺻ ���� �����ڿ� ���� a ��ü�� ���� ������ ���� �����ϴ� ���,
	//      �� ������ ����Ű�� �ִ� a ��ü�� b ��ü�� ��� ������ ���� ���� �ּҸ� ����Ű�� �ȴ�.
	//      �̶� a ��ü�� ���� �Ҹ��ϴ� ���, b ��ü�� �Ҹ��� ��
	//      �̹� �Ҹ�� ������ �Ҹ��Ϸ��� �õ��� �ϰ� �ǹǷ� ������ �߻��Ѵ�.
	Shallow(const Shallow& object)
	{
		cout << "Shallow copy constructor call" << endl;
		A = object.A;
		B = object.B;
	}

	__forceinline void print(string name) const
	{
		printf("%s::[%i, %i]\n", name.c_str(), *A, *B);
	};

	int* A;
	int* B;
};

class Deep
{
public:
	Deep(int a = 0, int b = 0)
	{
		A = new int(a);
		B = new int(b);
	}

	Deep(const Deep& object)
	{
		cout << "Deep copy constructor call" << endl;
		A = new int();
		B = new int();
		*A = *(object.A);
		*B = *(object.B);
	}

	__forceinline void print(string name) const
	{
		printf("%s::[%i, %i]\n", name.c_str(), *A, *B);
	};

	int* A;
	int* B;
};

int main()
{
	cout << "1) ���� ����(shallow copy)�� ����." << endl;
	Shallow s1 = Shallow(10, 20);
	Shallow s2 = Shallow(s1);
	*(s1.A) = 30;
	*(s1.B) = 40;
	s1.print("s1");
	s2.print("s2");
	cout << endl;

	cout << "2) ���� ����(deep copy)�� ����." << endl;
	Deep d1 = Deep(10, 20);
	Deep d2 = Deep(d1);
	*(d1.A) = 30;
	*(d1.B) = 40;
	d1.print("d1");
	d2.print("d2");
	cout << endl;

	return 0;
}