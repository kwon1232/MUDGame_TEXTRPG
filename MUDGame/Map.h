#pragma once

// 던전 및 던전 이동

typedef enum MAPTYPE
{
	EDungeon,
	EVillage
}_MapType;

typedef struct MAP
{
	_MapType MapType;
}_Map;


void MapInitialization(struct VILLAGE VillageMap[3], struct DUNGEON DungeonMap[3]);

