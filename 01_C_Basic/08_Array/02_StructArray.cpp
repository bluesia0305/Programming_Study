// 2022-06-09 ����(���)


#include <iostream>

struct Monster
{
	int hp;
	int atk;
};

int main()
{
	// ����� ���� �ڷ����� �̿��� �迭�� ���� �� �迭�� �� ��Һ� ��� ȣ���ϱ�.
	Monster myArray1[2] = {};		// �ʱ�ȭ���� ���� ����� ��� ����� ���� 0���� ������.
	std::cout << "1) ����� ���� �ڷ����� �̿��� �迭." << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << i + 1 << "��° ���" << std::endl;
		std::cout << myArray1[i].hp << std::endl;
		std::cout << myArray1[i].atk << std::endl << std::endl;
	}
	
	// ����� ���ÿ� ��� ����� ��� ����鿡 ���� �ʱ�ȭ �ϴ� ���.
	Monster myArray2[2] = { { 10, 1 }, { 20, 2 } };

	return 0;
}