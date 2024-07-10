#define _CRT_SECURE_NO_WARNINGS 


#include "MUDGame.h"
#include "Framework.h"

int main()
{
	SetConsoleTitle(TEXT("TEXTRPG"));
	system("mode con:cols=150 lines=50");
	srand(time(NULL));

	int mouse_x = 0, mouse_y = 0, keyCode = 0;
	Player player;
	player.PlayerJobType = None;
	while (true)
	{
		GaneStarOrGameEixt(&keyCode);

		if (keyCode == 2) return;
		SelectPlayerJob(keyCode, &player);
	}
	


	return 0;
}

