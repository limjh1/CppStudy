#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton =3
};

class Monster1 : public Creature
{
public:
	Monster1(int monsterType)
		: Creature(CT_Monster), _monsterType(monsterType)
	{

	}

	virtual void PrintInfo();

protected:
	int _monsterType;

};

class Slime : public Monster1
{
public:
	Slime() : Monster1(MT_Slime)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
};

class Orc : public Monster1
{
public:
	Orc() : Monster1(MT_Orc)
	{
		_hp = 80;
		_attack = 8;
		_defence = 3;
	}
};

class Skeleton : public Monster1
{
public:
	Skeleton() : Monster1(MT_Skeleton)
	{
		_hp = 100;
		_attack = 15;
		_defence = 4;
	}
};

