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

// 상,하,좌,우 이동 - 이때 벽을 고려하여 2칸씩 이동하는 것으로 설정함
//const int DIR[4][2] = { {0,-2},{0,2},{-2,0},{2,0} };
//
//void shuffleArray(int array[], int size);
//
//int inRange(int y, int x);
//
//// 깊이 우선 탐색 맵 형성
//void generateMap(int y, int x, int map[MAP_HEIGHT][MAP_WIDTH]);

//COORD getRandomStartingPoint();

