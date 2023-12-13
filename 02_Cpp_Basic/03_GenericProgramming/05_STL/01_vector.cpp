// 2022-07-27 ����


#include <iostream>
#include <vector>

// ǥ�� ���ø� ���̺귯��(STL, Standard template library)
// : ���α׷��ֿ� �ʿ��� �ڷᱸ���� �˰����� template ���·� �����ϴ� ���̺귯��.
//   * vector, map, set, priority_queue, queue, deque, multimap, multiset, list, iterator, functor, allocator, stack ���� Ŭ���� ���ø�.
//   * ����) �𸮾� ���������� vector -> TArray, map -> TMap ���� �̸��� ����Ǿ� ����.

// �����̳�(Container): �ڷᱸ���� ��Ÿ����, ��ü���� �����ϴ� ��ü�� �ǹ�.
// 1) ������ �����̳�(Sequence container)
//    - ���������� �ڷḦ �����ϴ� �����̳�.
//    - �������� ������ �����̹Ƿ�, �����͸� �ִ� ������� ��Ұ� �Ҵ�ȴ�.
//    - Ư���� �����̳� ������Ģ ���� �����Ͱ� �����ȴ�.
//    - ����� ���� �� ���Ű� ���� ���� Ư¡�̸�, ����/���Ž� �ڵ����� �ڽ��� ũ�⸦ �����Ѵ�.
//    - ����� Ž�� �ӵ��� ���� ���� Ư¡�̴�.
//    - ����� ���� �� ���Ž� �ݺ��� ��ȿȭ ������ �Ͼ �� �ִ�.
//    - �����δ� vector, list, deque ���� �ִ�.
// 
// 2) ���� �����̳�(Associate container)
//    - key�� value�� �������� �����͸� �ĺ������ν� ��Ҹ� �Ҵ��Ų��.
//    - Ư���� ��Ģ�� ���� �����Ͱ� �����ȴ�.
//    - ����� ���� �� ���Ű� ���� ���� Ư¡�̴�.
//    - ����� Ž�� �ӵ��� �ſ� ���� ���� Ư¡�̴�.
//    - �����δ� map, set, multi_map ���� �ִ�.

// �����̳� �����(Container adapter): 

// �˰���(Algorithm): �����͸� �ٷ�� ���� �Լ�.

// �Լ� ��ü(Functor):

// �޸� �Ҵ���(Allocator):

