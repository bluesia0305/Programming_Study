// 2022-07-29 ����


#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
using namespace std;

// <2022-08-04 ��������>
// 1. ��ǰ ��� �ݺ��� �Ϻ� ����(input�� �ڷ����� int -> string ���� ����)
// 2. (�˸�) �޼��� �߰�

void VectorPrint(vector<string> vector)
{
	cout << "<������ ���� ����Ʈ>" << endl;
	cout << endl;

	if (!vector.empty())
	{
		int i = 1;
		for (auto iter = vector.begin(); iter != vector.end(); iter++, i++)
			printf("%i. %s\n", i, (*iter).c_str());
	}

	cout << endl;
	cout << "-------------------------" << endl;
}

void MapPrint(map<string, unsigned> map)
{
	cout << "<������ �Ǹ� ��ǰ>" << endl;
	cout << endl;

	if (!map.empty())
	{
		int i = 1;
		for (auto iter = map.begin(); iter != map.end(); iter++, i++)
			printf("%i. %-8s: %i ��\n", i, iter->first.c_str(), iter->second);
	}

	cout << endl;
	cout << "-------------------------" << endl;
}

int main()
{
	map<string, unsigned> itemList;
	
	while (true)
	{
		system("cls");
		cout << "<�Ǹ��� ���� �߰��ϱ�>" << endl << endl;
		cout << "������� �߰��� ������ ����: " << itemList.size() << "��" << endl << endl;
		cout << "1. �Ǹ��� ������ �߰��Ѵ�." << endl;
		cout << "2. �ǸŸ� �����Ѵ�." << endl;

		string input;
		cout << "�Է�[1, 2]: ";
		cin >> input;
		if (input == "2")
		{
			cout << endl << "(�˸�) �ǸŸ� �����մϴ�..." << endl;
			break;
		}
		else if (input == "1")
		{
			string item = "����";
			unsigned price;

			while (item == "����")
			{
				system("cls");
				cout << "�Ǹ��� ������ �Է��ϼ���: ";
				cin >> item;
				if (item == "����")
				{
					cout << "(�˸�) �ش� �̸����δ� �Ǹ��� ������ ������ �� �����ϴ�. �ٸ� �̸��� �Է����ּ���." << endl;
					Sleep(1000);
				}
				else
				{
					printf("\'%s\'�� ����(��)�� �������ּ��� : ", item.c_str());
					cin >> price;
					itemList.insert(pair<string, unsigned>(item, price));
				}
			}
		}
		else
		{
			cout << endl << "(�˸�) ���� 1, �Ǵ� 2 �߿����� �Է����ּ���." << endl;
			Sleep(1000);
		}
	}

	system("pause");
	vector<string> purchaseList;
	unsigned money = 10000;

	while (true)
	{
		string item = "";

		system("cls");
		MapPrint(itemList);
		cout << endl;

		printf("������ ������ ����: %zi\n", purchaseList.size());
		printf("������: %i ��\n\n", money);

		if (itemList.empty())
		{
			cout << "(�˸�) ������ �Ǹ��� ������ �������� �ʾ� ���Ű� ����˴ϴ�..." << endl;
			break;
		}

		printf("���� ����� \'����\'�� �Է��Ͻø� �˴ϴ�(\',\' ����).\n");
		printf("� ������ �����Ͻðڽ��ϱ�? >> ");
		cin >> item;
		
		if (item == "����")
		{
			cout << endl << "(�˸�) ���Ÿ� �����մϴ�..." << endl;
			break;
		}
		else
		{
			auto iter = itemList.find(item);
			if (iter != itemList.end())
			{
				if (money >= iter->second)
				{
					money -= iter->second;
					purchaseList.push_back(item);
					itemList.erase(item);
					printf("\n\'%s\'(��)�� �����Ͽ����ϴ�.\n", item.c_str());
					Sleep(1000);
				}
				else
				{
					cout << "�������� �����մϴ�." << endl;
					Sleep(1000);
				}
			}
			else
			{
				printf("\'%s\'(��)�� �Ǹ����� �ʽ��ϴ�. ������ ������ �̸��� �ٽ� �Է����ּ���.\n", item.c_str());
				Sleep(1000);
			}
		}
	}
	system("pause");
	system("cls");
	VectorPrint(purchaseList);

	return 0;
}