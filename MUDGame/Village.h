#pragma once

typedef enum VILLAGETYPE
{
	None_VillageStage,
	TrainingCenter,
	Store,
	Quest
}_VillageType;

// �Ʒ��� ���

typedef enum TRAININGCENTER
{
	ENone_TrainingCenter,
	EHPTrainingCenter,
	EMPTrainingCenter,
	ESkillTrainingCenter,
	EQuicknessTrainingCenter
}_TrainingCenterType;

// ����
typedef enum STORETYPE
{
	ENone_StoreStage,
	EHPPotion,
	EMPPotion,
	EWood,
	EEmerald
}_StoreType;

// ����Ʈ
typedef enum QUESTTYPE
{
	ENone_QuestType,
	EDefaultLevel,
	EBeginnerLevel,
	EIntermediateLevel
}_QuestType;

typedef struct VILLAGE
{
	_Map Map;
	_TrainingCenterType TrainingCenterType;
	_QuestType QuestType;
	_StoreType StoreType;
	_VillageType VillageType;
	char VillageName[120];
	int VillageNum;
}_Village;


void VillageIntro(_Village* village, Player* player, _Dungeon dungeon[]);

void VillageMainScene(_Village* village, Player* player, _Dungeon dungeon[]);

void TrainingCenterIntro(_Village* village, Player* player, _Dungeon dungeon[]);
void HPTrainingCenter(Player* player);
void MPTrainingCenter(Player* player);
void SkillTrainingCenter(Player* player);
void QuicknessTrainingCenter(Player* player);

void QuestIntro(_Village* village, Player* player, _Dungeon dungeon[]);
bool QuestAccept(Player* player, char QuestNum[]);

void StoreIntro(_Village* village, Player* player, _Dungeon dungeon[]);

void printShield();
void printBuyComplete();
void printSaleorBuyItem();


