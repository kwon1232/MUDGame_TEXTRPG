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
	strcpy(VillageMap[3].VillageName, villageName[3]);

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
