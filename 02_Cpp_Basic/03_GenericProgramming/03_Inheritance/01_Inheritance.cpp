// 2022-07-26 ����


#include <iostream>
using namespace std;

template<typename T>
class Base
{
private:
	T a;
	int b;
	
public:
	Base()
	{ cout << __FUNCTION__ << ": " << sizeof(a) << endl; }

	void SetA(T a)
	{ this->a = a; }

	T GetA()
	{ return this->a; }

	virtual void Addition(T a, T b)
	{ cout << __FUNCTION__ << ": " << a + b << endl; }
};

// 1) Ŭ���� ���ø��� �Ļ� Ŭ������ �Ϲ� Ŭ������ ���
//    * �Ʒ��� ���� ��� Ŭ������ ���� ����� Ư��ȭ�� �ʿ�.
//    * (�ش� ������ ���� ���ÿ��� ����) Ŭ���� ���ø��̹Ƿ� ���ο� �Ϲ�ȭ�� �ڷ��� �߰� ����.
class DerivedInt : public Base<int>
{
public:
	DerivedInt() = default;
	virtual void Addition(int a, int b) override
	{ cout << __FUNCTION__ << ": " << sizeof(a) + sizeof(b) << endl; }
};

// 2) Ŭ���� ���ø��� �Ļ� Ŭ������ Ŭ���� ���ø��̸鼭 ��� Ŭ������ Ư��ȭ �� Ŭ������ ����ϴ� ���
template<typename T>
class DerivedTemplate1 : public Base<char>
{
private:
	T c;

public:
	DerivedTemplate1()
	{ cout << __FUNCTION__ << ": " << sizeof(c) << endl; }

	void SetC(T c)
	{ this->c = c; }

	T GetC() const
	{ return c; }

	virtual void Addition(char a, char b) override
	{ cout << __FUNCTION__ << ": " << sizeof(a) + sizeof(b) << endl; }
};

// 3) Ŭ���� ���ø��� �Ļ� Ŭ������ Ŭ���� ���ø��̸鼭 ��� Ŭ������ ���ø����� ����ϴ� ���
template<typename T>
class DerivedTemplate2 : public Base<T>
{
private:
	T c;

public:
	DerivedTemplate2()
	{ cout << __FUNCTION__ << ": " << sizeof(c) << endl; }

	void SetC(T c)
	{ this->c = c; }

	T GetC() const
	{ return c; }

	virtual void Addition(T a, T b) override
	{
		cout << __FUNCTION__ << ": " << sizeof(a) + sizeof(b) << endl;
		Base<T>::Addition(a, b);	// ��� Ŭ������ �Լ� ȣ�� ��, �ڷ����� �˷����ϹǷ� <T>�� �ٿ��� ��.
	}
};

// 4) Ŭ���� ���ø��� �Ļ� Ŭ������ Ŭ���� ���ø��̸鼭 ��� Ŭ������ ���ø����� ����ϴ� ���
template<typename T, typename U>
class DerivedTemplate3 : public Base<U>
{
private:
	T c;

public:
	DerivedTemplate3()
	{ cout << __FUNCTION__ << ": " << sizeof(c) << endl; }
	void SetC(T c)
	{ this->c = c; }
	T GetC() const
	{ return c; }
	virtual void Addition(U a, U b) override
	{
		//this->a = 10;
		cout << __FUNCTION__ << ": " << sizeof(a) + sizeof(b) << endl;
		Base<U>::Addition(a, b);	// ��� Ŭ������ �Լ� ȣ�� ��, �ڷ����� �˷����ϹǷ� <T>�� �ٿ��� ��.
	}
};

int main()
{
	cout << "��� Ŭ����(Ŭ���� ���ø�)" << endl;
	Base<float> base;
	base.SetA(1.5);
	cout << "a: " << base.GetA() << endl;
	base.Addition(1.5, 1.5);
	cout << endl;


	cout << "�Ļ� Ŭ����(��� Ŭ������ �ν��Ͻ�ȭ �� ���ø��� �Ϲ� Ŭ����)" << endl;
	DerivedInt derived1;
	derived1.SetA(10);
	cout << "a: " << derived1.GetA() << endl;
	derived1.Addition(1.5, 1.5);
	cout << endl;


	cout << "�Ļ� Ŭ����(��� Ŭ������ �ν��Ͻ�ȭ �� ���ø��� Ŭ���� ���ø�)" << endl;
	DerivedTemplate1<double> derived2;
	derived2.SetA(10);
	cout << "a: " << derived2.GetA() << endl;
	derived2.Addition(1.5, 1.5);
	cout << endl;


	cout << "�Ļ� Ŭ����(��� Ŭ������ ���ø��� Ŭ���� ���ø�)" << endl;
	DerivedTemplate2<short> derived3;
	derived3.SetA(10);
	cout << "a: " << derived3.GetA() << endl;
	derived3.Addition(1.5, 1.5);
	cout << endl;


	Base<float>* p = new DerivedTemplate2<float>;
	p->Addition(1.5, 1.5);


	DerivedTemplate3<int, float> derived4;
	derived4.Addition(1.5, 1.5);
	derived4.GetA();

	return 0;
}