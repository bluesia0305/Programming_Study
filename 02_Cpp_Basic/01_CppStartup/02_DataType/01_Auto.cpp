// 2022-06-29 ����


#include <iostream>
using namespace std;

// Ÿ�� �߷��� �ڷ��� auto
// : ����� �ʱ�ȭ�ϰ� �ִ� �����Ϳ� ���� �ڷ����� �����Ǹ� ���� �ݵ�� ����� ���ÿ� �ʱ�ȭ �ؾ���.
//   * ������ Ÿ�ӿ� Ÿ���� �����ǹǷ�, ���α׷��� ���� ���ϰ� ����.

// auto�� ��ȯ�����ε� ��� ������.
auto Add(int a, int b) { return a + b; }

// �� �Ʒ��� ���� �Ű������� Ÿ�����δ� ����� �� ����.
//auto Add2(auto a, auto b) { return a + b; }

int main()
{
	auto myInt = 3;
	auto myFloat = 3.14f;
	auto myDouble = 3.1415464657687;
	auto myChar = 'A';
	auto myStr = "ABC";
	auto myPointer = &myInt;

	cout << Add(1, 2) << " " << sizeof(Add(1, 2)) << endl;

}
