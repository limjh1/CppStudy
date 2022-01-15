#include <iostream>
using namespace std;

// TextRPG3

// main
// - EnterLobby (PlayerInfo)
// -- CreatePlayer
// -- EnterGame
// --- CreateMonsters
// --- EnterBattle

enum PlayerType
{
	PT_Kinght = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime =1,
	MT_Orc =2,
	MT_Skeleton =3,
};

struct StatInfo
{
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void PrintMsg(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
	srand((unsigned) time(nullptr));
	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		PrintMsg("Entering Lobby !");

		// Player!
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo);

		EnterGame(&playerInfo);
	}
}

void PrintMsg(const char* msg)
{
	cout << "****************************" << endl;
	cout << msg << endl;
	cout << "****************************" << endl;
}

void CreatePlayer(StatInfo* playerInfo)
{
	bool ready = false;

	while (ready == false)
	{		
		PrintMsg("Create Player!");
		PrintMsg("[1] Knight [2] Archer [3] Mage");
		cout << ">";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_Kinght:
			playerInfo->hp = 100;
			playerInfo->attack = 10;
			playerInfo->defence = 5;
			ready = true;
			break;
		case PT_Archer:
			playerInfo->hp = 80;
			playerInfo->attack = 15;
			playerInfo->defence = 3;
			ready = true;
			break;
		case PT_Mage:
			playerInfo->hp = 50;
			playerInfo->attack = 25;
			playerInfo->defence = 1;
			ready = true;
			break;
		default:
			break;
		}

	}
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "************************" << endl;
	cout << name << " : HP=" << info.hp << " ATK=" << info.attack << " DEF=" << info.defence << endl;
	cout << "************************" << endl;
}

void EnterGame(StatInfo* playerInfo)
{
	const int MONSTER_COUNT = 2;
	PrintMsg("Entered Game!");

	while (true)
	{
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			PrintStatInfo("Monster", monsterInfo[i]);
		}

		PrintStatInfo("Player", *playerInfo);

		PrintMsg("[1] Battle1 [2] Battle2 [3] Runaway");

		int input;
		cin >> input;

		if (input == 1 || input == 2)
		{
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &monsterInfo[index]);

			if (victory == false)
				break;
		}
	}
}

void CreateMonsters(StatInfo monsterInfo[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int randValue = 1 + rand() % 3; // 1,2,3

		switch (randValue)
		{
		case MT_Slime:
			monsterInfo[i].hp = 30;
			monsterInfo[i].attack = 5;
			monsterInfo[i].defence = 1;
		case MT_Orc:
			monsterInfo[i].hp = 40;
			monsterInfo[i].attack = 8;
			monsterInfo[i].defence = 2;
		case MT_Skeleton:
			monsterInfo[i].hp = 50;
			monsterInfo[i].attack = 15;
			monsterInfo[i].defence = 3;
		default:
			break;
		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
	while (true)
	{
		int damage = playerInfo->attack - monsterInfo->defence;
		if (damage < 0)
			damage = 0;

		monsterInfo->hp -= damage;
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0)
		{
			PrintMsg("Killed Monster");
			return true;
		}

		damage = monsterInfo->attack - playerInfo->defence;
		if (damage < 0)
			damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0)
		{
			PrintMsg("You Died");
			return false;
		}

	}

}