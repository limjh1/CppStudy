#include <iostream>
using namespace std;

// ���м� = ĸ��ȭ

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// ���м�(Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� �����.
// ����
//  1) �ǵ帮�� �ȵǴ� ���
//  2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��
// - �ڵ�, ���, ��
// ���� �Ǵ� �κ� (�ǵ帮�� ū�ϳ��� �κ�)
// - ����, ���� ���⼱

// public (����) protected (��ȣ) private (����)
// - public    : ����
// - protected : �ڼյ����׸� ���
// - private   : class ���ο����� ���

// ��� ���� ������ : ���� �������� ������ ��� ��������?
// �� �Ȱ��� ������� ���� ����
// - public : ���� �״�� ��� (public -> public, protected -> protected, private -> ���X)
// - protected : �ڼյ����׸� ������ (public -> protected, protected -> protected, private -> ���X)
// - private : ���� (public -> private, protected -> private)

class Car
{
public: // (���) ���� ������
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	void RunEngine() {} // ������ ������Ų��

private:
	void DisassembleCar() {} // ���� �����Ѵ�	
	void ConnectCircuit() {} // ���⼱ ����

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱

};

class SuperCar : public Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

// ���������ָ� �⺻������ private�� ������
class TestSuperCar : SuperCar
{
	// OpenDoor();
};

// ĸ��ȭ
// ������ �����Ϳ� �Լ��� �������� ������� ��

class Berserker
{
public:

	int GetHp() { return _hp; }
	void SetHp(int hp)
	{		
		_hp = hp;
		if (_hp <= 50) SetBerserkerMode();
	}

private:
	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ�
	void SetBerserkerMode()
	{
		cout << "�ſ� ������" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	Car car;

	SuperCar s_car;
	s_car.PushRemoteController();

	Berserker b;

	b.SetHp(20);

	TestSuperCar t_car;
	

	return 0;
}