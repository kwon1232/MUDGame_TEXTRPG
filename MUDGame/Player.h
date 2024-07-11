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

typedef struct P_QUEST
{
	bool CheckCompleteQuestList[QuestListCount];
	bool CheckAcceptQuestList[QuestListCount];
	char QuestListStr[QuestListCount][40];
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
	int Mp;
	int Attack;
	int Quickness;
	int SkillPoint;
	int Level;
	int TrainingCenterCount;
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
int playerWizardSkillInitial(Player* player, int SkillPoint);

int playerWizardDefaultSkillInitial(Player* player, int SkillPoint);
int playerWizardBeginnerSkillInitial(Player* player, int SkillPoint);
int playerWizardIntermediateSkillInitial(Player* player, int SkillPoint);

// Warrior
int playerWarriorSkillInitial(Player* player, int SkillPoint);

int playerWarriorDefaultSkillInitial(Player* player, int SkillPoint);
int playerWarriorBeginnerSkillInitial(Player* player, int SkillPoint);
int playerWarriorIntermediateSkillInitial(Player* player, int SkillPoint);

// Archer
int playerArcherSkillInitial(Player* player, int SkillPoint);

int playerArcherDefaultSkillInitial(Player* player, int SkillPoint);
int playerArcherBeginnerSkillInitial(Player* player, int SkillPoint);
int playerArcherIntermediateSkillInitial(Player* player, int SkillPoint);

