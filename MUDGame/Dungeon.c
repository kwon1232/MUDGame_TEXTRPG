#include "framework.h"
#include "DungeonMatrix.h"


//Dungeon
#define START 3    //���� ����
#define FINISH 4    //���� ����
#define PLAYER_ 20    //�÷��̾�
#define WALL 1    //�� - �÷��̾ ������ ���� �� �ϴ� ��.
#define SPACE 0    //�� ���� - �� �÷��̾ �̵��� �� �ִ� ��.
#define RMS 25    //��ǰ �迭�� ũ��


char* pMap[] = { "  ", "��" };    //���� ����Ʈ�� �� ����Ѵ�. 
int **map, mapSize, ** backupMap;    //�����Ҵ��� �ʰ� �Ҵ�� ���� ũ��
int level = 1, timer = 0;    //���� ����, Ÿ�Ӿƿ����� ���� �ð�



void DungeonInitial(_Dungeon dungeonArr[], Player* player)
{
	pMap[0] = " ";
	pMap[1] = "��";
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
	// ���⼭ �Լ� -> ���� -> Ż���� �ݺ��ؼ� ������ ���� ��Ű�� �迭 �������� ���⸸ �˰Բ� ���ֱ�
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
			printf("\n%s(��)�� ������ ���ư� �� �ֽ��ϴ�.\n", player->PlayerName);
			player->Hp = player->MaxHp;
			player->Mp = player->MaxMp;
			Sleep(1200);
			int num;
			printf("\n1. ������ ���ư���.\n");
			printf("2. ��� ������ Ž���Ѵ�\n");
			scanf("%d", &num);
			if (num == 1)
				return;
		}
		printf("��! ���Ͱ� �����ߴ�!\n\n");
		Sleep(1000);
		// ������ �����ϴ� ���� ��������ֱ�
		printf("������ �����մϴ�!\n");
		Sleep(1200);
		struct MONSTER monster;

		MonsterInitial(dungeon, &monster);

		while (true)
		{
			system("cls");
			printf("������ ���� ����! \n");
			// ���� ���� ����
			MonsterAtk(&monster, player);
			if (monster.Hp <= 0)
			{
				system("cls");
				printf("\n%s(��)�� �������� �¸��߽��ϴ�!\n", player->PlayerName);
				// ���� ������ ���� ������ �߰����ְ� ����Ʈ �Ϸ����ִ� ���� ������ֱ�
				Sleep(1200);
				break;
			}
			else if (player->Hp <= 0)
			{
				system("cls");
				printf("\n%s(��)�� �������� �й��߽��ϴ�!\n", player->PlayerName);
				printf("\n������ ���ư��ϴ�!");

				return;
			}

			printf("�÷��̾��� ���� ����! \n");
			// �÷��̾��� ���� ����
			PlayerAtkMonster(&monster, player);
			if (player->avoid)
			{
				player->monsterHuntingCount++;
				break;
			}

			if (monster.Hp <= 0)
			{
				system("cls");
				printf("\n%s(��)�� �������� �¸��߽��ϴ�!\n", player->PlayerName);
				player->monsterHuntingCount++;
				// ���� ������ ���� ������ �߰����ְ� ����Ʈ �Ϸ����ִ� ���� ������ֱ�
				PlayerAddItem(player, &monster);
				Sleep(1200);
				break;
			}
			else if (player->Hp <= 0)
			{
				system("cls");
				printf("\n%s(��)�� �������� �й��߽��ϴ�!\n", player->PlayerName);
				printf("\n������ ���ư��ϴ�!");

				return;
			}
			Sleep(1000);

		}
	}
}

void PrintDungeonIntro(_Dungeon* dungeon)
{
	// ��� ������ �����ߴ���?
	// ���� ��Ʈ�η� �� �� �ִ� �̻� �׸�!
	// ���ص� �����ƿ�~
	system("cls");
	system("cls");
	printf("/|\\^._.^/|\\ %s�� �����ϼ̽��ϴ�! /|\\^._.^/|\\\n", dungeon->DungeonName);
	Sleep(1000);
	system("cls");

	// ������ �̷� �� ���� �߰�
	
	// ƽ���� 2~4�� �������� ���Ͷ� ����
	// ���� 3���� ������ ���� �������� ����, �ƴϸ� ������ ���ư��� ���� ����
	// ���� 0 �ε��� -> ���� 1 �ε��� ������ ���������� �����ؾ���

	
}

void SetMap(_Dungeon* dungeon)
{
	mapSize = level * 100;
	// ���� 2���� �迭�� �����Ҵ� ��Ŵ
	map = (int**)malloc(sizeof(int*) * mapSize);

	for (int i = 0; i <= mapSize; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * mapSize);
	}
	
	// �����Ҵ� �� ���� ���� �� �������� �ʱ�ȭ ������
	for (int i = 0; i <= mapSize; i++)
	{
		for (int j = 0; j <= mapSize; j++)
		{
			map[i][j] = SPACE;
		}
	}
	// Ÿ�Ӿƿ� �ð�(== ���� ���� �ð�)�� level * 30��~ 1�� 30���ε� ���߿� ������ ��ġ ����!
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
//	int PosX = 1, PosY = 1;    //�÷��̾��� ��ǥ
//	sprintf(title, "title �̷�ã�� - %d�ܰ�", level);
//	system(title);
//	system("mode con: cols=100 lines=50");    //50 * 50��ŭ ����� â
//	SetMap();    //�� ���¿��� ������� �ڵ� �� ����
//}
//
//
//void PrintMap(int PosX, int PosY) {
//	int CameraPosX = 0, CameraPosY = 0;    //ī�޶� ��ǥ
//
//	//�����Ͱ� �ƴϱ� ������ Pos���� �ٲ㵵 ������.
//	if (PosX < 25) PosX = 0;   //ī�޶� ���� ���κ��� �ε����� ��
//	else if (PosX > mapSize - 26) PosX = mapSize - 50;    //ī�޶� ������ ���κ��� �ε����� ��
//	else PosX = PosX - 25;
//
//	if (PosY < 25) PosY = 0;    //ī�޶� ���� ���κ��� �ε����� ��
//	else if (PosY > mapSize - 26) PosY = mapSize - 50;    //ī�޶� �Ʒ��� ���κ��� �ε����� ��
//	else PosY = PosY - 25;
//
//	for (int i = 0; i < 50; i++) {
//		for (int j = 0; j < 50; j++) {
//			CameraPosX = PosX + j; CameraPosY = PosY + i;  //ī�޶�� ���� ��ǥ + ��µǴ� �ε�����.
//			gotoxy(j * 2, i);  //gotoxy�� �ֿܼ��� �Է��� ���̴� �״�� ���ָ� ��.
//			if (map[CameraPosY][CameraPosX] == PLAYER) {  //�÷��̾ ���
//				SetColor(10);
//				printf("��");
//				SetColor(15);
//			}
//			else if (map[CameraPosY][CameraPosX] == FINISH) {  //�ǴϽ� ��Ҹ� ���
//				SetColor(204);
//				printf("  ");
//				SetColor(15);
//			}
//			else printf("%s", pMap[map[CameraPosY][CameraPosX]]);  //�� �� ���̳� ������ ���
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
//	sprintf(title, "title �̷�ã�� - %d�ܰ�", level);
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