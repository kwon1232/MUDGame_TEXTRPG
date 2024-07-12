#include "Framework.h"

void MapInitialization(struct VILLAGE VillageMap[3], struct DUNGEON DungeonMap[3])
{
	char villageName[4][120] = {
		"숲 속 마을",
		"달맞이 마을",
		"해변 마을"
		"폭포 마을"
	};
	char DungeonName[3][120] = {
		"오솔길 던전",
		"숲 속 늪지대 던전",
		"얕은 해변가 던전"
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
