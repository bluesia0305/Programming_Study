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

// ��� ȣ���� ���� ��� - �ܼ� ���(= O(2^n))
// -> �ð� ���⵵�� �ſ� ���� �ٸ� �˰��� ���Ͽ� ���� �����÷ο찡 ������ �߻�)
ULONGLONG Fibonacci_Recursion(int n)
{
	if (n <= 2)
		return 1;

	return Fibonacci_Recursion(n - 1) + Fibonacci_Recursion(n - 2);
}

// ��� ȣ���� ���� ��� - ����� �̿��� ���(= O(log n))
// -> ������ ��귮�� ���ƺ������� �ð� ���⵵�� �� ���� ���� ������ ���� ��꿡�� �� ������
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

// ���� ���α׷��� (= O(n))
// -> �迭�� ũ�� ������ �ؼ� ���� ���� ��꿡���� �Ҹ���
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

	//cout << "[ ����� ��� - �Ϲ� ��ȭ��: O(2^n) ]" << endl;
	//timer.Start();
	//cout << Fibonacci_Recursion(n) << endl;
	//timer.End();
	//cout << "- �ҿ� �ð�: " << timer.RunningTime() << " ms" << endl << endl;

	cout << "[ ����� ���(����-����) - ���: O(log n) ]" << endl;
	cout << "* ��, ��� ����̹Ƿ� �̱� ���������� n�� ���� ���� �� ����" << endl;
	timer.Start();
	cout << "- �Ǻ���ġ ������ " << n << " ��° ���� ��: " << Fibonacci_Matrix(n) << endl;
	timer.End();
	cout << "- �ҿ� �ð�: " << timer.RunningTime() << " ms" << endl << endl;

	cout << "[ ������ȹ�� - (����)�迭�� ���: O(n) ]" << endl;
	timer.Start();
	ULONGLONG* const fibonacci = new ULONGLONG[n + 1];
	memset(fibonacci, 0, sizeof(ULONGLONG) * (n + 1));
	cout << "- �Ǻ���ġ ������ " << n << " ��° ���� ��: " << Fibonacci_DynamicProgramming(fibonacci, n) << endl;
	delete[] fibonacci;
	timer.End();
	cout << "- �ҿ� �ð�: " << timer.RunningTime() << " ms" << endl << endl;

	return 0;
}