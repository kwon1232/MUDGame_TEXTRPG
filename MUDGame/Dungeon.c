#include "framework.h"

void DungeonInitial(_Dungeon dungeon[], Player* player)
{
	dungeon->pMap[0] = " ";
	dungeon->pMap[1] = "■";
	dungeon->Dungeonlevel = 1;
	PrintDungeonIntro();
}

void DungeonEntrance()
{
}

void PrintDungeonIntro()
{
	system("cls");
	system("cls");
	printf("/|\\^._.^/|\\ 던전에 입장하셨습니다! /|\\^._.^/|\\\n");
	Sleep(1000);
	system("cls");
}

//void shuffleArray(int array[], int size)
//{
//}
//
//int inRange(int y, int x)
//{
//	return 0;
//}
//
//void generateMap(int y, int x, int map[MAP_HEIGHT][MAP_WIDTH])
//{
//}

