#include <iostream>
using namespace std;

// ��Ӽ�

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// �޸�

// [ [Player] ]
// [   Knight ]

// ��� (Inheritance) 

// ������(N��) / �Ҹ���(1��)

// - knight�� �����ϸ� -> player������? knight������?
// -> �Ѵ� ȣ��ȴ�

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
	Player() // �⺻ ������
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

// class ������ ���赵
class Knight : public Player
{
public:
	Knight() // �⺻ ������
		/*
		* ��ó�� ����
		* - ���⼭ Player() ������ ȣ�� 
		*/
	{
		_stamina = 100;
		cout << "Call Knight Constructor" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
		* ��ó�� ����
		* - ���⼭ Player(int hp) ������ ȣ��
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
		* ��ó�� ����
		* - ���⼭ Player() �Ҹ��� ȣ�� 
		*/

	// ������ : ��� ���Ӱ� �����
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