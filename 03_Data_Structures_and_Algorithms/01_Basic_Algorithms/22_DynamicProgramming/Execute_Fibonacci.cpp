#include <iostream>
#include "../Timer.h"

typedef unsigned long long ULONGLONG;
using namespace std;

struct Matrix
{
	ULONGLONG Data[2][2];

	static Matrix Multiply(const Matrix& a, const Matrix& b)
	{
		Matrix R;

		R.Data[0][0] = a.Data[0][0] * b.Data[0][0] + a.Data[0][1] * b.Data[1][0];
		R.Data[0][1] = a.Data[0][0] * b.Data[0][1] + a.Data[0][1] * b.Data[1][1];
		R.Data[1][0] = a.Data[1][0] * b.Data[0][0] + a.Data[1][1] * b.Data[1][0];
		R.Data[1][1] = a.Data[1][0] * b.Data[0][1] + a.Data[1][1] * b.Data[1][1];

		return R;
	}
};

Matrix Power(Matrix& m, int n)
{
	if (n <= 1)
		return m;

	m = Power(m, n / 2);
	m = Matrix::Multiply(m, m);

	if (n & 1)
	{
		Matrix b;
		b.Data[0][0] = 1;
		b.Data[0][1] = 1;
		b.Data[1][0] = 1;
		b.Data[1][1] = 0;
		m = Matrix::Multiply(m, b);
	}

	return m;
}

// 재귀 호출을 통한 계산 - 단순 재귀(= O(2^n))
// -> 시간 복잡도가 매우 높아 다른 알고리즘에 비하여 스택 오버플로우가 빠르게 발생)
ULONGLONG Fibonacci_Recursion(int n)
{
	if (n <= 2)
		return 1;

	return Fibonacci_Recursion(n - 1) + Fibonacci_Recursion(n - 2);
}

// 재귀 호출을 통한 계산 - 행렬을 이용한 재귀(= O(log n))
// -> 당장의 계산량은 많아보이지만 시간 복잡도가 더 낮아 높은 숫자의 항의 계산에서 더 유리함
ULONGLONG Fibonacci_Matrix(int n)
{
	Matrix m;
	m.Data[0][0] = 1;
	m.Data[0][1] = 1;
	m.Data[1][0] = 1;
	m.Data[1][1] = 0;

	m = Power(m, n);

	return m.Data[0][1];
}

// 동적 프로그래밍 (= O(n))
// -> 배열을 크게 만들어야 해서 높은 항의 계산에서는 불리함
ULONGLONG Fibonacci_DynamicProgramming(ULONGLONG* const fibonacci, int n)
{
	if (n <= 1)
	{
		fibonacci[n] = n;
		return fibonacci[n];
	}
	else if (fibonacci[n] != 0)
		return fibonacci[n];

	fibonacci[n] = Fibonacci_DynamicProgramming(fibonacci, n - 1) + Fibonacci_DynamicProgramming(fibonacci, n - 2);
	return fibonacci[n];
}

int main()
{
	Timer timer;
	int n = 3000;

	//cout << "[ 재귀적 방법 - 일반 점화식: O(2^n) ]" << endl;
	//timer.Start();
	//cout << Fibonacci_Recursion(n) << endl;
	//timer.End();
	//cout << "- 소요 시간: " << timer.RunningTime() << " ms" << endl << endl;

	cout << "[ 재귀적 방법(분할-정복) - 행렬: O(log n) ]" << endl;
	cout << "* 단, 행렬 계산이므로 싱글 쓰레딩에서 n이 낮을 때는 더 느림" << endl;
	timer.Start();
	cout << "- 피보나치 수열의 " << n << " 번째 항의 값: " << Fibonacci_Matrix(n) << endl;
	timer.End();
	cout << "- 소요 시간: " << timer.RunningTime() << " ms" << endl << endl;

	cout << "[ 동적계획법 - (동적)배열로 계산: O(n) ]" << endl;
	timer.Start();
	ULONGLONG* const fibonacci = new ULONGLONG[n + 1];
	memset(fibonacci, 0, sizeof(ULONGLONG) * (n + 1));
	cout << "- 피보나치 수열의 " << n << " 번째 항의 값: " << Fibonacci_DynamicProgramming(fibonacci, n) << endl;
	delete[] fibonacci;
	timer.End();
	cout << "- 소요 시간: " << timer.RunningTime() << " ms" << endl << endl;

	return 0;
}