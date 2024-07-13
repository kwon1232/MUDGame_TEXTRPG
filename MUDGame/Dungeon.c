#include "framework.h"
#include "DungeonMatrix.h"


//Dungeon
#define START 3    //시작 지점
#define FINISH 4    //도착 지점
#define PLAYER_ 20    //플레이어
#define WALL 1    //벽 - 플레이어가 막혀서 가지 못 하는 곳.
#define SPACE 0    //빈 공간 - 즉 플레이어가 이동할 수 있는 곳.
#define RMS 25    //부품 배열의 크기


char* pMap[] = { "  ", "■" };    //맵을 프린트할 때 사용한다. 
int **map, mapSize, ** backupMap;    //동적할당할 맵과 할당된 맵의 크기
int level = 1, timer = 0;    //현재 레벨, 타임아웃까지 남은 시간


void DungeonInitial(_Dungeon dungeonArr[], Player* player, _Dungeon* dungeon)
{
	pMap[0] = " ";
	pMap[1] = "■";
	level = 1;
	timer = 0;
	PrintDungeonIntro();
	// 여기서 함수 -> 입장 -> 탈출을 반복해서 로직을 진행 시키고 배열 시작점은 여기만 알게끔 해주기
	SetMap(dungeon);
}

void DungeonEntrance()
{

}

void PrintDungeonIntro()
{
	// 어느 던전에 입장했는지?
	// 던전 인트로로 쓸 수 있는 이쁜 그림!
	// 안해두 괜찮아요~
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

void SetMap(_Dungeon* dungeon)
{
	mapSize = level * 100;
	// 맵을 2차원 배열로 동적할당 시킴
	map = (int**)malloc(sizeof(int*) * mapSize);

	for (int i = 0; i <= mapSize; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * mapSize);
	}
	
	// 동적할당 된 맵을 전부 빈 공간으로 초기화 시켜줌
	for (int i = 0; i <= mapSize; i++)
	{
		for (int j = 0; j <= mapSize; j++)
		{
			map[i][j] = SPACE;
		}
	}
	// 타임아웃 시간(== 몬스터 스폰 시간)은 level * 30초~ 1분 30초인데 나중에 벨런스 패치 가능!
	timer = level * rand()% 29 + 60;

	int num = mapSize / RMS;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			srand((unsigned)time(NULL) * (i + j));
			int** arr = RollingArray(RandomMap[rand() % 2], rand() % 3, ((i == 0 && j == 0) || (i == num - 1 && j == num - 1)) ? 0 : (rand() % 5));
			for (int AH = RMS * i, height = 0; height < RMS; height++, AH++) {
				for (int AW = RMS * j, width = 0; width < RMS; width++, AW++) {
					map[AH][AW] = arr[height][width];
				}
				
			}
		}
	}

	for (int i = 0; i < mapSize; i++) {
		map[i][0] = WALL;
		map[0][i] = WALL;
		map[i][mapSize - 1] = WALL;
		map[mapSize - 1][i] = WALL;
	}
	
	FILE* fp = fopen("../data/mapTest.txt", "wt");
	for (int i = 0; i <= mapSize; i++) {
		for (int j = 0; j <= mapSize; j++) {
			fprintf(fp, "%s", pMap[map[i][j]]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);

	//for (int i = 0; i < mapSize; i++)
	//	free(map[i]);
	//free(map);

}

int** RollingArray(int MapArr[25][25], int num, int block)
{
	int** arr;
	//printf("%d\n", num);
	arr = (int**)malloc(sizeof(int*) * RMS);
	for (int i = 0; i < RMS; i++)
		arr[i] = (int*)malloc(sizeof(int) * RMS);

	for (int i = 0; i < num; i++) {
		int tempArr[RMS][RMS] = { 0 };
		for (int ii = 0; ii < RMS; ii++) {
			for (int j1 = RMS - 1, j2 = 0; j2 < RMS; j1--, j2++) {
				arr[ii][j2] = MapArr[j1][ii];
			}
		}
	}

	if (num == 0)
		for (int i = 0; i < RMS; i++) {
			for (int j = 0; j < RMS; j++)
				arr[i][j] = MapArr[i][j];
		}
	bool check[8] = { 0 };
	for (int i = 0; i < block; i++) {
		srand((unsigned)time(NULL) * (i + i));
		int random = rand() % 8;
		for (int i = 0; check[random]; i++) {
			if (i > 1000) {
				for (int j = 0; j < 8; j++)
					if (check[j] == false) {
						random = j;
						break;
					}
			}
			else random = rand() % 8;
		}

		check[random] = true;
		switch (random) {
		case 0:
			arr[1][0] = WALL;
			break;
		case 1:
			arr[0][1] = WALL;
			break;
		case 2:
			arr[0][RMS - 2] = WALL;
			break;
		case 3:
			arr[1][RMS - 1] = WALL;
			break;
		case 4:
			arr[RMS - 2][0] = WALL;
			break;
		case 5:
			arr[RMS - 1][1] = WALL;
			break;
		case 6:
			arr[RMS - 2][RMS - 1] = WALL;
			break;
		case 7:
			arr[RMS - 1][RMS - 2] = WALL;
			break;
		}
	}
	return arr;

}




