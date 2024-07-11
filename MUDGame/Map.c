#include "Framework.h"

void MapInitialization(struct VILLAGE VillageMap[3], struct DUNGEON DungeonMap[3])
{
	char villageName[3][120] = {
		"숲 속 마을",
		"울창한 숲 속 마을",
		"얕은 바닷가 마을"
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

