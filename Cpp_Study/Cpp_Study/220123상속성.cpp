#include <iostream>
using namespace std;

// 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 메모리

// [ [Player] ]
// [   Knight ]

// 상속 (Inheritance) 

// 생성자(N개) / 소멸자(1개)

// - knight를 생성하면 -> player생성자? knight생성자?
// -> 둘다 호출된다

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projetile
// -- Arrow, FireBall
// - Env(Enviorment)

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll

class GameObject
{
public:
	int _objectID;
};

class Player : public GameObject
{
public:
	Player() // 기본 생성자
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Call Player Constructor" << endl;
	}
	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Call Player(int hp) Constructor" << endl;
	}

	~Player()
	{
		cout << "Call ~Player Destructor" << endl;
	}

	void Move() { cout << "Call Player Move" << endl; }
	void Attack() { cout << "Call Player Attack" << endl; }
	void Die() { cout << "Call Player Die" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

// class 일종의 설계도
class Knight : public Player
{
public:
	Knight() // 기본 생성자
		/*
		* 선처리 영역
		* - 여기서 Player() 생성자 호출 
		*/
	{
		_stamina = 100;
		cout << "Call Knight Constructor" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
		* 선처리 영역
		* - 여기서 Player(int hp) 생성자 호출
		*/
	{
		_stamina = stamina;
		cout << "Call Knight(int stamina) Constructor" << endl;
	}

	~Knight()
	{
		cout << "Call ~Knight Destructor" << endl;
	}
		/*
		* 후처리 영역
		* - 여기서 Player() 소멸자 호출 
		*/

	// 재정의 : 상속 새롭게 만들기
	void Move() { cout << "Call Knight Move" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;

};

int main()
{
	Knight k;
	Knight k1(100);

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	//k.Move();
	//k.Player::Move();

	//k.Attack();
	//k.Die();

	return 0;
}