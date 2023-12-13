// 2022-07-07 ����


#include <iostream>
#include <string>
using namespace std;

// ���ڿ�(String) ���� std::string
// : C++ �������� �����ϴ� ���ڿ� Ŭ������, ���ڿ��� �ٷ�� ����� ���� �⺻ �Լ����� ����.

int main()
{
	const char* pStr = "Hello";
	string myStr1 = "Hello";
	string myStr2 = "Hello World !";
	cout << "1) string �������� ����� ���� ��� ����." << endl;
	cout << "pStr   : " << pStr << endl;
	cout << "myStr1 : " << myStr1 << endl;
	cout << endl;

	pStr = "World";
	myStr1 = "World";
	cout << "pStr   : " << pStr << endl;
	cout << "myStr1 : " << myStr1 << endl;
	cout << endl;
	

	// string �������� ����� ���ڿ��� ��Ģ�����ڰ� ��� ������.
	cout << "2) string ���Ŀ� ����� ���ڿ��� ���� ��Ģ������ ��� ����." << endl;
	myStr1 = "Hello " + myStr1;
	myStr1 += " !";
	cout << "myStr1 : " << myStr1 << endl;
	cout << endl;


	// c_str(): string �������� ����� ���ڿ��� const char* ���·� ��ȯ�ϴ� �Լ�.
	cout << "3) printf �Լ��� ���� string �������� ����� ���ڿ� ��½� ����Լ� c_str()�� �ʿ�." << endl;
	printf("%s\t(�߸��� ��� ������)\n", myStr1);
	printf("%s\n", myStr1.c_str());
	cout << endl;


	cout << "4) ���ڿ��� �񱳰� ��������." << endl;
	if (myStr1 == myStr2) printf("myStr1�� myStr2�� �����ϴ�.\n");
	else printf("myStr1�� myStr2�� �ٸ��ϴ�.\n");
	cout << endl;


	int myInt = 10;
	cout << "5) ���� ���ڿ��� ��ȯ�ϰų�, ���ڿ��� ������ ��ȯ�ϴ� �Լ� ����(string ��� ���� �Լ�)." << endl;
	// to_string({variable}): {variable}�� ����� ���� ���ڿ��� ��ȯ�Ͽ� ��ȯ�ϴ� �Լ� // string ����� ����.
	string IntToString = to_string(myInt);
	cout << "IntToString: " << IntToString << endl;
	
	// stoi({variable}): {variable}�� ����� ���ڿ��� int�������� ��ȯ�Ͽ� ��ȯ�ϴ� �Լ� // string ����� ����.
	// * stod(to double), stof(to float), stoll(to long long)
	int StringToInt = stoi(IntToString);
	cout << "StringToInt: " << StringToInt << endl;
	cout << endl;


	cout << "6) string �������� ����� ���ڿ��� ũ�⸦ ��ȯ�ϴ� ��� �Լ� ����." << endl;
	cout << "   * ������: NULL ���ڸ� ������ ũ�⸦ ��ȯ." << endl;
	// size(): NULL ���ڸ� ������ string ������ ũ�⸦ ��ȯ.
	cout << "myStr1                 : " << myStr1 << endl;
	cout << "myStr1.size()          : " << myStr1.size() << endl;

	// length(): NULL ���ڸ� ������ string ������ ũ�⸦ ��ȯ.
	cout << "myStr1.length()        : " << myStr1.length() << endl;
	cout << "sizeof(\"Hello World !\"): " << sizeof("Hello World !") << endl;
	cout << "sizeof(myStr1)         : " << sizeof(myStr1) << endl;		// string ������ ������ �ܼ� ���ڿ� ����� �ּҰ��� �����ϴ� ���� �ƴ�(string �ڷᱸ��).
	cout << "sizeof(string)         : " << sizeof(string) << endl;		// x86 ����: 28 Byte, x64 ����: 40 Byte.

	return 0;
}