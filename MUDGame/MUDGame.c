#define _CRT_SECURE_NO_WARNINGS 


#include "Framework.h"
#include "MUDGame.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

int main()
{
	SetConsoleTitle(TEXT("TEXTRPG"));
	srand(time(NULL));

	int mouse_x = 0, mouse_y = 0, keyCode = 0;
	Player player;
	playerInitialization(&player);

	_Village VillageMap[4];
	_Dungeon DungeonMap[3];
	PlaySound(TEXT("../aaa.wav"), NULL, SND_ASYNC | SND_LOOP);
	MapInitialization(VillageMap, DungeonMap);
	while (true)
	{
		PrintIntroMenu();
		system("mode con:cols=100 lines=25");
		GaneStarOrGameEixt(&keyCode);
		if (keyCode == 2) return;
		SelectPlayerJob(&player);
		SellecVillage(VillageMap, &player, DungeonMap);
	}
	


	return 0;
}

