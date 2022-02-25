#include <iostream>
using namespace std;

// ���ø� ����

// typename T �� ������ ��Ŀī�� � Ÿ�Ե� ����
// �׷��� ������ typename�� �ٿ��� �ϴ� ���� �ƴϴ�
// template< > �ȿ� ���� �� �������ϴ� �����

template<typename T, int SIZE>
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % SIZE; // 0~9
		return _data[idx];
	}

public:
	T _data[SIZE];
};

// ���ø� Ư��ȭ
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
	double GetRandomData()
	{
		cout << "RandomBoxDouble" << endl;
		int idx = rand() % SIZE; // 0~9
		return _data[idx];
	}

public:
	double _data[SIZE];
};


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int, 10> rb1;

	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<double, 20> rb2;

	for (int i = 0; i < 20; i++)
	{
		rb2._data[i] = i + 0.5;
	}
	double value2 = rb2.GetRandomData();
	cout << value2 << endl;

	//rb1 = rb2;

	return 0;
}