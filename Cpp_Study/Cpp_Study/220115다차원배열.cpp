#include <iostream>
using namespace std;

// ������ �迭

int main()
{
	int a[10] = { 1,2,3 };

	// [1] [1] [5] [2] [2] << 1��
	// [4] [2] [3] [4] [1] << 0��

	int first[5] = { 4,2,3,4,1 }; // 0��
	int second[5] = { 1,1,5,2,2 }; // 1��

	int apartment2D[2][5] = { 
		{4,2,3,4,1}, 
		{1,1,5,2,2} 
	};

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	int apartment1D[10] = { 4,2,3,4,1,1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2�� �迭�� --> 2D �α׶���ũ �� (��ǥ��)
	int map[5][5] =
	{
		{1,1,1,1,1},
		{0,0,0,1,1},
		{1,0,0,1,1},
		{1,0,0,0,0},
		{1,1,1,1,1},
	};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int info = map[y][x];
			cout << info;
		}
		cout << endl;
	}

	return 0;
}
