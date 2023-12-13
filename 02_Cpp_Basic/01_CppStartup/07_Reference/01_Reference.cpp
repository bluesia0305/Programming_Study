// 2022-07-06 수업


#include <iostream>
using namespace std;

// 참조자(Reference)
// : 할당된 하나의 메모리 공간(=변수)에 다른 이름(=별칭)을 붙이는 것을 말함.
//   * 한 번 어떠한 변수의 참조자로 선언이 되면, 영구적으로 다른 변수를 참조할 수 없음.

void SetTen(int& ref)
{
	ref = 10;
}

int main()
{
	// 1)
	int myVar = 10;
	int* myPtr = &myVar;
	int& myRef = myVar;
	cout << "1) 변수에 대한 레퍼런스의 선언(int& myRef = myVar;)." << endl;
	cout << "myVar    : " << myVar << endl;
	cout << "myPtr    : " << myPtr << " (= address of myVar)" << endl;
	cout << "myRef    : " << myRef << endl;
	cout << "&myVar   :" << &myVar << endl;
	cout << "&myPtr   :" << &myPtr << endl;
	cout << "&myRef   :" << &myRef << endl;
	cout << endl;


	// 2)
	// 참조자를 초기화한 후 다른 변수 혹은 상수값을 대입하게 된다면
	// 해당 변수, 상수값을 새로 참조하는 것이 아니라 값을 복사한다는 의미가 됨 (Var에 복사).
	int Test1 = 100;
	int Test2 = 20;
	myVar = Test1;
	myPtr = &Test1;
	myRef = Test2;
	cout << "2) 레퍼런스(myRef)를 변경할 경우, 기존 변수(myVar)의 값도 같이 변함." << endl;
	cout << "myVar    : " << myVar << endl;
	cout << "myPtr    : " << myPtr << endl;
	cout << "myRef    : " << myRef << endl;
	cout << "&Test1   : " << &Test1 << endl;
	cout << "&Test2   : " << &Test2 << endl;
	cout << "&myVar   : " << &myVar << endl;
	cout << "&myPtr   : " << &myPtr << endl;
	cout << "&myRef   : " << &myRef << endl;
	cout << endl;


	// 3)
	int*& pRef = myPtr;
	cout << "3) 포인터 변수에 대한 레퍼런스의 선언(int*& pRef = myPtr;)." << endl;
	cout << "pRef     : " << pRef << endl;
	cout << "&pRef    : " << &pRef << endl;
	cout << "*pRef    : " << *pRef << endl;
	cout << endl;


	// 4)
	int& myRef2 = myRef;
	myRef2 = 1;
	cout << "4) 특정 변수의 레퍼런스에 대한 레퍼런스의 선언(int& myRef2 = myRef;)." << endl;
	cout << "   * 이 경우는 myRef2는 myVar의 또다른 별칭이 되므로, int&&(rvalue 참조자) 형식이 아닌 int&(lvalue 참조자) 형식임." << endl;
	cout << "myVar    : " << myVar << endl;
	cout << "myRef    : " << myRef << endl;
	cout << "myRef2   : " << myRef2 << endl;
	cout << endl;


	// 5)
	const int& litRef1 = 50;		// const 키워드 없이 좌측과 같은 선언 불가능 (리터럴 = 상수이므로).
	cout << "5) 문자열이 아닌 리터럴에 대한 레퍼런스의 선언(const int& litRef1 = 50;)." << endl;
	cout << "litRef1  : " << litRef1 << endl;
	cout << "&litRef1 : " << &litRef1 << " (단, 상수 리터럴을 참조하면 선언 직후 댕글링 포인터가 됨에 주의)" << endl;
	cout << endl;


	//// 5-x) 문자열 리터럴에 대한 레퍼런스?
	//const char*& litRef2 = "abc";
	//cout << "litRef2 : " << litRef2 << endl;
	//cout << "&litRef2: " << &litRef2 << " (단, 상수 리터럴을 참조하면 선언 직후 댕글링 포인터가 됨에 주의)" << endl;
	//cout << endl;


	// 6)
	const int& constRef = myVar;
	myVar = 10;						// myVar 라는 이름으로 접근하면 수정이 가능
	//constRef = 11;				// constRef 라는 이름을 통해서는 값의 수정 불가능.
	cout << "6) 변수에 대한 const 레퍼런스의 선언(const int& constRef = myVar;)." << endl;
	cout << "constRef : " << constRef << endl;
	cout << "&constRef: " << &constRef << endl;
	cout << endl;


	// 7)
	const int* const cpc = &myVar;
	const int* const& ConstRefConst = cpc;
	cout << "7) const int* const 형식의 포인터에 대한 레퍼런스의 선언(소스 코드 참고)." << endl;


	// 8) 타입 추론형 자료형을 사용할 때 주의해야할 부분
	auto Auto1 = myVar;				// (좌변) = int 형식, (우변) = int 형식
	auto Auto2 = myRef;				// (좌변) = int 형식, (우변) = int& 형식
	auto& Auto3 = myRef;			// (좌변) = int& 형식, (우변) = int& 형식
	cout << "8) 타입 추론형 자료형에 대한 레퍼런스의 선언 시 주의점(소스 코드 참고)." << endl;
	
	
	// 9) lvalue(left value) vs rvalue(right value)
	//    lvalue: 단일 표현식 이후 사라지지 않고 지속되는 객체.
	//    rvalue: 단일 표현식이 종료된 후 더이상 존재하지 않는 임시적인 값.
	//    * 데이터의 이동: rvalue를 lvalue로 전환하는 과정.
	// Rvalue 참조자 && (&는 Lvalue 참조자 연산자임)
	int&& RRef = 10;					// 이때 RRef와 상수 리터럴 10은 모두 rvalue이나, 해당 코드가 실행된 뒤 RRef 변수는 lvalue가 됨.
	//int&& RRef = myRef;	- Error -	// myRef는 lvalue이므로 해당 명령문은 오류가 발생함.
	RRef = 33;
	cout << "9) Rvalue 참조연산자 && 사용 예시." << endl;
	cout << "RRef     : " << RRef << endl;


	// 10) 매개변수를 이용해 원래 변수의 값을 변경할 수 있는 함수 예시( void SetTen(int& ref) ).
	int t = 20;
	SetTen(t);
	cout << "10) 매개변수를 이용해 지역변수의 값을 변경할 수 있게 하는 함수 예시( void SetTen(int& ref) )." << endl;
	cout << t << endl;
	
	return 0;
}