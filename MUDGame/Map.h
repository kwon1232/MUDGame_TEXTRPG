#pragma once


// ���� �� ���� �̵�

typedef enum MAPTYPE
{
	Dungeon,
	Village
}_MapType;

typedef struct DUNGEON
{
	_Direction Direction;
}_Dungeon;

typedef struct MAP
{
	_Dungeon Dungeon;
	_MapType MapType;
}_Map;



void CreateDungeonMap();
