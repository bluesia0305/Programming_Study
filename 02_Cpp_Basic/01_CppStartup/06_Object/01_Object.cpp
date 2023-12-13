// 2022-07-01 수업


#include <iostream>
using namespace std;

// 객체(Object)
// : 추상 자료형의 인스턴스이며 어떠한 상태(변수 등)나 동작(함수 등)을 가지고 있다.

struct Object
{
	int A;

	// 생성자(Constructor)
	// : 객체를 생성할 때 (가장 먼저) 호출되는 함수.
	//   생성자의 이름은 구조체 또는 클래스의 이름과 같으며 뒤에 ()를 붙여 선언하며 반환형을 작성하지 않음.
	//   * 매개변수의 사용이 가능하며, 오버로딩이 가능함.
	//   * 생성자 선언을 생략하더라도 객체가 생성이 되면 반드시 '기본 생성자(컴파일러가 제공)'가 호출이 됨.
	Object(int a = 0)
	{
		printf("(Object가 생성됩니다)\n");
		A = a;
	}


	// 소멸자(Destructor)
	// : 객체가 소멸(할당된 메모리의 해제)할 때 호출되는 함수.
	//   구조체 또는 클래스의 이름 앞에 ~연산자를 붙이며 뒤에 ()를 붙여 선언하며 반환형을 작성하지 않음.
	//   * 매개변수의 사용이 불가능하며, 오버로딩이 불가능함.
	//   * 소멸자 선언을 생략하더라도 객체가 소멸이 되면 반드시 '기본 소멸자(컴파일러가 제공)'가 호출이 됨.
	~Object()
	{ printf("(Object가 소멸됩니다)\n"); }


	void Print() const
	{
		// this: 자기 자신의 위치(즉, pointer)를 반환하는 키워드.
		//       구조체 내의 함수에서 멤버 변수를 호출하거나 접근할 때에는 this-> 가 생략되어있는 것과 같음.
		//       이에 따라, 구조체 내의 함수에서 값을 변경하더라도 함수 외부의 멤버 변수의 값이 변경됨.
		cout << "this       : " << this << endl;
		cout << "this->A    : " << this->A << endl;
	}
};

int main()
{
	cout << "1) 생성자를 포함하는 정적할당 공간의 선언" << endl;
	int integer1 = int();
	cout << "integer1   : " << integer1 << endl;
	int integer2 = int(4);
	cout << "integer2   : " << integer2 << endl;

	Object object1 = Object();
	cout << "object1.A  : " << object1.A << endl;
	Object object2 = Object(2);
	cout << "object2.A  : " << object2.A << endl;
	cout << endl;


	cout << "2) 생성자를 포함하지 않는 동적할당 공간의 생성 -> 초기값이 trash value" << endl;
	int* p1 = new int;
	cout << "*p1        : " << *p1 << endl;
	delete p1;

	Object* pObject1 = new Object;
	cout << "pObject1->A: " << pObject1->A << endl;
	delete pObject1;
	cout << endl;


	cout << "3) 생성자를 포함하는 동적할당 공간의 생성 -> 초기값이 0 (NULL)" << endl;
	int* p2 = new int();
	Object* pObject2 = new Object();
	cout << "*p2        : " << *p2 << endl;
	cout << "pObject2->A: " << pObject2->A << endl;
	delete pObject2;
	delete p2;
	cout << endl;

	cout << "4) this pointer 적용 예시" << endl;
	Object obj1 = Object(1);
	Object obj2 = Object(2);
	printf("obj1 주소  : %p\n", &obj1);
	printf("obj1 값    : %i\n", obj1);
	obj1.Print();
	printf("obj2 주소  : %p\n", &obj2);
	printf("obj2 값    : %i\n", obj2);
	obj2.Print();
	cout << endl;

	return 0;
}