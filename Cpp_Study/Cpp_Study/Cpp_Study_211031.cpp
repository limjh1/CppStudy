#include <iostream>
using namespace std;

#pragma region 함수
//// 함수
//void PrintHelloWorld()
//{
//	cout << "Hello World" << endl;
//}
//
//void PrintNumber(int number)
//{
//	cout << "숫자는 " << number << " 입니다" << endl;
//}
//
//int MultiplyBy2(int number)
//{
//	int result = number * 2;
//	return result;
//}
//
//int MultiplyBy(int a, int b)
//{
//	return a * b;
//}
//
//int main()
//{
//	PrintHelloWorld();
//	PrintNumber(5);
//	cout << MultiplyBy2(2) << endl;
//	cout << MultiplyBy(2, 4) << endl;
//
//	return 0;
//}
#pragma endregion

#pragma region 지역, 전역 변수, 호출 스택

// 전역 변수
// 참고) 초기화 여부, const 등 .rodata .data .bss
int globalValue = 0;

void test()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	hp += 1;	
}

// 함수 선언
void Func1();
void Func2(int a, int b);
void Func3(float a);


// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 개수, 타입, 순서가 다르거나
int Add(int a, int b)
{
	return a + b;
}

int Add(int a)
{
	return a + 1;
}


float Add(float a, float b)
{
	return a + b;
}

// 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guildID = 0, int castleID = 0) // guildID : 0(NO) or 1(YES)..? 귀찮아서 기본값 세팅
{

}

// STACK OVERFLOW
int Factorial(int n)
{
	if (n == 1) return 1;

	return n * Factorial(n - 1);
}

// STACK FRAME --> [[매개변수][RETURN][지역변수] [매개변수][RETURN][지역변수]  |  [~
int main()
{
	//cout << "전역 변수의 값은 : " << globalValue << endl;
	//globalValue++;

	//test();

	////지역 변수
	//int localValue = 1;

	//int hp = 1;

	//cout << "BEFORE : " << hp << endl;
	//IncreaseHp(hp);
	//cout << "AFTER : " << hp << endl;

	//Func1();

	int result1 = Add(1, 2);
	float result2 = Add(1.5f, 2.1f);
	int result3 = Add(1);

	SetPlayerInfo(100, 40, 10);

	// 5! = 5*4*3*2*1
	cout << Factorial(5) << endl;


	return 0;
}

void Func1()
{
	cout << "FUNC 1" << endl;

	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "FUNC 2" << endl;

	Func3(10);
}

void Func3(float a)
{
	cout << "FUNC 3" << endl;

}

#pragma endregion
