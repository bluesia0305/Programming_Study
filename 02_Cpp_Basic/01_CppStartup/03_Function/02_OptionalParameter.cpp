// 2022-06-30 수업


#include <iostream>
using namespace std;

// 선택적 매개변수(Optional parameter)
// : 매개변수에 값이 전달이 되지 않을 때의 default 값을 초기화하며 매개변수를 사용할 수 있는 기능.
//   * 반드시 필수 매개변수보다 뒤에 작성해야한다(단, 개수는 무제한임).

void Print(int integer1, int integer2 = 0)
{
	cout << integer1 << endl;
	if (integer2) cout << integer2 << endl;
}

void Print(float float_1 = 0, float float_2 = 0, float float_3 = 0)
{ cout << float_1 << " : " << float_2 << " : " << float_3 << endl; }

int main()
{
	Print(1);
	Print(1, 2);
	Print();
	Print(1.1f);
	Print(1.1f, 2.2f);
	Print(1.1f, 2.2f, 3.3f);
	
	return 0;
}