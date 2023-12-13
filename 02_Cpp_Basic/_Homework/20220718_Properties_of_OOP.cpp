// 2022-07-18 과제


#include <iostream>
#include <string>
using namespace std;

// 객체지향 프로그래밍의 4대 속성 정리(의미, 필요성) 및 예시를 정리해주세요.

// 1) 캡슐화(Encapsulation)
//    - 정의: 객체의 멤버(멤버 변수 및 멤버 함수)를 묶고,
//            실제 구현 내용의 일부를 내부에 감추어 은닉하는 기능.
//	    
//	  - 필요성:
//      1) 클래스가 내부적으로 어떻게 구현되어있는지 알 필요 없이,
//         공개되어있는 멤버 함수의 필요 매개변수와 반환값의 형태만 알면 해당 멤버 함수를 사용할 수 있다.
//         즉, 프로그램의 복잡성을 낮춰준다.
//      2) 프로그래밍 상에서, 외부에서 객체에 접근하여 데이터를 수정하면 오류가 발생할 수 있는 부분들을 보호할 수 있다.
//	    
//	  - 예시: 접근제한자를 통해 구현할 수 있다.
#pragma region Example1
class Example1
{
private:
	string myStr;			// 문자열 상수를 가리킬 포인터.
	int myStr_len;			// pString이 가리키는 문자열의 길이를 저장할 공간.
							// 해당 변수가 public으로 선언되면, 의도와 다르게 pString과 전혀 관계없는 값이 저장될 수 있다.
public:
	Example1(string myStr = "")
	{ SetLen(); }

	void SetLen()
	{ myStr_len = static_cast<int>(myStr.length()); }
};
#pragma endregion


// 2) 상속성(Inheritance)
//    - 정의: 기반 클래스의 기능을 확장하여 파생 클래스를 선언하여 코드의 생산성을 높이는 기능.
//	    
//	  - 필요성:
//      이미 선언되어있는 클래스가 갖는 기능을 동시에 가지면서,
//      새로운 기능이 추가된 클래스를 선언하는 과정에서의 생산성을 높이기 위해 사용된다.
//	    
//	  - 예시: 아래와 같이 기반 클래스를 상속받은 파생 클래스의 선언이 가능하다.
#pragma region Example2
class Example2_Base
{
	// 기반 클래스
public:
	int var1 = 10;
	int var2 = 20;

	void print() const
	{ cout << "var1: " << var1 << ", var2: " << var2 << endl; }
};

class Example2_Derived : public Example2_Base
{
	// 파생 클래스
public:
	int var3 = 30;
};
#pragma endregion


// 3) 다형성(Polymorphism)
//    - 정의: 서로 다른 객체가 동일한 기능을 서로 다른 방법으로 처리할 수 있는 기능.
//	    
//	  - 필요성:
//      프로그램에서 처리해야하는 새로운 속성을 갖는 객체가 추가될 때,
//      기존 작성된 코드(클래스, 함수 등)의 수정을 최소화하면서 변화에 대처할 수 있도록 하기 위하여 사용된다.
//	    
//	  - 예시: 함수의 기능적 다형성과 클래스의 상속 등을 통해 구현된다
//            * 클래스 상속, 가상 함수, 오버라이딩, 오버로딩 등.
#pragma region Example3_Overriding
class IExample3_Pet
{
public:
	string Name;
	virtual ~IExample3_Pet() {}
	virtual void Sound() abstract;
	virtual void Eat() abstract;
};

class Example3_Dog : public IExample3_Pet
{
	// Example3_Pet을(를) 통해 상속됨
	virtual void Sound() override
	{ cout << "울음소리: 멍멍"; }
	virtual void Eat() override
	{ cout << "먹이: 뼈다귀"; }
};

class Example3_Cat : public IExample3_Pet
{
	// Example3_Pet을(를) 통해 상속됨
	virtual void Sound() override
	{ cout << "울음소리: 야옹"; }
	virtual void Eat() override
	{ cout << "먹이: 생선"; }
};

