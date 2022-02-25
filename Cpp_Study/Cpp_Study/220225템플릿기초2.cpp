#include <iostream>
using namespace std;

// 템플릿 기초

// typename T 는 일종의 조커카드 어떤 타입도 가능
// 그런데 무조건 typename을 붙여야 하는 것은 아니다
// template< > 안에 들어가는 건 골라줘야하는 목록임

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

// 템플릿 특수화
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