int main()
{
	// vector: �迭 ����� (������)�����̳�. vector ���̺귯���� ������ �� ��� �����ϴ�.
	//         * ��, �����迭 ������ Ŭ������ ������ �����ε�, �޼ҵ�, �ݺ��� ���� ���� �迭ó�� �۵��ϵ��� ������ ��.
	std::vector<int> vector;

	// push_back(value): vector�� �� �ڿ� �ش� value ���� ���� ��Ҹ� �߰��ϴ� �޼ҵ�.
	//                   * ���� ���� �߰��� ������ �迭�� ���� ������� ���� �ּҿʹ� ������ �ٸ� �ּҷ� �����.
	for (int i = 0; i < 3; i++)
	{
		std::cout << "push_back �޼ҵ� ����." << std::endl;
		vector.push_back(i + 1);
		for (int j = 0; j <= i; j++)
			printf("&vector[%i]: %p\n", j, &vector[j]);
	}
	std::cout << std::endl;

	//printf("&vector[3]: %p\n", &(vector[3]));		- Error -	* �ݺ��� ��ȿ ����� �����ϰ� ��Ÿ�� ���� (�������� �ʴ� ������ ����Ŵ).

	// clear(): �����̳� ���� ��� ��Ҹ� �����ϴ� �Լ�.
	vector.clear();
	for (int i = 1; i <= 5; i++)
		vector.push_back(10 * i);
	
	// �ݺ���(Iterator): �����̳ʿ� �ִ� ��Ҹ� ��ȸ�ϰų�, ������ �� �ְ� ���ִ� ��ü.
	// - �����̳ʿ� �˰����� �ϳ��� �����ϰ� ������ִ� �������̽� ������ �Ѵ�.
	// - ���� ��ҷ� �̵��� ��쿡 +, -, ++, -- �����ڸ� ����Ѵ�(�ּҿ���).
	// - �����̳��� ���� ��ü�� ������ �� �������� ������(*) �����ڸ� ����Ѵ�.

	// begin(): �����̳��� ù ��° ����� �ּҸ� ��ȯ�ϴ� �޼ҵ�.
	//          * �����̳� ��ü�� �ּ��� ���۰��� ù ��° ��Ұ� �ƴ� ���� �ֱ� ������ ���.
	std::vector<int>::iterator iter = vector.begin();
	std::cout << "vector�� ù ��° ���: " << *iter << std::endl;
	std::cout << "vector[1]: " << vector[1] << std::endl;
	std::cout << std::endl;

	// front(): �����̳��� �� �տ� �ִ� ��Ҹ� ��ȯ�ϴ� �޼ҵ�.
	std::cout << "vector.front(): " << vector.front() << std::endl;
	std::cout << std::endl;

	// back(): �����̳��� �� �ڿ� �ִ� ��Ҹ� ��ȯ�ϴ� �޼ҵ�.
	std::cout << "vector.back(): " << vector.back() << std::endl;
	std::cout << std::endl;

	// end(): �����̳��� ������ ����� ���� �ּ�(���� �����ϴ� ������ �ƴ�)�� ��ȯ�ϴ� �޼ҵ�.
	//        * back() �޼ҵ�� �ٸ� �ǹ��ӿ� ����(end() �ּҿ� �ִ� ���� ����Ϸ��� �ϸ� ��Ÿ�� ���� �߻�).
	for (; iter != vector.end(); iter++)
	{ std::cout << *iter << " "; }
	std::cout << std::endl;

	// pop_back(): ���������� �߰��� ��Ҹ� �����ϴ� �޼ҵ�.
	vector.pop_back();
	for (iter = ++vector.begin(); iter != vector.end(); iter++)
	{ std::cout << *iter << " "; }
	std::cout << std::endl;

	// <�ݺ��� ��ȿȭ ����>
	// - �ݺ��ڰ� ����Ű�� �ִ� ��Ҹ� ������ �� �ش� �ּҿ� ������ ��,
	//   �ݺ��� ��ȿ ����(��Ÿ�� ����)�� �Ͼ��.
	//   * �����Ҵ��� �ƴ�, stack area �󿡼� ��Ÿ�� ���ȿ� ������ ������ �����Ѽ� �߻��ϴ� ����.
	//   * erase �޼ҵ带 �������������ڿ� �Բ� ����ϸ� �ش� ������ ������ �� ����.
	//     ����) vector.erase(iter++);
	//           -> iter�� ���� erase �޼ҵ�� ���� -> iter�� �� ���� -> erase �޼ҵ� ���� ������ �̷������ ����.

	// �ݺ��� ��ȿȭ ������ �Ͼ�� ����(iter�� ����Ǿ��ִ� �ּ��� ������ ���� �� �߻�).
	//iter = vector.begin();
	//vector.erase(++iter);		// vector = { 10, ??, 30, 40 } �� ���� ����.
	//for (; iter != vector.end(); iter++)
	//{ std::cout << *iter << " "; }
	//std::cout << std::endl;

	// �ݺ��� ��ȿȭ ������ �Ͼ�� �ʴ� ����
	iter = vector.begin();
	// erase(address): �ش� �ּҿ� ��ġ�� ��Ҹ� �����ϴ� �޼ҵ�.
	vector.erase(iter + 1);
	for (; iter != vector.end(); iter++)
	{ std::cout << *iter << " "; }
	std::cout << std::endl;

	// size(): �ش� �����̳��� ũ��(����� ����)�� ��ȯ�ϴ� �޼ҵ�.
	std::cout << vector.size() << std::endl;

	// empty(): �ش� �����̳ʰ� ����ִ��� ���θ� ���������� ��ȯ(1: �������, 0: ������� ����).
	if (!vector.empty()) std::cout << "�ش� �����̳ʰ� ������� ����." << std::endl;

	return 0;
}