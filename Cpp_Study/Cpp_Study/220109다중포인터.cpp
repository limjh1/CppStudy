#include <iostream>
using namespace std;

// 다중 포인터

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
	
	// msg[ 주소 ] << 8바이트
	const char* msg = "Hello";
	SetMsg(msg);
	cout << msg << endl;

	return 0;
}