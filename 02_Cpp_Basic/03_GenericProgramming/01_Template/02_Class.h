// 2022-07-19 수업


#pragma once
#include <iostream>
using namespace std;

// 클래스 템플릿(Class template)
// : 클래스의 일반화 된 선언. 컴파일러에 의해 생성되기 때문에 생성된 클래스(generated class)라고도 불린다.
//	 * 함수 템플릿과는 다르게 완전 특수화 이외에 부분 특수화(partial specialization)가 가능하다.
//	 * 클래스 템플릿 내에 클래스 템플릿의 선언이 가능하다(nested class template).

// 부분 특수화(Partial specialization)
// : 템플릿 인수가 2개 이상인 경우에 대하여, 일부 매개변수만 특수화하는 경우를 의미한다.
//	 * 함수 템플릿에서는 제공되지 않으며 클래스 템플릿에서만 제공되는 기능.
template<typename T>
class Template
{
private:
	T Num1;
	T Num2;

public:
	Template(T num1, T num2);
	void Print();
	T GetNum1() const;
};

// 클래스 템플릿의 멤버 함수는 클래스 템플릿의 외부에서 정의된 경우, 함수 템플릿처럼 정의된다.
// * 클래스 템플릿의 메소드 선언 및 정의는 헤더 파일과 CPP 파일로 나눠 작성이 불가능하므로 헤더 파일에 전부 작성해야한다.
//   (헤더 파일부터 읽을 때에 자료형이 정해져있지 않으므로 컴파일러에 의해 인스턴스화가 불가능하다)
// * 클래스 템플릿의 멤버 함수는 그 자체로 함수 템플릿일 수 있다.
template<typename T>
inline Template<T>::Template(T num1, T num2)
{
	cout << "sizeof(T): " << sizeof(T) << endl;
	Num1 = num1;
	Num2 = num2;
}

template<typename T>
inline void Template<T>::Print()
{ cout << "Num1: " << Num1 << ", Num2: " << Num2 << endl; }

template<typename T>
inline T Template<T>::GetNum1() const
{ return Num1; }
