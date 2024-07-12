#pragma once


enum MonsterType
{
	EXStemp,
	EStemp,
	EDarkStemp,
	EFallenTreeFairy,
	EShadeFairy,
	EDail,
	EDino
};


//typedef struct STEMPMONSTERSKILL
//{
//	
//}StempMonsterSkill;

//typedef struct FAIRYMONSTERSKILL
//{
//	
//}FairyMonsterSkill;
//
//typedef struct DAILMONSTERSKILL
//{
//
//}DailMonsterSkill;
//
//typedef struct DINOMONSTERSKILL
//{
//
//}DINOMonsterSkill;

typedef struct MONSTER
{
	int Level;
	char MonsterName[120];
	enum MonsterType monsterType;
	int Hp;
	int Mp;
	int Attack;
}_Monster;


void MonsterInitial(_Dungeon* dungeon, _Monster* monster, Player* player);
void MonsterSetSkill(_Monster* monster);

void MonsterAtk(_Monster* monster, Player* player);
