// 2022-07-11 수업


#include <iostream>
#include <string>
using namespace std;

// 생성자(Constructor)
// : 객체를 생성할 시 호출되는 메서드.
//   클래스명과 동일한 이름을 가지며, 매개변수 사용이 가능하여 오버로딩이 가능함.
//   * 작성될 경우, 반드시 public 으로 작성되어야 한다.
//   * 반환형이 없는 특수 멤버 함수이다.

class Class1
{
	// 기본 생성자(Default constructor, 디폴트 생성자)
	// : 매개변수가 없거나 모든 매개변수가 초기화된 매개변수(선택적 매개변수)인 생성자이다.
	//   * 같은 클래스 내에 2 개 이상의 기본 생성자를 선언하면, 객체 선언 시에 모호함(ambiguous)에 의한 오류 발생.
	//   * 클래스 내에 명시적으로 정의된 생성자가 하나라도 존재할 경우, 반드시 클래스 내에 기본 생성자를 선언해야 한다.
	
	// 암시적 기본 생성자(Implicit default constructor)
	// : 클래스 선언 시, 생성자를 선언하지 않으면 컴파일러에 의해 암시적으로 제공되는 기본 생성자이며
	//   클래스명() {} 와 동일한 역할을 하는 inline 생성자이다.
	//   * 클래스명() = default; 와 동일함.
	//   1) 클래스 선언 시, 생성자를 선언하지 않으면 컴파일러에 의해 암시적 기본 생성자가 제공된다.
	//   2) 클래스 내에 생성자가 하나라도 정의되면 컴파일러는 묵시적으로 기본 생성자를 제공하지 않는다.
	//   3) 암시적 기본 생성자는 기본적으로 멤버 변수(필드)의 생성만을 수행하며, 값을 trash value로 초기화한다.
	//      * 단, 이니셜라이저와 함께 객체가 선언되면 값을 0으로 초기화한다.
	//   4) 암시적 기본 생성자를 사용할 때, {클래스명} {변수명}(); 와 같이 선언할 수 없다(함수 선언으로 인식되어 오류 발생).

public:
	Class1()
	{
		cout << "기본 생성자 호출." << endl;
	}

	Class1(string name, int a, int b)
	{
		Name = name;
		A = a;
		B = b;
		cout << "생성자(Class(int, int)) 호출." << endl;;
	}

	void print() const
	{
		printf("%s::[A: %i, B: %i]\n", Name.c_str(), A, B);
	}

private:
	string Name;
	int A = 10;		// 참고) 생성자에서 A를 초기화하는 경우, 값이 덮어씌워져 무의미해짐.
	int B;
};

class Class2
{
public:
	void print() const
	{
		printf("%s::[A: %i, B: %i]\n", Name.c_str(), A, B);
	}

private:
	string Name;
	int A;
	int B;
};

class Class3
{
public:
	Class3(string name, int a, int b)
	{
		Name = name;
		A = a;
		B = b;
		cout << "생성자(Class(int, int)) 호출." << endl;;
	}

	void print() const
	{
		printf("%s::[A: %i, B: %i]\n", Name.c_str(), A, B);
	}

private:
	string Name = "NULL";
	int A = 0;
	int B = 0;
};

int main()
{
	cout << "1) 명시적 기본 생성자에서 초기화되지 않은 멤버 변수의 예시." << endl;
	cout << "   -> 이니셜라이저와 관계 없이 항상 trash value로 초기화된다." << endl;
	Class1 myObj1;					// 기본 생성자의 암시적 호출  -> trash value로 초기화된다.
	Class1 myObj2 = Class1();		// 기본 생성자의 명시적 호출	-> trash value로 초기화된다.
	myObj1.print();
	myObj2.print();
	cout << endl;

	cout << "2) 암시적 기본 생성자에서의 초기화되지 않은 멤버 변수의 예시." << endl;
	cout << "   -> 이니셜라이저와 함께 선언되면 0으로 초기화된다." << endl;
	Class2 myObj3;					// 기본 생성자의 암시적 호출  -> trash value로 초기화된다.
	Class2 myObj4 = Class2();		// 기본 생성자의 명시적 호출	-> 0으로 초기화된다.
	myObj3.print();
	myObj4.print();
	cout << endl;
	printf("----------------------------------------------\n");
	cout << endl;

	cout << "3) 생성자 오버로딩의 예시." << endl;
	Class1 myObj5 = Class1("myObj5", 1, 2);			// explicit assignment     두 가지 방법으로 선언할 수 있다.
	Class1 myObj6("myObj6", 1, 2);					// implicit assignment
	myObj5.print();
	myObj6.print();
	cout << endl;
	printf("----------------------------------------------\n");
	cout << endl;

	// *** 4) 생성자 관련 유의사항 ***
	//Class3 myObj7;	- Error - 		* 생성자가 존재하나, 기본 생성자를 선언하지 않았을 때는 매개변수 없이 객체 선언이 불가능하다.
	//Class3 myObj8();					* 기본 생성자의 암시적 호출에서 ()를 사용하면 컴파일러는 해당 명령문을 객체 선언이 아닌 함수 선언으로 인식한다.

	return 0;
}