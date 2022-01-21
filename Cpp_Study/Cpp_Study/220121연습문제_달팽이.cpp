#include <iostream>
using namespace std;
#include <iomanip>

// 연습 문제

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

void SetBoard()
{
	int num = 1;
	int i = 0;
	while (num <= N*N)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = num;
			num++;
		}
		i++;
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();


	return 0;
}
