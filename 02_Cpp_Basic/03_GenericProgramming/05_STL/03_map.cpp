// 2022-07-29 ����


#include <iostream>
#include <map>

int main()
{
	// map: key�� value�� ��Ҹ� �����Ͽ� �����ϴ� ���� �����̳�. map ���̺귯���� ������ �� ��� �����ϴ�.
	//      * key�� �ߺ��� ������� �ʴ´�(�����̳� �� �ϳ��� key�� ���� ����).
	//      * ���ø� ���� �߿��� ������ key�� �ڷ����̸�, �������� value�� �ڷ����̴�.
	//      * pair ������ ��ҵ�� �̷����.
	std::map<std::string, std::string> fruits;
	
	// pair: �� �����͸� �ϳ��� ������ ���� ��ü�� ����� �� �ִ� Ŭ���� ���ø�.
	std::pair<std::string, std::string> orange;
	orange.first = "Orange";		// ������� first  == key
	orange.second = "������";		// ������� second == value

	// insert(pair): pair ������ ��Ҹ� �����̳ʿ� �߰��ϴ� �޼ҵ�.
	fruits.insert(orange);

	// �����̳ʿ� ��Ҹ� �߰��ϴ� ���� ���.
	fruits.insert(std::make_pair("Apple", "���"));							// std::make_pair(data1, data2): �Լ�.
	fruits.insert(std::pair<std::string, std::string>("Melon", "���"));		// �����ڸ� �̿��Ͽ� �����̳ʿ� ��Ҹ� �߰��ϴ� ���.

	// ��Ҹ� �߰��� ������ ��µǴ� ����(begin -> end)�� Ȯ���غ���
	std::cout << "1) �ݺ��ڰ� �����̳� ���� ��ҵ��� Ž���ϴ� ���� Ȯ��." << std::endl;
	std::map<std::string, std::string>::iterator iter = fruits.begin();
	for (; iter != fruits.end(); iter++)
		std::cout << iter->first << " : " << iter->second << std::endl;
	std::cout << std::endl;

	// at(key): �ش� key�� ������ �ִ� value�� ã�� ��ȯ�ϴ� �޼ҵ�.
	std::cout << "2) ������ �����ε�." << std::endl;
	std::cout << "fruits.at(\"Apple\") == " << fruits.at("Apple") << std::endl;
	std::cout << "fruits[\"Apple\"] == " << fruits["Apple"] << std::endl;			// �ε��� ������ �����ε�(index ��� key �Է� ����).
	std::cout << std::endl;

	// erase(key), begin(), end(), clear(), empty(), size() ���� �޼ҵ� ���� vector������ ������(�Ǵ� ������) ����� �����ϵ��� ���ǵǾ�����.
	std::cout << "3) ��Ÿ �޼ҵ� ��� ���õ�." << std::endl;
	fruits.erase("Apple");
	for (auto iter = fruits.begin(); iter != fruits.end(); iter++)
		std::cout << iter->first << " : " << iter->second << std::endl;
	std::cout << std::endl;

	// find(key): �ش� key�� ������ �ִ� ��Ҹ� ã�´ٸ� �ش� ��ġ�� ��ȯ�ϰ�, ã�� ���� ��� end()�� ��ȯ�ϴ� �޼ҵ�.
	iter = fruits.find("Melon");
	if (iter == fruits.end()) std::cout << "\"Melon\"(��)�� key�� ���� ��Ұ� �������� �ʽ��ϴ�." << std::endl;
	else std::cout << iter->first << " : " << iter->second << std::endl;

	return 0;
}