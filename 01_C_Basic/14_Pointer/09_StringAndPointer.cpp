// 2022-06-23 ����(���)


// ���ڿ��� ������ ������ ���� �˾ƺ���.


#include <iostream>

const char* const ReturnStr()
{
	return "Hello";
}

int main()
{
	// ���ڴ� ����̹Ƿ� const char�� ������.
	// ���� ���ڿ��� ���� ���ڵ��� '�迭'�̹Ƿ� const char* const�� ���°� ��.
	const char* const str1 = "Hello";
	printf("%s\n", ReturnStr());

	const char* str2 = "World";		// ���ڿ��� ����Ű�� �����͸� �Ű������� ������ ��찡 ����.
	printf("%s ", str2);
	str2 = "!";
	printf("%s ", str2);

	return 0;
}