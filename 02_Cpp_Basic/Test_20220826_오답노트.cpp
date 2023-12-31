/*
	21. 가상 소멸자에 대한 설명으로 올바른 것은 ?
	1 ) 소멸자의 호출 순서가 기반에서 파생으로 끝나기 때문에 생겨난 개념이다.
	2 ) 소멸자 앞에 virtual 을 붙여 선언한다.
	3 ) 참조하고 있는 실제 객체를 기준으로 호출해주는 C 기본 함수 호출 방식 때문에 사용한다.
	4 ) 부모의 소멸자만 가상 소멸자로 지정해준다 해도 아무런 문제가 없다.
	답 : 2
	(추가 공부)
	- 보기 4번: 파생 클래스의 소멸자에 모두 virtual 키워드를 붙이지 않으면 가상 테이블 상에서 문제 발생할 수 있다.

	22. 순수 가상함수에 대한 설명으로 올바른 것은 ?
	1 ) 객체지향의 4대 속성중 상속성에 가장 가까운 기술이다.
	2 ) 함수뒤에 = 0;, pure , abstract 를 작성하여 선언한다.
	3 ) 순수가상함수를 하나 이상 가지고 있는 클래스를 인터페이스라고 한다.
	4 ) 파생 클래스에서 재정의하지 않을 시 해당 파생 클래스를 상속받은 파생 클래스에서 정의한다면 문제가 없다.
	답 : 2 (정답: 4)
	(추가 공부)
	- 보기 4번: 순수가상함수를 재정의하지 않은 파생 클래스(인터페이스)를 인스턴스화 시키지 않는다면 문제가 없다.

	30. Iterator 에 대한 설명으로 올바르지 않은 것은 ?
	1 ) 컨테이너의 요소에 접근하기 위해 사용 된다.
	2 ) Iterator 와 같은 경우 컨테이너 같이 포함되는 개념이다.
	3 ) 요소를 순회할 때 ++, --, + , - 연산자를 사용한다.
	4 ) 요소의 위치를 저장하는 기능이다.
	답 : 2
	(추가 공부)
	- 보기 2번: iterator는 allocator 내에 포함되는 개념이다(객체를 저장하는 객체인 container의 개념이 아님).

	49. PeekMessage 에 대한 설명으로 올바르지 않은 것은 ?
	1 ) CPU 연산을 통한 호출 주기가 매우 빠르다.
	2 ) 메세지를 꺼내와 MSG 형식에 저장하는 기능을 가지고 있다.
	3 ) GetMessage 와 같이 메세지를 꺼내오고 처리하는 과정이 필요없다.
	3 ) 메세지가 없다면 false 를 반환한다.
	답 : 2 (정답: 3)
	(추가 공부)
	- 보기 2번: MSG msg 매개변수에 저장한다.
	- 보기 3번: GetMessage와 마찬가지로 메세지를 처리하는 과정이 필요하다(예시: DispatchMessage(), SendMessage() 등).
*/