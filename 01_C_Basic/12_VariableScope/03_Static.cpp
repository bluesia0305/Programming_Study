// 2022-06-17 수업(계속)


// 정적변수(Static variables)
// : 공간을 할당받은 후에 프로그램이 종료할 때까지 유지시키는 변수를 의미함.
//   * static 키워드를 통해 변수를 선언하는 명령문은 프로그램 실행 시 반복하더라도 최초 1번만 실행.
//   * 위와 같은 특성을 가지지만 기본적으로 변수의 접근은 전역변수, 지역변수와 동일한 규칙에 의해 적용됨.
//     (ex: 정적지역변수는 선언된 중괄호의 외부에서 호출이나 값의 초기화 불가능.)


#include <iostream>

extern int globalVar;
static int staticGlobalVar = 10;
extern int staticGlobalVar2;		// 다른 파일에서 선언된 정적전역변수는 extern으로 사용할 수 없음.

void staticTest()
{
	// 정적 변수의 선언: static 키워드를 사용해 선언함.
	// * 단 한번의 초기화만 이루어지며, 이후 데이터를 계속 보관함.
	static int staticLocalVar = 10;
	int localVar = 10;

	localVar += 10;
	globalVar += 10;
	staticLocalVar += 10;
	staticGlobalVar += 10;

	printf("    지역변수 localVar       의 값: %i\n", localVar);
	printf("    전역변수 globalVar      의 값: %i\n", globalVar);
	printf("정적지역변수 staticLocalVar 의 값: %i\n", staticLocalVar);
	printf("정적전역변수 staticGlobalVar의 값: %i\n", staticGlobalVar);
	printf("-------------------------------------\n");
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		staticTest();
	}

	return 0;
}