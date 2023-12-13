// 2022-07-18 ����


#include <iostream>
#include <string>
using namespace std;

// ��ü���� ���α׷����� 4�� �Ӽ� ����(�ǹ�, �ʿ伺) �� ���ø� �������ּ���.

// 1) ĸ��ȭ(Encapsulation)
//    - ����: ��ü�� ���(��� ���� �� ��� �Լ�)�� ����,
//            ���� ���� ������ �Ϻθ� ���ο� ���߾� �����ϴ� ���.
//	    
//	  - �ʿ伺:
//      1) Ŭ������ ���������� ��� �����Ǿ��ִ��� �� �ʿ� ����,
//         �����Ǿ��ִ� ��� �Լ��� �ʿ� �Ű������� ��ȯ���� ���¸� �˸� �ش� ��� �Լ��� ����� �� �ִ�.
//         ��, ���α׷��� ���⼺�� �����ش�.
//      2) ���α׷��� �󿡼�, �ܺο��� ��ü�� �����Ͽ� �����͸� �����ϸ� ������ �߻��� �� �ִ� �κе��� ��ȣ�� �� �ִ�.
//	    
//	  - ����: ���������ڸ� ���� ������ �� �ִ�.
#pragma region Example1
class Example1
{
private:
	string myStr;			// ���ڿ� ����� ����ų ������.
	int myStr_len;			// pString�� ����Ű�� ���ڿ��� ���̸� ������ ����.
							// �ش� ������ public���� ����Ǹ�, �ǵ��� �ٸ��� pString�� ���� ������� ���� ����� �� �ִ�.
public:
	Example1(string myStr = "")
	{ SetLen(); }

	void SetLen()
	{ myStr_len = static_cast<int>(myStr.length()); }
};
#pragma endregion


// 2) ��Ӽ�(Inheritance)
//    - ����: ��� Ŭ������ ����� Ȯ���Ͽ� �Ļ� Ŭ������ �����Ͽ� �ڵ��� ���꼺�� ���̴� ���.
//	    
//	  - �ʿ伺:
//      �̹� ����Ǿ��ִ� Ŭ������ ���� ����� ���ÿ� �����鼭,
//      ���ο� ����� �߰��� Ŭ������ �����ϴ� ���������� ���꼺�� ���̱� ���� ���ȴ�.
//	    
//	  - ����: �Ʒ��� ���� ��� Ŭ������ ��ӹ��� �Ļ� Ŭ������ ������ �����ϴ�.
#pragma region Example2
class Example2_Base
{
	// ��� Ŭ����
public:
	int var1 = 10;
	int var2 = 20;

	void print() const
	{ cout << "var1: " << var1 << ", var2: " << var2 << endl; }
};

class Example2_Derived : public Example2_Base
{
	// �Ļ� Ŭ����
public:
	int var3 = 30;
};
#pragma endregion


// 3) ������(Polymorphism)
//    - ����: ���� �ٸ� ��ü�� ������ ����� ���� �ٸ� ������� ó���� �� �ִ� ���.
//	    
//	  - �ʿ伺:
//      ���α׷����� ó���ؾ��ϴ� ���ο� �Ӽ��� ���� ��ü�� �߰��� ��,
//      ���� �ۼ��� �ڵ�(Ŭ����, �Լ� ��)�� ������ �ּ�ȭ�ϸ鼭 ��ȭ�� ��ó�� �� �ֵ��� �ϱ� ���Ͽ� ���ȴ�.
//	    
//	  - ����: �Լ��� ����� �������� Ŭ������ ��� ���� ���� �����ȴ�
//            * Ŭ���� ���, ���� �Լ�, �������̵�, �����ε� ��.
#pragma region Example3_Overriding
class IExample3_Pet
{
public:
	string Name;
	virtual ~IExample3_Pet() {}
	virtual void Sound() abstract;
	virtual void Eat() abstract;
};

class Example3_Dog : public IExample3_Pet
{
	// Example3_Pet��(��) ���� ��ӵ�
	virtual void Sound() override
	{ cout << "�����Ҹ�: �۸�"; }
	virtual void Eat() override
	{ cout << "����: ���ٱ�"; }
};

class Example3_Cat : public IExample3_Pet
{
	// Example3_Pet��(��) ���� ��ӵ�
	virtual void Sound() override
	{ cout << "�����Ҹ�: �߿�"; }
	virtual void Eat() override
	{ cout << "����: ����"; }
};

