#include <iostream>
using namespace std;


void SetHp(int* hp)
{
	*hp = 100;
}



// [매개변수][RETURN][지역변수(hp 1 )]  
// Pointer
int main()
{
	int hp = 1;
	SetHp(&hp);

	// 지금까지 사용한 방식
	// number라는 이름의 4바이트 정수 타입의 바구니를 만든다
	// number라는 변수 스택 메모리에 할당
	// number = 1은, number바구니에 1이라는 숫자 넣으라는 의미.
	// 따라서 스택 메모리에 있는 특정 주소(number 바구니)에 우리가 원하는 값을 넣은 셈
	// number는 비유하자면 메모리에 이름을 붙인 것
	int number = 1;

	// TYPE* 변수이름;
	// 일단 2가지 요소
	// - TYPE
	// - *

	// 바구니는 바구니인데  [주소를 저장하는 바구니]
	// 참고) 포인터라는 바구니는 8바이트(64비트) 고정 크기
	int* ptr = &number; // number의 주소를 ptr에 저장

	// 추가 문법 : [주소를 저장하는 바구니]가 가리키는 주소로가서 무엇인가를 해라.
	// *변수이름 = 값;


	// - 변수 선언
	// - 사용할 때(포탈을 타고 순간이동)
	int value1 = *ptr; // ptr이라는 주소를 저장하는 바구니가 가리키는 해당 내용 가져오기
	*ptr = 2; // 가리키는 해당 내용을 2로

	// TYPE은 왜 붙여줄까?
	// * = 포인터의 의미 = 주소를 저장하는 바구니 = 4 or 8 byte 고정 크기

	// 타입의 불일치
	__int64* ptr2 = (__int64*)&number;

	*ptr2 = 0xAABBCCDDEEFF; // 16진수

	return 0;
}