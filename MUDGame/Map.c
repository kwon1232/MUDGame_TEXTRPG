#include "Framework.h"

void MapInitialization(struct VILLAGE VillageMap[3], struct DUNGEON DungeonMap[3])
{
	char villageName[3][120] = {
		"�� �� ����",
		"��â�� �� �� ����",
		"���� �ٴ尡 ����"
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

	for(int idx = 0; idx < 3; idx++)
	{
		if (VillageMap[idx].Map.MapType == EVillage)
		{
			strcpy(VillageMap[idx].VillageName, villageName[idx]);
		}
		if (DungeonMap[idx].Map.MapType == EDungeon)
		{
			strcpy(DungeonMap[idx].DungeonName, DungeonName[idx]);
		}
	}

	//for (int i = 0; i < 3; i++) {
	//	printf("Village %d: %s\n", i + 1, VillageMap[i].VillageName);
	//	printf("Dungeon %d: %s\n", i + 1, DungeonMap[i].DungeonName);
	//}
	for (int i = 0; i < 3; i++) 
	{
		VillageMap[i].VillageNum = i + 1;
		DungeonMap[i].DungeonNum = i + 1;
	}

}

