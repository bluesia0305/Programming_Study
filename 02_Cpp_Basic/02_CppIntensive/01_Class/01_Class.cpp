// 2022-07-08 수업


#include <iostream>
using namespace std;

// 클래스(Class)
// : C++ 에서부터 사용 가능한 사용자 정의 자료형.
//   기존 C에서의 사용자 정의 자료형인 구조체(struct)와 매우 유사하다.

struct Struct
{
// 구조체의 경우, 접근제한자를 명시하지 않으면 public으로 간주됨.
private:
	int A = 10;
	int B;

	Struct()
	{
		cout << "Struct Constructor call.";
		B = 20;
	}

	~Struct()
	{
		cout << "Struct Destructor call." << endl;
	}
};

class Class
{
// 클래스의 경우, 접근제한자를 명시하지 않으면 private로 간주됨.
public:
	int A = 10;
	int B;

	Class()
	{
		cout << "Class Constructor call.";
		B = 20;
	}

	~Class()
	{ cout << "Class Destructor call." << endl; }
};

// 구조체와 클래스 차이점
// : 구조체의 경우 접근제한자를 명시하지 않으면 기본적으로 public 으로,
//   클래스의 경우 접근제한자를 명시하지 않으면 기본적으로 private 으로 선언됨.

int main()
{
	// 접근제한자 여부에 따라 아래와 같은 예시 적용해보기.
	// * 생성자, 소멸자를 선언하지 않으면 (즉, 기본 생성자/소멸자 이용) private으로 선언되어도 구조체 형식의 변수 or 객체의 선언 자체는 가능함.
	//Struct myStruct;
	//myStruct.A;
	//
	//Class myClass;
	//myClass.A;

	return 0;
}