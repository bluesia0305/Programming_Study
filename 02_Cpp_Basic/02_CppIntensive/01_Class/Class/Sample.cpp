#include "Sample.h"
#include <iostream>
using namespace std;

// �Ʒ��� ���� �����ϸ� �����Լ��� �Լ� �̸� �ڿ� const Ű���带 ����� �� ����
//void Print() const
//{
//
//}

// ��� �Լ��� ���� ���
// -> {��ȯ��} {Ŭ������}::{����Լ���}( {�Ű�����_���} )
void Sample::Print() const
{ cout << "A: " << A << ", B: " << B << endl; }