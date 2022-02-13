#pragma once
#include "Player1.h"
#include "Field.h"

// 전방선언
class Player1;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	Player1* _player;
	Field* _field;


};

