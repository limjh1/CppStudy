#include <iostream>
using namespace std;

// ���� ������

void SetNumber(int* a)
{
	*a = 1;
}

void SetMsg(const char* a)
{
	a = "Bye";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	
	// msg[ �ּ� ] << 8����Ʈ
	const char* msg = "Hello";
	SetMsg(msg);
	cout << msg << endl;

	return 0;
}