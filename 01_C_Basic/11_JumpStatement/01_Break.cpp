// 2022-06-16 수업


// 점프 구문(Jump statement)
// : 프로그램에서 현재 실행중인 명령을 중단하고 원하는 시점으로 건너뛰는 기능을 수행하는 구문.
//   * 점프 구문의 종류: break, continue, return, goto

// break;
// : switch~case 또는 반복문의 실행을 중단하고, 다음 명령을 실행하기 위해 사용하는 점프 구문.


#include <iostream>

int main()
{
	printf("1) switch ~ case 구문에서의 break; 사용 예시.\n");
	switch (1)
	{
	case 1:	printf("Case1.\n");
	case 2:	printf("Case2.\n");
	case 3:	printf("Case3.\n"); break;
	case 4: printf("Case4.\n");			// 해당 명령문은 break;에 의해 수행되지 않음.
	default: printf("Default.\n");		// 해당 명령문은 break;에 의해 수행되지 않음.
	}
	
	printf("\n");
	printf("2) 반복문에서의 break; 사용 예시.\n");
	int Count = 0;
	while (Count < 10)
	{
		Count++;
		if (Count == 3) break;
		printf("while 구문이 현재 %i번째 실행 중입니다.\n", Count);
	}

	printf("\n");
	printf("3) 중첩 반복문에서의 break; 사용 예시.\n");
	for (int i = 0; i < 7; i++)
	{
		printf("i: %i // j: ", i);
		for (int j = 0; j < 5; j++)
		{
			printf("%i ", j);
			if (j == 3) break;
		}
		printf("\n");
	}

	return 0;
}