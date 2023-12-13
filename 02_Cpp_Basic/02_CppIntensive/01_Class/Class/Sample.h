#pragma once

// ���� �߿����� �̷��� ������ ������ ���� �ǹ� ���� ����������
// Ŭ������ ���� ��� ����(.h)�� CPP ����(.cpp)�� ������ ������.
// * �̶�, �� ������ �̸��� �޶� ����� ������ ��������� �̸��� ���� �ϴ� ���� ó���ӵ�/���� ���� ���鿡�� ����.

// ��� ����: Ŭ������ ����, ��� ���� �� �Լ��� ����, �ζ��� �Լ� ����.
// CPP ����: ��� �Լ��� ����.

class Sample
{
private:
	int A = 10;
	int B = 20;

public:
	// �Լ��� ���� �κ��� ������ �ҽ� �ڵ� ���Ϸ� �Ű� �����ϴ� ���
	// -> ���ǵ��� ���� �Լ��� �巡���� ��, Ctrl + '.' ����
	//    '���� / ���� �����'�� Ŭ��.
	void Print() const;
	void Print1() const;
	void Print2() const;
	void Print3() const;
	void Print4() const;
	void Print5() const;
	void Print6() const;

	__forceinline void SetA(int a) { A = a; }
	__forceinline void SetB(int b) { B = b; }
};

