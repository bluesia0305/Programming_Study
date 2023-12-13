// 2022-06-17 수업


// 전역변수(Global variables)
// : 모든 중괄호의 외부에서 선언된 변수로, 전역성을 띠는 변수.
//   * extern 키워드를 이용하면 다른 파일에 있는 전역변수를 가져와 사용할 수도 있음.
//     (단, 프로젝트에 포함되어있지 않은 파일에서 선언된 전역변수는 불러올 수 없음)


#include <iostream>

extern int globalVar;

void globalAddTest()
{
	globalVar += 10;
}

int main()
{
	printf("1) 전역변수의 성질 이해.\n");
	printf("전역변수 globalVar의 값: %i\n", globalVar);
	globalAddTest();
	printf("전역변수 globalVar의 값: %i\n", globalVar);

	printf("2) 동일한 전역변수와 지역변수를 갖는 경우에 대한 예시.\n");
	int globalVar = 1;
	printf("지역변수 globalVar의 값: %i\n", globalVar);
	printf("전역변수 globalVar의 값: %i\n", ::globalVar);		// 동일한 이름의 변수 중, 전역변수를 호출할 때 ::를 앞에 붙이면 됨.

	return 0;
}