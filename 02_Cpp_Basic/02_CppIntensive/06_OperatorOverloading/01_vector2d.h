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

	// 연산자 오버로딩 예시
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
		this->X++;			// 연산자 우선순위 유념
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
	// -> 잘 생각해보면 함수의 몸체를 구성하는 부분은 딱히 어려운 개념은 아님
	//    (변수의 값은 변화시키되, 증감 이전의 값을 다른 곳에 저장한 뒤 그 값을 반환하면 된다.
	//     따라서, 반환형 역시 참조형일 필요가 딱히 없음)
	// * 후위증감연산자의 경우, 전위증감연산자와의 구분을 위해 매개변수로 int 자료형을 전달받는 것이 허용된다(다른 자료형 안됨).
	Vector2D operator++ (int)
	{
		Vector2D temp = *this;
		++*this;					// 앞에서 정의한 오버로딩을 사용하는 부분
		return temp;
	}
	Vector2D operator-- (int)
	{
		Vector2D temp = *this;
		--*this;					// 앞에서 정의한 오버로딩을 사용하는 부분
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
	// friend 키워드
	// : 접근제한자를 무시하고 어디에서나 접근하도록 할 수 있게 만드는 키워드. (특정) 멤버를 공개하고자 하는 쪽에서 선언한다.
	//   * 자기 자신도 friend로 명시하는 것이 가능하다.
	//
	//   <사용 예시>
	//   1) friend 클래스	: 클래스를 friend로 지정할 경우, 접근 레벨과 관계 없이 명시한 클래스에서 이루어지는 모든 멤버에 대한 접근을 허용한다.
	//   2) friend 멤버 함수	: 메소드에 클래스명을 명시하는 경우, 명시한 클래스의 해당 메소드 내에서만 모든 멤버에 대한 접근을 항상 허용한다.
	//   3) friend 전역 함수	: 메소드에 클래스명을 명시하지 않는 경우, 해당 함수를 클래스의 멤버로서가 아닌 전역에서 사용할 수 있도록 허용한다.
	//                        동시에 friend로 선언된 해당 함수 내에서 모든 클래스(템플릿)의 모든 멤버에 대한 접근이 가능해진다.
	//                        * friend 전역 함수로 선언되는 순간, 해당 멤버 함수는 더이상 어느 클래스의 멤버 함수로도 존재하지 않게 된다(객체를 통한 접근 불가능).
	//                        * (중요) 주로 C++ 표준으로 구현된 클래스의 객체를 피연산자로 이용하는 연산자 오버로딩에서 사용된다.

	// 아래와 같이 C++ 표준으로 구현된 클래스의 객체를 피연산자로 사용하려면
	// 해당 클래스나 객체는 사용자가 수정할 수 없으므로, 전역 함수로만 구현할 수 있다.
	friend ostream& operator<< (ostream& o, const Vector2D& v)
	{
		o << "( " << v.X << ", " << v.Y << " )";
		return o;
	}
#pragma endregion
};