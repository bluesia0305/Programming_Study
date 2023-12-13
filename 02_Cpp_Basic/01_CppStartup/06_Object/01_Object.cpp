// 2022-07-01 ����


#include <iostream>
using namespace std;

// ��ü(Object)
// : �߻� �ڷ����� �ν��Ͻ��̸� ��� ����(���� ��)�� ����(�Լ� ��)�� ������ �ִ�.

struct Object
{
	int A;

	// ������(Constructor)
	// : ��ü�� ������ �� (���� ����) ȣ��Ǵ� �Լ�.
	//   �������� �̸��� ����ü �Ǵ� Ŭ������ �̸��� ������ �ڿ� ()�� �ٿ� �����ϸ� ��ȯ���� �ۼ����� ����.
	//   * �Ű������� ����� �����ϸ�, �����ε��� ������.
	//   * ������ ������ �����ϴ��� ��ü�� ������ �Ǹ� �ݵ�� '�⺻ ������(�����Ϸ��� ����)'�� ȣ���� ��.
	Object(int a = 0)
	{
		printf("(Object�� �����˴ϴ�)\n");
		A = a;
	}


	// �Ҹ���(Destructor)
	// : ��ü�� �Ҹ�(�Ҵ�� �޸��� ����)�� �� ȣ��Ǵ� �Լ�.
	//   ����ü �Ǵ� Ŭ������ �̸� �տ� ~�����ڸ� ���̸� �ڿ� ()�� �ٿ� �����ϸ� ��ȯ���� �ۼ����� ����.
	//   * �Ű������� ����� �Ұ����ϸ�, �����ε��� �Ұ�����.
	//   * �Ҹ��� ������ �����ϴ��� ��ü�� �Ҹ��� �Ǹ� �ݵ�� '�⺻ �Ҹ���(�����Ϸ��� ����)'�� ȣ���� ��.
	~Object()
	{ printf("(Object�� �Ҹ�˴ϴ�)\n"); }


	void Print() const
	{
		// this: �ڱ� �ڽ��� ��ġ(��, pointer)�� ��ȯ�ϴ� Ű����.
		//       ����ü ���� �Լ����� ��� ������ ȣ���ϰų� ������ ������ this-> �� �����Ǿ��ִ� �Ͱ� ����.
		//       �̿� ����, ����ü ���� �Լ����� ���� �����ϴ��� �Լ� �ܺ��� ��� ������ ���� �����.
		cout << "this       : " << this << endl;
		cout << "this->A    : " << this->A << endl;
	}
};

int main()
{
	cout << "1) �����ڸ� �����ϴ� �����Ҵ� ������ ����" << endl;
	int integer1 = int();
	cout << "integer1   : " << integer1 << endl;
	int integer2 = int(4);
	cout << "integer2   : " << integer2 << endl;

	Object object1 = Object();
	cout << "object1.A  : " << object1.A << endl;
	Object object2 = Object(2);
	cout << "object2.A  : " << object2.A << endl;
	cout << endl;


	cout << "2) �����ڸ� �������� �ʴ� �����Ҵ� ������ ���� -> �ʱⰪ�� trash value" << endl;
	int* p1 = new int;
	cout << "*p1        : " << *p1 << endl;
	delete p1;

	Object* pObject1 = new Object;
	cout << "pObject1->A: " << pObject1->A << endl;
	delete pObject1;
	cout << endl;


	cout << "3) �����ڸ� �����ϴ� �����Ҵ� ������ ���� -> �ʱⰪ�� 0 (NULL)" << endl;
	int* p2 = new int();
	Object* pObject2 = new Object();
	cout << "*p2        : " << *p2 << endl;
	cout << "pObject2->A: " << pObject2->A << endl;
	delete pObject2;
	delete p2;
	cout << endl;

	cout << "4) this pointer ���� ����" << endl;
	Object obj1 = Object(1);
	Object obj2 = Object(2);
	printf("obj1 �ּ�  : %p\n", &obj1);
	printf("obj1 ��    : %i\n", obj1);
	obj1.Print();
	printf("obj2 �ּ�  : %p\n", &obj2);
	printf("obj2 ��    : %i\n", obj2);
	obj2.Print();
	cout << endl;

	return 0;
}