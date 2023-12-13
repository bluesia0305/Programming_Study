// 2022-06-16 수업(계속)


// continue;
// : 현재 실행중인 반복문의 실행을 중단하고, 조건문으로 돌아가도록 제어하는 점프 구문.
//   break; 와 마찬가지로 중첩 반복문에서는 현재 실행중인 루프에 대해서만 작동함.


#include <iostream>

int main()
{
	int Count = 0;

	// continue; 에 의해 아래의 반복문은 무한루프로 실행됨.
	while (Count < 5)
	{
		printf("반복문 실행. ");
		if (Count == 3) continue;
		++Count;
	}

	return 0;
}