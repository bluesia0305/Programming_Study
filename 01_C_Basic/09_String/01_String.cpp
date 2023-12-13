// 2022-06-09 ����(���)


// ���ڿ�(String)
// : ���ڷ� �̷���� �������� �迭.
//   ���� �����͸� ǥ���ϱ� ���� �ڷ������δ� char�� �����.


#include <iostream>
#pragma warning(disable : 4996)

int main()
{
	std::cout << "1) ���� �������� ǥ��." << std::endl;
	'A';											// !! ����) ������ ǥ���� ����ǥ�� �̿��Ͽ� �̷����.
	char myChar = 'A';

	std::cout << myChar << std::endl;
	printf("%c\n\n", myChar);						// %c: ���ڿ��� ǥ���ϱ� ���� ����������.

	std::cout << "2-1) ���ڿ��� ���� �� ���." << std::endl;
	// ���ڿ��� ���� ����� �Ʒ��� ���ÿ� ���� ���̿� �� �ε����� ���ڸ� �ʱ�ȭ�ϰų� (��)
	// ���̸� ���������� �ʰ�, ���ڿ��� �ֵ���ǥ�� �����Ͽ� �ʱ�ȭ�� �� ���� (�Ʒ�).
	char myStr1[5] = { 'H', 'e', 'l', 'l', 'o' };
	char myStr2[] = "Hello";						// !! ����) ���ڿ��� ǥ���� �ֵ���ǥ�� �̿��Ͽ� �̷����.
													// �ֵ���ǥ�� �̿��� ���𿡼� ���ڿ��� ���� �����ϱ� ����
													// NULL ����('\0', ASCII �ڵ�: 0)�� ���� �ÿ� ���ڿ��� ���� �ڵ����� �پ �ʱ�ȭ ��.
	
	//myStr2[] = "Mello";							// !! ����) ���ڿ� ���� ���� �� ���� �ٽ� �ʱ�ȭ�ϴ� ���� �Ұ�����.
	myStr2[0] = 'M';								// �ε������� �ϳ��� �ʱ�ȭ�� ����.
	for (int i = 0; i < 5; i++)
	{
		std::cout << myStr1[i];
	}
	std::cout << std::endl;
	printf("myStr1     : %s\n", myStr1);
	printf("myStr1 size: %zi\n", sizeof(myStr1));
	printf("myStr2     : %s\n", myStr2);
	printf("myStr2 size: %zi\n\n", sizeof(myStr2));

	std::cout << "2-2) ���ڿ� ���� ��, ������ ���̺��� �ʱ�ȭ �ϴ� ���� ���� ���� ���." << std::endl;
	char myStr3[7] = { 'H', 'e', 'l', 'l' };
	myStr3[6] = 'o';
	printf("myStr3     : %s\n", myStr3);
	printf("myStr3[4]  : %i\n", myStr3[4]);			// 0 (= '\0')���� �ʱ�ȭ�� ��.
	printf("myStr3[6]  : %c\n\n", myStr3[6]);

	std::cout << "2-3) NULL ���ڿ� ���� ���ظ� ���� ����." << std::endl;
	char myStr4[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char myStr5[] = "Hell\0o";
	printf("myStr4     : %s\n", myStr4);
	printf("myStr4 size: %zi\n", sizeof(myStr4));
	printf("myStr5     : %s\n", myStr5);
	printf("myStr5 size: %zi\n\n", sizeof(myStr5));

	std::cout << "3) ���ڿ� �������� �����(���ڿ� ���� ����(space)�� �ִ� ��쵵 �õ��غ���)." << std::endl;
	char inputStr[256] = { 0 };
	printf("�Է�1: ");
	// ���ڿ� �����͸� �Է¹��� ��(scanf)���� �ּҸ� �������� �ʾƵ� ��.
	scanf("%s", inputStr);
	printf("���1: %s\n", inputStr);
	printf("size: %zi\n\n", sizeof(inputStr));

	std::cout << "�Է�2: ";
	std::cin >> inputStr;
	std::cout << "���2: " << inputStr << std::endl;
	std::cout << "size: " << sizeof(inputStr) << std::endl << std::endl;

	// scanf�� cin�� �۵� ���
	// : Enter Ű�� ������ ��, �� ���� ����('\n')�� �Է¹��� �� �Է��� ������.
	//   �Է¹��� ���ڿ��� ������ �� ����(buffer)�� �����ִ� ���� ���ڸ� �������� �����͸� ������.
	//   ����, ���� ���ڸ� �Է¹ް��� �� ������ �Ʒ��� ���� ����� ����ؾ� ��.
	std::cout << "4) ���ڿ� ���� ����(space)�� �ִ� ���ڿ��� �Է¹޴� ���." << std::endl;
	char myStr6[] = "Hello World";
	printf("���� ��ÿ� ������ ������ ���ڿ��� ���: %s\n", myStr6);
	char myStr7[256] = { 0 };
	
	// �׳� ���鹮�� ��� ����)
	// getchar();
	// : ���ۿ� �����ִ� �����͸� �ϳ��� �������� �Լ�.
	/*for (int i = 0; i < 6; i++)
	{
		printf("%c", getchar());
	}
	printf("\n");
	printf("%s", myStr6)*/

	while (getchar() != '\n');		// ���ۿ� �����ִ� ���ڿ��� ��� ����� ���� ��ɹ�(�տ��� �� ���̶� �Է��� �޾Ҵٸ� �ʼ��� �ؾ���).
	printf("�Է�3: ");
	scanf("%[^\n]s", myStr7);		// %[^\n]s: ���� ���ڸ��� �������� �Ͽ� ���ۿ� �ִ� �����͸� �����ϱ� ���� ���� ������.
	printf("���3: %s\n\n", myStr7);

	while (getchar() != '\n');		// ���ۿ� �����ִ� ���ڿ��� ��� ����� ���� ��ɹ�(�տ��� �� ���̶� �Է��� �޾Ҵٸ� �ʼ��� �ؾ���).
	std::cout << "�Է�: ";
	// std::cin.getline( �Է¹��� ���ڿ��� ������ �迭, �迭�� ũ��, ������ ������ ����);
	// getline�� �̿��Ͽ� ������ �̿��� ���ڿ��� �Է��� ���, �ڵ������� �Է� �� ���ۿ� ���� �����͸� ������.
	std::cin.getline(myStr7, sizeof(myStr7), '\n');
	std::cout << "���: " << myStr7 << std::endl;

	return 0;
}