// 2022-06-29 ����


#include <iostream>

// ���� �����̽�(�̸�����, Namespace)
// : �̸��� ���� �ڵ���� ���� �� �ִ� Ű����.
//   Namespace ���� ������(���� �� �Լ� ��)�� ������ �� '::' (������ ������, scope operator)�� �̿���.

// ������ ������(Scope operator)
// : ���� ���� �����ڶ�� �Ҹ��� ����ü, Ŭ����, ���ӽ����̽� ����
//   �̸��� ������ �� �ִ� ������ ������ �� �ִ� ������.

namespace Namespace1
{
	int A = 10;		// ��������
	void Print()
	{
		printf("abc\n");
	}

}

namespace Namespace2
{
	int A = 20;		// ��������
}

int A = 30;			// ��������

namespace Namespace3
{
	int A = 1;
	namespace Namespace4
	{
		int A = 2;
	}
}

// using namespace {namespace};
// : �ش� {namespace}�� �����Ͽ� ����ϵ��� ����ϴ� ��ɾ�.
//   * ���� �����̽��� �̸��� �������� ��, �ߺ��Ǵ� ���� �̸��̳� �Լ��� ���� �� ���� �߻���.
//     ���� ���� ��찡 �ƴ϶��, ���� ���� ������ ����Ǿ �˾Ƽ� ������ ���� �����̽��� ã�Ƽ� �ش� ���� �� �Լ��� ã�� ȣ����.
//   * using namespace ������ �߰�ȣ ������ ����Ǹ�, �߰�ȣ �ܺο����� ������� ����.
using namespace std;

// �͸� ���� �����̽� -> �̸��� ���� ���� �����̽����� ����� ������ ���������� ��޵Ǿ� �����.
namespace
{
	int a;
	int b;
	int c;
}
//static int a, b, c;

int main()
{
	int A = 40;

	// ���� �����̽��� �ٸ��� ���� �̸��� �ߺ��ǰ� ������ ������.
	std::cout << Namespace1::A << std::endl;
	std::cout << Namespace2::A << std::endl;
	std::cout << ::A << std::endl;
	std::cout << A << std::endl;

	// ��ø�� ���� �����̽� ���� ���� ȣ�� ���.
	std::cout << Namespace3::A << std::endl;
	std::cout << Namespace3::Namespace4::A << std::endl;
	
	// ���� �����̽� ������ ����� �Լ� ȣ�� ���.
	Namespace1::Print();


	return 0;
}