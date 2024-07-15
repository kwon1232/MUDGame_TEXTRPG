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

enum EMonsterSkillType
{
	EVinesBat,
	ECurseofForest,
	EPowerofMystery,
	EWonderSteam,
	ECurseOfSwamp,
	EThrowingMud,
	EGameOfDirt
};

typedef struct STEMPMONSTERSKILL
{
	// ���� �����
	int VinesBat;
	// ���� ����
	int CurseofForest;
	char skillName[2][120];
}_StempMonsterSkill;

typedef struct FAIRYMONSTERSKILL
{
	// �ź��� ��
	int PowerofMystery;
	// ����ձ�
	int WonderSteam;
	char skillName[2][120];
}_FairyMonsterSkill;

typedef struct DAILMONSTERSKILL
{
	// ���� ����
	int CurseOfSwamp;
	// ���� ������
	int ThrowingMud;
	char skillName[2][120];
}_DailMonsterSkill;

typedef struct DINOMONSTERSKILL
{
	// ������ ����
	int GameOfDirt;
	char skillName[120];
}_DinoMonsterSkill;

typedef struct MONSTER
{
	int Level;
	_DinoMonsterSkill DinoMonsterSkill;
	_DailMonsterSkill DailMonsterSkill;
	_FairyMonsterSkill FairyMonsterSkill;
	_StempMonsterSkill StempMonsterSkill;
	enum EMonsterSkillType MonsterSkillType;
	char MonsterName[120];
	enum MonsterType monsterType;
	int Hp;
	int Mp;
	int Attack;
}_Monster;


void MonsterInitial(struct DUNGEON* dungeon, _Monster* monster);
void MonsterSetSkill(_Monster* monster);

void MonsterAtk(_Monster* monster, Player* player);

// Monster Atk effect to Player Quickness
bool AvoidMonsterAttackWithPlayerQuickness(_Monster* monster, Player* player);

// Player Atk Monster
void PlayerAtkMonster(_Monster* monster, Player* player);
void PlayerSkillAtkMonster(_Monster* monster, Player* player);
