#include <iostream>
using namespace std;

#pragma region �Լ�
//// �Լ�
//void PrintHelloWorld()
//{
//	cout << "Hello World" << endl;
//}
//
//void PrintNumber(int number)
//{
//	cout << "���ڴ� " << number << " �Դϴ�" << endl;
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

#pragma region ����, ���� ����, ȣ�� ����

// ���� ����
// ����) �ʱ�ȭ ����, const �� .rodata .data .bss
int globalValue = 0;

void test()
{
	cout << "���� ������ ���� : " << globalValue << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	hp += 1;	
}

// �Լ� ����
void Func1();
void Func2(int a, int b);
void Func3(float a);


// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű����� ����, Ÿ��, ������ �ٸ��ų�
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

// �⺻ ���ڰ�
void SetPlayerInfo(int hp, int mp, int attack, int guildID = 0, int castleID = 0) // guildID : 0(NO) or 1(YES)..? �����Ƽ� �⺻�� ����
{

}

// STACK OVERFLOW
int Factorial(int n)
{
	if (n == 1) return 1;

	return n * Factorial(n - 1);
}

// STACK FRAME --> [[�Ű�����][RETURN][��������] [�Ű�����][RETURN][��������]  |  [~
int main()
{
	//cout << "���� ������ ���� : " << globalValue << endl;
	//globalValue++;

	//test();

	////���� ����
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
