#include <iostream> // cpp 공식 라이브러리는 < >
using namespace std;
#include "Game.h" // custom으로 추가한 헤더는 " "

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