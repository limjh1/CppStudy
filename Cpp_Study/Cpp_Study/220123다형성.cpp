#include <iostream>
using namespace std;

// 다형성

// Polymorphism = Poly + morph 형태가 다양하게 있다. 
// = 겉은 똑같은데 기능이 다르게 동작한다.
// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용
// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의


// 바인딩 (Binding) == 묶는다
// - 정적 바인딩 : 컴파일 시점에 결정
// - 동적 바인딩 : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원한다면? -> 가상 함수 (virtual function)

// 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해줄까?
// - 가상 함수 테이블 (vftable)

// .vftable [] 4바이트(32) 8바이트(64)
// [VMove] [VDie]

class Player
{
public:
	Player()
	{
		_hp = 100;
	}


	void Move() { cout << "Move Player!" << endl; }
	// void Move(int a) { cout << "Move Player(int)!" << endl; } // 오버 로딩

	virtual void VMove() { cout << "VMove Player!" << endl; }
	virtual void VDie() { cout << "VDie Player!" << endl; }

public:
	int _hp;

};

class Knight : public Player
{
public:

	Knight()
	{
		_stamina = 100;
	}

	void Move() { cout << "Move Knight!" << endl; } // 오버 라이딩

	// 가상 함수는 재정의 하더라도 가상 함수다.
	virtual void VMove() { cout << "VMove Knight!" << endl; }
	virtual void VDie() { cout << "VDie Knight!" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{

public:
	int _mp;
};

void MovePlayer(Player* player)
{
	//player->Move();
	player->VMove();
	player->VDie();
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}


void main()
{
	Player p;
	p.Move();
	// p.Move(100);

	MovePlayer(&p); // 플레이어는 플레이어다? YES
	//MoveKnight(&p); // 플레이어는 기사다? NO (항상 아닐경우 NO)

	Knight k;
	k.Move();

	MoveKnight(&k); // 기사는 기사다? YES
	MovePlayer(&k); // 기사는 플레이어다? YES
}