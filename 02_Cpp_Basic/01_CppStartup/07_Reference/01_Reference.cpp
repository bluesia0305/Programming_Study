// 2022-07-06 ����


#include <iostream>
using namespace std;

// ������(Reference)
// : �Ҵ�� �ϳ��� �޸� ����(=����)�� �ٸ� �̸�(=��Ī)�� ���̴� ���� ����.
//   * �� �� ��� ������ �����ڷ� ������ �Ǹ�, ���������� �ٸ� ������ ������ �� ����.

void SetTen(int& ref)
{
	ref = 10;
}

int main()
{
	// 1)
	int myVar = 10;
	int* myPtr = &myVar;
	int& myRef = myVar;
	cout << "1) ������ ���� ���۷����� ����(int& myRef = myVar;)." << endl;
	cout << "myVar    : " << myVar << endl;
	cout << "myPtr    : " << myPtr << " (= address of myVar)" << endl;
	cout << "myRef    : " << myRef << endl;
	cout << "&myVar   :" << &myVar << endl;
	cout << "&myPtr   :" << &myPtr << endl;
	cout << "&myRef   :" << &myRef << endl;
	cout << endl;


	// 2)
	// �����ڸ� �ʱ�ȭ�� �� �ٸ� ���� Ȥ�� ������� �����ϰ� �ȴٸ�
	// �ش� ����, ������� ���� �����ϴ� ���� �ƴ϶� ���� �����Ѵٴ� �ǹ̰� �� (Var�� ����).
	int Test1 = 100;
	int Test2 = 20;
	myVar = Test1;
	myPtr = &Test1;
	myRef = Test2;
	cout << "2) ���۷���(myRef)�� ������ ���, ���� ����(myVar)�� ���� ���� ����." << endl;
	cout << "myVar    : " << myVar << endl;
	cout << "myPtr    : " << myPtr << endl;
	cout << "myRef    : " << myRef << endl;
	cout << "&Test1   : " << &Test1 << endl;
	cout << "&Test2   : " << &Test2 << endl;
	cout << "&myVar   : " << &myVar << endl;
	cout << "&myPtr   : " << &myPtr << endl;
	cout << "&myRef   : " << &myRef << endl;
	cout << endl;


	// 3)
	int*& pRef = myPtr;
	cout << "3) ������ ������ ���� ���۷����� ����(int*& pRef = myPtr;)." << endl;
	cout << "pRef     : " << pRef << endl;
	cout << "&pRef    : " << &pRef << endl;
	cout << "*pRef    : " << *pRef << endl;
	cout << endl;


	// 4)
	int& myRef2 = myRef;
	myRef2 = 1;
	cout << "4) Ư�� ������ ���۷����� ���� ���۷����� ����(int& myRef2 = myRef;)." << endl;
	cout << "   * �� ���� myRef2�� myVar�� �Ǵٸ� ��Ī�� �ǹǷ�, int&&(rvalue ������) ������ �ƴ� int&(lvalue ������) ������." << endl;
	cout << "myVar    : " << myVar << endl;
	cout << "myRef    : " << myRef << endl;
	cout << "myRef2   : " << myRef2 << endl;
	cout << endl;


	// 5)
	const int& litRef1 = 50;		// const Ű���� ���� ������ ���� ���� �Ұ��� (���ͷ� = ����̹Ƿ�).
	cout << "5) ���ڿ��� �ƴ� ���ͷ��� ���� ���۷����� ����(const int& litRef1 = 50;)." << endl;
	cout << "litRef1  : " << litRef1 << endl;
	cout << "&litRef1 : " << &litRef1 << " (��, ��� ���ͷ��� �����ϸ� ���� ���� ��۸� �����Ͱ� �ʿ� ����)" << endl;
	cout << endl;


	//// 5-x) ���ڿ� ���ͷ��� ���� ���۷���?
	//const char*& litRef2 = "abc";
	//cout << "litRef2 : " << litRef2 << endl;
	//cout << "&litRef2: " << &litRef2 << " (��, ��� ���ͷ��� �����ϸ� ���� ���� ��۸� �����Ͱ� �ʿ� ����)" << endl;
	//cout << endl;


	// 6)
	const int& constRef = myVar;
	myVar = 10;						// myVar ��� �̸����� �����ϸ� ������ ����
	//constRef = 11;				// constRef ��� �̸��� ���ؼ��� ���� ���� �Ұ���.
	cout << "6) ������ ���� const ���۷����� ����(const int& constRef = myVar;)." << endl;
	cout << "constRef : " << constRef << endl;
	cout << "&constRef: " << &constRef << endl;
	cout << endl;


	// 7)
	const int* const cpc = &myVar;
	const int* const& ConstRefConst = cpc;
	cout << "7) const int* const ������ �����Ϳ� ���� ���۷����� ����(�ҽ� �ڵ� ����)." << endl;


	// 8) Ÿ�� �߷��� �ڷ����� ����� �� �����ؾ��� �κ�
	auto Auto1 = myVar;				// (�º�) = int ����, (�캯) = int ����
	auto Auto2 = myRef;				// (�º�) = int ����, (�캯) = int& ����
	auto& Auto3 = myRef;			// (�º�) = int& ����, (�캯) = int& ����
	cout << "8) Ÿ�� �߷��� �ڷ����� ���� ���۷����� ���� �� ������(�ҽ� �ڵ� ����)." << endl;
	
	
	// 9) lvalue(left value) vs rvalue(right value)
	//    lvalue: ���� ǥ���� ���� ������� �ʰ� ���ӵǴ� ��ü.
	//    rvalue: ���� ǥ������ ����� �� ���̻� �������� �ʴ� �ӽ����� ��.
	//    * �������� �̵�: rvalue�� lvalue�� ��ȯ�ϴ� ����.
	// Rvalue ������ && (&�� Lvalue ������ ��������)
	int&& RRef = 10;					// �̶� RRef�� ��� ���ͷ� 10�� ��� rvalue�̳�, �ش� �ڵ尡 ����� �� RRef ������ lvalue�� ��.
	//int&& RRef = myRef;	- Error -	// myRef�� lvalue�̹Ƿ� �ش� ��ɹ��� ������ �߻���.
	RRef = 33;
	cout << "9) Rvalue ���������� && ��� ����." << endl;
	cout << "RRef     : " << RRef << endl;


	// 10) �Ű������� �̿��� ���� ������ ���� ������ �� �ִ� �Լ� ����( void SetTen(int& ref) ).
	int t = 20;
	SetTen(t);
	cout << "10) �Ű������� �̿��� ���������� ���� ������ �� �ְ� �ϴ� �Լ� ����( void SetTen(int& ref) )." << endl;
	cout << t << endl;
	
	return 0;
}