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

	// Swap 함수를 실행시켜 동작할당한 공간의 주소가
	// 뒤바뀌도록 설정해주세요.
	// -> 아래 중 한 가지 방법 사용.
    //p1.Swap(&p2);
	p1.Swap(&p2.p);

    p1.Print();
    p2.Print();

	return 0;
}