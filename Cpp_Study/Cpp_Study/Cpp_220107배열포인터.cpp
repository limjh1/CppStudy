#include <iostream>
using namespace std;

// 포인터 vs 배열


void Test(int a)
{
	a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환함 (char[] -> char *)
// 시작 주소 즉, 포인터 주소를 넘김
void Test(char a[])
{
	a[0] = 'x';
}

int main() 
{
	// 문자열 = 문자 배열
	
	// test1[ 시작 주소 ] << 8바이트
	const char* test1 = "Hello World";

	char test2[] = "Hello World";
	test2[0] = 'R';

	//cout << test2 << endl;

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
	// - 배열 이름은 '바구니 모음'의 [시작 주소]

	// 배열을 함수의 인자로 넘기게 된다면

	int a = 0;

	// 안바뀜
	Test(a);
	cout << a << endl;

	// 바뀜 --> 배열의 시작주소를 넘기기 때문에
	Test(test2);
	cout << test2 << endl;

	return 0;
}