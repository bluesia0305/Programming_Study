// 2022-07-29 과제


#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
using namespace std;

// <2022-08-04 수정사항>
// 1. 물품 등록 반복문 일부 수정(input의 자료형을 int -> string 으로 수정)
// 2. (알림) 메세지 추가

void VectorPrint(vector<string> vector)
{
	cout << "<구매한 물건 리스트>" << endl;
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
	cout << "<상점의 판매 물품>" << endl;
	cout << endl;

	if (!map.empty())
	{
		int i = 1;
		for (auto iter = map.begin(); iter != map.end(); iter++, i++)
			printf("%i. %-8s: %i 원\n", i, iter->first.c_str(), iter->second);
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
		cout << "<판매할 물건 추가하기>" << endl << endl;
		cout << "현재까지 추가한 물건의 갯수: " << itemList.size() << "개" << endl << endl;
		cout << "1. 판매할 물건을 추가한다." << endl;
		cout << "2. 판매를 시작한다." << endl;

		string input;
		cout << "입력[1, 2]: ";
		cin >> input;
		if (input == "2")
		{
			cout << endl << "(알림) 판매를 시작합니다..." << endl;
			break;
		}
		else if (input == "1")
		{
			string item = "종료";
			unsigned price;

			while (item == "종료")
			{
				system("cls");
				cout << "판매할 물건을 입력하세요: ";
				cin >> item;
				if (item == "종료")
				{
					cout << "(알림) 해당 이름으로는 판매할 물건을 설정할 수 없습니다. 다른 이름을 입력해주세요." << endl;
					Sleep(1000);
				}
				else
				{
					printf("\'%s\'의 가격(원)을 설정해주세요 : ", item.c_str());
					cin >> price;
					itemList.insert(pair<string, unsigned>(item, price));
				}
			}
		}
		else
		{
			cout << endl << "(알림) 숫자 1, 또는 2 중에서만 입력해주세요." << endl;
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

		printf("구매한 물건의 갯수: %zi\n", purchaseList.size());
		printf("소지금: %i 원\n\n", money);

		if (itemList.empty())
		{
			cout << "(알림) 상점에 판매할 물건이 존재하지 않아 구매가 종료됩니다..." << endl;
			break;
		}

		printf("구매 종료는 \'종료\'를 입력하시면 됩니다(\',\' 제외).\n");
		printf("어떤 물건을 구매하시겠습니까? >> ");
		cin >> item;
		
		if (item == "종료")
		{
			cout << endl << "(알림) 구매를 종료합니다..." << endl;
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
					printf("\n\'%s\'(을)를 구매하였습니다.\n", item.c_str());
					Sleep(1000);
				}
				else
				{
					cout << "소지금이 부족합니다." << endl;
					Sleep(1000);
				}
			}
			else
			{
				printf("\'%s\'(은)는 판매하지 않습니다. 구매할 물건의 이름을 다시 입력해주세요.\n", item.c_str());
				Sleep(1000);
			}
		}
	}
	system("pause");
	system("cls");
	VectorPrint(purchaseList);

	return 0;
}