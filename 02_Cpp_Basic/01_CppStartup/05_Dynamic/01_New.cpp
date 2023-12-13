// 2022-06-30 수업


#include <iostream>
using namespace std;

int main()
{
	// C에서 배운 방법으로, 4 Byte 크기의 공간을 동적할당하고 해당 공간에 4를 저장하고 출력해보기.
	int* pMalloc = (int*)malloc(sizeof(int));
	printf("%i\n", *pMalloc);		// 값을 초기화하지 않고 출력하면 trash value 출력됨.
	*pMalloc = 4;
	printf("%i\n", *pMalloc);
	free(pMalloc);
	pMalloc = NULL;
	
	// C++ 에서는 new 연산자를 사용하여 동적할당이 가능하다.
	// new {자료형};      또는
	// new {자료형}({초기화값});
	// : 해당 자료형을 갖는 공간을 동적할당하고 할당한 공간의 위치를 반환한다.
	//   *new 연산자를 이용하면 동적할당과 동시에 값의 초기화가 가능하다.
	int* pNew = new int(4);
	printf("%i \n", *pNew);

	// C++ 에서는 동적할당한 공간을 해제할 때 delete 연산자가 사용 가능하다.
	delete pNew;

	// C++ 에서는 댕글링 포인터를 제거할 때 nullptr 키워드가 사용 가능하다.
	pNew = nullptr;

	// 2022-06-30 과제
	// Q1. malloc(), new 의 차이점을 서술.
	// A1. 1) malloc()의 경우에는 C 기준 stdlib.h, C++ 기준 iostream 헤더에 포함된 함수이므로 해당 헤더를 반드시 포함해야 사용가능하지만,
	//        new의 경우에는 연산자이므로 헤더가 없어도 사용할 수 있고 오버로딩이 가능하다.
	//     2) malloc()의 기본적인 반환형은 void* 이므로 반드시 사용할 자료형을 캐스팅해야 하고,
	//        new의 경우에는 동적할당받을 공간의 자료형 설정이 가능하다
	//     3) malloc()을 이용할 때에는 생성자를 호출하지 않으므로 값의 초기화가 불가능하지만,
	//        new의 경우에는 생성자를 호출하므로 동적할당과 동시에 값의 초기화가 가능하다.
	//     4) malloc()을 통해 동적할당받은 공간은 재할당이 가능하나,
	//        new의 경우에는 공간을 제거한 뒤 다시 할당해야한다.
	// 
	// Q2. free(), delete 의 차이점을 서술.
	// A2. free()는 소멸자를 호출하는 기능을 갖지 않지만
	//     delete 연산자의 경우에는 소멸자를 호출한다.
	// 
	// Q3. NULL, nullptr의 차이점을 서술.
	// A3. NULL은 매크로에서 정의되어 컴파일러가 0으로 인식하는 '매크로 상수'이며,
	//     nullptr는 주소값이 NULL인 '포인터'이다.
	
	return 0;
}