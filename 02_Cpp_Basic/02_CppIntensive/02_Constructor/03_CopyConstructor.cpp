// 2022-07-11 수업


#include <iostream>
#include <string>
using namespace std;

// 복사 생성자(Copy constructor)
// : 객체의 복사본을 생성할 때 호출되는 생성자.
//   복사 생성자의 원형은 {class_name} ( const {class_name}& {param_name} ) {} 이다.

class Shallow
{
public:
	Shallow(int a = 0, int b = 0)
	{
		A = new int(a);
		B = new int(b);
	}

	// 얕은 복사(Shallow copy)
	// : 멤버 변수가 저장하고 있는 값만 복사하는 형태.

	// 깊은 복사(Deep copy)
	// : 멤버 변수가 저장하고 있는 값 뿐만이 아니라,
	//   가리키고 있는 공간까지 복사하는 형태.

	// 기본 복사 생성자(Default copy constructor)
	// : 복사 생성자를 명시하지 않았을 때, 컴파일러가 제공하는 복사 생성자.
	//   같은 형식의 객체를 '참조'하여 값을 복사한다 -> 얕은 복사.
	//   * 따라서, 일반적으로 객체 내에서 메모리 영역의 힙(heap) 영역을 참조하는 경우에는
	//     깊은 복사가 일어나도록 복사 생성자를 명시하는 것이 바람직하다.
	// 
	//   <얕은 복사에 의한 문제점 예시>
	//   -  동일한 클래스의 객체 a, b를 만들때, a의 멤버 변수가 힙 영역을 참조하며
	//      b를 기본 복사 생성자에 의한 a 객체의 복사 생성을 통해 생성하는 경우,
	//      힙 영역을 가리키고 있는 a 객체와 b 객체의 멤버 변수가 서로 같은 주소를 가리키게 된다.
	//      이때 a 객체를 먼저 소멸하는 경우, b 객체를 소멸할 때
	//      이미 소멸된 공간을 소멸하려는 시도를 하게 되므로 에러가 발생한다.
	Shallow(const Shallow& object)
	{
		cout << "Shallow copy constructor call" << endl;
		A = object.A;
		B = object.B;
	}

	__forceinline void print(string name) const
	{
		printf("%s::[%i, %i]\n", name.c_str(), *A, *B);
	};

	int* A;
	int* B;
};

class Deep
{
public:
	Deep(int a = 0, int b = 0)
	{
		A = new int(a);
		B = new int(b);
	}

	Deep(const Deep& object)
	{
		cout << "Deep copy constructor call" << endl;
		A = new int();
		B = new int();
		*A = *(object.A);
		*B = *(object.B);
	}

	__forceinline void print(string name) const
	{
		printf("%s::[%i, %i]\n", name.c_str(), *A, *B);
	};

	int* A;
	int* B;
};

int main()
{
	cout << "1) 얕은 복사(shallow copy)의 예시." << endl;
	Shallow s1 = Shallow(10, 20);
	Shallow s2 = Shallow(s1);
	*(s1.A) = 30;
	*(s1.B) = 40;
	s1.print("s1");
	s2.print("s2");
	cout << endl;

	cout << "2) 깊은 복사(deep copy)의 예시." << endl;
	Deep d1 = Deep(10, 20);
	Deep d2 = Deep(d1);
	*(d1.A) = 30;
	*(d1.B) = 40;
	d1.print("d1");
	d2.print("d2");
	cout << endl;

	return 0;
}