//#include "Vector.h"		// 2022-07-20 �ǽ�
#include "Vector2.h"		// 2022-07-21 �ǽ�

int main()
{
	
	// ���� Ŭ���� ���ø�
	printf("(IntVector ��ü ����)\n");
	Vector<int> IntVector;
	printf("IntVector.Size(): %i\n", IntVector.Size());

	// Push(value): ������ �߰� �����ϸ� �߰��� ������ ���� value ������ �ʱ�ȭ.
	for (int i = 0; i < 5; i++)
	{
		IntVector.Push(i * 10);
		IntVector.PrintAll();
		printf("�迭�� ����: %i\n", IntVector.Length());
	}

	// Get(index): �ش� index�� ����� ���� ��ȯ.
	printf("IntVector.Get(2): %i\n", IntVector.Get(2));

	// Set(index, value): �ش� index�� ����� ���� value�� �ʱ�ȭ.
	IntVector.Set(0, 100);
	printf("IntVector.Get(0): %i\n", IntVector.Get(0));

	// Size(): �迭�� ũ��(byte)�� ��ȯ.
	printf("IntVector.Size(): %i\n", IntVector.Size());

	// Length(): �迭�� ����(����� ����)�� ��ȯ.
	printf("IntVector.Length(): %i\n", IntVector.Length());

	// Erase(index): �ش� index�� ������ ����.
	IntVector.Erase(2);
	IntVector.PrintAll();
	
	// Empty(): �ش� �迭�� ��� ���� ���ο� ���� bool ������ �������� ��ȯ�ϴ� �Լ�.
	if (IntVector.Empty()) printf("�迭�� ���� Empty �����Դϴ�.\n");
	else printf("�迭�� ���� Empty ���°� �ƴմϴ�.\n");

	// Clear(): �ش� �迭�� ��� ��� ����.
	IntVector.Clear();
	IntVector.PrintAll();
	printf("�迭�� ����: %i\n", IntVector.Length());

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

	// Swap(index1, index2): �ش� �迭 ������ �־��� index�� ��ҿ� ����� ���� ���� ��ȯ.
	printf("(0�� index ��ҿ� 9�� index ��� Swap // �ҽ� �ڵ�)\n");
	IntVector.Swap(0, 9);
	IntVector.PrintAll();
	
	// Sort(): �ش� �迭�� ��Ҹ� ��������.
	IntVector.Sort();
	IntVector.PrintAll();

	// Shuffle(): �ش� �迭�� ��Ҹ� shuffle.
	IntVector.Shuffle();
	IntVector.PrintAll();

	return 0;
}