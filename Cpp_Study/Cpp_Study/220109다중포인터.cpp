#include <iostream>
using namespace std;

// ���� ������

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	
	// msg[ �ּ� ] << 8����Ʈ
	const char* msg = "Hello";
	SetMessage(msg);
	//cout << msg << endl;


	// Hello�ּ� [ ] << 1����Ʈ
	// msg [ Hello�ּ� ] << 8����Ʈ
	// pp [ &msg ] << 8����Ʈ
	const char** pp = &msg;
	SetMessage(&msg);

	//*pp = "Bye";
	cout << msg << endl;

	// * �� �ϳ��� ��鼭 Ÿ�� ���ٰ� ����
	const char** pp2;

	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}