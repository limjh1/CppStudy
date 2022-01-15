#include <iostream>
using namespace std;

// 다중 포인터

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
	
	// msg[ 주소 ] << 8바이트
	const char* msg = "Hello";
	SetMessage(msg);
	//cout << msg << endl;


	// Hello주소 [ ] << 1바이트
	// msg [ Hello주소 ] << 8바이트
	// pp [ &msg ] << 8바이트
	const char** pp = &msg;
	SetMessage(&msg);

	//*pp = "Bye";
	cout << msg << endl;

	// * 을 하나씩 까면서 타고 들어간다고 생각
	const char** pp2;

	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}