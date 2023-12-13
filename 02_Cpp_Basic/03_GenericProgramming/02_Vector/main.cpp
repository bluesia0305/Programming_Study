//#include "Vector.h"		// 2022-07-20 실습
#include "Vector2.h"		// 2022-07-21 실습

int main()
{
	
	// 벡터 클래스 템플릿
	printf("(IntVector 객체 생성)\n");
	Vector<int> IntVector;
	printf("IntVector.Size(): %i\n", IntVector.Size());

	// Push(value): 공간을 추가 생성하며 추가된 공간의 값을 value 값으로 초기화.
	for (int i = 0; i < 5; i++)
	{
		IntVector.Push(i * 10);
		IntVector.PrintAll();
		printf("배열의 길이: %i\n", IntVector.Length());
	}

	// Get(index): 해당 index에 저장된 값을 반환.
	printf("IntVector.Get(2): %i\n", IntVector.Get(2));

	// Set(index, value): 해당 index에 저장된 값을 value로 초기화.
	IntVector.Set(0, 100);
	printf("IntVector.Get(0): %i\n", IntVector.Get(0));

	// Size(): 배열의 크기(byte)를 반환.
	printf("IntVector.Size(): %i\n", IntVector.Size());

	// Length(): 배열의 길이(요소의 갯수)를 반환.
	printf("IntVector.Length(): %i\n", IntVector.Length());

	// Erase(index): 해당 index의 공간을 제거.
	IntVector.Erase(2);
	IntVector.PrintAll();
	
	// Empty(): 해당 배열에 요소 존재 여부에 대해 bool 형식의 진리값을 반환하는 함수.
	if (IntVector.Empty()) printf("배열이 현재 Empty 상태입니다.\n");
	else printf("배열이 현재 Empty 상태가 아닙니다.\n");

	// Clear(): 해당 배열의 모든 요소 제거.
	IntVector.Clear();
	IntVector.PrintAll();
	printf("배열의 길이: %i\n", IntVector.Length());

	IntVector.Push(10);
	IntVector.Push(9);
	IntVector.Push(8);
	IntVector.Push(7);
	IntVector.Push(6);
	IntVector.Push(5);
	IntVector.Push(4);
	IntVector.Push(3);
	IntVector.Push(2);
	IntVector.Push(1);
	IntVector.PrintAll();

	// Swap(index1, index2): 해당 배열 내에서 주어진 index의 요소에 저장된 값을 서로 교환.
	printf("(0번 index 요소와 9번 index 요소 Swap // 소스 코드)\n");
	IntVector.Swap(0, 9);
	IntVector.PrintAll();
	
	// Sort(): 해당 배열의 요소를 버블정렬.
	IntVector.Sort();
	IntVector.PrintAll();

	// Shuffle(): 해당 배열의 요소를 shuffle.
	IntVector.Shuffle();
	IntVector.PrintAll();

	return 0;
}