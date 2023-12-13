// 2022-06-27 수업(계속)


// 배열 및 구조체에 대한 동적할당


#include <iostream>

struct Struct
{
	int a;
	int b;
};

int main()
{
	// 배열
	int* pArr = (int*) malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
	{
		pArr[i] = (i + 1) * 10;
		printf("%i ", pArr[i]);
	}
	printf("\n");
	free(pArr);
	pArr = NULL;
	printf("\n");

	// 구조체
	Struct* pStruct = (Struct*) malloc(sizeof(Struct));
	(*pStruct).a = 10;
	pStruct->b = 20;
	printf("a::[%i] b::[%i]\n", (*pStruct).a, pStruct->b);
	free(pStruct);
	pStruct = NULL;
	printf("\n");

	// 구조체 배열 동적할당
	// Struct형의 요소를 5개 저장할 수 있는 배열을 동적할당하고
	// 해당 공간을
	// a: 1, 3, 5, 7, 9
	// b: 2, 4, 6, 8, 10
	// 으로 초기화한 뒤 출력하기.

	// 1) 직접접근
	Struct* pStructArr1 = (Struct*) malloc(sizeof(Struct) * 5);
	printf("%zi\n", sizeof(pStructArr1));
	for (int i = 0; i < 5; i++)
	{
		pStructArr1[i].a = 2 * i + 1;
		pStructArr1[i].b = 2 * (i + 1);
		printf("pStructArr1[%i]: a == %i, b == %i\n", i, pStructArr1[i].a, pStructArr1[i].b);
	}
	free(pStructArr1);
	pStructArr1 = NULL;
	printf("\n");

	// 2) 간접접근
	Struct* pStructArr2[5];
	printf("%zi\n", sizeof(pStructArr2));
	for (int i = 0; i < 5; i++)
	{
		pStructArr2[i] = (Struct*) malloc(sizeof(Struct));
		pStructArr2[i]->a = 2 * i + 1;
		pStructArr2[i]->b = 2 * (i + 1);
		printf("pStructArr2[%i]: a == %i, b == %i\n", i, pStructArr2[i]->a, pStructArr2[i]->b);
		free(pStructArr2[i]);
		pStructArr2[i] = NULL;
	}
	
	// (과제) 위의 두 예시에 대하여 차이점을 서술하기.
	// 
	// Q1. 위의 1번과 2번의 예시에서 동적할당이 어떤 식으로 할당되는지?
	// A1. 1)의 경우:
	//                   최초, ('Struct' 구조체의 크기) X (요소의 갯수) 만큼의 크기에 해당하는 메모리를 1회 동적할당받아
	//                   해당 공간의 주소를 'pStructArr1' 라는 이름의 'Struct' 구조체 형식을 가리키는 포인터 변수에 저장하고,
	//                   주소연산을 통해 동적할당받은 1개의 공간을 5개의 'Struct' 형식의 구조체와 동일한 크기의 공간으로 나누어 접근하는 형태이다.
	//                   최종적으로는 동적할당받은 공간에 대해 1회 메모리를 해제하고 있다.
	// 
	//     2)의 경우:
	//                   5개의 포인터 변수를 요소로 갖는 pStructArr2 라는 이름의 '포인터 배열'을 선언한 뒤,
	//                   각 i번째 요소(=포인터 변수)마다 'Struct' 구조체와 동일한 크기의 메모리를 동적할당받아
	//                   해당 공간의 주소를 i번째 요소에 저장하고, 이 주소를 이용해 접근하는 형태이다.
	//                   각 요소별로 동적할당받은 공간에 대해 메모리를 해제를 반복하고 있다.
	// 
	// 
	// Q2. 1은 왜 인덱스 접근연산자 이후 멤버 직접접근 연산자를 사용해야하고,
	//     2는 왜 인덱스 접근연산자 이후 멤버 간접접근 연산자를 사용해야하는지?
	// 
	//     1)의 경우:
	//                   pStructArr1은 동적할당받은 공간을 'Struct' 구조체와 동일한 크기만큼으로 5개의 공간으로 나누어 접근하는 형태이므로
	//                   'Struct' 형식의 구조체를 요소로 갖는 배열과 동일하게 작동한다.
	//                   즉, pStructArr1[i]와 같은 인덱스 접근연산의 결과가 <<'Struct' 형식의 구조체>>이므로
	//                   인덱스 접근연산 후 멤버에 접근하기 위해서는 직접접근해야한다.
	// 
	//     2)의 경우:
	//                   pStructArr2는 'Struct' 구조체 형식을 가리키는 포인터 변수 5개를 요소로 갖는 배열이므로
	//                   'Struct' 형식의 구조체와 동일한 크기만큼 동적할당받은 공간을 가리키는 포인터들의 배열이다.
	//                   즉, pStructArr2[i]와 같은 인덱스 접근연산의 결과가 <<'Struct' 형식의 구조체를 가리키는 포인터>>이므로
	//                   인덱스 접근연산 후 멤버에 접근하기 위해서는 간접접근해야한다.
	// 
	// 
	// Q3: 1은 왜 한번 free 함수를 사용하고, 2는 왜 5번 free 함수를 사용하는지?
	//     1)의 경우:
	//                   최초 동적할당받을 때, (Struct 구조체의 크기) X (요소의 갯수) 만큼의 크기로 한 번 동적할당하였기 때문에
	//                   해당 동적할당받은 공간에 대하여 한 번만 메모리를 해제하면 된다.
	// 
	//     2)의 경우:
	//                   5 개의 각각의 요소에 대하여 동적할당받은 공간의 생성 및 동적할당받은 공간의 주소를 저장하고 있으므로,
	//                   동적할당받은 공간의 수가 5 개이다. 따라서, 동적할당받은 공간에 대한 메모리의 해제 역시 5 번 이루어져야한다.

	return 0;
}