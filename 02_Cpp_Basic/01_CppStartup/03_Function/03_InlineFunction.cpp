// 2022-06-30 ����


#include <iostream>
using namespace std;

// �ζ��� �Լ�(Inline function)
// : �Լ� ȣ�⿡���� �������(overhead)�� ���� ���α׷��� ���� ���ϸ� ���� ���� C++�������� ���Ե� ���.
//   �Լ��� ��ȯ�� �տ� inline �Ǵ� __forceinline Ű���带 �ۼ��Ͽ� ����.
//   * �������(Overhead): ���α׷��� ���� �帧 ���߿� �������� ��ġ�� �ڵ带 ������Ѿ��� ��,
//                        �߰������� �ð�, �޸�, �ڿ� ���� ���Ǵ� ����.

// inline : �����Ϸ����� �ζ��� ���θ� �����϶� �����մϴ�.
inline void Print()
{ cout << "Hello World" << endl; }

// __forceinline : �����Ϸ����� �ζ��� ������ �����϶� �����մϴ�.
__forceinline void Add(int a, int b)
{ cout << a + b << endl; }

int main()
{
	Print();
	Add(10, 20);

	return 0;
}