// 2022-05-27 과제


// int형 변수 num을 선언하고, 값을 입력받아
// 입력 받은 값이 짝수인지, 홀수인지 출력하는 프로그램을 만들어주세요.

// ex)
// Num을 입력하세요 : 10
// Num은 짝수입니다.

// Num을 입력하세요 : 11
// Num은 홀수입니다.


#include <stdio.h>

int main()
{
	int num;
	
	printf("num을 입력하세요: ");
	scanf_s("%i", &num);
	printf("num은 %s\n", (num % 2) ? "홀수입니다." : "짝수입니다.");

	return 0;
}