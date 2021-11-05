#include <iostream>
using namespace std;

// Text RPG

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct ObjectInfo
{
	int type;
	int hp;
	int attack;
	int defence;
};

ObjectInfo playerInfo;
ObjectInfo MosterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	srand(time(0)); // Random Seed

	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "-----------------------------------" << endl;
		cout << "Enter Lobby." << endl;
		cout << "-----------------------------------" << endl;

		// Player Job Select
		SelectPlayer();

		cout << "-----------------------------------" << endl;
		cout << "(1) Enter Field. (2) Exit Game" << endl;
		cout << "-----------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "Select JOB." << endl;
		cout << "(1) Knight (2) Archer (3) Mage." << endl;
		cout << "> ";

		cin >> playerInfo.type;

		if (playerInfo.type == PT_Knight)
		{
			cout << "Creating Knight..." << endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.type == PT_Archer)
		{
			cout << "Creating Archer..." << endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defence = 3;
			break;
		}
		else if (playerInfo.type == PT_Mage)
		{
			cout << "Creating Mage..." << endl;
			playerInfo.hp = 80;
			playerInfo.attack = 25;
			playerInfo.defence = 0;
			break;
		}
	}	
}

void EnterField()
{
	while (true)
	{
		cout << "-----------------------------------" << endl;
		cout << "Enter Field." << endl;
		cout << "-----------------------------------" << endl;

		cout << "[PLAYER] HP : " << playerInfo.hp << " / ATTACK : " << playerInfo.attack << " / DEFENCE : " << playerInfo.defence << endl;

		CreateRandomMonster();

		cout << "-----------------------------------" << endl;
		cout << "(1) Battle  (2) Run" << endl;
		cout << "> ";

		int input;
		cin >> input;
		
		if (input == 1)
		{
			EnterBattle();

			if (playerInfo.hp == 0)
				return;
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	// 1~3
	MosterInfo.type = 1 + (rand() % 3); // 1 2 3

	switch (MosterInfo.type)
	{
	case MT_Slime:
		cout << "Creating Slime... (HP:15 / ATT:5 / DEF:0)" << endl;
		MosterInfo.hp = 15;
		MosterInfo.attack = 5;
		MosterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << "Creating Orc... (HP:40 / ATT:10 / DEF:3)" << endl;
		MosterInfo.hp = 40;
		MosterInfo.attack = 10;
		MosterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << "Creating Skeleton... (HP:80 / ATT:15 / DEF:5)" << endl;
		MosterInfo.hp = 80;
		MosterInfo.attack = 15;
		MosterInfo.defence = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerInfo.attack - MosterInfo.defence;
		if (damage < 0)
			damage = 0;

		MosterInfo.hp -= damage;
		if (MosterInfo.hp < 0)
			MosterInfo.hp = 0;

		cout << "Monster HP : " << MosterInfo.hp << endl;
		if (MosterInfo.hp == 0)
		{
			cout << "Monster is Dead" << endl;
			return;
		}

		damage = MosterInfo.hp - playerInfo.defence;
		if (damage < 0)
			damage = 0;

		playerInfo.hp -= damage;
		if (playerInfo.hp < 0)
			playerInfo.hp = 0;

		cout << "Player HP : " << playerInfo.hp << endl;
		if (playerInfo.hp == 0)
		{
			cout << "Player is Dead.. GAME OVER" << endl;
			return;
		}
	}
}