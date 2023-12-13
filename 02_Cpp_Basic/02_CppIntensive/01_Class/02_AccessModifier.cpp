// 2022-07-08 수업


#include <iostream>
using namespace std;

// 캡슐화(Encapsulation)
// : 객체지향 프로그래밍의 4대 속성 중의 하나로,
//   공개(public)하거나 감출(private, protected) 멤버(변수 = fields, 함수 = methods)들을 묶어놓는 기능을 의미함.

// 접근제한자(Access modifier)
// : 은닉성을 이용하기 위해 존재하는 기능으로,
//   멤버 변수 및 함수의 기능을 감추거나 공개하는 데에 사용.
//   * 종류: private, public, protected (3 종).

// 구조체와 클래스가 별도의 개념으로 존재하는 이유?
// 1) 은닉성에 대한 중요성이 인식된 후 클래스가 만들어졌으나
//    기존 C언어 개발자들에 의해 구조체 형식이 이미 많이 사용되어 기존 작성된 코드들의 전체 변경이 어려움.
// 2) 직접접근 연산자 대신, private 멤버 변수에 대해 접근할 수 있도록 하려면
//    모든 클래스에 대하여 해당 값을 반환하는 멤버 함수를 만들어야함(아래 예시 참고).

class Class
{
	// private: 자료형 외부에서 멤버의 정보를 숨겨 접근할 수 없음.
private:
	int priVar;
	int priFunc() const
	{
		cout << "(Private Function Call)" << endl;
		cout << "priVar: " << priVar << endl;
	}

	// public: 자료형 외부에서 멤버의 정보를 공개하여 접근이 가능함.
public:
	int pubVar;
	int pubFunc() const
	{ cout << "(Public Function Call)" << endl; }

	// private으로 선언된 멤버 변수 자체를 넘겨주는 함수(반환형이 참조자 형식 = int&)
	int& GetPriVar()
	{ return priVar; }
};

int main()
{
	Class myObject;
	myObject.pubVar = 20;
	myObject.pubFunc();

	// 접근제한자가 private로 선언된 부분에 대해서는 외부에서 접근이 불가능함.
	//myObject.priVar = 1;
	//myObject.priFunc();

	return 0;
}