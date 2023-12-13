// 2022-06-16 수업(계속)


// return (값);
// : 현재 실행 중인 함수의 실행을 종료하고, 값을 반환하는 기능을 수행하는 점프 구문.


#include <iostream>

int test(int a)
{
	printf("test(%i); 의 결과 >>", a);
	if (a == 1) return 1;
	printf("a는 1이 아닙니다.\n");
}

void test2()
{
	return;			// 반환값이 없는 void 형식으로 선언된 함수에서는 반환값 없이 return; 가능함.
	printf("test2(); 의 결과 >>");
}

int main()
{
	printf("1) int 형식으로 선언된 함수의 경우.\n");
	test(1);
	printf("\n");
	test(2);
	printf("\n\n");

	printf("2) void 형식으로 선언된 함수의 경우.\n");
	test2();

	return 0;
}