#include "Framework.h"



int playerWizardSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;

	switch (player->JobStepType)
	{
	case EDefault:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardDefaultSkillReset(player, SkillPoint);
	}
	break;
	case EBeginner:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardBeginnerSkillReset(player, SkillPoint);
	}
	break;
	case EIntermediate:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardIntermediateSkillReset(player, SkillPoint);
	}
		break;
	case EAll:
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardDefaultSkillReset(player, SkillPoint);
		tempSkillPoint += playerWizardBeginnerSkillReset(player, SkillPoint);
		tempSkillPoint += playerWizardIntermediateSkillReset(player, SkillPoint);
	}

	return SkillPoint += tempSkillPoint;
}

int playerWizardDefaultSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Default_WizardSkill.FireBall >= 5)
	{
		player->JobSkillList.Default_WizardSkill.FireBall -= 5;
		tempSkillPoint += player->JobSkillList.Default_WizardSkill.FireBall;
		player->JobSkillList.Default_WizardSkill.FireBall = 5;
	}

	if (player->JobSkillList.Default_WizardSkill.SnowBall >= 5)
	{
		player->JobSkillList.Default_WizardSkill.SnowBall -= 5;
		tempSkillPoint += player->JobSkillList.Default_WizardSkill.SnowBall;
		player->JobSkillList.Default_WizardSkill.SnowBall = 5;
	}

	if (player->JobSkillList.Default_WizardSkill.LightBall >= 5)
	{
		player->JobSkillList.Default_WizardSkill.LightBall -= 5;
		tempSkillPoint += player->JobSkillList.Default_WizardSkill.LightBall;
		player->JobSkillList.Default_WizardSkill.LightBall = 5;
	}
	return tempSkillPoint;
}

int playerWizardBeginnerSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Beginner_WizardSkill.AquaBeam >= 10)
	{
		player->JobSkillList.Beginner_WizardSkill.AquaBeam -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WizardSkill.AquaBeam;
		player->JobSkillList.Beginner_WizardSkill.AquaBeam = 10;
	}

	if (player->JobSkillList.Beginner_WizardSkill.FireBeam >= 10)
	{
		player->JobSkillList.Beginner_WizardSkill.FireBeam -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WizardSkill.FireBeam;
		player->JobSkillList.Beginner_WizardSkill.FireBeam = 10;
	}

	if (player->JobSkillList.Beginner_WizardSkill.LightingBeam >= 10)
	{
		player->JobSkillList.Beginner_WizardSkill.LightingBeam -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WizardSkill.LightingBeam;
		player->JobSkillList.Beginner_WizardSkill.LightingBeam = 10;
	}
	return tempSkillPoint;
}

int playerWizardIntermediateSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Intermediate_WizardSkill.ConOfIce >= 20)
	{
		player->JobSkillList.Intermediate_WizardSkill.ConOfIce -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WizardSkill.ConOfIce;
		player->JobSkillList.Intermediate_WizardSkill.ConOfIce = 20;
	}

	if (player->JobSkillList.Intermediate_WizardSkill.FireSpike >= 20)
	{
		player->JobSkillList.Intermediate_WizardSkill.FireSpike -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WizardSkill.FireSpike;
		player->JobSkillList.Intermediate_WizardSkill.FireSpike = 20;
	}

	return tempSkillPoint;
}

int playerWarriorSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	switch (player->JobStepType)
	{
	case EDefault:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorDefaultSkillReset(player, SkillPoint);
	}
	break;
	case EBeginner:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorBeginnerSkillReset(player, SkillPoint);
	}
	break;
	case EIntermediate:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorIntermediateSkillReset(player, SkillPoint);
	}
	break;
	case EAll:
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorDefaultSkillReset(player, SkillPoint);
		tempSkillPoint += playerWarriorBeginnerSkillReset(player, SkillPoint);
		tempSkillPoint += playerWarriorIntermediateSkillReset(player, SkillPoint);
	}

	return SkillPoint += tempSkillPoint;
}

int playerWarriorDefaultSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Default_WarriorSkill.Blade >= 5)
	{
		player->JobSkillList.Default_WarriorSkill.Blade -= 5;
		tempSkillPoint += player->JobSkillList.Default_WarriorSkill.Blade;
		player->JobSkillList.Default_WarriorSkill.Blade = 5;
	}

	if (player->JobSkillList.Default_WarriorSkill.Phantom >= 5)
	{
		player->JobSkillList.Default_WarriorSkill.Phantom -= 5;
		tempSkillPoint += player->JobSkillList.Default_WarriorSkill.Phantom;
		player->JobSkillList.Default_WarriorSkill.Phantom = 5;
	}

	if (player->JobSkillList.Default_WarriorSkill.Hellfire >= 5)
	{
		player->JobSkillList.Default_WarriorSkill.Hellfire -= 5;
		tempSkillPoint += player->JobSkillList.Default_WarriorSkill.Hellfire;
		player->JobSkillList.Default_WarriorSkill.Hellfire = 5;
	}
	return tempSkillPoint;
}

int playerWarriorBeginnerSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;

	if (player->JobSkillList.Beginner_WarriorSkill.BletInfinity >= 10)
	{
		player->JobSkillList.Beginner_WarriorSkill.BletInfinity -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WarriorSkill.BletInfinity;
		player->JobSkillList.Beginner_WarriorSkill.BletInfinity = 10;
	}

	if (player->JobSkillList.Beginner_WarriorSkill.Damascus >= 10)
	{
		player->JobSkillList.Beginner_WarriorSkill.Damascus -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WarriorSkill.Damascus;
		player->JobSkillList.Beginner_WarriorSkill.Damascus = 10;
	}

	if (player->JobSkillList.Beginner_WarriorSkill.Judgment >= 10)
	{
		player->JobSkillList.Beginner_WarriorSkill.Judgment -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WarriorSkill.Judgment;
		player->JobSkillList.Beginner_WarriorSkill.Judgment = 10;
	}
	return tempSkillPoint;
}

int playerWarriorIntermediateSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;

	if (player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite >= 20)
	{
		player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite;
		player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite = 20;
	}

	if (player->JobSkillList.Intermediate_WarriorSkill.Duellatorum >= 20)
	{
		player->JobSkillList.Intermediate_WarriorSkill.Duellatorum -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WarriorSkill.Duellatorum;
		player->JobSkillList.Intermediate_WarriorSkill.Duellatorum = 20;
	}
	return tempSkillPoint;
}

int playerArcherSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	switch (player->JobStepType)
	{
	case EDefault:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherDefaultSkillReset(player, SkillPoint);
	}
	break;
	case EBeginner:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherBeginnerSkillReset(player, SkillPoint);
	}
	break;
	case EIntermediate:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherIntermediateSkillReset(player, SkillPoint);
	}
	break;
	case EAll:
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherDefaultSkillReset(player, SkillPoint);
		tempSkillPoint += playerArcherBeginnerSkillReset(player, SkillPoint);
		tempSkillPoint += playerArcherIntermediateSkillReset(player, SkillPoint);
	}

	return SkillPoint += tempSkillPoint;
}

int playerArcherDefaultSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Default_ArcherSkill.IceArrow >= 5)
	{
		player->JobSkillList.Default_ArcherSkill.IceArrow -= 5;
		tempSkillPoint += player->JobSkillList.Default_ArcherSkill.IceArrow;
		player->JobSkillList.Default_ArcherSkill.IceArrow = 5;
	}

	if (player->JobSkillList.Default_ArcherSkill.FireArrow >= 5)
	{
		player->JobSkillList.Default_ArcherSkill.FireArrow -= 5;
		tempSkillPoint += player->JobSkillList.Default_ArcherSkill.FireArrow;
		player->JobSkillList.Default_ArcherSkill.FireArrow = 5;
	}

	if (player->JobSkillList.Default_ArcherSkill.BustArrow >= 5)
	{
		player->JobSkillList.Default_ArcherSkill.BustArrow -= 5;
		tempSkillPoint += player->JobSkillList.Default_ArcherSkill.BustArrow;
		player->JobSkillList.Default_ArcherSkill.BustArrow = 5;
	}
	return tempSkillPoint;
}

int playerArcherBeginnerSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Beginner_ArcherSkill.PosionArrow >= 10)
	{
		player->JobSkillList.Beginner_ArcherSkill.PosionArrow -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_ArcherSkill.PosionArrow;
		player->JobSkillList.Beginner_ArcherSkill.PosionArrow = 10;
	}

	if (player->JobSkillList.Beginner_ArcherSkill.LightningArrow >= 10)
	{
		player->JobSkillList.Beginner_ArcherSkill.LightningArrow -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_ArcherSkill.LightningArrow;
		player->JobSkillList.Beginner_ArcherSkill.LightningArrow = 10;
	}

	if (player->JobSkillList.Beginner_ArcherSkill.WindBoom >= 10)
	{
		player->JobSkillList.Beginner_ArcherSkill.WindBoom -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_ArcherSkill.WindBoom;
		player->JobSkillList.Beginner_ArcherSkill.WindBoom = 10;
	}

	return tempSkillPoint;
}

