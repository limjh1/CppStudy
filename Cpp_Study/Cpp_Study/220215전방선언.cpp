#include <iostream>
#include <stdlib.h>
using namespace std;
#include "player.h"

int main()
{
	// player�� �� ����Ʈ?
	// int 2�� = 2 * 4 = 8byte

	// sizeof(Monster*) = 4 or 8 byte

	player p1; // �������� stack

	player* p2 = new player(); // �����Ҵ� heap

	p1._target = p2;

	return 0;
}