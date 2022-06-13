#include <iostream>
using namespace std;

struct StatInfo // 12byte
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void EnterLobby();
StatInfo CreatePlayer(); // 포인터를 사용하지 않는 버전
void CreateMonster(StatInfo* info); // 포인터를 사용하는 버전
bool StartBattle(StatInfo* player, StatInfo* monster); // 플레이어 승리시 TRUE
int damageCalc(int attack, int defence); // Damage 계산 함수

int main()
{
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	cout << "Enter Lobby" << endl;	

	// 캐릭터 생성
	// 포인터 사용 안하고
	StatInfo player;
	player = CreatePlayer(); // 복사

	// 몬스터 생성
	// 포인터 사용 하고
	StatInfo monster;
	CreateMonster(&monster); // 원본 수정
	
	if (StartBattle(&player, &monster) == true) cout << "MOSTER DIE" << endl;
	else if(StartBattle(&player, &monster) == false) cout << "PLAYER DIE" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret; // 하나더 생성해서

	cout << "Create Player " << endl;

	// 값을 넣고
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;
	
	// 반환하여 복사함
	return ret;
}

void CreateMonster(StatInfo* info)
{
	// 주소를 활용해서 원본 자체를 바꿈
	cout << "Create Monster" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 5;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	cout << endl << "Start Battle" << endl << endl;

	while (true)
	{
		if (player->hp <= 0) return false;
		else if (monster->hp <= 0) return true;		

		cout << "PLAYER HP : " << player->hp << endl;
		cout << "MOSTER HP : " << monster->hp << endl << endl;

		player->hp -= damageCalc(player->attack, monster->defence);
		monster->hp -= damageCalc(monster->attack, player->defence);			
	}
}

int damageCalc(int attack, int defence)
{
	int damage = attack - defence;	

	if (damage <= 0) damage = 0;

	return damage;
}