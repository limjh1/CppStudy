#include <iostream>
using namespace std;

// 파일 분할 관리

// 객체지향 프로그래밍
// 
// 절차(procedureal)지향 프로그래밍
// - 함수(procedure)

// 데이터 + 가공(로직, 동작)

// 객체지향 = 객체
// 객체 --> 플레이어, 몬스터, GAME ROOM, 등 오브젝트

// Design Knight
// - 속성(데이터) : HP, ATK, POSITION(x,y)
// - 기능(동작)   : MOVE, ATK, DIE


// class는 일종의 설계도
class Knight // 설계도 개념, CPP에서는 struct랑 비슷
{
public:
	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() { hp = 0; cout << "Die" << endl; };

public:
	// 멤버 변수 선언
	int hp;
	int attack;
	int posY;
	int posX;

};

// 일반 함수
void Move(Knight* Knight, int y, int x)
{
	Knight->posX = x;
	Knight->posY = y;
}

// 객체지향
void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

// Instantiate 객체를 만든다
int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	//Move(&k1, 2, 2); // 일반 함수

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}