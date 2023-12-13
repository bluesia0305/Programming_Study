// 2022-06-28 ����


// ��ó�� ���þ�(Preprocessing directive)
// : �������� ����Ǳ� ������ �����Ϸ����� ������ ó���ϵ��� ������ �� ����ϴ� ����.
//   * ��ó������ '#'���� ���۵Ǹ�, �� �ٿ� �� ���� ��ó���� ���ɸ��� ����� �� ����.
//   * ��ó������ ������ ';'�� �ۼ����� �ʴ´�.


#pragma once
// #pragma: �����Ϸ��� ����� Ȯ���ų �� �ֵ��� �ϴ� ���þ�
// #pragma once: �����Ϸ����� �ش� ������ �� ���� �����ϵ��� ����.


#pragma warning (disable : 4996)
// #pragma warning ( disable : {error_code} ): ������ code�� ��� �޼����� ����.


#pragma region Region
#pragma endregion
// #pragma region {region_name}: Ȯ��/��ҽ�ų �� �ִ� �ڵ���� ������ ������. 
// #pragma endregion: ������ ������ ���� ǥ����.


#include <iostream>
// #include {file_name}: ������ ������ ������ �о�� ���þ �ۼ��� ���Ͽ� ���Խ�Ŵ.
// * �������(.h): �ҽ� �ڵ� ������ ����� ������� ���ǵǾ��ִ� ����.
//                ��� ������ ���Խ�Ŵ���ν� ��� ���Ͽ� ����Ǿ��ִ� �Լ�, ���� ���� ����� �� ����.
//   - �⺻ ���� ��� ����: Visual Studio���� �⺻������ �����ϴ� ��� �����̸� <,>�� ����Ͽ� �߰��� �� ����.
//   - ����� ���� ��� ����: ����ڰ� ���� �ۼ��� ��� �����̸� ","�� ����Ͽ� �߰��� �� ����.


#define DEBUG
// #define {name}: �ɺ�, �Ǵ� ��ũ�� ��� �� �Լ��� �����ϴ� ���þ�.
#define PI 3.14f			// (��ũ�� ��� ����) 3.14f �� ���� PI��� Ű����� �����Ͽ� PI�� ����� �� 3.14f ��� �ڵ�� ġȯ��.
#define plus(x, y) (x + y)	// (��ũ�� �Լ� ����) plus(x, y)��� �ڵ带 ����, (x + y)��� �ڵ�� ġȯ�� (* ġȯ�� �� (,)���� ���� ġȯ�ǹǷ� ����, �Ű������� Ÿ�� ��� �Ұ���).


#undef DEBUG
// #undef {name}: ���ǵ� �ɺ�, �Ǵ� ��ũ�� ��� �� �Լ��� �����ϴ� ���þ�.


#define INT 1
#if INT
// #if {condition_statement}: ���ǿ� ���� ������ ���θ� �˻��ϴ� ���þ�. ���� �Ǵ� ������ ���ĸ��� ����� �� ����.
#elif INT == 0
// #elif {condition_statement): �� ������ ���� �ʴ� ���� �Ͽ��� �߰����� �˻縦 �����ϴ� ���þ�.
#else
// #else: ��� ������ �������� �ʾ��� �� �������� �����ϴ� ���þ�.
#endif
// #endif: ��ó�� if ���ǹ��� ���Ḧ ��Ÿ���� ���ɾ�. #if ���þ ����� ��� �ݵ�� �Բ� ���Ǿ����.


#ifdef INT
// ifdef {name}: �ɺ�, ��ũ�� ��� �� �Լ��� ���ǵǾ��ִ��� �˻��ϴ� ���þ�. ���������� #endif�� �Բ� ���Ǿ�� ��.
#endif
#ifndef INT
// ifndef {name}: �ɺ�, ��ũ�� ��� �� �Լ��� ���ǵǾ����� ������ �˻��ϴ� ���þ�. ���������� #endif�� �Բ� ���Ǿ�� ��.
#endif