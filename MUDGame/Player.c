#include "Framework.h"


void controlCharacter(Player* player)
{
	if ((GetAsyncKeyState(VK_UP) & 0x8000) || (GetAsyncKeyState(0X57) & 0x8000))
	{
		if (player->pPlane.y > 0) 
		{
			player->pPlane.y--;
		}
	}
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000) || (GetAsyncKeyState(0x53) & 0x8000))
	{
		if (player->pPlane.y < 50 - 1)
		{
			player->pPlane.y++;
		}
	}
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState(0x41) & 0x8000))
	{
		if (player->pPlane.x > 0)
		{
			player->pPlane.x -= 2;
		}
	}
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState(0x44) & 0x8000))
	{
		if (player->pPlane.x < 150 - 2)
		{
			player->pPlane.x += 2;
		}
	}
}

void playerInitialization(Player* player)
{
	playerInventoryInitial(player);
	player->SkillPoint = 3;
	player->JobStepType = ENone_JobType;
	player->Level = 1;
	player->TrainingCenterCount = 5;
	
	playerQuestListInitial(player);

	switch (player->PlayerJobType)
	{
	case EWizard:
	{
		playerWizardSkillInitial(player, player->SkillPoint);
	}
	break;
	case EWarrior:
	{
		playerWarriorSkillInitial(player, player->SkillPoint);
	}
	break;
	case EArcher:
	{
		playerArcherSkillInitial(player, player->SkillPoint);
	}
	break;
	case ENone_JobType:
	{
		player->SkillPoint = 0;
		playerWizardSkillInitial(player, player->SkillPoint);
		playerWarriorSkillInitial(player, player->SkillPoint);
		playerArcherSkillInitial(player, player->SkillPoint);
	}
	}
}

void playerInventoryInitial(Player* player)
{
	player->PInventory.emerald = 0;
	player->PInventory.gold = 0;
	player->PInventory.HPpotion = 0;
	player->PInventory.MPpotion = 0;
	player->PInventory.wood = 0;
	player->PInventory.MaxOwnItem = 20;
	player->PInventory.MaxOwnPotion = 20;
}

void playerQuestListInitial(Player* player)
{
	for (int i = 0; i < QuestListCount; i++)
	{
		player->P_Quest.CheckCompleteQuestList[i] = false;
		player->P_Quest.CheckAcceptQuestList[i] = false;
	}
	strcpy(player->P_Quest.QuestListStr[0], "Q.N-1");
	strcpy(player->P_Quest.QuestListStr[1], "Q.N-2");
	strcpy(player->P_Quest.QuestListStr[2], "Q.D-1");
	strcpy(player->P_Quest.QuestListStr[3], "Q.D-2");
	strcpy(player->P_Quest.QuestListStr[4], "Q.B-1");
	strcpy(player->P_Quest.QuestListStr[5], "Q.B-2");
	strcpy(player->P_Quest.QuestListStr[6], "Q.I-1");
	strcpy(player->P_Quest.QuestListStr[7], "Q.I-2");
}
