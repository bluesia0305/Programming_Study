// 2022-06-29 ����


#include <iostream>
using namespace std;

// �Ҹ���(boolean) �ڷ��� bool
// : ���� ������ ������ �� �ִ� �ڷ������� 1 Byte�� ������ ������.

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