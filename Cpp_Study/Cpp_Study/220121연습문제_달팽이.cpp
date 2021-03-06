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

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N) return false;

	if (x < 0 || x >= N) return false;

	if (board[y][x] != 0) return false;

	return true;
}

void SetBoard()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = { 0, 1, 0, -1 }; // RIGHT DOWN LEFT UP 순으로 y값 변화
	int dx[] = { 1, 0, -1, 0 }; // RIGHT DOWN LEFT UP 순으로 x값 변화

	while (true)
	{
		board[y][x] = num;

		if (num == N * N) break;

		/*int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		default:
			break;
		}*/ // swtich로 할 경우

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			dir = (dir + 1) % 4; // 0 1 2 3 뺑뺑이 돌거임 밑의 switch랑 같은 의미

			/*
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			default:
				break;
			}*/
		}
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();


	return 0;
}
