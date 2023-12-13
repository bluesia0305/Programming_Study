// 2022-06-22 수업(계속)


// 1. 배열의 생성 원리 및 배열과 포인터의 관계 알아보기.
// 2. 주소연산에 대해 알아보기.


#include <iostream>

void PrintArray(int* const p)
{
	for (int i = 0; i < 5; i++)
		printf("%i ", p[i]);
	printf("\n");
}

int main()
{
	int A = 0;
	int B = 0;
	int* const p1 = &A;
	//p1 = &B;		- Error -	* 상수 포인터(constant pointer)이므로 주소값의 변경이 불가능함.

	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 0 };
	//arr1 = arr2;	- Error -	* 배열의 경우에는 왜 이렇게 초기화하는 것이 안될까?

	// 원래 주소를 표현하기 위한 형식지정자는 %p 이지만 주소의 작동 원리를 확인하기 위해 이하의 예시에서 %lld로 주소를 출력함.
	printf("arr1          : %lld\n", arr1);
	printf("arr2          : %lld\n", arr2);			// 배열의 이름은 곧 배열의 첫번째 요소를 가리키는 포인터를 의미함.
	printf("*arr1         : %lld\n", *arr1);		// 배열의 이름을 역참조하면? -> 배열의 가장 첫번째 요소의 값이 출력됨.
	for (int i = 0; i < 5; i++)	printf("arr1[%i]의 주소: %i\n", i, &arr1[i]);
	printf("\n");
	
	// 주소연산: 주소값 + (n * (해당 주소공간의 크기));
	for (int i = 0; i < 5; i++)	printf("arr1 + %i      : %i\n", i, arr1 + i);
	for (int i = 0; i < 5; i++)	printf("*(arr1 + %i)   : %i\n", i, *(arr1 + i));
	for (int i = 0; i < 5; i++)	printf("arr1[%i]       : %i\n", i, arr1[i]);
	// -> 즉, 인덱스 연산자는 이러한 주소연산을 간편하게 표기하고
	//    이러한 주소연산을 수행한 뒤 가리키는 공간의 데이터에 접근하기 위해 사용하는 연산자임.
	printf("\n");

	// (심화) 배열과 포인터의 관계
	printf("arr1          : %lld\n", arr1);			// 1. 배열의 이름은 곧 첫번째 요소(배열의 시작점)를 가리키는 포인터를 의미함.
	printf("arr1 + 1      : %lld\n", arr1 + 1);		//    즉, arr1의 형식은 int* 임 (단, 배열 선언과 동시에 이름이 가리키는 주소의 변경이 안되므로 int* const 형태이다).
	printf("&arr1         : %lld\n", &arr1);		// 2. 주소연산자의 피연산자가 배열의 이름일 경우에는 배열 전체를 가리키는 포인터를 반환함(시작점은 동일).
	printf("&arr1 + 1     : %lld\n", &arr1 + 1);	//    즉, &arr1의 형식은 int(*)[5] 이며 따라서, 이 경우에는 주소연산을 통해 배열의 크기만큼 주소값의 증감이 일어난다.
	printf("sizeof(arr1)  : %zi\n", sizeof(arr1));	// (참고) sizeof 연산자 역시 피연산자가 배열의 이름인 경우에는 배열의 첫 요소가 아닌, 배열 전체의 크기를 반환한다.
	printf("\n");

	// 다른 상수 포인터 변수를 만든 뒤, 배열의 이름을 대입연산 해버리면 아래와 같이 사용 가능함을 확인 가능.
	int* pArr = arr1;
	printf("pArr          : %i\n", pArr);
	printf("*pArr         : %i\n", *pArr);
	for (int i = 0; i < 5; i++)	printf("pArr[%i]의 주소: %i\n", i, &pArr[i]);
	for (int i = 0; i < 5; i++)	printf("pArr + %i      : %i\n", i, pArr + i);
	for (int i = 0; i < 5; i++)	printf("*(pArr + %i)   : %i\n", i, *(pArr + i));
	for (int i = 0; i < 5; i++)	printf("pArr[%i]       : %i\n", i, pArr[i]);

	PrintArray(arr1);

	return 0;
}