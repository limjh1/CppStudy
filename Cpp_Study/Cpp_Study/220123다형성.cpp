#include <iostream>
using namespace std;

// ������

// Polymorphism = Poly + morph ���°� �پ��ϰ� �ִ�. 
// = ���� �Ȱ����� ����� �ٸ��� �����Ѵ�.
// - �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����
// - �������̵�(Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������


// ���ε� (Binding) == ���´�
// - ���� ���ε� : ������ ������ ����
// - ���� ���ε� : ���� ������ ����

// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ� (virtual function)

// ���� ��ü�� � Ÿ������ ��� �˰� �˾Ƽ� �����Լ��� ȣ�����ٱ�?
// - ���� �Լ� ���̺� (vftable)

// .vftable [] 4����Ʈ(32) 8����Ʈ(64)
// [VMove] [VDie]

class Player
{
public:
	Player()
	{
		_hp = 100;
	}


	void Move() { cout << "Move Player!" << endl; }
	// void Move(int a) { cout << "Move Player(int)!" << endl; } // ���� �ε�

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

	void Move() { cout << "Move Knight!" << endl; } // ���� ���̵�

	// ���� �Լ��� ������ �ϴ��� ���� �Լ���.
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

	MovePlayer(&p); // �÷��̾�� �÷��̾��? YES
	//MoveKnight(&p); // �÷��̾�� ����? NO (�׻� �ƴҰ�� NO)

	Knight k;
	k.Move();

	MoveKnight(&k); // ���� ����? YES
	MovePlayer(&k); // ���� �÷��̾��? YES
}