// 2022-07-29 수업


#include <iostream>
#include <map>

int main()
{
	// map: key와 value로 요소를 구분하여 저장하는 연관 컨테이너. map 라이브러리를 포함한 뒤 사용 가능하다.
	//      * key의 중복을 허용하지 않는다(컨테이너 당 하나의 key만 존재 가능).
	//      * 템플릿 인자 중에서 왼쪽이 key의 자료형이며, 오른쪽이 value의 자료형이다.
	//      * pair 형식의 요소들로 이루어짐.
	std::map<std::string, std::string> fruits;
	
	// pair: 두 데이터를 하나의 쌍으로 묶은 객체를 사용할 수 있는 클래스 템플릿.
	std::pair<std::string, std::string> orange;
	orange.first = "Orange";		// 멤버변수 first  == key
	orange.second = "오렌지";		// 멤버변수 second == value

	// insert(pair): pair 형식의 요소를 컨테이너에 추가하는 메소드.
	fruits.insert(orange);

	// 컨테이너에 요소를 추가하는 여러 방법.
	fruits.insert(std::make_pair("Apple", "사과"));							// std::make_pair(data1, data2): 함수.
	fruits.insert(std::pair<std::string, std::string>("Melon", "멜론"));		// 생성자를 이용하여 컨테이너에 요소를 추가하는 방법.

	// 요소를 추가한 순서와 출력되는 순서(begin -> end)를 확인해보기
	std::cout << "1) 반복자가 컨테이너 내의 요소들을 탐색하는 순서 확인." << std::endl;
	std::map<std::string, std::string>::iterator iter = fruits.begin();
	for (; iter != fruits.end(); iter++)
		std::cout << iter->first << " : " << iter->second << std::endl;
	std::cout << std::endl;

	// at(key): 해당 key를 가지고 있는 value를 찾아 반환하는 메소드.
	std::cout << "2) 연산자 오버로딩." << std::endl;
	std::cout << "fruits.at(\"Apple\") == " << fruits.at("Apple") << std::endl;
	std::cout << "fruits[\"Apple\"] == " << fruits["Apple"] << std::endl;			// 인덱스 연산자 오버로딩(index 대신 key 입력 가능).
	std::cout << std::endl;

	// erase(key), begin(), end(), clear(), empty(), size() 등의 메소드 역시 vector에서와 동일한(또는 유사한) 기능을 수행하도록 정의되어있음.
	std::cout << "3) 기타 메소드 사용 예시들." << std::endl;
	fruits.erase("Apple");
	for (auto iter = fruits.begin(); iter != fruits.end(); iter++)
		std::cout << iter->first << " : " << iter->second << std::endl;
	std::cout << std::endl;

	// find(key): 해당 key를 가지고 있는 요소를 찾는다면 해당 위치를 반환하고, 찾지 못할 경우 end()를 반환하는 메소드.
	iter = fruits.find("Melon");
	if (iter == fruits.end()) std::cout << "\"Melon\"(을)를 key로 갖는 요소가 존재하지 않습니다." << std::endl;
	else std::cout << iter->first << " : " << iter->second << std::endl;

	return 0;
}