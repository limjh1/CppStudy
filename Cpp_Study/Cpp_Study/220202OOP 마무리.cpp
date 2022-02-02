#include <iostream>
using namespace std;

// ��ü���� ������

// 1) struct vs class

// C++ ������ ���� �� �� ���̴�.

// struct�� �⺻ ���� �����ڰ� public�̰�, class�� private�̴�.
// -> struct�� ����ü (������ ����) ǥ�� �뵵
// -> class�� ��ü ���� ���α׷����� Ư¡ ��Ÿ���� �뵵

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

// 2) static ����, static �Լ� (���� = ������)

class Marine
{
public:
	// Ư�� ���� ��ü�� ������
	int _hp;

	void TakeDamage(int damage) 
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		// _hp = 100; Ŭ������ ���� ����. static�̶� � ������ �ǵ���� �� �� ��.
	}

	// Ư�� ���� ��ü�ʹ� ����
	// �����̶�� Ŭ���� ��ü�� ����
	static int s_attack; // �������� ���� ����ٴ� ���� // ���赵�����θ� ������
};


int Marine::s_attack = 0; // class �ܺ� ����

class Player
{
public:
	int _id;
};

int GenerateId()
{
	// ���� ���� ��ü
	// 
	// �����ֱ� : ���α׷� ����/���� (�޸𸮿� �׻� �ö� ����)
	// ���ù���(��� ���� ����) : �Լ� ����
	static int s_id = 1;

	return s_id++;
}

// ���� ���� ��ü
static int s_globalInt;

int main()
{
	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);

	Marine::s_attack = 6; // ������ ���������� �� ����
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
	
	// ���� �ƴ�. .data ����
	static int id = 10;
	int a = id;

	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;

	return 0;
}