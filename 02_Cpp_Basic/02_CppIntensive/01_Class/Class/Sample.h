#pragma once

// 수업 중에서는 이렇게 하지는 않지만 실제 실무 개발 과정에서는
// 클래스는 보통 헤더 파일(.h)과 CPP 파일(.cpp)을 나누어 개발함.
// * 이때, 두 파일의 이름이 달라도 관계는 없으나 통상적으로 이름을 같게 하는 것이 처리속도/관리 등의 측면에서 유리.

// 헤더 파일: 클래스의 선언, 멤버 변수 및 함수의 선언, 인라인 함수 정의.
// CPP 파일: 멤버 함수의 정의.

class Sample
{
private:
	int A = 10;
	int B = 20;

public:
	// 함수의 정의 부분을 간단히 소스 코드 파일로 옮겨 생성하는 방법
	// -> 정의되지 않은 함수를 드래그한 뒤, Ctrl + '.' 이후
	//    '선언 / 정의 만들기'를 클릭.
	void Print() const;
	void Print1() const;
	void Print2() const;
	void Print3() const;
	void Print4() const;
	void Print5() const;
	void Print6() const;

	__forceinline void SetA(int a) { A = a; }
	__forceinline void SetB(int b) { B = b; }
};

