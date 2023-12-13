// 2022-07-19 수업


#include <iostream>
#include <string>
using namespace std;

// 일반화 프로그래밍(Generic programming)
// : C++이 가지는 프로그래밍 언어로서의 특징 중 하나로,
//	 객체지향 프로그래밍 패러다임 이후로 데이터와 행동을 나누는 것을 기반으로 하여
//	 효과적인 알고리즘, 데이터 구조와 다른 소프트웨어 개념에 대한 추상적인 표현을 찾는 것과
//	 그들의 시스템적인 조직에 중점을 두는 패러다임.
//	 * C++에서는 자료형(data type)의 일반화(generalization)를 통하여 구현된다.

// 함수 템플릿(Function template)
// : 함수의 일반화된 선언으로, 컴파일러에 의해 생성되기 때문에 생성된 함수(generated function)라고도 불린다.
//	 같은 알고리즘을 기반으로 하면서, 서로 다른 자료형에 대해 동작하는 함수를 한 번에 정의할 수 있다.
// 
//	 <함수 템플릿 인스턴스화>
//	 - 함수 템플릿이 각 형식에 대해 처음 호출될 때 컴파일러는 인스턴스를 만든다(code area에 저장).
//	   이때, 각 인스턴스는 전달받은 형식에 대해 특수화된 템플릿 함수의 버전(version)이다.
//	 
//	 <함수 템플릿 특징>
//	 * 함수 템플릿끼리, 또는 일반 함수와의 오버로딩이 가능하다(단, 명확하지 않은 템플릿 함수가 생기지 않도록 주의).
//	 * 일반 함수의 오버로딩에서는 선택적 매개변수의 사용과 인라인 함수 설정이 가능하지만, 템플릿에서는 모두 불가능하다.
//	 * 템플릿 함수 호출의 우선순위는 특수화 된 템플릿이 우선순위가 가장높고, 이후에는 알맞은 코드가 2순위이다.
//	   또한, 오버로딩 관계에 있는 일반 함수가 존재한다면 해당 일반 함수가 템플릿보다 우선순위가 더 높다.
template<typename T> void Addition(T a, T b)							// 메인 템플릿(Main template).
{ cout << a + b << endl; }

// 명시적 특수화(Explicit specialization)
// : 특정 자료형에 대하여, 메인 템플릿(main template)과 다른 기능을 수행을 할 수 있도록 하는 기능(오버로딩 방식).
//	 * 아래 예시에서 함수의 프로토타입 부분의 <const char*>는 제외할 수 있다(deduced template argument).
template<> void Addition<const char*>(const char* a, const char* b)		// 특수화 된 템플릿(Specialized template).
{ cout << "const char* 형식은 서로 더할 수 없습니다." << endl; }

// 템플릿 인수를 2 개 이상 사용하는 템플릿의 예시
template<typename T, typename U> void Addition2(T a, U b)
{ cout << a + b << endl; }

int main()
{
	Addition(1, 2);							// 암시적 인스턴스화(implicit instantiation).
	Addition<float>(1.2f, 2);				// 명시적 인스턴스화(explicit ~): 명시적으로 템플릿 인수의 자료형을 지정.
	Addition<string>("ABC", "DEF");
	Addition<const char*>("ABC", "DEF");	// const char* 형식에 대해 명시적 특수화 -> 컴파일 오류가 일어나지 않도록 오버로딩.
	Addition2<float, float>(1.0f, 2.5f);	// 템플릿 인수를 2 개 이상 사용하는 템플릿의 예시(자료형 2개를 사용했지만 같아도 됨).
	Addition2<float, int>(1.0f, 2);

	return 0;
}