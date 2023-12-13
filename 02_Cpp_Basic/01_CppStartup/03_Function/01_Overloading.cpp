// 2022-06-30 수업


#include <iostream>
using namespace std;

// 함수 오버로딩(Function overloading) 
// : 서로 다른 매개변수를 갖는 동일한 이름의 여러 개의 함수를 정의할 수 있는 C++의 기능(C에서는 제공하지 않는다).
//   * 반드시 매개변수의 개수나 타입이 달라야하고, 반환형은 고려되지 않는다(오직 매개변수에 의해서만 결정됨).
//   * typedef 선언에 의한 자료형 이름 변경 역시 고려되지 않는다(새로운 자료형을 만드는 게 아니므로).

void Print()
{ cout << "Hello World" << endl; }

void Print(int integer)
{ cout << integer << endl; }

void Print(int integer1, int integer2)
{ cout << integer1 << " : " << integer2 << endl; }

void Print(const char* str)
{ cout << str << endl; }

// namespace를 이용할 때에는
// 매개변수의 개수와 형식까지 동일한 이름이 같은 함수를 정의할 수 있음.
namespace STR
{
	void Print(const char * str)
	{ cout << str << endl; }
}

int   Addition(int   a, int   b) { return a * b; }
float Addition(float a, float b) { return a * b; }
float Addition(int   a, float b) { return a * b; }
float Addition(float a, int   b) { return a * b; }

int main()
{
	Print();
	Print(1);
	Print(1, 2);
	Print("Hello");
	STR::Print("Hello");

	cout << Addition(1 , 2) << endl;
	cout << Addition(1.1f , 2) << endl;
	cout << Addition(1 , 2.1f) << endl;
	cout << Addition(1.1f , 2.1f) << endl;

	return 0;
}
