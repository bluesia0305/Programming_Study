#include "Sample.h"
#include <iostream>
using namespace std;

// 아래와 같이 정의하면 전역함수라서 함수 이름 뒤에 const 키워드를 사용할 수 없음
//void Print() const
//{
//
//}

// 멤버 함수의 정의 방법
// -> {반환형} {클래스명}::{멤버함수명}( {매개변수_목록} )
void Sample::Print() const
{ cout << "A: " << A << ", B: " << B << endl; }