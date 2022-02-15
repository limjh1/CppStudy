#include <iostream>
#include <stdlib.h>
using namespace std;
#include "player.h"

int main()
{
	// player는 몇 바이트?
	// int 2개 = 2 * 4 = 8byte

	// sizeof(Monster*) = 4 or 8 byte

	player p1; // 지역변수 stack

	player* p2 = new player(); // 동적할당 heap

	p1._target = p2;

	return 0;
}