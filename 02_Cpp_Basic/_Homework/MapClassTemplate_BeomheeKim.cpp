// 2022-08-05 과제
// Map 클래스 템플릿과 유사한 기능을 하는 클래스 템플릿 구현

#include "MapClassTemplate_BeomheeKim.h"
using namespace std;

int main()
{
	Map<string, string> map;

	// Insert() 메소드: pair 클래스 템플릿 형식의 요소를 추가할 수 있으며, 동시에 key를 기준으로하여 사전순으로 container 내부를 정렬,
	//                  동일한 key를 갖는 신규 요소가 container에 추가되지 않도록 메소드를 정의
	pair<string, string> apple = pair<string, string>("사과", "apple");
	map.Insert(apple);

	map.Insert(pair<string, string>("멜론2", "melon2"));
	map.Insert(pair<string, string>("멜론3", "melon3"));
	map.Insert(pair<string, string>("멜론4", "melon4"));
	map.Insert(pair<string, string>("멜론1", "melon1"));

	// Length(), Size() 메소드
	cout << "sizeof(pair<string, string>) == " << sizeof(pair<string, string>) << endl;		// pair 클래스 크기(참고용)
	cout << "map.Length() == " << map.Length() << endl;
	cout << "map.Size() == " << map.Size() << endl;
	cout << endl;

	// Print() 메소드: 모든 요소 출력
	map.Print();
	cout << endl;

	// iterator 객체 구현은 못해서 단순 포인터로 반환하도록 begin, end, find 메소드 구현
	// begin() 메소드: container 내의 첫번째 요소를 가리키는 포인터를 반환.
	// end() 메소드: container 내의 마지막 요소의 다음 주소를 가리키는 포인터를 반환.
	// find() 메소드: 해당 key를 갖는 요소를 찾으면 해당 요소를 가리키는 포인터를 반환,
	//                찾지 못하는 경우에는 마지막 요소의 다음 주소를 가리키는 포인터를 반환
	cout << "map.begin() == " << (long long)map.Begin() << endl;
	cout << "map.end()   == " << (long long)map.End() << endl;
	cout << "map.find(\"사과\") == " << (long long)map.Find("사과") << endl;
	cout << "map.find(\"바보\") == " << (long long)map.Find("바보") << endl;
	cout << endl;

	// Erase() 메소드
	map.Print();
	map.Erase("바나나");		// 존재하지 않는 key를 erase 할 때
	cout << endl;

	map.Erase("멜론3");		// 존재하는 key를 erase 할 때
	map.Print();
	cout << endl;

	// At() 메소드, 인덱스 연산자 오버로딩
	cout << "map.At(\"멜론2\") == " << map.At("멜론2") << endl;
	cout << "map[\"멜론2\"] == " << map["멜론2"] << endl;
	cout << endl;

	// Empty() 메소드
	if (map.Empty()) printf("container가 empty 상태입니다.\n");
	else printf("container가 empty 상태가 아닙니다.\n");
	cout << "map.Length() == " << map.Length() << endl;
	cout << endl;

	// Clear() 메소드
	map.Clear();
	if (map.Empty()) printf("container가 empty 상태입니다.\n");
	else printf("container가 empty 상태가 아닙니다.\n");
	cout << "map.Length() == " << map.Length() << endl;
	cout << endl;

	return 0;
}
