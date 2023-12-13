// 2022-05-27 수업(계속)


// 비교연산자(Comparison operator)
// : 두 값을 비교하여 진리값(1: true, 0: false)을 반환하는 연산자.
//   A < B    ->  A의 값이 B 미만이라면 1, 아니라면 0을 반환함.
//   A <= B   ->  A의 값이 B 이하라면 1, 아니라면 0을 반환함.
//   A > B    ->  A의 값이 B 초과라면 1, 아니라면 0을 반환함.
//   A >= B   ->  A의 값이 B 이상이라면 1, 아니라면 0을 반환함.
//   A == B   ->  A의 값 B의 값과 같으면 1, 아니라면 0을 반환함.
//   A != B   ->  A의 값이 B의 값과 다르면 1, 아니라면 0을 반환함.


#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	printf("a = %i, b = %i\n", a, b);
	printf("a < b : %i\n", a < b);
	printf("b <= a : %i\n", b <= a);
	printf("a > b : %i\n", a > b);
	printf("b >= a : %i\n", b >= a);
	printf("a == b : %i\n", a == b);
	printf("a != b : %i\n", a != b);

	return 0;
}