#include "framework.h"
#include "DungeonMatrix.h"

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

	// 무작위 미로 맵 로직 추가
	
	// 틱으로 2~4초 간격으로 몬스터랑 만남
	// 몬스터 3마리 잡으면 다음 던전으로 갈지, 아니면 마을로 돌아갈지 선택 가능
	// 던전 0 인덱스 -> 던전 1 인덱스 순으로 순차적으로 접근해야함

	
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

