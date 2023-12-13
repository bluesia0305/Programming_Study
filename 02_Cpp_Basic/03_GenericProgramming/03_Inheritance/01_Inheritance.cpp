// 2022-07-26 수업


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

// 1) 클래스 템플릿의 파생 클래스가 일반 클래스일 경우
//    * 아래와 같이 기반 클래스에 대한 명시적 특수화가 필요.
//    * (해당 내용은 이하 예시에도 동일) 클래스 템플릿이므로 새로운 일반화된 자료형 추가 가능.
class DerivedInt : public Base<int>
{
public:
	DerivedInt() = default;
	virtual void Addition(int a, int b) override
	{ cout << __FUNCTION__ << ": " << sizeof(a) + sizeof(b) << endl; }
};

// 2) 클래스 템플릿의 파생 클래스가 클래스 템플릿이면서 기반 클래스를 특수화 된 클래스로 상속하는 경우
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

// 3) 클래스 템플릿의 파생 클래스가 클래스 템플릿이면서 기반 클래스를 템플릿으로 상속하는 경우
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
		Base<T>::Addition(a, b);	// 기반 클래스의 함수 호출 시, 자료형을 알려야하므로 <T>를 붙여야 함.
	}
};

// 4) 클래스 템플릿의 파생 클래스가 클래스 템플릿이면서 기반 클래스를 템플릿으로 상속하는 경우
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
		Base<U>::Addition(a, b);	// 기반 클래스의 함수 호출 시, 자료형을 알려야하므로 <T>를 붙여야 함.
	}
};

int main()
{
	cout << "기반 클래스(클래스 템플릿)" << endl;
	Base<float> base;
	base.SetA(1.5);
	cout << "a: " << base.GetA() << endl;
	base.Addition(1.5, 1.5);
	cout << endl;


	cout << "파생 클래스(기반 클래스가 인스턴스화 된 템플릿인 일반 클래스)" << endl;
	DerivedInt derived1;
	derived1.SetA(10);
	cout << "a: " << derived1.GetA() << endl;
	derived1.Addition(1.5, 1.5);
	cout << endl;


	cout << "파생 클래스(기반 클래스가 인스턴스화 된 템플릿인 클래스 템플릿)" << endl;
	DerivedTemplate1<double> derived2;
	derived2.SetA(10);
	cout << "a: " << derived2.GetA() << endl;
	derived2.Addition(1.5, 1.5);
	cout << endl;


	cout << "파생 클래스(기반 클래스가 템플릿인 클래스 템플릿)" << endl;
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