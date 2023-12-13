// 2022-07-19 ¼ö¾÷


#include "02_Class.h"
using namespace std;

int main()
{
	Template<int> temp = Template<int>(10, 20);
	temp.Print();

	Template<double> temp2 = Template<double>(3.14, 3.15);
	temp2.Print();

	return 0;
}