#include <iostream>
using namespace std;

// ������ vs �迭


void Test(int a)
{
	a++;
}

// �迭�� �Լ� ���ڷ� �ѱ��, �����Ϸ��� �˾Ƽ� �����ͷ� ġȯ�� (char[] -> char *)
// ���� �ּ� ��, ������ �ּҸ� �ѱ�
void Test(char a[])
{
	a[0] = 'x';
}

int main() 
{
	// ���ڿ� = ���� �迭
	
	// test1[ ���� �ּ� ] << 8����Ʈ
	const char* test1 = "Hello World";

	char test2[] = "Hello World";
	test2[0] = 'R';

	//cout << test2 << endl;

	// �����ʹ� [�ּҸ� ��� �ٱ���]
	// �迭�� [] ��, �� ��ü�� ���� �����ͳ��� �پ��ִ� '�ٱ��� ����'
	// - �迭 �̸��� '�ٱ��� ����'�� [���� �ּ�]

	// �迭�� �Լ��� ���ڷ� �ѱ�� �ȴٸ�

	int a = 0;

	// �ȹٲ�
	Test(a);
	cout << a << endl;

	// �ٲ� --> �迭�� �����ּҸ� �ѱ�� ������
	Test(test2);
	cout << test2 << endl;

	return 0;
}