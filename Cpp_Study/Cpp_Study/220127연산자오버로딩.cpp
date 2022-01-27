#include <iostream>
using namespace std;

// ������ �����ε� (Operator Overloading)

// ������ vs �Լ�
// - �����ڴ� �ǿ������� ����/Ÿ�� ����

// ������ �����ε�?
// ������ �Լ��� �����ؾ� ��
// �Լ��� ����Լ� vs �����Լ��� �����ϴ� �� ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����

// - ��� ������ �Լ� version
// -- a op b ���¿��� ������ �������� ���� (a�� Ŭ�������� ����. a�� '���� �ǿ�����'��� ��)
// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����

// - ���� ������ �Լ� version
// -- a op b ���, a,b��θ� ������ �Լ��� �ǿ����ڷ� �������

// ���� ������ (a=b) --> ���� ������ version���δ� �� �����

// ���� ���� ������
// - [���� ������] [���� ������] [���� ���� ������]
// -- ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��

// ��� �����ڸ� �� �����ε� �� �� �ִ� ���� �ƴ� (:: . .* ��)
// ��� �����ڰ� �� 2�� ���� �ִ� ���� �ƴ�. ++ -- �� ��ǥ��(���� ������)
// - ���� ������ ++ --
// -- ������ (++a) operator++()
// -- ������ (a++) operator++(int)

class Position
{
public:

	//Position(const Position& arg) // ���� ������
	//{

	//}
	
	Position operator+(const Position& arg)
	{
		Position pos;

		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;

		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	// [���� ������] [���� ���� ������] �� Ư�� ��츦 �޴� ����
	// �� �״�� ��ü�� ����Ǳ� ���ϴ� Ư¡ ����	
	// �����Ҵ� �ð��� �� �ڼ��� �˾ƺ� ��
	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._x;

		//Position* this = �� �ڽ��� �ּ�;
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};

// (x)
// 
//void operator=(const Position& a,int b)
//{
//	a._x = b;
//	a._y = b;
//}

Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

int main()
{
	int a = 1;
	int b = 2;
	
	int c = (a = 3);

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	// pos3 = pos.operator+(pos2);
	Position pos3 = pos + pos2;

	// pos4 = pos3.operator+(1);
	Position pos4 = pos3 + 1;
	Position pos5 = 1 + pos4;

	bool isSame = (pos3 == pos4);

	// Position pos6 = 6; (x)
	//Position pos6;
	//pos6 = 6;
	//pos3 = (pos6 = 6);

	// (const pos&)    (pos) ���簪
	//Position a = pos3++;
	//pos5 = a;
	pos5 = pos3++;
	

	++(++pos3);
	

	return 0;
}