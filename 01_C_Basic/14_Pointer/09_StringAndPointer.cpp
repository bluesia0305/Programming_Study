// 2022-06-23 수업(계속)


// 문자열과 포인터 사이의 관계 알아보기.


#include <iostream>

const char* const ReturnStr()
{
	return "Hello";
}

int main()
{
	// 문자는 상수이므로 const char의 형태임.
	// 따라서 문자열의 경우는 문자들의 '배열'이므로 const char* const의 형태가 됨.
	const char* const str1 = "Hello";
	printf("%s\n", ReturnStr());

	const char* str2 = "World";		// 문자열을 가리키는 포인터를 매개변수로 보내는 경우가 많음.
	printf("%s ", str2);
	str2 = "!";
	printf("%s ", str2);

	return 0;
}