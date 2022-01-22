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

// ������(Constructor)�� �Ҹ���(Destructor)
// Ŭ������ '�Ҽ�'�� �Լ����� ��� �Լ�
// �� �߿��� [����]�� [��]�� �˸��� �Լ���
// - ����(ź��) -> ������ (������ ����)
// - ��(�Ҹ�) -> �Ҹ��� (���� 1����)

// [�Ͻ���(Implicit) ������]
// �����ڸ� ��������� ������ ������,
// �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������.
// -> �׷��� �츮�� �����(Explicit)���� �ƹ� ������ �ϳ� �����,
// �ڵ����� ��������� [�⺻ ������]�� �� �̻� ��������� ����..!


// class�� ������ ���赵
class Knight // ���赵 ����, CPP������ struct�� ���
{
public:
	// [1] �⺻ ������ (���ڰ� ����)
	Knight()
	{
		cout << "CALL Knight() Constructor" << endl;
		
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] ���� ������ (�ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����)
	// (�Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� ����Ѵ�
	Knight(const Knight& knight)
	{
		cout << "CALL Knight Copy Constructor" << endl;

		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] ��Ÿ ������
	
	// �� �߿��� ���ڸ� 1���� �޴� [��Ÿ ������]�� 
	// [Ÿ�� ��ȯ ������]��� �θ��⵵ ��

	// ������� �뵵�θ� ����� ��!
	explicit Knight(int hp)
	{
		cout << "CALL Knight(int) Constructor" << endl;

		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	// �Ҹ���
	~Knight()
	{
		cout << "CALL ~Knight() Destructor" << endl;
	}


	// ��� �Լ� ����
	void Move(int y, int x);
	void Attack();
	void Die() 
	{ 
		// this->_hp = 0;
		_hp = 0; 
		cout << "Die" << endl; 
	};

public:
	// ��� ���� ����
	int _hp;
	int _attack;
	int _posY;
	int _posX;

};

// �Ϲ� �Լ�
void Move(Knight* Knight, int y, int x)
{
	Knight->_posX = x;
	Knight->_posY = y;
}

// ��ü����
void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// Instantiate ��ü�� �����
int main()
{
	// Knight k1; // �⺻ ������
	Knight k1(100);
	//k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	//Move(&k1, 2, 2); // �Ϲ� �Լ�

	Knight k2(k1); // k1�� �Ȱ����Ÿ� ����°���. ���� ������
	Knight k3 = k1; // �̰ŵ� ���� ������, ������ ���ÿ� ����

	// �̰� ���� �����ڶ� �ǹ̰� �ٸ�
	Knight k4; // �⺻ �����ڷ� �����
	k4 = k1; // k1�� k4�� ��������

	Knight k5(100, 10, 0, 0); // ��Ÿ ������

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// �Ͻ��� ����ȯ -> �����Ϸ��� �˾Ƽ� �ٲ�ġ��
	int num = 1;

	float f = (float)num; // ����� < �ڵ�� num�� float�� ��ȯ
	double d = num; // �Ͻ��� < �����Ϸ��� �˾Ƽ� ��ȯ

	//// �Ͻ������� ��ȯ explicit ���̸� �Ұ���
	//Knight k6;
	//k6 = 1; // Ÿ�� ��ȯ ������, Knight(int hp)�� �尨

	//HelloKnight(5);

	Knight k6;
	k6 = (Knight)1; // �����

	HelloKnight((Knight)5); // �����

	return 0;
}