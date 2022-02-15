#include "player.h"
#include "monster.h"

void player::KillMonster()
{	
	// (*_target2)._hp = 0;
	_target2->_hp = 0;

	_target2->KillMe();


}
