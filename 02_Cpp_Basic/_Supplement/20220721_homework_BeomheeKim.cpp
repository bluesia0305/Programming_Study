#include <iostream>
using namespace std;

#pragma region 과제
// 재귀함수를 이용하여 n! 를 구현해주세요
// N == 5
// return value : 5 x 4 x 3 x 2 x 1
// N == 10
// return value : 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1

int factorial(unsigned N)
{ return (N > 1) ? N * factorial(N - 1) : 1; }

void Addition(int   E, float F, bool I = false)
{ ((I) ? cout << "A: " << E << endl << "B: " << F << endl : cout) << "A + B == " << E + F << endl; }
#pragma endregion

int main()
{
	printf("0! : %i\n", factorial(0));
	printf("5! : %i\n", factorial(5));
	printf("10!: %i\n", factorial(10));
	printf("\n");

	printf("1) true일 때 출력결과\n");
	Addition(1, 2.5f, true);
	printf("\n");
	printf("2) false일 때 출력결과\n");
	Addition(1, 2.5f, false);

	return 0;
}