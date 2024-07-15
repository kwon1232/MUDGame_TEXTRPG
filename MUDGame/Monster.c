#include "Framework.h"


void MonsterInitial(struct DUNGEON* dungeon, _Monster* monster)
{
	char MonsterNameArr[7][120] =
	{
		"엑스 스텀프",
		"스텀프",
		"다크 스텀프",
		"타락한 나무 정령",
		"셰이드",
		"현혹된 악어 다일",
		"보스 디노"
	};
	// if (던전 레벨)
	// {
	//		몬스터
	//		능력치 =  몬스터 레벨 + % n
	// }
	// 전투중 몬스터 스킬은 2번 일반 공격 후 랜덤 돌린 뒤 1이면 공격 0 이면 안함
	if (strcmp(dungeon->DungeonName, "오솔길 던전") == 0)
	{
		int DungeonLevel = rand() % 1 + 1;

		monster->Level = DungeonLevel + rand() % 2;
		monster->Hp = DungeonLevel + rand() % 3;
		printf("\nMonster HP : %d", monster->Hp);
		monster->Mp = DungeonLevel;
		monster->Attack = DungeonLevel;

		DungeonLevel = rand() % 2;
		switch (DungeonLevel)
		{
		case 0:
		{
			strcpy(monster->MonsterName, MonsterNameArr[0]);
			monster->monsterType = EXStemp;
		}
		break;
		case 1:
		{
			strcpy(monster->MonsterName, MonsterNameArr[1]);
			monster->monsterType = EStemp;
		}
		break;
		case 2:
		{
			strcpy(monster->MonsterName, MonsterNameArr[2]);
			monster->monsterType = EDarkStemp;
		}
		break;
		}
	}
	else if (strcmp(dungeon->DungeonName, "숲 속 늪지대 던전") == 0)
	{
		int DungeonLevel = rand() % 1 + 2;

		monster->Level = DungeonLevel + rand() % 2;
		monster->Hp = DungeonLevel + rand() % 3;
		monster->Mp = DungeonLevel;
		monster->Attack = DungeonLevel % 1 + 1;

		DungeonLevel = rand() % 1;
		switch (DungeonLevel)
		{
		case 0:
		{
			strcpy(monster->MonsterName, MonsterNameArr[3]);
			monster->monsterType = EFallenTreeFairy;
		}
		break;
		case 1:
		{
			strcpy(monster->MonsterName, MonsterNameArr[4]);
			monster->monsterType = EShadeFairy;
		}
		break;
		}
	}
	else if (strcmp(dungeon->DungeonName, "얕은 해변가 던전") == 0)
	{
		int DungeonLevel = rand() % 1 + 3;

		monster->Level = DungeonLevel + rand() % 2;
		monster->Hp = DungeonLevel + rand() % 3;
		monster->Mp = DungeonLevel;
		monster->Attack = DungeonLevel % 1 + 2;

		DungeonLevel = rand() % 1;
		switch (DungeonLevel)
		{
		case 0:
		{
			strcpy(monster->MonsterName, MonsterNameArr[5]);
			monster->monsterType = EDail;
		}
		break;
		case 1:
		{
			strcpy(monster->MonsterName, MonsterNameArr[6]);
			monster->monsterType = EDino;
		}
		break;
		}
	}
	MonsterSetSkill(monster);
}

