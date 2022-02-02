#include <iostream>
using namespace std;

// 객체지향 마무리

// 1) struct vs class

// C++ 에서는 종이 한 장 차이다.

// struct는 기본 접근 지정자가 public이고, class는 private이다.
// -> struct는 구조체 (데이터 묶음) 표현 용도
// -> class는 객체 지향 프로그래밍의 특징 나타내는 용도

struct TestStruct
{
public:
	int _a;
	int _b;
};

class TestClass
{
private:
	int _a;
	int _b;
};

// 2) static 변수, static 함수 (정적 = 고정된)

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage) 
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		// _hp = 100; 클래스와 연관 없음. static이라서 어떤 마린을 건드려야 할 지 모름.
	}

	// 특정 마린 객체와는 무관
	// 마린이라는 클래스 자체와 연관
	static int s_attack; // 전역으로 따로 빼줬다는 느낌 // 설계도상으로만 존재함
};


int Marine::s_attack = 0; // class 외부 선언

class Player
{
public:
	int _id;
};

int GenerateId()
{
	// 정적 지역 객체
	// 
	// 생명주기 : 프로그램 시작/종료 (메모리에 항상 올라가 있음)
	// 가시범위(사용 가능 범위) : 함수 내부
	static int s_id = 1;

	return s_id++;
}

// 정적 전역 객체
static int s_globalInt;

int main()
{
	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);

	Marine::s_attack = 6; // 마린은 공통적으로 다 가짐
	//m1.s_attack = 6;	

	Marine m2;
	m2._hp = 40;
	//m2.s_attack = 6;
	m2.TakeDamage(10);

	// Marine Attack Power Upgrade Complete
	Marine::s_attack = 7;
	//m1.s_attack = 7;
	//m2.s_attack = 7;

	Marine::SetAttack();
	
	// 스택 아님. .data 영역
	static int id = 10;
	int a = id;

	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;

	return 0;
}