int playerArcherIntermediateSkillReset(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Intermediate_ArcherSkill.Evolve >= 20)
	{
		player->JobSkillList.Intermediate_ArcherSkill.Evolve -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_ArcherSkill.Evolve;
		player->JobSkillList.Intermediate_ArcherSkill.Evolve = 20;
	}

	if (player->JobSkillList.Intermediate_ArcherSkill.IllusionStep >= 20)
	{
		player->JobSkillList.Intermediate_ArcherSkill.IllusionStep -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_ArcherSkill.IllusionStep;
		player->JobSkillList.Intermediate_ArcherSkill.IllusionStep = 20;
	}
	return tempSkillPoint;
}

void playerWizardSkillInitial(Player* player)
{
	player->JobSkillList.Default_WizardSkill.FireBall = 5;
	player->JobSkillList.Default_WizardSkill.SnowBall = 5;
	player->JobSkillList.Default_WizardSkill.LightBall = 5;

	player->JobSkillList.Beginner_WizardSkill.AquaBeam = 10;
	player->JobSkillList.Beginner_WizardSkill.FireBeam = 10;
	player->JobSkillList.Beginner_WizardSkill.LightingBeam = 10;

	player->JobSkillList.Intermediate_WizardSkill.ConOfIce = 20;
	player->JobSkillList.Intermediate_WizardSkill.FireSpike = 20;
}

void playerWarriorSkillInitial(Player* player)
{
	player->JobSkillList.Default_WarriorSkill.Blade = 5;
	player->JobSkillList.Default_WarriorSkill.Phantom = 5;
	player->JobSkillList.Default_WarriorSkill.Hellfire = 5;

	player->JobSkillList.Beginner_WarriorSkill.BletInfinity = 10;
	player->JobSkillList.Beginner_WarriorSkill.Damascus = 10;
	player->JobSkillList.Beginner_WarriorSkill.Judgment = 10;

	player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite = 20;
	player->JobSkillList.Intermediate_WarriorSkill.Duellatorum = 20;
}

void playerArcherSkillInitial(Player* player)
{
	player->JobSkillList.Default_ArcherSkill.IceArrow = 5;
	player->JobSkillList.Default_ArcherSkill.FireArrow = 5;
	player->JobSkillList.Default_ArcherSkill.BustArrow = 5;

	player->JobSkillList.Beginner_ArcherSkill.PosionArrow = 10;
	player->JobSkillList.Beginner_ArcherSkill.LightningArrow = 10;
	player->JobSkillList.Beginner_ArcherSkill.WindBoom = 10;

	player->JobSkillList.Intermediate_ArcherSkill.Evolve = 20;
	player->JobSkillList.Intermediate_ArcherSkill.IllusionStep = 20;
}


