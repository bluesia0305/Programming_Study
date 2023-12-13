// 2022-06-29 수업


#include <iostream>
using namespace std;

// 불리언(boolean) 자료형 bool
// : 참과 거짓을 저장할 수 있는 자료형으로 1 Byte의 공간을 차지함.

int main()
{
	bool myBool = 127;
	cout << "myBool: " << myBool << endl;
	cout << "sizeof(bool): " << sizeof(bool) << endl;

	bool myBool_true = true;
	bool myBool_false = false;
	cout << myBool_true << endl;
	cout << myBool_false << endl;

	return 0;
}