class Example3_Pikachu : public IExample3_Pet
{
	// Example3_Pet��(��) ���� ��ӵ�
	virtual void Sound() override
	{ cout << "�����Ҹ�: ��ī��ī"; }
	virtual void Eat() override
	{ cout << "����: ���ϸ� ����"; }
};
#pragma endregion
#pragma region Example3_Overloading
int Add(int a, int b) { return a + b; }
float Add(float a, int b) { return a + b; }
float Add(int a, float b) { return a + b; }
float Add(float a, float b) { return a + b; }
#pragma endregion


// 4) �߻�ȭ(Abstraction)
//    - ����: ����� ����� ��� �߻������� ǥ���ϴ� �𵨸� ���.
//	    
//	  - �ʿ伺:
//      ��ü���� ���α׷��ֿ����� ���� �ذ��� ���� ��ü�� �����ϰ�,
//      �̵��� �������� Ư¡�� �Ӽ�(��� ����)�� ���(��� �Լ�)���� �����Ͽ� Ŭ������ ǥ���ϱ� ���� �ʿ��ϴ�.
//
//	  - ����: 1) �Ʒ��� ���� �л��鿡 ���� �������� Ư¡�� ��� ������ ������ ������(������ �߻�ȭ).
//               * main �Լ� ����(�迭�� ���� ������ �������� ��).
//            2) �߻� Ŭ����, �������̽� ��(���μ��� �߻�ȭ).
#pragma region Example4
class Student
{
public:
	const string Name;					// �̸�
	const string Gender;				// ����
	unsigned int Grade;					// �г�
	unsigned int ClassNum;				// ��
	unsigned int StudentNum;			// �⼮ ��ȣ

	Student(string name, string gender, int grade, int classNum, int studentNum) :
		Name(name), Gender(gender), Grade(grade), ClassNum(classNum), StudentNum(studentNum)
	{}
};
#pragma endregion


int main()
{
	printf("����2) ��Ӽ�\n");
	Example2_Derived Derived;
	Derived.print();
	printf("Derived.var3: %i\n", Derived.var3);
	printf("\n");

	printf("����3-1) ������-�������̵�\n");
	Example3_Dog myDog;
	myDog.Name = "������";
	Example3_Cat myCat;
	myCat.Name = "�߿���";
	Example3_Pikachu myPikachu;
	myPikachu.Name = "��ī��";
	IExample3_Pet* myPets[3] = { &myDog, &myCat, &myPikachu };
	for (int i = 0; i < 3; i++)
	{
		printf("%i�� �ֿϵ���: %s / ", i + 1, myPets[i]->Name.c_str());
		myPets[i]->Sound();
		printf(" / ");
		myPets[i]->Eat();
		printf("\n");
	}
	printf("\n");

	printf("����3-2) ������-�����ε�\n");
	printf("Add(%i   , %i   ) == %i\n", 1, 2, Add(1, 2));
	printf("Add(%.2f, %i   ) == %.2f\n", 1.2f, 2, Add(1.2f, 2));
	printf("Add(%i   , %.2f) == %.2f\n", 1, 2.5f, Add(1, 2.5f));
	printf("Add(%.2f, %.2f) == %.2f\n", 1.2f, 2.5f, Add(1.2f, 2.5f));

	// ����4) �߻�ȭ
	// �迭�� ���� �л��� �����͸� �����ϴ� ��� -> ���ο� �л��� ���� ������ �߰��� �Ϸ��� �ڵ� ��ü ������ �ʿ��ϴ�.
	string Name[2] = { "��۰�" , "�ڼҶ�" };
	string Gender[2] = { "��", "��" };
	unsigned int Grade[2] = { 3, 1 };
	unsigned int ClassNum[2] = { 2, 5 };
	unsigned int StudentNum[2] = { 1, 21 };

	// �߻�ȭ�� ���� Ŭ������ �����ϰ� �ν��Ͻ�ȭ �Ͽ� �л��� �����͸� �����ϴ� ��� -> ��ü�� �߰��� �����ϱ⸸ �ϸ� �ȴ�.
	Student student1("��۰�", "��", 3, 2, 1);
	Student student2("�ڼҶ�", "��", 1, 5, 21);
	Student student3("�̸�����", "��", 2, 1, 1);
	// ����) "�̸�����" �л��� ���� �����ϴ� �͵� �����ϴ�.
	student3.ClassNum = 2;

	return 0;
}