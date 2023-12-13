// 2022-06-09 수업(계속)


// 문자열(String)
// : 문자로 이루어진 데이터의 배열.
//   문자 데이터를 표현하기 위한 자료형으로는 char를 사용함.


#include <iostream>
#pragma warning(disable : 4996)

int main()
{
	std::cout << "1) 문자 데이터의 표현." << std::endl;
	'A';											// !! 주의) 문자의 표현은 따옴표를 이용하여 이루어짐.
	char myChar = 'A';

	std::cout << myChar << std::endl;
	printf("%c\n\n", myChar);						// %c: 문자열을 표현하기 위한 형식지정자.

	std::cout << "2-1) 문자열의 선언 및 출력." << std::endl;
	// 문자열의 선언 방법은 아래의 예시와 같이 길이와 각 인덱스별 문자를 초기화하거나 (위)
	// 길이를 지정해주지 않고, 문자열을 쌍따옴표로 구분하여 초기화할 수 있음 (아래).
	char myStr1[5] = { 'H', 'e', 'l', 'l', 'o' };
	char myStr2[] = "Hello";						// !! 주의) 문자열의 표현은 쌍따옴표를 이용하여 이루어짐.
													// 쌍따옴표를 이용한 선언에서 문자열의 끝을 구분하기 위한
													// NULL 문자('\0', ASCII 코드: 0)가 선언 시에 문자열의 끝에 자동으로 붙어서 초기화 됨.
	
	//myStr2[] = "Mello";							// !! 주의) 문자열 선언 이후 한 번에 다시 초기화하는 것은 불가능함.
	myStr2[0] = 'M';								// 인덱스별로 하나씩 초기화는 가능.
	for (int i = 0; i < 5; i++)
	{
		std::cout << myStr1[i];
	}
	std::cout << std::endl;
	printf("myStr1     : %s\n", myStr1);
	printf("myStr1 size: %zi\n", sizeof(myStr1));
	printf("myStr2     : %s\n", myStr2);
	printf("myStr2 size: %zi\n\n", sizeof(myStr2));

	std::cout << "2-2) 문자열 선언 시, 선언한 길이보다 초기화 하는 값의 수가 적은 경우." << std::endl;
	char myStr3[7] = { 'H', 'e', 'l', 'l' };
	myStr3[6] = 'o';
	printf("myStr3     : %s\n", myStr3);
	printf("myStr3[4]  : %i\n", myStr3[4]);			// 0 (= '\0')으로 초기화가 됨.
	printf("myStr3[6]  : %c\n\n", myStr3[6]);

	std::cout << "2-3) NULL 문자에 대한 이해를 위한 예시." << std::endl;
	char myStr4[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char myStr5[] = "Hell\0o";
	printf("myStr4     : %s\n", myStr4);
	printf("myStr4 size: %zi\n", sizeof(myStr4));
	printf("myStr5     : %s\n", myStr5);
	printf("myStr5 size: %zi\n\n", sizeof(myStr5));

	std::cout << "3) 문자열 데이터의 입출력(문자열 내에 공백(space)이 있는 경우도 시도해보기)." << std::endl;
	char inputStr[256] = { 0 };
	printf("입력1: ");
	// 문자열 데이터를 입력받을 때(scanf)에는 주소를 보내주지 않아도 됨.
	scanf("%s", inputStr);
	printf("출력1: %s\n", inputStr);
	printf("size: %zi\n\n", sizeof(inputStr));

	std::cout << "입력2: ";
	std::cin >> inputStr;
	std::cout << "출력2: " << inputStr << std::endl;
	std::cout << "size: " << sizeof(inputStr) << std::endl << std::endl;

	// scanf와 cin의 작동 방식
	// : Enter 키를 눌렀을 때, 즉 개행 문자('\n')를 입력받을 시 입력을 종료함.
	//   입력받은 문자열을 저장할 땐 버퍼(buffer)에 남아있는 공백 문자를 기준으로 데이터를 저장함.
	//   따라서, 공백 문자를 입력받고자 할 때에는 아래와 같은 방법을 사용해야 함.
	std::cout << "4) 문자열 내에 공백(space)이 있는 문자열을 입력받는 방법." << std::endl;
	char myStr6[] = "Hello World";
	printf("선언 당시에 공백을 포함한 문자열의 출력: %s\n", myStr6);
	char myStr7[256] = { 0 };
	
	// 그냥 공백문자 출력 예시)
	// getchar();
	// : 버퍼에 남아있는 데이터를 하나씩 가져오는 함수.
	/*for (int i = 0; i < 6; i++)
	{
		printf("%c", getchar());
	}
	printf("\n");
	printf("%s", myStr6)*/

	while (getchar() != '\n');		// 버퍼에 남아있는 문자열을 모두 지우기 위한 명령문(앞에서 한 번이라도 입력을 받았다면 필수로 해야함).
	printf("입력3: ");
	scanf("%[^\n]s", myStr7);		// %[^\n]s: 개행 문자만을 기준으로 하여 버퍼에 있는 데이터를 저장하기 위한 형식 지정자.
	printf("출력3: %s\n\n", myStr7);

	while (getchar() != '\n');		// 버퍼에 남아있는 문자열을 모두 지우기 위한 명령문(앞에서 한 번이라도 입력을 받았다면 필수로 해야함).
	std::cout << "입력: ";
	// std::cin.getline( 입력받은 문자열을 저장할 배열, 배열의 크기, 저장을 구분할 문자);
	// getline을 이용하여 공백을 이용한 문자열을 입력할 경우, 자동적으로 입력 후 버퍼에 남은 데이터를 제거함.
	std::cin.getline(myStr7, sizeof(myStr7), '\n');
	std::cout << "출력: " << myStr7 << std::endl;

	return 0;
}