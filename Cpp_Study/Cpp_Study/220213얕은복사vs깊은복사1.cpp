#include <iostream>
using namespace std;

// ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet&)" << endl;
		return *this;
	}
};

class RabbitPet : public Pet
{

};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	Player(const Player& player) // ���� ������
	{
		cout << "Player(const Player&)" << endl;
		_level = player._level;
	}

	Player& operator=(const Player& player) // ���� ���� ������
	{
		cout << "operator=(const Player&)" << endl;
		_level = player._level;
		return *this;
	}

public:
	int _level = 0;

};

class Knight : public Player
{
public:
	Knight()
	{
		// _pet = new Pet();
	}

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
	{
		cout << "Knight(const Knight&)" << endl;

		_hp = knight._hp;
		// _pet = new Pet(*(knight._pet)); // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{
		Player::operator=(knight);
		_pet = knight._pet;

		_hp = knight._hp;
		

		// _pet = new Pet(*(knight._pet)); // ���� ����
		return *this;
	}

	~Knight()
	{
		
	}

public:
	int _hp = 100;
	Pet _pet;
};

int main()
{
	// Pet* pet = new Pet();

	Knight knight; // �⺻ ������
	knight._hp = 200;
	// knight._pet = pet;
	knight._level = 99;
	
	//Knight knight2 = knight; // ���� ������
	// Knight knight3(knight);

	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������
	

	// [���� ������] + [���� ���� ������]
	// �� �� �ȸ�����ָ� �����Ϸ��� '�Ͻ�������' ������ش�

	// [ ���� ���� ]
	// ��� �����͸� ��Ʈ�� ������ �Ȱ��� ����, �޸� ������ ���� �״�� ����
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight1 [ hp 0x1000(*pet) ] -> Heap 0x1000 Pet[ ]
	// Stack : Knight2 [ hp 0x1000(*pet) ]
	// Stack : Knight3 [ hp 0x1000(*pet) ]

	/*
	Pet* pet = new Pet();
	delete pet;
	delete pet;
	delete pet;
	*/

	// [���� ����]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش�. 
	// (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü ����Ű�� ���°� ��
	// Stack : Knight1 [ hp 0x1000(*pet) ] -> Heap 0x1000 Pet[ ]
	// Stack : Knight2 [ hp 0x2000(*pet) ] -> Heap 0x2000 Pet[ ]
	// Stack : Knight3 [ hp 0x3000(*pet) ] -> Heap 0x3000 Pet[ ]

	// ����
	// - �Ͻ��� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ����)
	
	// - ����� ���� ������ Steps
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) ��� Ŭ������ �⺻ ������ ȣ��
	
	// - �Ͻ��� ���� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ����)
	
	// - ����� ���� ���� ������ Steps
	// 1) �˾Ƽ� ���ִ°� ����
	

	// ��ü�� ���� �Ѵٴ� ���� �� ��ü�� ������ ��ġ��Ű���� ��
	// ���� �⺻������ ���� ���� ������� ����
	
	// ����� ���� -> ��� å���� ���α׷������� �����ϰڴٴ� �ǹ�

	return 0;
}