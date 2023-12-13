// 2022-06-02 수업


// 분기문(switch, case)
// : 여러 경우의 수를 특정 정수형 데이터로 나누어 제어하기 위해 사용하는 구문.
//   단, case에 만족하는 값일 때 명령을 수행한 뒤에 이하의 명령문도 전부 실행한다는 특징이 있음.
//   * 이에 따라 주로 break;와 함께 많이 사용됨.
//   * if문과의 차이점은 조건식이 3개 이상일 경우, 연산 속도가 switch ~ case 구문에서 월등하게 빨라짐.

// switch(정수형 데이터)
// {
//     case 0:      // 정수형 데이터가 0일 경우 실행할 명령(이하의 명령문도 모두 실행함)
//     case 1:      // 정수형 데이터가 1일 경우 실행할 명령(이하의 명령문도 모두 실행함)
//     ...
//     case n:      // 정수형 데이터가 n일 경우 실행할 명령(이하의 명령문도 모두 실행함)
//     default:     // 위의 경우에 해당하지 않을 경우 실행할 명령
// }


#include <stdio.h>

int main()
{
	int input;
	printf("입력 :");
	scanf_s("%i", &input);

	switch (input)
	{
	case 0: printf("입력한 값은 0입니다.\n");
		break;
	case 1: printf("입력한 값은 1입니다.\n");
		break;
	case 2: case 3: printf("입력한 값은 2 또는 3입니다.\n");
		break;
	case 4: printf("입력한 값은 4입니다.\n");
		break;
	default: printf("입력한 값은 0, 1, 2, 3, 4가 아닙니다.\n"); 
	}

	return 0;
}