// 2022-07-07 수업


#include <iostream>
#include <string>
using namespace std;

// 문자열(String) 형식 std::string
// : C++ 에서부터 제공하는 문자열 클래스로, 문자열을 다루는 기능을 가진 기본 함수들을 포함.

int main()
{
	const char* pStr = "Hello";
	string myStr1 = "Hello";
	string myStr2 = "Hello World !";
	cout << "1) string 형식으로 선언된 변수 사용 예시." << endl;
	cout << "pStr   : " << pStr << endl;
	cout << "myStr1 : " << myStr1 << endl;
	cout << endl;

	pStr = "World";
	myStr1 = "World";
	cout << "pStr   : " << pStr << endl;
	cout << "myStr1 : " << myStr1 << endl;
	cout << endl;
	

	// string 형식으로 저장된 문자열은 사칙연산자가 사용 가능함.
	cout << "2) string 형식에 저장된 문자열에 대한 사칙연산자 사용 예시." << endl;
	myStr1 = "Hello " + myStr1;
	myStr1 += " !";
	cout << "myStr1 : " << myStr1 << endl;
	cout << endl;


	// c_str(): string 형식으로 저장된 문자열을 const char* 형태로 반환하는 함수.
	cout << "3) printf 함수를 통해 string 형식으로 저장된 문자열 출력시 멤버함수 c_str()이 필요." << endl;
	printf("%s\t(잘못된 사용 예시임)\n", myStr1);
	printf("%s\n", myStr1.c_str());
	cout << endl;


	cout << "4) 문자열의 비교가 가능해짐." << endl;
	if (myStr1 == myStr2) printf("myStr1과 myStr2는 같습니다.\n");
	else printf("myStr1과 myStr2는 다릅니다.\n");
	cout << endl;


	int myInt = 10;
	cout << "5) 값을 문자열로 변환하거나, 문자열을 값으로 변환하는 함수 예시(string 헤더 내의 함수)." << endl;
	// to_string({variable}): {variable}에 저장된 값을 문자열로 변환하여 반환하는 함수 // string 헤더에 포함.
	string IntToString = to_string(myInt);
	cout << "IntToString: " << IntToString << endl;
	
	// stoi({variable}): {variable}에 저장된 문자열을 int형식으로 변환하여 반환하는 함수 // string 헤더에 포함.
	// * stod(to double), stof(to float), stoll(to long long)
	int StringToInt = stoi(IntToString);
	cout << "StringToInt: " << StringToInt << endl;
	cout << endl;


	cout << "6) string 형식으로 저장된 문자열의 크기를 반환하는 멤버 함수 예시." << endl;
	cout << "   * 주의점: NULL 문자를 제외한 크기를 반환." << endl;
	// size(): NULL 문자를 제외한 string 형식의 크기를 반환.
	cout << "myStr1                 : " << myStr1 << endl;
	cout << "myStr1.size()          : " << myStr1.size() << endl;

	// length(): NULL 문자를 제외한 string 형식의 크기를 반환.
	cout << "myStr1.length()        : " << myStr1.length() << endl;
	cout << "sizeof(\"Hello World !\"): " << sizeof("Hello World !") << endl;
	cout << "sizeof(myStr1)         : " << sizeof(myStr1) << endl;		// string 형식의 변수는 단순 문자열 상수의 주소값을 저장하는 것이 아님(string 자료구조).
	cout << "sizeof(string)         : " << sizeof(string) << endl;		// x86 기준: 28 Byte, x64 기준: 40 Byte.

	return 0;
}