void MonsterSetSkill(_Monster* monster)
{
	int SkillAtk;
	switch (monster->monsterType)
	{
	case EXStemp:
	case EStemp:
	case EDarkStemp:
	{
		SkillAtk = 2 + monster->Attack;
		monster->StempMonsterSkill.CurseofForest = SkillAtk;
		monster->StempMonsterSkill.VinesBat = SkillAtk;
		strcpy(monster->StempMonsterSkill.skillName[0], "덩쿨 방망이");
		strcpy(monster->StempMonsterSkill.skillName[1], "숲의 저주");
	}
	break;
	case EFallenTreeFairy:
	case EShadeFairy:
	{
		SkillAtk = 2 + monster->Attack;
		monster->FairyMonsterSkill.PowerofMystery = SkillAtk;
		monster->FairyMonsterSkill.WonderSteam = SkillAtk;
		strcpy(monster->FairyMonsterSkill.skillName[0], "신비의 힘");
		strcpy(monster->FairyMonsterSkill.skillName[1], "증기 뿜기");
	}
	break;
	case EDail:
	{
		SkillAtk = 3 + monster->Attack;
		monster->DailMonsterSkill.CurseOfSwamp = SkillAtk;
		monster->DailMonsterSkill.ThrowingMud = SkillAtk;
		strcpy(monster->FairyMonsterSkill.skillName[0], "늪의 저주");
		strcpy(monster->FairyMonsterSkill.skillName[1], "진흙 던지기");
	}
	break;
	case EDino:
	{
		SkillAtk = 4 + monster->Attack;
		monster->DinoMonsterSkill.GameOfDirt = SkillAtk;
		strcpy(monster->FairyMonsterSkill.skillName[0], "흙탕물 놀이");
	}
	break;
	}
}


