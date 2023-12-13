// 2022-06-15 과제
// 1) int형 데이터를 반환하며, int형 데이터 3 개를 재료로 하는 max3라는 함수를 만들고
//    호출 시에 넘겨준 데이터 중 최댓값을 구하는 함수를 만들어보기.

// 2) int형 데이터를 반환하며, int형 데이터 3 개를 재료로 하는 middle3라는 함수를 만들고
//    호출 시에 넘겨준 데이터 중 중간값을 구하는 함수를 만들어보기.


#include <iostream>

int larger_value(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int max3(int a, int b, int c)
{
	return larger_value(larger_value(a, b), c);
}

int middle3(int a, int b, int c)
{
	int max_value = max3(a, b, c);

	if (max_value == a) return larger_value(b, c);
	else if (max_value == b) return larger_value(a, c);
	else return larger_value(a, b);
}

// 모범답안 1) 3개의 수 중, 최댓값 구하기
int max3_standard(int a, int b, int c)
{
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

// 모범답안 2) 3개의 수 중, 중간값 구하기
int middle3_standard(int a, int b, int c)
{
	if (a >= b)
	{
		if (b >= c) return b;
		else if (a <= c) return a;
		else return c;
	}
	else if (a > c) return a;
	else if (b > c) return c;
	else return b;
}

int main()
{
	int a;
	int b;
	int c;
	
	printf("a 입력[int]: ");
	std::cin >> a;
	printf("b 입력[int]: ");
	std::cin >> b;
	printf("c 입력[int]: ");
	std::cin >> c;

	printf("[a: %i] [b: %i] [c: %i]\n", a, b, c);
	printf("max3 함수의 반환값: %i\n", max3(a, b, c));
	printf("middle3 함수의 반환값: %i\n", middle3(a, b, c));
	
	return 0;
}