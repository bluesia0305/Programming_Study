// 2022-07-27 수업


#include <iostream>
#include <vector>

// 표준 템플릿 라이브러리(STL, Standard template library)
// : 프로그래밍에 필요한 자료구조와 알고리즘을 template 형태로 제공하는 라이브러리.
//   * vector, map, set, priority_queue, queue, deque, multimap, multiset, list, iterator, functor, allocator, stack 등의 클래스 템플릿.
//   * 참고) 언리얼 엔진에서는 vector -> TArray, map -> TMap 으로 이름이 변경되어 제공.

// 컨테이너(Container): 자료구조를 나타내며, 객체들을 저장하는 객체를 의미.
// 1) 시퀀스 컨테이너(Sequence container)
//    - 선형구조로 자료를 관리하는 컨테이너.
//    - 선형적인 데이터 집합이므로, 데이터를 넣는 순서대로 요소가 할당된다.
//    - 특별한 제약이나 관리규칙 없이 데이터가 관리된다.
//    - 요소의 삽입 및 제거가 빠른 것이 특징이며, 삽입/제거시 자동으로 자신의 크기를 조절한다.
//    - 요소의 탐색 속도가 느린 것이 특징이다.
//    - 요소의 삽입 및 제거시 반복자 무효화 현상이 일어날 수 있다.
//    - 종류로는 vector, list, deque 등이 있다.
// 
// 2) 연관 컨테이너(Associate container)
//    - key와 value를 연관시켜 데이터를 식별함으로써 요소를 할당시킨다.
//    - 특별한 규칙에 의해 데이터가 관리된다.
//    - 요소의 삽입 및 제거가 느린 것이 특징이다.
//    - 요소의 탐색 속도가 매우 빠른 것이 특징이다.
//    - 종류로는 map, set, multi_map 등이 있다.

// 컨테이너 어댑터(Container adapter): 

// 알고리즘(Algorithm): 데이터를 다루기 위한 함수.

// 함수 객체(Functor):

// 메모리 할당자(Allocator):

int main()
{
	// vector: 배열 기반의 (시퀀스)컨테이너. vector 라이브러리를 포함한 뒤 사용 가능하다.
	//         * 즉, 동적배열 구조의 클래스를 연산자 오버로딩, 메소드, 반복자 등을 통해 배열처럼 작동하도록 구현한 것.
	std::vector<int> vector;

	// push_back(value): vector의 맨 뒤에 해당 value 값을 갖는 요소를 추가하는 메소드.
	//                   * 값을 새로 추가할 때마다 배열이 새로 만들어져 기존 주소와는 완전히 다른 주소로 변경됨.
	for (int i = 0; i < 3; i++)
	{
		std::cout << "push_back 메소드 실행." << std::endl;
		vector.push_back(i + 1);
		for (int j = 0; j <= i; j++)
			printf("&vector[%i]: %p\n", j, &vector[j]);
	}
	std::cout << std::endl;

	//printf("&vector[3]: %p\n", &(vector[3]));		- Error -	* 반복자 무효 현상과 동일하게 런타임 에러 (존재하지 않는 공간을 가리킴).

	// clear(): 컨테이너 내의 모든 요소를 제거하는 함수.
	vector.clear();
	for (int i = 1; i <= 5; i++)
		vector.push_back(10 * i);
	
	// 반복자(Iterator): 컨테이너에 있는 요소를 순회하거나, 접근할 수 있게 해주는 객체.
	// - 컨테이너와 알고리즘이 하나로 동작하게 만들어주는 인터페이스 역할을 한다.
	// - 다음 요소로 이동할 경우에 +, -, ++, -- 연산자를 사용한다(주소연산).
	// - 컨테이너의 내부 객체에 접근할 때 직접참조 연산자(*) 연산자를 사용한다.

	// begin(): 컨테이너의 첫 번째 요소의 주소를 반환하는 메소드.
	//          * 컨테이너 자체의 주소의 시작값이 첫 번째 요소가 아닐 수도 있기 때문에 사용.
	std::vector<int>::iterator iter = vector.begin();
	std::cout << "vector의 첫 번째 요소: " << *iter << std::endl;
	std::cout << "vector[1]: " << vector[1] << std::endl;
	std::cout << std::endl;

	// front(): 컨테이너의 맨 앞에 있는 요소를 반환하는 메소드.
	std::cout << "vector.front(): " << vector.front() << std::endl;
	std::cout << std::endl;

	// back(): 컨테이너의 맨 뒤에 있는 요소를 반환하는 메소드.
	std::cout << "vector.back(): " << vector.back() << std::endl;
	std::cout << std::endl;

	// end(): 컨테이너의 마지막 요소의 다음 주소(값을 저장하는 공간이 아님)를 반환하는 메소드.
	//        * back() 메소드와 다른 의미임에 주의(end() 주소에 있는 값을 출력하려고 하면 런타임 에러 발생).
	for (; iter != vector.end(); iter++)
	{ std::cout << *iter << " "; }
	std::cout << std::endl;

	// pop_back(): 마지막으로 추가한 요소를 제거하는 메소드.
	vector.pop_back();
	for (iter = ++vector.begin(); iter != vector.end(); iter++)
	{ std::cout << *iter << " "; }
	std::cout << std::endl;

	// <반복자 무효화 현상>
	// - 반복자가 가리키고 있는 요소를 제거한 뒤 해당 주소에 접근할 때,
	//   반복자 무효 현상(런타임 에러)이 일어난다.
	//   * 동적할당은 아님, stack area 상에서 런타임 동안에 삭제된 공간을 가리켜서 발생하는 문제.
	//   * erase 메소드를 후위증가연산자와 함께 사용하면 해당 현상을 방지할 수 있음.
	//     원리) vector.erase(iter++);
	//           -> iter의 값을 erase 메소드로 전달 -> iter의 값 증가 -> erase 메소드 실행 순으로 이루어지기 때문.

	// 반복자 무효화 현상이 일어나는 예시(iter에 저장되어있는 주소의 공간을 제거 시 발생).
	//iter = vector.begin();
	//vector.erase(++iter);		// vector = { 10, ??, 30, 40 } 과 같은 상태.
	//for (; iter != vector.end(); iter++)
	//{ std::cout << *iter << " "; }
	//std::cout << std::endl;

	// 반복자 무효화 현상이 일어나지 않는 예시
	iter = vector.begin();
	// erase(address): 해당 주소에 위치한 요소를 제거하는 메소드.
	vector.erase(iter + 1);
	for (; iter != vector.end(); iter++)
	{ std::cout << *iter << " "; }
	std::cout << std::endl;

	// size(): 해당 컨테이너의 크기(요소의 갯수)를 반환하는 메소드.
	std::cout << vector.size() << std::endl;

	// empty(): 해당 컨테이너가 비어있는지 여부를 진리값으로 반환(1: 비어있음, 0: 비어있지 않음).
	if (!vector.empty()) std::cout << "해당 컨테이너가 비어있지 않음." << std::endl;

	return 0;
}