void MonsterAtk(_Monster* monster, Player* player)
{

	bool isSkillAtk = rand() % 3;
	system("cls");
	if (!isSkillAtk && monster->Mp > 0)
	{
		switch (monster->monsterType)
		{
		case EXStemp:
		case EStemp:
		case EDarkStemp:
		{
			int randSkill = rand() % 1;
			switch (randSkill)
			{
			case 0:
				printf("\n\n몬스터가 %s 스킬을 사용했습니다!\n",monster->StempMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n",player->PlayerName);
					player->Hp -= monster->StempMonsterSkill.VinesBat;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
						system("cls");
						return;
					}
					printf("\n플레이어의 HP : %d", player->Hp);
				}
				printf("\n플레이어의 HP : %d", player->Hp);
				printf("\n몬스터의 HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			case 1:
				printf("\n\n몬스터가 %s 스킬을 사용했습니다!\n", monster->StempMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n", player->PlayerName);
					player->Hp -= monster->StempMonsterSkill.CurseofForest;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
						system("cls");
						return;
					}
				}
				printf("\n플레이어의 HP : %d", player->Hp);
				printf("\n몬스터의 HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			}
			// 원래 대전 로직으로 돌아가기
			return;
		}
		break;
		case EFallenTreeFairy:
		case EShadeFairy:
		{
			int randSkill = rand() % 1;
			switch (randSkill)
			{
			case 0:
				printf("\n\n몬스터가 %s 스킬을 사용했습니다!\n", monster->FairyMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n",player->PlayerName);
					player->Hp -= monster->FairyMonsterSkill.PowerofMystery;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
						system("cls");
						return;
					}
					printf("\n플레이어의 HP : %d", player->Hp);
				}
				printf("\n플레이어의 HP : %d", player->Hp);
				printf("\n몬스터의 HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			case 1:
				printf("\n\n몬스터가 %s 스킬을 사용했습니다!\n", monster->FairyMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n", player->PlayerName);
					player->Hp -= monster->FairyMonsterSkill.WonderSteam;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
						system("cls");
						return;
					}
					printf("\n플레이어의 HP : %d", player->Hp);
				}
				printf("\n플레이어의 HP : %d", player->Hp);
				printf("\n몬스터의 HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			}
			// 원래 대전 로직으로 돌아가기
			return;
		}
		break;
		case EDail:
		{
			int randSkill = rand() % 1;
			switch (randSkill)
			{
			case 0:
				printf("\n\n몬스터가 %s 스킬을 사용했습니다!\n", monster->DailMonsterSkill.skillName[randSkill]);
				Sleep(1200);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n", player->PlayerName);
					Sleep(1200);
					player->Hp -= monster->DailMonsterSkill.CurseOfSwamp;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
						Sleep(1200);
						system("cls");
						return;
					}
				}
				printf("\n플레이어의 HP : %d", player->Hp);
				printf("\n몬스터의 HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			case 1:
				printf("\n\n몬스터가 %s 스킬을 사용했습니다!\n", monster->DailMonsterSkill.skillName[randSkill]);
				Sleep(1200);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n", player->PlayerName);
					player->Hp -= monster->DailMonsterSkill.ThrowingMud;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
						Sleep(1200);
						system("cls");
						return;
					}
				}
				printf("\n플레이어의 HP : %d", player->Hp);
				printf("\n몬스터의 HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			}
			// 원래 대전 로직으로 돌아가기
			return;
		}
		break;
		case EDino:
		{
			printf("\n\n디노가 %s 스킬을 사용했습니다!\n", monster->DailMonsterSkill.skillName[0]);
			printf("디노의 스킬은 회피할 수 없습니다!");
			// ToDo
			// 비행기 놀이 구현
			
			// 원래 대전 로직으로 돌아가기
			printf("\n\n몬스터의 스킬로 %s는 피해를 입었습니다!\n", player->PlayerName);
			player->Hp -= monster->DailMonsterSkill.ThrowingMud;
			if (player->Hp <= 0)
			{
				printf("\n\n%s(이)가 사망했습니다!\n", player->PlayerName);
				Sleep(1200);
				system("cls");
				return;
			}
			printf("\n플레이어의 HP : %d", player->Hp);
			printf("\n몬스터의 HP : %d", monster->Hp);
			system("cls");
			Sleep(1100);
			return;
		}
		break;
		}
	}

	else
	{
		system("cls");
		printf("몬스터가 몸통박치기를 했습니다! \n");
		Sleep(1100);
		if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
		{
			printf("%s(이)가 회피에 성공했습니다!\n", player->PlayerName);
			Sleep(1100);
			system("cls");
			return;
		}

		printf("%s(이)가 공격받았습니다!\n\n", player->PlayerName);
		player->Hp -= monster->Attack;
		if (player->Hp <= 0)
		{
			printf("%s(이)가 사망했습니다!\n", player->PlayerName);
			Sleep(1200);
			system("cls");
			return;
		}
		printf("플레이어의 HP : %d", player->Hp);
		printf("몬스터의 HP : %d", monster->Hp);
		Sleep(1200);
		system("cls");
		
		Sleep(1100);
	}
}

bool AvoidMonsterAttackWithPlayerQuickness(_Monster* monster, Player* player)
{
	int playerQuicknes = rand() % 99 + 1;

	if (playerQuicknes >= 1 && playerQuicknes <= player->Quickness)
	{
		return true;
	}
	return false;
}

void PlayerAtkMonster(_Monster* monster, Player* player)
{
	int InputValue = 0;
	bool isRun = false;

	while (true)
	{
		if (!isRun)
		{
			printf("1. 스킬 사용\n2. 기본 공격\n3. 도망가기\n\n");
			scanf("%d", &InputValue);

			switch (InputValue)
			{
			case 1:
			{
				PlayerSkillListPrint(player);
				PlayerSkillAtkMonster(monster, player);
			}
			break;
			case 2:
			{
				printf("%s(이)는 기본 공격을 성공했다!", player->PlayerName);
				monster->Hp -= player->Attack;
				system("cls");
				// TODO:
				// 대전 로직으로 돌아가기
				return;
			}
				break;
			case 3:
			{
				isRun = rand() % 1;
				if (!isRun)
				{
					printf("\n\n%s는 도망갈 수 있었다!\n", player->PlayerName);
					system("cls");
					// TODO:
					// 대전 로직도 탈출하기
					return;
				}
				else
				{
					printf("\n\n%s는 도망갈 수 없었다!\n", player->PlayerName);
				}
			}
				break;
			}
		}
		else
		{
			printf("\n\n플레이어가 공격할 차례입니다!\n");
			printf("1. 스킬 사용\n2. 기본 공격\n\n");
			scanf("%d", &InputValue);

			switch (InputValue)
			{
			case 1:
			{
				PlayerSkillListPrint(player);
				PlayerSkillAtkMonster(monster, player);
			}
				break;
			case 2:
			{
				printf("%s(이)는 기본 공격을 성공했다!", player->PlayerName);
				monster->Hp -= player->Attack;
				system("cls");
				// TODO:
				// 대전 로직으로 돌아갈 수 있도록 대전 로직 만들기
				return;
			}
				break;
			}
		}


		system("cls");
	}
}

void PlayerSkillAtkMonster(_Monster* monster, Player* player)
{
	char SkillToUse[80];
	printf("사용하실 스킬을 입력해주세요 : ");
	scanf("%s", &SkillToUse);
	switch (player->PlayerJobType)
	{
	case EWizard:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(SkillToUse, "FireSpike") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WizardSkill.FireSpike;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", player->JobSkillList.Intermediate_WizardSkill.FireSpike);
				// 공격 후 다시 대전 상태로 돌아감
				// 대전 상태에서 몬스터 죽으면 처치했습니다! 출력 후
				// 다시 맵 포지션으로 돌아감
			}
			else if (strcmp(SkillToUse, "ConOfIce") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WizardSkill.ConOfIce;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", player->JobSkillList.Intermediate_WizardSkill.ConOfIce);
			}
		case EBeginner:
			if (strcmp(SkillToUse, "FireBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.FireBeam;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", player->JobSkillList.Beginner_WizardSkill.FireBeam);
			}
			else if (strcmp(SkillToUse, "AquaBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.AquaBeam;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_WizardSkill.AquaBeam);
			}
			else if (strcmp(SkillToUse, "LightingBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.LightingBeam;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_WizardSkill.LightingBeam);
			}
		case EDefault:
			if (strcmp(SkillToUse, "FireBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.FireBall;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_WizardSkill.FireBall);
			}
			else if (strcmp(SkillToUse, "SnowBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.SnowBall;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_WizardSkill.SnowBall);
			}
			else if (strcmp(SkillToUse, "LightBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.LightBall;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_WizardSkill.LightBall);
			}
			break;
		}
		break;
	case EWarrior:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(SkillToUse, "BloodInfinite") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite);
			}
			else if (strcmp(SkillToUse, "Duellatorum") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.Duellatorum;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.Duellatorum);
			}
		case EBeginner:
			if (strcmp(SkillToUse, "BletInfinity") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.BletInfinity;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.BletInfinity);
			}
			else if (strcmp(SkillToUse, "Damascus") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Damascus;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Damascus);
			}
			else if (strcmp(SkillToUse, "Judgment") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Judgment;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Judgment);
			}
		case EDefault:
			if (strcmp(SkillToUse, "Blade") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Blade;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Blade);
			}
			else if (strcmp(SkillToUse, "Phantom") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Phantom;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Phantom);
			}
			else if (strcmp(SkillToUse, "Hellfire") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Hellfire;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Hellfire);
			}
			break;
		}

	case EArcher:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(SkillToUse, "Evolve") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.Evolve;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.Evolve);
			}
			else if (strcmp(SkillToUse, "IllusionStep") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.IllusionStep;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.IllusionStep);
			}
		case EBeginner:
			if (strcmp(SkillToUse, "PosionArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.PosionArrow;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.PosionArrow);
			}
			else if (strcmp(SkillToUse, "LightningArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.LightningArrow;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.LightningArrow);
			}
			else if (strcmp(SkillToUse, "WindBoom") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.WindBoom;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.WindBoom);
			}
		case EDefault:
			if (strcmp(SkillToUse, "IceArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.IceArrow;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.IceArrow);
			}
			else if (strcmp(SkillToUse, "FireArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.FireArrow;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.FireArrow);
			}
			else if (strcmp(SkillToUse, "BustArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.BustArrow;
				printf("\n몬스터에게 %d 만큼 피해를 입혔습니다!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.BustArrow);
			}
			break;
		}

	}
}
