#include <iostream>
using namespace std;

// �迭 


struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};


int main()
{
	// TYPE �̸�[����];


	//�迭�� ũ��� ������� �� (VC �����Ϸ� ����)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// ���� = �ٱ���
	int a = 10;
	a = 3;

	// �迭�� [�̸�] ���� �ٸ��� ����
	// StatInfo players[10];
	// players = monsters;

	// �迭�� �̸��� ?
	// �迭�� �̸��� �� �迭�� ���� �ּ�
	// ��Ȯ���� ���� ��ġ�� ����Ű�� TYPE* ������
	auto WhoAmI = monsters;

	StatInfo* monster_0 = monsters; // �迭�� ù �ּҸ� �����ͷ� �޾ư�
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// �������� ���� --> StatInfo Ÿ�� �ٱ��� �Ѱ��� �̵��϶�� �ǹ�

	StatInfo* monster_1 = monsters + 1; // ���� �ּҸ� ����Ŵ
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// �����Ϳ� ������ ��������� ��ȯ����
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// ������ �ٸ� �ǹ�
	StatInfo temp = *(monsters + 2); // �迭�� 3��° �ּ��� �����͸� temp�� ������
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4; // temp�� �ٲ�� ������ �ȹٲ�


	// �̸� �� �� �ڵ�ȭ
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = 1 * (i + 1);
	}

	// *(monsters+i) ����, ������ ������
	// �ε��� ���
	// �迭 �ε��� 0������ ���� �迭�̸�[N]
	// *(monsters+i) = monsters[N]

	monsters[0].hp = 100;
	monsters[0].attack = 100;
	monsters[0].defence = 100;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = monsters[i];
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = 1 * (i + 1);
	}

	// �迭 �ʱ�ȭ ����
	int numbers[5] = {}; // 0���� �ʱ�ȭ
	int numbers1[10] = { 1,2,3,4,5 }; // ���� �� �̿ܿ� ���� 0���� �ʱ�ȭ
	int numbers2[] = { 1,2,3,4,5,6,7,8,9 }; // ������ ũ�⿡ �ش��ϴ� �迭�� �������

	char helloStr[] = { 'H','e','l','l','o','\0' };
	cout << helloStr << endl;


	return 0;
}