// 2022-08-05 ����
// Map Ŭ���� ���ø��� ������ ����� �ϴ� Ŭ���� ���ø� ����

#include "MapClassTemplate_BeomheeKim.h"
using namespace std;

int main()
{
	Map<string, string> map;

	// Insert() �޼ҵ�: pair Ŭ���� ���ø� ������ ��Ҹ� �߰��� �� ������, ���ÿ� key�� ���������Ͽ� ���������� container ���θ� ����,
	//                  ������ key�� ���� �ű� ��Ұ� container�� �߰����� �ʵ��� �޼ҵ带 ����
	pair<string, string> apple = pair<string, string>("���", "apple");
	map.Insert(apple);

	map.Insert(pair<string, string>("���2", "melon2"));
	map.Insert(pair<string, string>("���3", "melon3"));
	map.Insert(pair<string, string>("���4", "melon4"));
	map.Insert(pair<string, string>("���1", "melon1"));

	// Length(), Size() �޼ҵ�
	cout << "sizeof(pair<string, string>) == " << sizeof(pair<string, string>) << endl;		// pair Ŭ���� ũ��(�����)
	cout << "map.Length() == " << map.Length() << endl;
	cout << "map.Size() == " << map.Size() << endl;
	cout << endl;

	// Print() �޼ҵ�: ��� ��� ���
	map.Print();
	cout << endl;

	// iterator ��ü ������ ���ؼ� �ܼ� �����ͷ� ��ȯ�ϵ��� begin, end, find �޼ҵ� ����
	// begin() �޼ҵ�: container ���� ù��° ��Ҹ� ����Ű�� �����͸� ��ȯ.
	// end() �޼ҵ�: container ���� ������ ����� ���� �ּҸ� ����Ű�� �����͸� ��ȯ.
	// find() �޼ҵ�: �ش� key�� ���� ��Ҹ� ã���� �ش� ��Ҹ� ����Ű�� �����͸� ��ȯ,
	//                ã�� ���ϴ� ��쿡�� ������ ����� ���� �ּҸ� ����Ű�� �����͸� ��ȯ
	cout << "map.begin() == " << (long long)map.Begin() << endl;
	cout << "map.end()   == " << (long long)map.End() << endl;
	cout << "map.find(\"���\") == " << (long long)map.Find("���") << endl;
	cout << "map.find(\"�ٺ�\") == " << (long long)map.Find("�ٺ�") << endl;
	cout << endl;

	// Erase() �޼ҵ�
	map.Print();
	map.Erase("�ٳ���");		// �������� �ʴ� key�� erase �� ��
	cout << endl;

	map.Erase("���3");		// �����ϴ� key�� erase �� ��
	map.Print();
	cout << endl;

	// At() �޼ҵ�, �ε��� ������ �����ε�
	cout << "map.At(\"���2\") == " << map.At("���2") << endl;
	cout << "map[\"���2\"] == " << map["���2"] << endl;
	cout << endl;

	// Empty() �޼ҵ�
	if (map.Empty()) printf("container�� empty �����Դϴ�.\n");
	else printf("container�� empty ���°� �ƴմϴ�.\n");
	cout << "map.Length() == " << map.Length() << endl;
	cout << endl;

	// Clear() �޼ҵ�
	map.Clear();
	if (map.Empty()) printf("container�� empty �����Դϴ�.\n");
	else printf("container�� empty ���°� �ƴմϴ�.\n");
	cout << "map.Length() == " << map.Length() << endl;
	cout << endl;

	return 0;
}
