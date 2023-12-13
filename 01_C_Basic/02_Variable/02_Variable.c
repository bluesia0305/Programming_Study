// 2022-05-25 수업


// 컴퓨터에서의 실수의 표현: 고정소수점 / 부동소수점 방식으로 나뉨.
// 1) 고정소수점(fixed point) 방식: 실수부, 지수부, 가수부에 사용할 메모리를 고정.
// 2) 부동소수점(floating point) 방식: 실수부, 지수부, 가수부에 사용할 메모리를 한정짓지 않음.
// * 실수의 bit state 변환에 있어서는 오차가 발생할 수 있음 (완벽한 값을 계산할 수 없을 수 있음).

// 실수 표현 자료형
// float	4 byte (32 bit)		3.4 * 10^-37	~	3.4 * 10^38
// double	8 byte (64 bit)		1.7 * 10^-307	~	3.4 * 10^308
// * float, double 모두 unsigned 키워드를 지원하지 않음 (무조건 부호가 있음).

// 오차범위
// float:	소수점 7자리까지 오차가 거의 발생하지 않음.
// double:	소수점 15자리까지 오차가 거의 발생하지 않음.

// 대중적인 변수 표기법:
// 1) Camel: warriorCharacter	<- 첫글자는 소문자, 단어가 바뀔 때마다 대문자
// 2) Pascal: WarriorCharacter	<- 단어 모두 첫글자를 대문자로
// 3) Hungarian: fWarriorHP		<- 변수명의 첫글자를 자료형으로
// 4) Snake: warrior_character	<- 단어가 바뀔 때마다 _(underbar)로 구분


#include <stdio.h>

int main()
{
	float myFloat = 3.14f;		// float 자료형에 값을 초기화할 때, f를 접미사로 붙여주는 것이 좋음.
	double myDouble = 1.234;

	printf("myFloat: %f\n", myFloat);
	printf("myFloat: %.14f\n", myFloat);
	printf("myDouble: %lf\n", myDouble);
	printf("myDouble: %.14lf\n", myDouble);    // 소수점 이하 14자리까지 출력
	printf("myDouble: %.50lf\n", myDouble);    // 소수점 이하 50자리까지 출력

	return 0;
}