class Example3_Pikachu : public IExample3_Pet
{
	// Example3_Pet을(를) 통해 상속됨
	virtual void Sound() override
	{ cout << "울음소리: 피카피카"; }
	virtual void Eat() override
	{ cout << "먹이: 포켓몬 먹이"; }
};
#pragma endregion
#pragma region Example3_Overloading
int Add(int a, int b) { return a + b; }
float Add(float a, int b) { return a + b; }
float Add(int a, float b) { return a + b; }
float Add(float a, float b) { return a + b; }
#pragma endregion


// 4) 추상화(Abstraction)
//    - 정의: 공통된 기능을 모아 추상적으로 표현하는 모델링 기법.
//	    
//	  - 필요성:
//      객체지향 프로그래밍에서의 문제 해결을 위한 객체를 설정하고,
//      이들의 공통적인 특징을 속성(멤버 변수)과 기능(멤버 함수)으로 구분하여 클래스로 표현하기 위해 필요하다.
//
//	  - 예시: 1) 아래와 같이 학생들에 대한 공통적인 특징을 멤버 변수로 구분이 가능함(데이터 추상화).
//               * main 함수 참고(배열을 통한 데이터 관리와의 비교).
//            2) 추상 클래스, 인터페이스 등(프로세스 추상화).
#pragma region Example4
class Student
{
public:
	const string Name;					// 이름
	const string Gender;				// 성별
	unsigned int Grade;					// 학년
	unsigned int ClassNum;				// 반
	unsigned int StudentNum;			// 출석 번호

	Student(string name, string gender, int grade, int classNum, int studentNum) :
		Name(name), Gender(gender), Grade(grade), ClassNum(classNum), StudentNum(studentNum)
	{}
};
#pragma endregion


int main()
{
	printf("예시2) 상속성\n");
	Example2_Derived Derived;
	Derived.print();
	printf("Derived.var3: %i\n", Derived.var3);
	printf("\n");

	printf("예시3-1) 다형성-오버라이딩\n");
	Example3_Dog myDog;
	myDog.Name = "갱얼쥐";
	Example3_Cat myCat;
	myCat.Name = "야옹이";
	Example3_Pikachu myPikachu;
	myPikachu.Name = "피카츄";
	IExample3_Pet* myPets[3] = { &myDog, &myCat, &myPikachu };
	for (int i = 0; i < 3; i++)
	{
		printf("%i번 애완동물: %s / ", i + 1, myPets[i]->Name.c_str());
		myPets[i]->Sound();
		printf(" / ");
		myPets[i]->Eat();
		printf("\n");
	}
	printf("\n");

	printf("예시3-2) 다형성-오버로딩\n");
	printf("Add(%i   , %i   ) == %i\n", 1, 2, Add(1, 2));
	printf("Add(%.2f, %i   ) == %.2f\n", 1.2f, 2, Add(1.2f, 2));
	printf("Add(%i   , %.2f) == %.2f\n", 1, 2.5f, Add(1, 2.5f));
	printf("Add(%.2f, %.2f) == %.2f\n", 1.2f, 2.5f, Add(1.2f, 2.5f));

	// 예시4) 추상화
	// 배열을 통해 학생의 데이터를 관리하는 경우 -> 새로운 학생에 대한 데이터 추가를 하려면 코드 전체 수정이 필요하다.
	string Name[2] = { "김멍게" , "박소라" };
	string Gender[2] = { "남", "여" };
	unsigned int Grade[2] = { 3, 1 };
	unsigned int ClassNum[2] = { 2, 5 };
	unsigned int StudentNum[2] = { 1, 21 };

	// 추상화를 통해 클래스를 선언하고 인스턴스화 하여 학생의 데이터를 관리하는 경우 -> 객체를 추가로 생성하기만 하면 된다.
	Student student1("김멍게", "남", 3, 2, 1);
	Student student2("박소라", "여", 1, 5, 21);
	Student student3("이말미잘", "남", 2, 1, 1);
	// 예시) "이말미잘" 학생의 반을 변경하는 것도 간편하다.
	student3.ClassNum = 2;

	return 0;
}