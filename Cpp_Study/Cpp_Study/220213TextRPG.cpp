#include <iostream> // cpp ���� ���̺귯���� < >
using namespace std;
#include "Game.h" // custom���� �߰��� ����� " "

// TextRPG



int main()
{
	srand((unsigned int)time(nullptr));

	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return 0;
}