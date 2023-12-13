// 2022-07-12 ����


#include <iostream>
#include <string>
using namespace std;

class Class
{
public:
	// �ʱ�ȭ ����Ʈ ������(Initializer list ~, �̴ϼȶ����� ��� ������)
	// : �������� ���Ǹ� �����ϱ� ���� ������ �� �ִ� ���� �߰��� �� �ִ�.
	//   ������ ���� ���� ':'(colon)�� ���� �ۼ��ϸ�, �ʱ�ȭ�� ��� ������ ','�� ������ �� '()' ���� �ʱ�ȭ�� ���� �����Ѵ�.
	//   * ��� ���� �ʱ�ȭ��( member_var1( init_value1 ), ... ), �������� �߰��� ������.
	//   * const Ű���带 �����Ͽ� ����� ��� ������ ���� ������ ����(�̿��� ������δ� ���� �߻���).
	//   * ����� ���ÿ� �ʱ�ȭ �ϴ� ���¿� ����.
	Class(int Num = 0) : Const(Num), A(1), B(2)
	{
		cout << "�⺻ ������ ȣ��" << endl;
		cout << "Const: " << Const << endl;
		cout << "A: " << A << endl;
		cout << "B: " << B << endl;
	};

	// ������ ���� ���� ':'�� �̿��Ͽ� �ٸ� ������ ȣ���� ������.
	// * �� ��쿡�� �̴ϼȶ����� ����Ʈ�� �����ϴ� �����ڸ� ���� ������ ��, {} ���� �ڵ���� ����ȴ�.
	//   ��, ���� �ҽ� �ڵ� ��������
	//     1) Class Ŭ������ �⺻ ������(������ �������� ��)�� �����Ͽ� Const, A, B�� ���� num(�μ��� �Ѱ����Ƿ�), 1, 2�� ����
	//     2) �־��� a, b �μ��� A, B�� �ٽ� �ʱ�ȭ.
	//   �� ���� ������ ����ȴ�.
	Class(int num, int a, int b) : Class(num)
	{
		cout << "�����ε� ������ ȣ��" << endl;
		A = a;
		B = b;
	};

	// const Ű����� �ش� ��� �Լ� ������ ��� ������ ���� �������� �ʱ� ���� ���������
	// ���� ��� ������ ���ؼ��� ������� �ʴ´�(���� ��� ���� �޸� ������ data �������� �Ҵ�Ǳ� ����).
	__forceinline void print() const
	{
		Static++;
		cout << "Print call: " << Static << endl;
		cout << "Const     : " << Const << endl;
		cout << "A         : " << A << endl;
		cout << "B         : " << B << endl;
	}

	int GetStatic()
	{ return Static; }

	// ���� ��� �Լ�(Static member function)
	// : ��ü ���� ����ϱ� ���� �����ϴ� �Լ��̸�, ���� ��� ������ ���� �Ǵ� ����� �Ұ����ϴ�(const Ű���嵵 �Ұ�����).
	//   * thiscall�� ������ �ƴϹǷ�, � ��ü�� ��� ������ �����ϴ��� �� �� ���� ����.
	static void StaticFunc()
	{ cout << "Static Function Call" << endl; }

	// �Ҹ���(Destructor)
	// : ��ü�� �Ҹ�� �� �ݵ�� ȣ��Ǵ� ��� �Լ�.
	~Class() {}

private:
	int A;
	int B;

	// ��� ���
	// : ����� �ʱ�ȭ�� �ʿ�������, ���������� �̴ϼȶ����� ����Ʈ �����ڸ� ���� �ʱ�ȭ�� ������.
	const int Const;

public:
	// ���� ��� ����(Static member variable)
	// : �ش� ������ ������ ��� ��ü���� �����ϴ� ��� �����̸�
	//   public���� ����Ǿ����� ���, ��ü ���� Ŭ������::������� �� ������ �����ϴ�(thiscall�� ������ �ƴ�).
	//   * Ŭ���� �ܺο��� �ʱ�ȭ�ؾ��Ѵ�(�Ʒ� ����).
	static int Static;
};

// ���� ��� ������ �ʱ�ȭ�� Ŭ������ �ܺο��� �����Ѵ�.
// * Ŭ���� ���ο��� �ʱ�ȭ�ϸ� �����Ϸ��� ������� �Ǵ���.
int Class::Static = 0;

int main()
{
	Class Object1 = Class();
	Object1.print();

	Class Object2 = Class(1, 2, 3);
	Object2.print();

	cout << "���� ��� ������ �� ���: ";
	cout << Class::Static << endl;
	cout << endl;

	cout << "���� ��� �Լ� ȣ��" << endl;
	Class::StaticFunc();

	return 0;
}