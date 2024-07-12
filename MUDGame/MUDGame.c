#define _CRT_SECURE_NO_WARNINGS 


#include "Framework.h"
#include "MUDGame.h"

int main()
{
	SetConsoleTitle(TEXT("TEXTRPG"));
	srand(time(NULL));

	int mouse_x = 0, mouse_y = 0, keyCode = 0;
	Player player;
	playerInitialization(&player);

	_Village VillageMap[3];
	_Dungeon DungeonMap[3];

	MapInitialization(VillageMap, DungeonMap);
	while (true)
	{
		PrintIntroMenu();
		system("mode con:cols=100 lines=25");
		GaneStarOrGameEixt(&keyCode);
		if (keyCode == 2) return;
		SelectPlayerJob(keyCode, &player);
		VillageIntro(&VillageMap[0], &player, DungeonMap);
	}
	


	return 0;
}

