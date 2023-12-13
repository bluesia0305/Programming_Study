// 2022-07-12 수업


#include <iostream>
#include <string>
using namespace std;

class Class
{
public:
	// 초기화 리스트 생성자(Initializer list ~, 이니셜라이저 목록 생성자)
	// : 생성자의 정의를 실행하기 전에 실행할 수 있는 식을 추가할 수 있다.
	//   생성자 선언 뒤의 ':'(colon)을 통해 작성하며, 초기화할 멤버 변수를 ','로 구분한 뒤 '()' 내에 초기화할 값을 지정한다.
	//   * 멤버 변수 초기화식( member_var1( init_value1 ), ... ), 생성자의 추가가 가능함.
	//   * const 키워드를 포함하여 선언된 멤버 변수의 값의 설정이 가능(이외의 방법으로는 오류 발생함).
	//   * 선언과 동시에 초기화 하는 형태와 같다.
	Class(int Num = 0) : Const(Num), A(1), B(2)
	{
		cout << "기본 생성자 호출" << endl;
		cout << "Const: " << Const << endl;
		cout << "A: " << A << endl;
		cout << "B: " << B << endl;
	};

	// 생성자 선언 뒤의 ':'를 이용하여 다른 생성자 호출이 가능함.
	// * 이 경우에는 이니셜라이저 리스트에 존재하는 생성자를 먼저 실행한 뒤, {} 내의 코드블럭이 실행된다.
	//   즉, 현재 소스 코드 기준으로
	//     1) Class 클래스의 기본 생성자(위에서 재정의한 것)를 실행하여 Const, A, B에 각각 num(인수로 넘겼으므로), 1, 2를 대입
	//     2) 주어진 a, b 인수를 A, B에 다시 초기화.
	//   와 같은 순서로 수행된다.
	Class(int num, int a, int b) : Class(num)
	{
		cout << "오버로드 생성자 호출" << endl;
		A = a;
		B = b;
	};

	// const 키워드는 해당 멤버 함수 내에서 멤버 변수의 값을 변경하지 않기 위해 사용하지만
	// 정적 멤버 변수에 대해서는 적용되지 않는다(정적 멤버 변수 메모리 영역은 data 영역으로 할당되기 때문).
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

	// 정적 멤버 함수(Static member function)
	// : 객체 없이 사용하기 위해 선언하는 함수이며, 따라서 멤버 변수의 접근 또는 사용이 불가능하다(const 키워드도 불가능함).
	//   * thiscall의 개념이 아니므로, 어떤 객체의 멤버 변수에 접근하는지 알 수 없기 때문.
	static void StaticFunc()
	{ cout << "Static Function Call" << endl; }

	// 소멸자(Destructor)
	// : 객체가 소멸될 때 반드시 호출되는 멤버 함수.
	~Class() {}

private:
	int A;
	int B;

	// 멤버 상수
	// : 선언시 초기화가 필요하지만, 예외적으로 이니셜라이저 리스트 생성자를 통한 초기화가 가능함.
	const int Const;

public:
	// 정적 멤버 변수(Static member variable)
	// : 해당 형식을 가지는 모든 객체들이 공유하는 멤버 변수이며
	//   public으로 선언되어있을 경우, 객체 없이 클래스명::정적멤버 로 접근이 가능하다(thiscall의 개념이 아님).
	//   * 클래스 외부에서 초기화해야한다(아래 참고).
	static int Static;
};

// 정적 멤버 변수의 초기화는 클래스의 외부에서 수행한다.
// * 클래스 내부에서 초기화하면 컴파일러가 오류라고 판단함.
int Class::Static = 0;

int main()
{
	Class Object1 = Class();
	Object1.print();

	Class Object2 = Class(1, 2, 3);
	Object2.print();

	cout << "정적 멤버 변수의 값 출력: ";
	cout << Class::Static << endl;
	cout << endl;

	cout << "정적 멤버 함수 호출" << endl;
	Class::StaticFunc();

	return 0;
}