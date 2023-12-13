// 2022-06-20 수업(계속)


// Call-by-value, call-by-reference의 차이를 이해하고 포인터가 필요한 이유를 확인.


#include <iostream>

struct A
{
	int num1;
	int num2;
};

void StructChange(A Struct)
{
	printf("(StructChange 함수) 매개변수에서 받아온 값\n");
	printf("구조체(매개변수)의 값: { %i, %i }\n\n", Struct.num1, Struct.num2);
	Struct.num1 += 10;
	Struct.num2 += 10;
	printf("(StructChange 함수) 연산 후의 값\n");
	printf("구조체(매개변수)의 값: { %i, %i }\n", Struct.num1, Struct.num2);
}

void ArrayChange(int arr[])
{
	printf("(ArrayChange 함수) 매개변수에서 받아온 값\n");
	printf("배열(매개변수)의 값: { %i, %i, %i, %i, %i }\n\n",
		arr[0], arr[1], arr[2], arr[3], arr[4]);
	for (int i = 0; i < 5; i++)
	{
		arr[i] += 10;
	}
	printf("(ArrayChange 함수) 연산 후의 값\n");
	printf("배열(매개변수)의 값: { %i, %i, %i, %i, %i }\n",
		arr[0], arr[1], arr[2], arr[3], arr[4]);
}

int main()
{
	// 1) 배열은 기존에 선언되어있는 배열을 복사하여 같은 값을 갖도록 초기화할 수 없음.
	A a = { 10, 20 };
	A b = a;

	int arr1[5] = { 1, 2, 3, 4, 5 };
	//int arr2[5] = arr1;	- Error -

	// 2) 구조체는 매개변수로 넘겨줄 경우에 값이 변하지 않지만(매개변수의 공간을 생성한 뒤, 기존 변수의 값을 복사하여 초기화 = call-by-value),
	//    배열은 매개변수로 넘겨줄 경우, 원래의 변수의 값이 변함(call-by-reference).

	printf("(main 함수) StructChange(), ArrayChange() 함수의 실행 전\n");
	printf("구조체 a의 값: { %i, %i }\n", a.num1, a.num2);
	printf("배열 arr1의 값: { %i, %i, %i, %i, %i }\n",
		arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);
	printf("\n---------------------------------------\n\n");
	StructChange(a);
	printf("\n");
	ArrayChange(arr1);
	printf("\n---------------------------------------\n\n");
	printf("(main 함수) StructChange(), ArrayChange() 함수의 실행 후\n");
	printf("구조체 a의 값: { %i, %i }\n", a.num1, a.num2);
	printf("배열 arr1의 값: { %i, %i, %i, %i, %i }\n",
		arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);

	return 0;
}