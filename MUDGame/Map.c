#include "Framework.h"

void MapInitialization(struct VILLAGE VillageMap[3], struct DUNGEON DungeonMap[3])
{
	char villageName[4][120] = {
		"�� �� ����",
		"�޸��� ����",
		"�غ� ����"
		"���� ����"
	};
	char DungeonName[3][120] = {
		"���ֱ� ����",
		"�� �� ������ ����",
		"���� �غ��� ����"
	};


	for (int i = 0; i < 3; i++)
	{
		VillageMap[i].Map.MapType = EVillage;
		DungeonMap[i].Map.MapType = EDungeon;
	}
	VillageMap[3].Map.MapType = EVillage;

	for (int idx = 0; idx < 4; idx++)
	{
		VillageMap[idx].VillageNum = idx;
		if (VillageMap[idx].Map.MapType == EVillage)
		{
			strcpy(VillageMap[idx].VillageName, villageName[idx]);
		}
	}
	for(int idx = 0; idx < 3; idx++)
	{
		DungeonMap[idx].DungeonNum = idx;
		if (DungeonMap[idx].Map.MapType == EDungeon)
		{
			strcpy(DungeonMap[idx].DungeonName, DungeonName[idx]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		switch (DungeonMap[i].DungeonNum)
		{
		case 0:
			DungeonMap->DungeonType = EStempDungeon;
			break;
		case 1:
			DungeonMap->DungeonType = EFairyDungeon;
			break;
		case 2:
			DungeonMap->DungeonType = EDailDinoDungeon;
			break;
		}
	}

}
