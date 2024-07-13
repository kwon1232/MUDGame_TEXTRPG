#pragma once

typedef enum _DIRECTION
{
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_RIGHT,
	DIRECTION_DOWN
} _Direction;

typedef enum MAPFLAG
{
	MAP_FLAG_WALL,
	MAP_FLAG_EMPTY,
	MAP_FLAG_VISITED,
}_MapFlag;

typedef struct DUNGEON
{
	_Map Map;
	_Direction Direction;
	char DungeonName[120];
	int DungeonNum;
	//char* pMap[2];
	//int** dungeonMapPtr, dungeonMapSize, ** DungeonBackMap;
	//int Dungeonlevel, DungeonTimer;
	// ���� ������ ���� �����Ǵ� ���� Ÿ�� �ٲ��ֱ�
}_Dungeon;


void DungeonInitial(_Dungeon dungeonArr[], Player* player, _Dungeon* dungeon);

void DungeonEntrance();

void PrintDungeonIntro();

// �̷� ��

void SetMap(_Dungeon* dungeon);

int** RollingArray(int MapArr[25][25], int num);


