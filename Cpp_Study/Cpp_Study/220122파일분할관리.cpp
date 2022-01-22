#include <iostream>
using namespace std;

// ���� ���� ����

// ��ü���� ���α׷���
// 
// ����(procedureal)���� ���α׷���
// - �Լ�(procedure)

// ������ + ����(����, ����)

// ��ü���� = ��ü
// ��ü --> �÷��̾�, ����, GAME ROOM, �� ������Ʈ

// Design Knight
// - �Ӽ�(������) : HP, ATK, POSITION(x,y)
// - ���(����)   : MOVE, ATK, DIE


// class�� ������ ���赵
class Knight // ���赵 ����, CPP������ struct�� ���
{
public:
	// ��� �Լ� ����
	void Move(int y, int x);
	void Attack();
	void Die() { hp = 0; cout << "Die" << endl; };

public:
	// ��� ���� ����
	int hp;
	int attack;
	int posY;
	int posX;

};

// �Ϲ� �Լ�
void Move(Knight* Knight, int y, int x)
{
	Knight->posX = x;
	Knight->posY = y;
}

// ��ü����
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

// Instantiate ��ü�� �����
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

	//Move(&k1, 2, 2); // �Ϲ� �Լ�

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}