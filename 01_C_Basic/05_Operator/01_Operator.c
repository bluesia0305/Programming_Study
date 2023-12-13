// 2022-05-26 수업


// 연산자(Operator)
// : 특정 데이터에 대한 연산 결과를 반환해주는 기능을 가짐.
//   * 반환: 연산 결과에 대한 데이터를 돌려주는 것을 의미함.

// 비트연산자(Bit operator)
// : Bit에 대한 연산을 해주는 연산자.


#include <stdio.h>
#include <string.h>

#pragma region Binary
#pragma warning(disable : 4996) // 에러코드 4996에 해당하는 에러를 무시하기 위한 소스 코드.

void GetBinary(char value)		// 십진수를 이진수로 변환하여 콘솔 상에 출력해주는 함수.
{
	static char b[9];
	b[0] = '\0';

	// for loop
	// for ( (initialization_statement); (test_expression); (update_statement) );
	for (int z = 128; z > 0; z >>= 1)
		// 삼항연산자(ternary operator)
		// (조건) ? (값 A) : (값 B)
		// : (조건)이 true일 경우 (값 A), false일 경우 (값 B)를 출력함.
		
		// strcat(variable, string);
		// : string variable에 입력받은 string을 이어붙이는 함수.
		strcat(b, ((value & z) == z) ? "1" : "0");

	printf("%d\t== %s\n", value, b);
}
#pragma endregion

int main()
{
	// 왼쪽, 오른쪽 시프트 연산자 (<<, >>)
	// : value의 비트를 왼쪽(또는 오른쪽)으로 n만큼 이동함.
	
	// 오른쪽 시프트 연산자의 경우,
	// 이동했을 때 자리를 넘어가는 비트의 데이터는 무조건 사라지고
	// 이때, 채워지는 부분은 양수의 경우 0, 음수의 경우 1로 채워짐(부호 비트 유지 정책).
	// * 단, unsigned 자료형의 경우에는 무조건 0으로만 채워짐.
	char value_1 = 3;				// signed 자료형에서 양수의 경우 어떻게 시프팅 되는지 확인.
	GetBinary(value_1);
	GetBinary(value_1 >> 1);
	printf("\n");

	char value_2 = -3;				// signed 자료형에서 음수의 경우 어떻게 시프팅 되는지 확인.
	GetBinary(value_2);
	GetBinary(value_2 >> 2);
	printf("\n");

	unsigned char value_3 = 255;	// unsigned 자료형에서 어떻게 시프팅 되는지 확인.
	GetBinary(value_3);
	GetBinary(value_3 >> 2);
	printf("-------------------\n");

	// 왼쪽 시프트 연산자의 경우에는 항상 0으로 채워짐.
	// * 부호 비트 유지 정책을 적용하지 않음.
	char value_4 = 10;
	GetBinary(value_4);
	GetBinary(value_4 << 4);
	printf("-------------------\n");

	// NOT 연산자(~): 주어진 value의 비트를 0은 1로, 1은 0으로 반전시키는 기능을 함.
	// * 부호 비트 유지 정책을 적용하지 않음.
	char value_5 = -1;
	GetBinary(value_5);
	GetBinary(~value_5);
	printf("-------------------\n");


	// (실습)
	// * 비트 이동연산은 실제로 잘 쓰이지는 않지만, 기술 면접에 나옴.
	signed char mySigned = 1;
	unsigned char myUnsigned = 1;
	// 위의 mySigned, myUnsigned, 비트 연산자를 사용하여
	// signed char와 unsigned char의 최댓값을 출력해주세요.
	// 또한, signed char의 최솟값을 출력해주세요.
	
	// signed char의 최댓값 (= 127 = 01111111 (2)).
	GetBinary(~(mySigned << 7));
	// unsigned char의 최댓값 (= 255 = 11111111 (2)).
	GetBinary(~(myUnsigned >> 1));
	// signed char의 최솟값 (= -128 = 10000000 (2)).
	GetBinary(mySigned << 7);
	printf("-------------------\n");

	// 비트 AND 연산자(= 논리곱 AND 연산자, &)
	// 각 자리의 비트를 비교하여 둘 다 1이라면 1로, 하나라도 1이 아니라면 0을 반환하는 연산자.
	GetBinary(50);
	GetBinary(70);
	GetBinary(50 & 70);
	printf("-------------------\n");

	// 비트 OR 연산자(= 논리합 OR 연산자, |)
	// 각 자리의 비트 중 어느 하나라도 1일 경우 1로, 둘 다 0일 경우 0을 반환하는 연산자.
	GetBinary(50);
	GetBinary(70);
	GetBinary(50 | 70);
	printf("-------------------\n");

	// 배타적 논리합 XOR 연산자(^)
	// 각 자리의 비트를 비교하여 다르다면 1, 같다면 0으로 반환하는 연산자.
	GetBinary(50);
	GetBinary(70);
	GetBinary(50 ^ 70);
	printf("-------------------\n");

	return 0;
}