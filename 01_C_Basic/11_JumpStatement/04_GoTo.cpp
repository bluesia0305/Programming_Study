// 2022-06-16 수업(계속)


// goto {레이블명};
// : 프로그램의 흐름을 중단하고 지정된 레이블로 이동시키는 기능.
//   절차지향 프로그래밍의 속성을 따르지 않는 기능이므로 실무에서 거의 사용되지 않음(기능이 존재한다는 것만 알아두기).


#include <iostream>

int main()
{
	printf("main 시작\n");
	int n = 0;

// 아래의 명령줄과 같이 레이블 선언할 수 있음 -> {레이블명} :
Teleport :
	if (n == 1) printf("teleport!\n");
	system("pause");

	n = 1;
	goto Teleport;

	return 0;
}