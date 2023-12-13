#include "01_vector2d.h"
using namespace std;

// 연산자 오버로딩(Operator overloading)
// : 기존에 정의되어있는 연산자에 대하여 원래의 기능과 다른 기능을 오버로딩 하는 것.
//   * 오버로딩이 불가능한 연산자: #(전처리기), ##(전처리기 연결), ?:(삼항연산자), ::(스코프 연산자), .(간접접근 연산자), .*(멤버 포인터 선택), sizeof(자료형 크기) 등.
//   * 기존에 존재하지 않는 새로운 연산자에 대한 정의는 불가능하다.
//   * 오버로드 된 연산자는 비정적 클래스 멤버 함수이거나 전역 함수여야만 한다.
// 
//   <연산자 오버로딩 방식에 따른 특징>
//   1) 멤버 함수: 피연산자로 반드시 호출되는 해당 클래스의 객체 형식이 사용되며(this pointer),
//                 이항연산에서 반드시 첫번째 파라미터(연산자의 왼쪽에 위치)로서 사용된다.
//   2) 전역 함수: 피연산자로 모든 클래스의 객체에 대하여 접근제한자를 무시하며 멤버들에 대한 접근이 가능하다.
//                 이항연산에서 사용되는 2 개의 피연산자끼리의 순서 변경이 자유롭다(프로토타입에서 정의한 대로 정해짐).

int main()
{
	Vector2D v1 = Vector2D(.1f, .1f);
	Vector2D v2 = Vector2D(.2f, .2f);
	Vector2D v3 = v1 + v2;
	cout << "1) 사칙연산자 오버로딩" << endl;
	v3.Print();

	// 연산자 오버로딩을 하지 않으면 바로 아랫줄의 명령 결과가 ( 1.1, 0.1 ) 로 나옴.
	Vector2D v4 = v1 + 1.f;
	v4.Print();

	Vector2D v5 = v1 - 1.f;
	v5.Print();

	Vector2D v6 = v1 * 2;
	v6.Print();

	Vector2D v7 = v1 / .1f;
	v7.Print();

	Vector2D v8 = v1 / v2;
	v8.Print();
	cout << endl;

	cout << "2) 복합대입연산자 오버로딩" << endl;
	Vector2D v9 = v1;
	v9 *= 10;
	v9.Print();
	cout << endl;

	cout << "3) 증감연산자 오버로딩" << endl;
	Vector2D v10 = v1;
	(v10++).Print();
	v10.Print();
	(++v10).Print();
	cout << endl;

	cout << "4) 단항부호연산자 오버로딩" << endl;
	Vector2D v11 = +v1;
	Vector2D v12 = -v1;
	v11.Print();
	v12.Print();
	cout << endl;

	cout << "5) 출력연산자 오버로딩" << endl;
	cout << v1;
	cout << endl;
	return 0;
}