#include <iostream>
using namespace std;

// �Լ� ������2

class Knight
{
public:

	// ���� �Լ�
	static void HelloKnight()
	{

	}

	// ��� �Լ�
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;

};

// typedef
// typedef ���� ������ -> ������ Ŀ���� Ÿ�� ����
// typedef int NUMBER;
// ��Ȯ���� ����/������ ������ �ƴ϶�,
// [���� ����]���� typedef�� �տ��� ���̴� ��

typedef int INTEGER;
typedef int* POINTER;
// typedef int FUNC(int, int);
typedef int ARRAY[20];

// ����,���� �Լ� ������
typedef int(*P_FUNC)(int, int);

// ��� �Լ� ������
typedef int(Knight::*PMEM_FUNC)(int, int);

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

int t(int a, int b)
{
	cout << "t" << endl;
	return a + b;
}


int main()
{
	// �Լ� ������
	// 1) ������ *
	// 2) ������ �̸� fn
	// 3) Ÿ�� �Լ�(���ڷ� int 2�� �ް�, int 1���� ��ȯ)
		
//	P_FUNC t;

//	t(1, 2);

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;
	//int (*fn)(int, int);
	P_FUNC fn;

	fn = Test;
	// fn = &Test; // & ���� ���� (C��� ȣȯ�� ����)

	fn(1, 2);
	(*fn)(1, 2);

	// �� �������� [���� �Լ�/ ���� �Լ�]�� ���� �� �ִ� (ȣ�� �Ծ��� ������ �ֵ�)
	// fn = &Knight::GetHp;

	Test(1, 2);

	// Knight::GetHp(1, 2); ������ ��� ������ Ư�� ��ü�� ������̾���� �մϴ�. ����
	// �ϳ� ������ְ� �ؾ���
	Knight k1;
	k1.GetHp(1, 1);
	
	PMEM_FUNC mfn;
	mfn = &Knight::GetHp; // & ���� �Ұ���
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	// ((*k2).*mfn)(1, 1);
	(k2->*mfn)(1, 1);
	delete k2;

	

	return 0;
}