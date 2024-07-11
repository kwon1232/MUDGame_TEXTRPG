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
}_Dungeon;


void PrintDungeonIntro();

// ��,��,��,�� �̵� - �̶� ���� ����Ͽ� 2ĭ�� �̵��ϴ� ������ ������
//const int DIR[4][2] = { {0,-2},{0,2},{-2,0},{2,0} };
//
//void shuffleArray(int array[], int size);
//
//int inRange(int y, int x);
//
//// ���� �켱 Ž�� �� ����
//void generateMap(int y, int x, int map[MAP_HEIGHT][MAP_WIDTH]);

//COORD getRandomStartingPoint();

