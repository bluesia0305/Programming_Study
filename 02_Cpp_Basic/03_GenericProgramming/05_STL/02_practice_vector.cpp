// 2022-07-28 ����


#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

// (�ǽ�) �� ���� �ۼ��ϴ� ����Ʈ�� �����

int main()
{
	vector<string> todoList;
	// iter�� ���� ���ÿ� vector.begin(); �� �ʱ�ȭ�� ���� Ÿ�� �߷������� ���� ������.
	vector<string>::iterator iter;
	string work;
	while (work != "����")
	{
		cout << "�� ���� �Է��ϼ��� : ";
		cin >> work;
		if (work != "����") todoList.push_back(work);
	}
	cout << endl;

	while (!todoList.empty())
	{
		system("cls");
		cout << "<�Է� ���� List>" << endl;
		
		// �Ʒ� ������ �ݺ��� ���� ���� �ٸ��� �� ����: ��ȣ ����Ϸ���...
		// * �� ��� �ܿ��� �ʱ��, �����Ŀ� ���� ���� �����ϴ� ������� �����ϴٸ� �׷��� �ڵ��ص� ��.
		//   (��, ���� �ڷ����� ������ ���� �����ϸ�, �� �� �̻��� ������ ','�� ���� ���� ������)
		for (int i = 0; i < todoList.size(); i++)
		{ cout << i + 1 << ". " << todoList[i] << endl; }


		cout << "� ���� �����Ͻðڽ��ϱ�? ";
		cin >> work;

		bool isFind = false;
		for (iter = todoList.begin(); iter != todoList.end(); iter++)
		{
			if (*iter == work)
			{
				todoList.erase(iter++);
				isFind = true;
				break;
			}
		}

		if (!isFind)
		{
			cout << work << " (��)�� ���� ���� ��Ͽ� �����ϴ�." << endl;
			Sleep(1000);
		}
	}

	system("cls");
	cout << "��� ������ �������ϴ�." << endl;

	return 0;
}