#pragma once

typedef struct CharacterPos
{
	int x, y, size_x, size_y;
	char sprite[6];
}Plane;

// WIZARD
typedef struct DEFAULTWIZARDSKILL
{
	int FireBall;
	int SnowBall;
	int LightBall;
}DefaultWizardSkill;

typedef struct BEGINNERWIZARDSKILL
{
	int FireBeam;
	int AquaBeam;
	int LightingBeam;
}BeginnerWizardSkill;

typedef struct INTERMEDIATETWIZARDSKILL
{
	int FireSpike;
	int ConOfIce;
}IntermediateWizardSkill;

// WARRIOR
typedef struct DEFAULTWARRIORSKILL
{
	int Blade;
	int Phantom;
	int Hellfire;
}DefaultWarriorSkill;

typedef struct BEGINNERWARRIORSKILL
{
	int BletInfinity;
	int Damascus;
	int Judgment;
}BeginnerWarriorSkill;

typedef struct INTERMEDIATETWARRIORSKILL
{
	int BloodInfinite;
	int Duellatorum;
}IntermediateWarriorSkill;

// Archer
typedef struct DEFAULTARCHERSKILL
{
	int IceArrow;
	int FireArrow;
	int BustArrow;
}DefaultArcherSkill;

typedef struct BEGINNERARCHERSKILL
{
	int PosionArrow;
	int LightningArrow;
	int WindBoom;
}BeginnerArcherSkill;

typedef struct INTERMEDIATETARCHERSKILL
{
	int Evolve;
	int IllusionStep;
}IntermediateArcherSkill;

enum CharacterJobType
{
	ENone_JobType = 0,
	EWizard = 1,
	EWarrior = 2,
	EArcher = 3,
};

enum CharacterJobStepType
{
	ENone_JobStepType,
	EDefault,
	EBeginner,
	EIntermediate,
	EAll
};

typedef struct CHARACTERJOBSKILL
{
	DefaultWizardSkill Default_WizardSkill;
	BeginnerWizardSkill Beginner_WizardSkill;
	IntermediateWizardSkill Intermediate_WizardSkill;

	DefaultWarriorSkill Default_WarriorSkill;
	BeginnerWarriorSkill Beginner_WarriorSkill;
	IntermediateWarriorSkill Intermediate_WarriorSkill;

	DefaultArcherSkill Default_ArcherSkill;
	BeginnerArcherSkill Beginner_ArcherSkill;
	IntermediateArcherSkill Intermediate_ArcherSkill;
}CharacterJobSkill;

typedef struct INVENTORY
{
	int MaxOwnItem;
	int MaxOwnPotion;
	int HPpotion;
	int MPpotion;
	int gold;
	int wood;
	int emerald;
}Inventory;

// TODO. 몬스터별로 아이템 드랍하고
// 몬스터 처치히면 퀘스트 리스트 가져와서
// 달성 상태 체크해줘야 함
// 마을로 돌아갔을 때 달성했다면 퀘스트 완료 목록 보이게 로직 짜기
typedef struct P_QUEST
{
	bool CheckCompleteQuestList[QuestListCount];
	bool CheckAcceptQuestList[QuestListCount];
	char QuestListStr[QuestListCount][40];
	int DarkStempNum;
	int ShadeFairyNum;
	int FallenTreeFairy;
	int Dail;
	int XStemp;
}_P_Quest;

typedef struct PLAYER
{
	char PlayerJobName[60];
	char PlayerName[120];
	Inventory PInventory;
	Plane pPlane;
	CharacterJobSkill JobSkillList;
	enum CharacterJobStepType JobStepType;
	enum CharacterJobType PlayerJobType;
	_P_Quest P_Quest;
	int Hp;
	int MaxHp;
	int Mp;
	int MaxMp;
	int Attack;
	int Quickness;
	int SkillPoint;
	int Level;
	int TrainingCenterCount;
	bool avoid;
	int dungeonplayIdx;
	int monsterHuntingCount;
}Player;

// 전체 맵 초기화 
//void fileMap(char str[], char str_s, int max_value);

// 플레이어 움직임 함수
void controlCharacter(Player* player);

// 플레이어 초기화
void playerInitialization(Player* player);

void playerInventoryInitial(Player* player);

void playerQuestListInitial(Player* player);


// Wizard
int playerWizardSkillReset(Player* player, int SkillPoint);

int playerWizardDefaultSkillReset(Player* player, int SkillPoint);
int playerWizardBeginnerSkillReset(Player* player, int SkillPoint);
int playerWizardIntermediateSkillReset(Player* player, int SkillPoint);

// Warrior
int playerWarriorSkillReset(Player* player, int SkillPoint);

int playerWarriorDefaultSkillReset(Player* player, int SkillPoint);
int playerWarriorBeginnerSkillReset(Player* player, int SkillPoint);
int playerWarriorIntermediateSkillReset(Player* player, int SkillPoint);


// Archer
int playerArcherSkillReset(Player* player, int SkillPoint);

int playerArcherDefaultSkillReset(Player* player, int SkillPoint);
int playerArcherBeginnerSkillReset(Player* player, int SkillPoint);
int playerArcherIntermediateSkillReset(Player* player, int SkillPoint);

// All Job Skill Initial
void playerWizardSkillInitial(Player* player);
void playerWarriorSkillInitial(Player* player);
void playerArcherSkillInitial(Player* player);




//Skill Update

// Player Skill List
void PlayerSkillListPrint(Player* player);
// Player Skill Up
void PlayerSkillUp(Player* player);


//Add Item
void PlayerAddItem(Player* player, struct MONSTER* monster);


// Quest
void CheckPlayerQuestList(Player* player);
