// 2022-06-02 수업(계속)


// 반복문(while, for)
// : 특정 구문들(loop)을 반복해서 여러 번 실행해야하는 경우를 제어하기 위해 사용하는 구문. 중첩 작성이 가능함.
//   * 무한루프에 빠지는 경우가 많으니 주의해서 사용해야함
//     (무한루프만을 일부러 이용하는 경우는 없음, 반드시 빠져나올 수 있도록 제어문이 추가 필요함).

// while (조건식) { 코드 블럭; }
// 조건식이 참일 때, 코드 블럭 내의 명령을 계속해서 실행함.
// 참이 아니라면 명령을 수행하지 않고 다음의 구문으로 넘어감.


#include <stdio.h>

int main()
{
	printf("반복문 연습.\n");
	int count = 0;
	while (count < 5)
	{
		printf("반복문이 현재 %i번째 실행되고 있습니다.\n", count + 1);
		count++;
	}
	
	printf("반복문을 빠져나왔습니다.\n\n");

	// 2022-06-02 실습
	// int형 변수를 선언하고 값을 입력받아,
	// 해당 값의 구구단을 출력해주세요.
	// ex) 입력: 5
	//     5 x 1 = 5
	//     5 x 2 = 10
	//     ...
	//     5 x 9 = 45
	printf("입력받은 수의 구구단 출력하기.\n");

	int i = 0;
	int num;
	printf("입력: ");
	scanf_s("%i", &num);
	
	while (i < 9)
	{
		printf("%i x %i = %i\n", num, i+1, num * (i+1));
		i++;
	}
	printf("\n");
}





