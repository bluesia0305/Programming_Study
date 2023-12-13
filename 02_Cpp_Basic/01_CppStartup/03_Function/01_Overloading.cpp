// 2022-06-30 ����


#include <iostream>
using namespace std;

// �Լ� �����ε�(Function overloading) 
// : ���� �ٸ� �Ű������� ���� ������ �̸��� ���� ���� �Լ��� ������ �� �ִ� C++�� ���(C������ �������� �ʴ´�).
//   * �ݵ�� �Ű������� ������ Ÿ���� �޶���ϰ�, ��ȯ���� ������� �ʴ´�(���� �Ű������� ���ؼ��� ������).
//   * typedef ���� ���� �ڷ��� �̸� ���� ���� ������� �ʴ´�(���ο� �ڷ����� ����� �� �ƴϹǷ�).

void Print()
{ cout << "Hello World" << endl; }

void Print(int integer)
{ cout << integer << endl; }

void Print(int integer1, int integer2)
{ cout << integer1 << " : " << integer2 << endl; }

void Print(const char* str)
{ cout << str << endl; }

// namespace�� �̿��� ������
// �Ű������� ������ ���ı��� ������ �̸��� ���� �Լ��� ������ �� ����.
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
