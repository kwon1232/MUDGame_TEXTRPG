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



void DungeonInitial(_Dungeon dungeonArr[], Player* player)
{
	pMap[0] = " ";
	pMap[1] = "■";
	level = 1;
	timer = 0;
	player->TrainingCenterCount = 5;

	int DungeonLevel = 0;
	player->Hp = player->MaxHp;
	player->Mp = player->MaxMp;

	if (player->Level <= 1)
	{
		PrintDungeonIntro(&dungeonArr[DungeonLevel]);
		DungeonMatchup(player, &dungeonArr[DungeonLevel]);
	}
	// 여기서 함수 -> 입장 -> 탈출을 반복해서 로직을 진행 시키고 배열 시작점은 여기만 알게끔 해주기
	//SetMap(dungeon);

}

void DungeonMatchup(Player* player, _Dungeon* dungeon)
{
	while (true)
	{
		system("cls");
		if (player->monsterHuntingCount == 3)
		{
			system("cls");
			printf("\n%s(이)는 마을로 돌아갈 수 있습니다.\n", player->PlayerName);
			player->Hp = player->MaxHp;
			player->Mp = player->MaxMp;
			Sleep(1200);
			int num;
			printf("\n1. 마을로 돌아간다.\n");
			printf("2. 계속 던전을 탐험한다\n");
			scanf("%d", &num);
			if (num == 1)
				return;
		}
		printf("앗! 몬스터가 등장했다!\n\n");
		Sleep(1000);
		// 대전을 시작하는 로직 실행시켜주기
		printf("대전을 시작합니다!\n");
		Sleep(1200);
		struct MONSTER monster;

		MonsterInitial(dungeon, &monster);

		while (true)
		{
			system("cls");
			printf("몬스터의 공격 시작! \n");
			// 몬스터 공격 로직
			MonsterAtk(&monster, player);
			if (monster.Hp <= 0)
			{
				system("cls");
				printf("\n%s(이)가 전투에서 승리했습니다!\n", player->PlayerName);
				// 몬스터 종류에 따라 아이템 추가해주고 퀘스트 완료해주는 로직 만들어주기
				Sleep(1200);
				break;
			}
			else if (player->Hp <= 0)
			{
				system("cls");
				printf("\n%s(이)가 전투에서 패배했습니다!\n", player->PlayerName);
				printf("\n마을로 돌아갑니다!");

				return;
			}

			printf("플레이어의 공격 시작! \n");
			// 플레이어의 공격 로직
			PlayerAtkMonster(&monster, player);
			if (player->avoid)
			{
				player->monsterHuntingCount++;
				break;
			}

			if (monster.Hp <= 0)
			{
				system("cls");
				printf("\n%s(이)가 전투에서 승리했습니다!\n", player->PlayerName);
				player->monsterHuntingCount++;
				// 몬스터 종류에 따라 아이템 추가해주고 퀘스트 완료해주는 로직 만들어주기
				PlayerAddItem(player, &monster);
				Sleep(1200);
				break;
			}
			else if (player->Hp <= 0)
			{
				system("cls");
				printf("\n%s(이)가 전투에서 패배했습니다!\n", player->PlayerName);
				printf("\n마을로 돌아갑니다!");

				return;
			}
			Sleep(1000);

		}
	}
}

void PrintDungeonIntro(_Dungeon* dungeon)
{
	// 어느 던전에 입장했는지?
	// 던전 인트로로 쓸 수 있는 이쁜 그림!
	// 안해두 괜찮아요~
	system("cls");
	system("cls");
	printf("/|\\^._.^/|\\ %s에 입장하셨습니다! /|\\^._.^/|\\\n", dungeon->DungeonName);
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
//https://blog.naver.com/ifthe1201/221056987564
//void GamePlay(void) {
//	int PosX = 1, PosY = 1;    //플레이어의 좌표
//	sprintf(title, "title 미로찾기 - %d단계", level);
//	system(title);
//	system("mode con: cols=100 lines=50");    //50 * 50만큼 출력할 창
//	SetMap();    //전 강좌에서 만들었던 자동 맵 생성
//}
//
//
//void PrintMap(int PosX, int PosY) {
//	int CameraPosX = 0, CameraPosY = 0;    //카메라 좌표
//
//	//포인터가 아니기 때문에 Pos값을 바꿔도 괜찮다.
//	if (PosX < 25) PosX = 0;   //카메라가 왼쪽 세로벽에 부딪혔을 때
//	else if (PosX > mapSize - 26) PosX = mapSize - 50;    //카메라가 오른쪽 세로벽에 부딪혔을 때
//	else PosX = PosX - 25;
//
//	if (PosY < 25) PosY = 0;    //카메라가 위쪽 가로벽에 부딪혔을 때
//	else if (PosY > mapSize - 26) PosY = mapSize - 50;    //카메라가 아래쪽 가로벽에 부딪혔을 때
//	else PosY = PosY - 25;
//
//	for (int i = 0; i < 50; i++) {
//		for (int j = 0; j < 50; j++) {
//			CameraPosX = PosX + j; CameraPosY = PosY + i;  //카메라는 현재 좌표 + 출력되는 인덱스다.
//			gotoxy(j * 2, i);  //gotoxy는 콘솔에서 입력할 것이니 그대로 해주면 됨.
//			if (map[CameraPosY][CameraPosX] == PLAYER) {  //플레이어를 출력
//				SetColor(10);
//				printf("●");
//				SetColor(15);
//			}
//			else if (map[CameraPosY][CameraPosX] == FINISH) {  //피니시 장소를 출력
//				SetColor(204);
//				printf("  ");
//				SetColor(15);
//			}
//			else printf("%s", pMap[map[CameraPosY][CameraPosX]]);  //그 외 벽이나 공간을 출력
//		}
//	}
//	return;
//}
//
//void PlayerMove(int* PosX, int* PosY, int Key) {
//	switch (Key) {
//	case VK_UP: if (map[*PosY - 1][*PosX] != WALL) { map[*PosY][*PosX] = SPACE; *PosY -= 1; } break;
//	case VK_DOWN: if (map[*PosY + 1][*PosX] != WALL) { map[*PosY][*PosX] = SPACE; *PosY += 1; } break;
//	case VK_LEFT: if (map[*PosY][*PosX - 1] != WALL) { map[*PosY][*PosX] = SPACE; *PosX -= 1; } break;
//	case VK_RIGHT: if (map[*PosY][*PosX + 1] != WALL) { map[*PosY][*PosX] = SPACE; *PosX += 1; } break;
//	}
//	map[*PosY][*PosX] = PLAYER;
//	return;
//}
//
//void GamePlay(void) {
//	int PosX = 1, PosY = 1, NowLevel = level;
//	char title[40] = { 0 };
//
//	sprintf(title, "title 미로찾기 - %d단계", level);
//	system(title);
//	system("mode con: cols=100 lines=50");
//	SetMap();
//	while (true) {
//		if (GetAsyncKeyState(VK_UP))
//			PlayerMove(&PosX, &PosY, VK_UP);
//		else if (GetAsyncKeyState(VK_DOWN))
//			PlayerMove(&PosX, &PosY, VK_DOWN);
//		else if (GetAsyncKeyState(VK_LEFT))
//			PlayerMove(&PosX, &PosY, VK_LEFT);
//		else if (GetAsyncKeyState(VK_RIGHT))
//			PlayerMove(&PosX, &PosY, VK_RIGHT);
//		PrintMap(PosX, PosY);
//		Sleep(1);
//	}
//	return;
//}