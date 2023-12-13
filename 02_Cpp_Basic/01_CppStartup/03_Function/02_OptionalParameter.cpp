// 2022-06-30 ����


#include <iostream>
using namespace std;

// ������ �Ű�����(Optional parameter)
// : �Ű������� ���� ������ ���� ���� ���� default ���� �ʱ�ȭ�ϸ� �Ű������� ����� �� �ִ� ���.
//   * �ݵ�� �ʼ� �Ű��������� �ڿ� �ۼ��ؾ��Ѵ�(��, ������ ��������).

void Print(int integer1, int integer2 = 0)
{
	cout << integer1 << endl;
	if (integer2) cout << integer2 << endl;
}

void Print(float float_1 = 0, float float_2 = 0, float float_3 = 0)
{ cout << float_1 << " : " << float_2 << " : " << float_3 << endl; }

int main()
{
	Print(1);
	Print(1, 2);
	Print();
	Print(1.1f);
	Print(1.1f, 2.2f);
	Print(1.1f, 2.2f, 3.3f);
	
	return 0;
}