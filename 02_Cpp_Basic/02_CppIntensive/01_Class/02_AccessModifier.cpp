// 2022-07-08 ����


#include <iostream>
using namespace std;

// ĸ��ȭ(Encapsulation)
// : ��ü���� ���α׷����� 4�� �Ӽ� ���� �ϳ���,
//   ����(public)�ϰų� ����(private, protected) ���(���� = fields, �Լ� = methods)���� ������� ����� �ǹ���.

// ����������(Access modifier)
// : ���м��� �̿��ϱ� ���� �����ϴ� �������,
//   ��� ���� �� �Լ��� ����� ���߰ų� �����ϴ� ���� ���.
//   * ����: private, public, protected (3 ��).

// ����ü�� Ŭ������ ������ �������� �����ϴ� ����?
// 1) ���м��� ���� �߿伺�� �νĵ� �� Ŭ������ �����������
//    ���� C��� �����ڵ鿡 ���� ����ü ������ �̹� ���� ���Ǿ� ���� �ۼ��� �ڵ���� ��ü ������ �����.
// 2) �������� ������ ���, private ��� ������ ���� ������ �� �ֵ��� �Ϸ���
//    ��� Ŭ������ ���Ͽ� �ش� ���� ��ȯ�ϴ� ��� �Լ��� ��������(�Ʒ� ���� ����).

class Class
{
	// private: �ڷ��� �ܺο��� ����� ������ ���� ������ �� ����.
private:
	int priVar;
	int priFunc() const
	{
		cout << "(Private Function Call)" << endl;
		cout << "priVar: " << priVar << endl;
	}

	// public: �ڷ��� �ܺο��� ����� ������ �����Ͽ� ������ ������.
public:
	int pubVar;
	int pubFunc() const
	{ cout << "(Public Function Call)" << endl; }

	// private���� ����� ��� ���� ��ü�� �Ѱ��ִ� �Լ�(��ȯ���� ������ ���� = int&)
	int& GetPriVar()
	{ return priVar; }
};

int main()
{
	Class myObject;
	myObject.pubVar = 20;
	myObject.pubFunc();

	// ���������ڰ� private�� ����� �κп� ���ؼ��� �ܺο��� ������ �Ұ�����.
	//myObject.priVar = 1;
	//myObject.priFunc();

	return 0;
}