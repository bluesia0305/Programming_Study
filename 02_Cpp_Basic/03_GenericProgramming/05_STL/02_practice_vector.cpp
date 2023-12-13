// 2022-07-28 수업


#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

// (실습) 할 일을 작성하는 리스트를 만들기

int main()
{
	vector<string> todoList;
	// iter를 선언 동시에 vector.begin(); 로 초기화할 때는 타입 추론형으로 선언 가능함.
	vector<string>::iterator iter;
	string work;
	while (work != "종료")
	{
		cout << "할 일을 입력하세요 : ";
		cin >> work;
		if (work != "종료") todoList.push_back(work);
	}
	cout << endl;

	while (!todoList.empty())
	{
		system("cls");
		cout << "<입력 받은 List>" << endl;
		
		// 아래 루프랑 반복문 제어 변수 다르게 한 이유: 번호 출력하려고...
		// * 이 방법 외에도 초기식, 증감식에 여러 변수 선언하는 방법으로 가능하다면 그렇게 코딩해도 됨.
		//   (단, 같은 자료형의 변수일 때만 가능하며, 두 개 이상의 변수는 ','를 통해 구분 가능함)
		for (int i = 0; i < todoList.size(); i++)
		{ cout << i + 1 << ". " << todoList[i] << endl; }


		cout << "어떤 일을 수행하시겠습니까? ";
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
			cout << work << " (은)는 현재 할일 목록에 없습니다." << endl;
			Sleep(1000);
		}
	}

	system("cls");
	cout << "모든 할일이 끝났습니다." << endl;

	return 0;
}