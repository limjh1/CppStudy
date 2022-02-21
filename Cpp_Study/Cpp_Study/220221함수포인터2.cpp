#include <iostream>
using namespace std;

// 함수 포인터2

class Knight
{
public:

	// 정적 함수
	static void HelloKnight()
	{

	}

	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;

};

// typedef
// typedef 왼쪽 오른값 -> 오른쪽 커스텀 타입 정의
// typedef int NUMBER;
// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽

typedef int INTEGER;
typedef int* POINTER;
// typedef int FUNC(int, int);
typedef int ARRAY[20];

// 전역,정적 함수 포인터
typedef int(*P_FUNC)(int, int);

// 멤버 함수 포인터
typedef int(Knight::*PMEM_FUNC)(int, int);

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

int t(int a, int b)
{
	cout << "t" << endl;
	return a + b;
}


int main()
{
	// 함수 포인터
	// 1) 포인터 *
	// 2) 변수의 이름 fn
	// 3) 타입 함수(인자로 int 2개 받고, int 1개를 반환)
		
//	P_FUNC t;

//	t(1, 2);

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;
	//int (*fn)(int, int);
	P_FUNC fn;

	fn = Test;
	// fn = &Test; // & 생략 가능 (C언어 호환성 때문)

	fn(1, 2);
	(*fn)(1, 2);

	// 위 문법으로 [전역 함수/ 정적 함수]만 담을 수 있다 (호출 규약이 동일한 애들)
	// fn = &Knight::GetHp;

	Test(1, 2);

	// Knight::GetHp(1, 2); 비정적 멤버 참조는 특정 개체에 상대적이어야하 합니다. 에러
	// 하나 만들어주고 해야함
	Knight k1;
	k1.GetHp(1, 1);
	
	PMEM_FUNC mfn;
	mfn = &Knight::GetHp; // & 생략 불가능
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	// ((*k2).*mfn)(1, 1);
	(k2->*mfn)(1, 1);
	delete k2;

	

	return 0;
}