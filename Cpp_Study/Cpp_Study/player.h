#pragma once

// #include "monster.h"

//class monster;

class player
{
public:

	void KillMonster();

	// #include "monster.h" ���ϸ� ���� ����
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