void PlayerSkillListPrint(Player* player)
{
	switch (player->PlayerJobType)
	{
	case ENone_JobType:
		printf("\n\n직업이 없기 때문에 스킬도 없습니다!\n");
		Sleep(1200);
		system("cls");
		break;
	case EWizard:
		printf("\n\n%s(이)의 직업은 %s입니다.\n", player->PlayerName, player->PlayerJobName);
		printf("\n%s의 직업 단계에서 사용 가능한 스킬은 다음과 같습니다\n\n", player->PlayerName);
		Sleep(1200);
		switch (player->JobStepType)
		{
		case ENone_JobStepType:
			printf("\n이 단계에서는 배울 수 있는 스킬이 없습니다 !! \n");
			break;
		case EIntermediate:
			printf("Intermediate 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("7. FireSpike\n8. ConOfIce");
			Sleep(1200);

		case EBeginner:
			printf("Beginner 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("4. FireBeam\n5. AquaBeam\n6. LightingBeam");
			Sleep(1200);

		case EDefault:
			printf("Default 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("1. FireBall\n2. SnowBall\n3. LightBall");
			Sleep(1200);
			break;
		}
		break;
	case EWarrior:
		printf("\n\n%s(이)의 직업은 %s입니다.\n", player->PlayerName, player->PlayerJobName);
		printf("\n%s의 직업 단계에서 사용 가능한 스킬은 다음과 같습니다\n\n", player->PlayerName);
		Sleep(1200);
		switch (player->JobStepType)
		{
		case ENone_JobStepType:
			printf("\n이 단계에서는 배울 수 있는 스킬이 없습니다 !! \n");
			break;
		case EIntermediate:
			printf("Intermediate 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("7. BloodInfinite\n8. Duellatorum");
			Sleep(1200);

		case EBeginner:
			printf("Beginner 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("4. BletInfinity\n5. Damascus\n6. Judgment");
			Sleep(1200);

		case EDefault:
			printf("Default 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("1. Blade\n2. SnowBall\n3. Hellfire");
			Sleep(1200);
			break;
		}
		break;
	case EArcher:
		printf("\n\n%s(이)의 직업은 %s입니다.\n", player->PlayerName, player->PlayerJobName);
		printf("\n%s의 직업 단계에서 사용 가능한 스킬은 다음과 같습니다\n\n", player->PlayerName);
		Sleep(1200);
		switch (player->JobStepType)
		{
		case ENone_JobStepType:
			printf("\n이 단계에서는 배울 수 있는 스킬이 없습니다 !! \n");
			break;
		case EIntermediate:
			printf("Intermediate 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("7. Evolve\n8. IllusionStep");
			Sleep(1200);

		case EBeginner:
			printf("Beginner 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("4. PosionArrow\n5. LightningArrow\n6. WindBoom");
			Sleep(1200);

		case EDefault:
			printf("Default 스킬은 다음과 같습니다\n\n\n");
			Sleep(800);
			printf("1. IceArrow\n2. FireArrow\n3. BustArrow");
			Sleep(1200);
			break;
		}
	}

	Sleep(1200);
}

void PlayerSkillUp(Player* player)
{
	char SkillName[120];
	printf("\n\n%s(이)가 배울 스킬의 이름을 입력해주세요! \n", player->PlayerName);
	scanf("%s",SkillName);
	switch (player->PlayerJobType)
	{
	case EWizard:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(SkillName, "FireSpike") == 0)
			{
				printf("\n플레이어의 FireSpike 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 FireSpike 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Intermediate_WizardSkill.FireSpike);
				player->JobSkillList.Intermediate_WizardSkill.FireSpike++;
				printf("\n플레이어의 FireSpike 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Intermediate_WizardSkill.FireSpike);
			}
			else if (strcmp(SkillName, "ConOfIce") == 0)
			{
				printf("\n플레이어의 ConOfIce 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 ConOfIce 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Intermediate_WizardSkill.ConOfIce);
				player->JobSkillList.Intermediate_WizardSkill.ConOfIce++;
				printf("\n플레이어의 ConOfIce 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Intermediate_WizardSkill.ConOfIce);
			}
		case EBeginner:
			if (strcmp(SkillName, "FireBeam") == 0)
			{
				printf("\n플레이어의 FireBeam 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 FireBeam 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_WizardSkill.FireBeam);
				player->JobSkillList.Intermediate_WizardSkill.ConOfIce++;
				printf("\n플레이어의 FireBeam 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_WizardSkill.FireBeam);
			}
			else if (strcmp(SkillName, "AquaBeam") == 0)
			{
				
				printf("\n플레이어의 AquaBeam 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 AquaBeam 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_WizardSkill.AquaBeam);
				player->JobSkillList.Beginner_WizardSkill.AquaBeam++;
				printf("\n플레이어의 AquaBeam 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_WizardSkill.AquaBeam);
			}
			else if (strcmp(SkillName, "LightingBeam") == 0)
			{
				printf("\n플레이어의 LightingBeam 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 LightingBeam 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_WizardSkill.LightingBeam);
				player->JobSkillList.Beginner_WizardSkill.LightingBeam++;
				printf("\n플레이어의 LightingBeam 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_WizardSkill.LightingBeam);
			}
		case EDefault:
			if (strcmp(SkillName, "FireBall") == 0)
			{
				printf("\n플레이어의 FireBall 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 FireBall 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_WizardSkill.FireBall);
				player->JobSkillList.Default_WizardSkill.FireBall++;
				printf("\n플레이어의 FireBall 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_WizardSkill.FireBall);
			}
			else if (strcmp(SkillName, "SnowBall") == 0)
			{
				printf("\n플레이어의 SnowBall 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 SnowBall 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_WizardSkill.SnowBall);
				player->JobSkillList.Default_WizardSkill.FireBall++;
				printf("\n플레이어의 SnowBall 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_WizardSkill.SnowBall);
			}
			else if (strcmp(SkillName, "LightBall") == 0)
			{
				printf("\n플레이어의 LightBall 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 LightBall 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_WizardSkill.LightBall);
				player->JobSkillList.Default_WizardSkill.LightBall++;
				printf("\n플레이어의 LightBall 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_WizardSkill.LightBall);
			}
			break;
		}
		break;
	case EWarrior:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(SkillName, "BloodInfinite") == 0)
			{
				printf("\n플레이어의 BloodInfinite 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 BloodInfinite 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite);
				player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite++;
				printf("\n플레이어의 BloodInfinite 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite);
			}
			else if (strcmp(SkillName, "Duellatorum") == 0)
			{
				printf("\n플레이어의 Duellatorum 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Duellatorum 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Intermediate_WarriorSkill.Duellatorum);
				player->JobSkillList.Intermediate_WarriorSkill.Duellatorum++;
				printf("\n플레이어의 Duellatorum 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Intermediate_WarriorSkill.Duellatorum);
			}
		case EBeginner:
			if (strcmp(SkillName, "BletInfinity") == 0)
			{
				printf("\n플레이어의 BletInfinity 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 BletInfinity 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_WarriorSkill.BletInfinity);
				player->JobSkillList.Beginner_WarriorSkill.BletInfinity++;
				printf("\n플레이어의 BletInfinity 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_WarriorSkill.BletInfinity);
			}
			else if (strcmp(SkillName, "Damascus") == 0)
			{
				printf("\n플레이어의 Damascus 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Damascus 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_WarriorSkill.Damascus);
				player->JobSkillList.Beginner_WarriorSkill.Damascus++;
				printf("\n플레이어의 Damascus 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_WarriorSkill.Damascus);
			}
			else if (strcmp(SkillName, "Judgment") == 0)
			{
				printf("\n플레이어의 Judgment 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Judgment 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_WarriorSkill.Judgment);
				player->JobSkillList.Beginner_WarriorSkill.Judgment++;
				printf("\n플레이어의 Judgment 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_WarriorSkill.Judgment);
			}
		case EDefault:
			if (strcmp(SkillName, "Blade") == 0)
			{
				printf("\n플레이어의 Blade 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Blade 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_WarriorSkill.Blade);
				player->JobSkillList.Default_WarriorSkill.Blade++;
				printf("\n플레이어의 Blade 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_WarriorSkill.Blade);
			}
			else if (strcmp(SkillName, "Phantom") == 0)
			{
				printf("\n플레이어의 Phantom 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Phantom 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_WarriorSkill.Phantom);
				player->JobSkillList.Default_WarriorSkill.Phantom++;
				printf("\n플레이어의 Blade 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_WarriorSkill.Phantom);
			}
			else if (strcmp(SkillName, "Hellfire") == 0)
			{
				printf("\n플레이어의 Hellfire 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Hellfire 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_WarriorSkill.Hellfire);
				player->JobSkillList.Default_WarriorSkill.Hellfire++;
				printf("\n플레이어의 Hellfire 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_WarriorSkill.Hellfire);
			}
			break;
		}

	case EArcher:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(SkillName, "Evolve") == 0)
			{
				printf("\n플레이어의 Evolve 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 Evolve 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Intermediate_ArcherSkill.Evolve);
				player->JobSkillList.Intermediate_ArcherSkill.Evolve++;
				printf("\n플레이어의 Evolve 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Intermediate_ArcherSkill.Evolve);
			}
			else if (strcmp(SkillName, "IllusionStep") == 0)
			{
				printf("\n플레이어의 IllusionStep 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 IllusionStep 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Intermediate_ArcherSkill.IllusionStep);
				player->JobSkillList.Intermediate_ArcherSkill.IllusionStep++;
				printf("\n플레이어의 IllusionStep 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Intermediate_ArcherSkill.IllusionStep);
			}
		case EBeginner:
			if (strcmp(SkillName, "PosionArrow") == 0)
			{
				printf("\n플레이어의 PosionArrow 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 PosionArrow 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_ArcherSkill.PosionArrow);
				player->JobSkillList.Beginner_ArcherSkill.PosionArrow++;
				printf("\n플레이어의 IllusionStep 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_ArcherSkill.PosionArrow);
			}
			else if (strcmp(SkillName, "LightningArrow") == 0)
			{
				printf("\n플레이어의 LightningArrow 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 LightningArrow 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_ArcherSkill.LightningArrow);
				player->JobSkillList.Beginner_ArcherSkill.LightningArrow++;
				printf("\n플레이어의 LightningArrow 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_ArcherSkill.LightningArrow);
			}
			else if (strcmp(SkillName, "WindBoom") == 0)
			{
				printf("\n플레이어의 WindBoom 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 WindBoom 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Beginner_ArcherSkill.WindBoom);
				player->JobSkillList.Beginner_ArcherSkill.WindBoom++;
				printf("\n플레이어의 WindBoom 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Beginner_ArcherSkill.WindBoom);
			}
		case EDefault:
			if (strcmp(SkillName, "IceArrow") == 0)
			{
				printf("\n플레이어의 IceArrow 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 IceArrow 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_ArcherSkill.IceArrow);
				player->JobSkillList.Default_ArcherSkill.IceArrow++;
				printf("\n플레이어의 IceArrow 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_ArcherSkill.IceArrow);
			}
			else if (strcmp(SkillName, "FireArrow") == 0)
			{
				printf("\n플레이어의 FireArrow 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 FireArrow 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_ArcherSkill.FireArrow);
				player->JobSkillList.Default_ArcherSkill.FireArrow++;
				printf("\n플레이어의 FireArrow 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_ArcherSkill.FireArrow);
			}
			else if (strcmp(SkillName, "BustArrow") == 0)
			{
				printf("\n플레이어의 BustArrow 스킬 능력이 향상됩니다!\n");
				printf("\n플레이어의 BustArrow 업데이트 전 능력치는 %d 였습니다.\n", player->JobSkillList.Default_ArcherSkill.BustArrow);
				player->JobSkillList.Default_ArcherSkill.BustArrow++;
				printf("\n플레이어의 FireArrow 업데이트 후 능력치는 %d 입니다.\n", player->JobSkillList.Default_ArcherSkill.BustArrow);
			}
			break;
		}

	}
	Sleep(1200);
	player->SkillPoint--;
}

void PlayerAddItem(Player* player, struct MONSTER* monster)
{
	switch (monster->monsterType)
	{
	case EXStemp:
	case EStemp:
	case EDarkStemp:
		if(player->PInventory.wood <= player->PInventory.MaxOwnItem-5)
			player->PInventory.wood += 5;
		else
		{
			printf("\n추가될 나무가 너무 많아서 인벤토리에 추가할 수 없습니다!\n\n아이템을 팔아주세요!");
			system("cls");
		}
		player->PInventory.gold += 5;
		printf("\n\n플레이어의 인벤토리에 나무가 +5 되었습니다!");
		printf("\n\n플레이어의 인벤토리에 골드가 +5 되었습니다!");
		// Q.D-1 체크 로직
		if (monster->monsterType == EDarkStemp && player->P_Quest.CheckAcceptQuestList[2] == true)
		{
			player->P_Quest.DarkStempNum++;
			if (player->P_Quest.DarkStempNum >= 3)
			{
				player->P_Quest.CheckCompleteQuestList[2] = true;
				printf("\n\n플레이어가 Q.D-1 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +80 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +3 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 MP포션이 +3 되었습니다!");
				player->PInventory.gold += 80;
				player->PInventory.HPpotion += 3;
				player->PInventory.MPpotion += 3;
				Sleep(1200);
				system("cls");
			}
		}
		// Q.N-2 체크 로직
		if (player->P_Quest.CheckAcceptQuestList[1] == true)
		{

			if (player->PInventory.wood >= 3 )
			{
				player->P_Quest.CheckCompleteQuestList[1] = true;
				player->PInventory.wood -= 3;
				printf("\n\n플레이어가 Q.N-2 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 나무가 -3 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +50 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +5 되었습니다!");
				player->PInventory.gold += 50;
				player->PInventory.HPpotion += 5;
				Sleep(1200);
				system("cls");
			}
		}
		// Q.N-1 체크 로직
		if (player->P_Quest.CheckAcceptQuestList[0] == true && monster->monsterType == EXStemp)
		{
			player->P_Quest.XStemp++;
			if (player->P_Quest.DarkStempNum >= 3)
			{
				player->P_Quest.CheckCompleteQuestList[1] = true;
				player->PInventory.wood -= 3;
				printf("\n\n플레이어가 Q.N-2 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +50 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +5 되었습니다!");
				player->P_Quest.XStemp = 0;
				player->PInventory.gold += 50;
				player->PInventory.HPpotion += 5;
				Sleep(1200);
				system("cls");
			}
		}
		break;
	
	case EFallenTreeFairy:
	case EShadeFairy:
		player->PInventory.gold += 20;
		printf("\n\n플레이어의 인벤토리에 골드가 +20 되었습니다!");
		// Q.B-1 체크 로직
		if (monster->monsterType == EShadeFairy && player->P_Quest.CheckAcceptQuestList[4] == true)
		{
			player->P_Quest.ShadeFairyNum++;
			if (player->P_Quest.ShadeFairyNum >= 3)
			{
				player->P_Quest.CheckCompleteQuestList[4] = true;
				printf("\n\n플레이어가 Q.B-1 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +110 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +4 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 MP포션이 +4 되었습니다!");
				player->P_Quest.ShadeFairyNum = 0;
				player->PInventory.gold += 110;
				player->PInventory.HPpotion += 4;
				player->PInventory.MPpotion += 4;
				Sleep(1200);
				system("cls");
			}
		}
		// Q.D-2 체크 로직
		if (monster->monsterType == EFallenTreeFairy && player->P_Quest.CheckAcceptQuestList[4] == true)
		{
			player->P_Quest.FallenTreeFairy++;
			if (player->P_Quest.FallenTreeFairy >= 3)
			{
				player->P_Quest.CheckCompleteQuestList[4] = true;
				printf("\n\n플레이어가 Q.B-1 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +110 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +4 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 MP포션이 +4 되었습니다!");
				player->P_Quest.FallenTreeFairy = 0;
				player->PInventory.gold += 110;
				player->PInventory.HPpotion += 4;
				player->PInventory.MPpotion += 4;
				Sleep(1200);
				system("cls");
			}
		}
		break;

	case EDail:
	case EDino:
		if (player->PInventory.emerald <= player->PInventory.MaxOwnItem - 10)
			player->PInventory.emerald += 10;
		else
		{
			printf("\n추가될 에메랄드가 너무 많아서 인벤토리에 추가할 수 없습니다!\n\n아이템을 팔아주세요!");
			system("cls");
		}
		player->PInventory.gold += 40;
		player->PInventory.emerald += 10;
		printf("\n\n플레이어의 인벤토리에 골드가 +40 되었습니다!");
		printf("\n\n플레이어의 인벤토리에 에메랄드가 +20 되었습니다!");
		// Q.I-1 실행 로직
		if (monster->monsterType == EDail && player->P_Quest.CheckAcceptQuestList[6])
		{
			player->P_Quest.Dail++;
			if (player->P_Quest.Dail >= 1)
			{
				player->P_Quest.CheckCompleteQuestList[6] = true;
				printf("\n\n플레이어가 Q.I-1 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +200 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +4 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 MP포션이 +4 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 에메랄드가 -1 되었습니다!");
				player->P_Quest.Dail = 0;
				player->PInventory.gold += 200;
				player->PInventory.HPpotion += 4;
				player->PInventory.MPpotion += 4;
				player->PInventory.emerald -= 1;
				Sleep(1200);
				system("cls");
			}
		}
		// Q.I-2 완료
		if (monster->monsterType == EDino && player->P_Quest.CheckAcceptQuestList[7])
		{
			player->P_Quest.Dail++;
			if (player->P_Quest.Dail >= 1)
			{
				player->P_Quest.CheckCompleteQuestList[7] = true;
				printf("\n\n플레이어가 Q.I-2 퀘스트를 완료했습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 골드가 +280 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 HP포션이 +4 되었습니다!");
				Sleep(550);
				printf("\n\n플레이어의 인벤토리에 MP포션이 +4 되었습니다!");
				player->P_Quest.Dail = 0;
				player->PInventory.gold += 280;
				player->PInventory.HPpotion += 4;
				player->PInventory.MPpotion += 4;
				Sleep(1200);
				system("cls");
			}
		}
		break;
	}
}

void CheckPlayerQuestList(Player* player)
{
}


