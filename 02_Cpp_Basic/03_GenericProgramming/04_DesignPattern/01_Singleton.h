// 2022-07-27 수업


#pragma once
#include <iostream>
using namespace std;

// 디자인 패턴(Design pattern)
// : 자주 사용하는 코드를 패턴화 시킨 것을 의미함.

// <외부에서 해당 클래스의 객체를 생성할 수 없도록 만드는 방법>
// 1) 생성자를 private 또는 protected 섹션에서 선언.
// 2) 순수 가상 함수를 하나 이상으로 포함하는 클래스로 선언(즉, 추상 클래스).
// 3) 추상 클래스로 선언(abstract 키워드).

// 싱글톤 디자인 패턴(Singleton ~)
// : 프로그램 실행 후 해당 클래스의 인스턴스가 단 하나만 존재할 수 있도록하는 디자인 패턴.
//   * 주로 템플릿 형태로 만들어지며, 디자인 원리는 아래와 같이 정적 멤버 함수와 정적 지역 변수의 특성을 이용한다.
class Singleton_test
{
public:
	int a_base;
	int b_base;

private:
	Singleton_test();

public:
	// 정적 멤버 함수의 경우에는 구조만 존재해도 멤버 함수의 호출이 가능하므로
	// 해당 클래스와 같이 객체가 없는 상태에서도 멤버 함수 호출이 가능하다.
	static Singleton_test* GetInstance()
	{
		static Singleton_test* single = new Singleton_test();
		return single;
	}
};

template<typename T>
class Singleton
{
public:
	int a_base;
	int b_base;

private:
	Singleton();

public:
	// 정적 멤버 함수의 경우에는 구조만 존재해도 멤버 함수의 호출이 가능하므로
	// 해당 클래스와 같이 객체가 없는 상태에서도 멤버 함수 호출이 가능하다.
	static T* GetInstance()
	{
		static T* single = new T();
		return single;
	}
};