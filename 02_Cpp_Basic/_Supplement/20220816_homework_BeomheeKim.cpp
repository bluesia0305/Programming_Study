#include <iostream>

struct DoublePointer
{
	int* p;
	void Setp() { p = new int(); }
	void Print() { std::cout << p << std::endl; }

	void Swap(DoublePointer* p2)
	{
		int* temp = this->p;
		this->p = p2->p;
		p2->p = temp;
	}

	void Swap(int** p)
	{
		int* temp = this->p;
		this->p = *p;
		*p = temp;
	}
};

int main()
{
	DoublePointer p1; 
    p1.Setp();
    DoublePointer p2;
    p2.Setp();

    p1.Print();
    p2.Print();

	// Swap �Լ��� ������� �����Ҵ��� ������ �ּҰ�
	// �ڹٲ�� �������ּ���.
	// -> �Ʒ� �� �� ���� ��� ���.
    //p1.Swap(&p2);
	p1.Swap(&p2.p);

    p1.Print();
    p2.Print();

	return 0;
}