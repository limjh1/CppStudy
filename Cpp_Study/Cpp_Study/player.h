#pragma once

// #include "monster.h"

//class monster;

class player
{
public:

	void KillMonster();

	// #include "monster.h" 안하면 빌드 오류
	/*void KillMonster2()
	{
		_target2->_hp = 0;
	}*/
	

public:
	int _hp;
	int _attack;
	
	//monster _target;
	class monster* _target2;

	Player* _target;

};

