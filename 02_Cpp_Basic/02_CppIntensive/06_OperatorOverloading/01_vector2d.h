#pragma once
#include <iostream>
using namespace std;

class Vector2D final
{
public:
	float X;
	float Y;

	Vector2D(float X = 0.0f, float Y = 0.0f)
	{
		this->X = X;
		this->Y = Y;
	}

	__forceinline void Print() const
	{ printf("( %.1f, %.1f )\n", X, Y); }

	// ������ �����ε� ����
#pragma region Arithmetic Operators
	template<typename T>
	Vector2D operator+ (const T& literal)
	{ return Vector2D( X + literal, Y + literal); }
	template<>
	Vector2D operator+<Vector2D> (const Vector2D& v)
	{ return Vector2D( X + v.X, Y + v.Y ); }

	template<typename T>
	Vector2D operator- (const T& literal)
	{ return Vector2D(X - literal, Y - literal); }
	template<>
	Vector2D operator-<Vector2D> (const Vector2D& v)
	{ return Vector2D(X - v.X, Y - v.Y); }

	template<typename T>
	Vector2D operator* (const T& literal)
	{ return Vector2D(X * literal, Y * literal); }
	template<>
	Vector2D operator*<Vector2D> (const Vector2D& v)
	{ return Vector2D(X * v.X, Y * v.Y); }

	template<typename T>
	Vector2D operator/ (const T& literal)
	{
		if (literal) return Vector2D(X / literal, Y / literal);
		else return 0;
	}
	template<>
	Vector2D operator/<Vector2D> (const Vector2D& v)
	{ return Vector2D(X / v.X, Y / v.Y); }
#pragma endregion
#pragma region Compound Assignment Operators
	template<typename T>
	void operator+= (const T& literal)
	{
		this->X = this->X + literal;
		this->Y = this->Y + literal;
	}
	template<>
	void operator+=<Vector2D> (const Vector2D& v)
	{
		this->X = this->X + v.X;
		this->Y = this->Y + v.Y;
	}

	template<typename T>
	void operator-= (const T& literal)
	{
		this->X = this->X - literal;
		this->Y = this->Y - literal;
	}
	template<>
	void operator-=<Vector2D> (const Vector2D& v)
	{
		this->X = this->X - v.X;
		this->Y = this->Y - v.Y;
	}

	template<typename T>
	void operator*= (const T& literal)
	{
		this->X = this->X * literal;
		this->Y = this->Y * literal;
	}
	template<>
	void operator*=<Vector2D> (const Vector2D& v)
	{
		this->X = this->X * v.X;
		this->Y = this->Y * v.Y;
	}

	template<typename T>
	void operator/= (const T& literal)
	{ this = this / literal; }
	template<>
	void operator/=<Vector2D> (const Vector2D& v)
	{
		this->X = this->X / v.X;
		this->Y = this->Y / v.Y;
	}
#pragma endregion
#pragma region In/decrement Operators
	// prefix in/decrement operators
	Vector2D& operator++ ()
	{
		this->X++;			// ������ �켱���� ����
		this->Y++;
		return *this;
	}
	Vector2D& operator-- ()
	{
		this->X--;
		this->Y--;
		return *this;
	}

	// postfix in/decrement
	// -> �� �����غ��� �Լ��� ��ü�� �����ϴ� �κ��� ���� ����� ������ �ƴ�
	//    (������ ���� ��ȭ��Ű��, ���� ������ ���� �ٸ� ���� ������ �� �� ���� ��ȯ�ϸ� �ȴ�.
	//     ����, ��ȯ�� ���� �������� �ʿ䰡 ���� ����)
	// * ���������������� ���, �������������ڿ��� ������ ���� �Ű������� int �ڷ����� ���޹޴� ���� ���ȴ�(�ٸ� �ڷ��� �ȵ�).
	Vector2D operator++ (int)
	{
		Vector2D temp = *this;
		++*this;					// �տ��� ������ �����ε��� ����ϴ� �κ�
		return temp;
	}
	Vector2D operator-- (int)
	{
		Vector2D temp = *this;
		--*this;					// �տ��� ������ �����ε��� ����ϴ� �κ�
		return temp;
	}
#pragma endregion
#pragma region Sign Operators
	Vector2D operator+ ()
	{ return Vector2D(this->X, this->Y); }

	Vector2D operator- ()
	{ return Vector2D(this->X * (-1), this->Y * (-1)); }
#pragma endregion
#pragma region Output Operators
	// friend Ű����
	// : ���������ڸ� �����ϰ� ��𿡼��� �����ϵ��� �� �� �ְ� ����� Ű����. (Ư��) ����� �����ϰ��� �ϴ� �ʿ��� �����Ѵ�.
	//   * �ڱ� �ڽŵ� friend�� ����ϴ� ���� �����ϴ�.
	//
	//   <��� ����>
	//   1) friend Ŭ����	: Ŭ������ friend�� ������ ���, ���� ������ ���� ���� ����� Ŭ�������� �̷������ ��� ����� ���� ������ ����Ѵ�.
	//   2) friend ��� �Լ�	: �޼ҵ忡 Ŭ�������� ����ϴ� ���, ����� Ŭ������ �ش� �޼ҵ� �������� ��� ����� ���� ������ �׻� ����Ѵ�.
	//   3) friend ���� �Լ�	: �޼ҵ忡 Ŭ�������� ������� �ʴ� ���, �ش� �Լ��� Ŭ������ ����μ��� �ƴ� �������� ����� �� �ֵ��� ����Ѵ�.
	//                        ���ÿ� friend�� ����� �ش� �Լ� ������ ��� Ŭ����(���ø�)�� ��� ����� ���� ������ ����������.
	//                        * friend ���� �Լ��� ����Ǵ� ����, �ش� ��� �Լ��� ���̻� ��� Ŭ������ ��� �Լ��ε� �������� �ʰ� �ȴ�(��ü�� ���� ���� �Ұ���).
	//                        * (�߿�) �ַ� C++ ǥ������ ������ Ŭ������ ��ü�� �ǿ����ڷ� �̿��ϴ� ������ �����ε����� ���ȴ�.

	// �Ʒ��� ���� C++ ǥ������ ������ Ŭ������ ��ü�� �ǿ����ڷ� ����Ϸ���
	// �ش� Ŭ������ ��ü�� ����ڰ� ������ �� �����Ƿ�, ���� �Լ��θ� ������ �� �ִ�.
	friend ostream& operator<< (ostream& o, const Vector2D& v)
	{
		o << "( " << v.X << ", " << v.Y << " )";
		return o;
	}
#pragma endregion
};