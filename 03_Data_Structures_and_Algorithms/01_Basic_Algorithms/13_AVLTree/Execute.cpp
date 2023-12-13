#include <iostream>

template<typename T>
class A
{
public:
	static void Print()
	{
		printf("%s\n", __FUNCTION__);
	}
};

class B
	: public A<B>
{
public:
};

class C
	: public A<C>
{
public:
};


int main()
{
	B::Print();
	C::Print();

	return 0;
}