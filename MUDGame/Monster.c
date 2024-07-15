#include "Framework.h"


void MonsterInitial(struct DUNGEON* dungeon, _Monster* monster)
{
	char MonsterNameArr[7][120] =
	{
		"���� ������",
		"������",
		"��ũ ������",
		"Ÿ���� ���� ����",
		"���̵�",
		"��Ȥ�� �Ǿ� ����",
		"���� ���"
	};
	// if (���� ����)
	// {
	//		����
	//		�ɷ�ġ =  ���� ���� + % n
	// }
	// ������ ���� ��ų�� 2�� �Ϲ� ���� �� ���� ���� �� 1�̸� ���� 0 �̸� ����
	if (strcmp(dungeon->DungeonName, "���ֱ� ����") == 0)
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
	else if (strcmp(dungeon->DungeonName, "�� �� ������ ����") == 0)
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
	else if (strcmp(dungeon->DungeonName, "���� �غ��� ����") == 0)
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
		strcpy(monster->StempMonsterSkill.skillName[0], "���� �����");
		strcpy(monster->StempMonsterSkill.skillName[1], "���� ����");
	}
	break;
	case EFallenTreeFairy:
	case EShadeFairy:
	{
		SkillAtk = 2 + monster->Attack;
		monster->FairyMonsterSkill.PowerofMystery = SkillAtk;
		monster->FairyMonsterSkill.WonderSteam = SkillAtk;
		strcpy(monster->FairyMonsterSkill.skillName[0], "�ź��� ��");
		strcpy(monster->FairyMonsterSkill.skillName[1], "���� �ձ�");
	}
	break;
	case EDail:
	{
		SkillAtk = 3 + monster->Attack;
		monster->DailMonsterSkill.CurseOfSwamp = SkillAtk;
		monster->DailMonsterSkill.ThrowingMud = SkillAtk;
		strcpy(monster->FairyMonsterSkill.skillName[0], "���� ����");
		strcpy(monster->FairyMonsterSkill.skillName[1], "���� ������");
	}
	break;
	case EDino:
	{
		SkillAtk = 4 + monster->Attack;
		monster->DinoMonsterSkill.GameOfDirt = SkillAtk;
		strcpy(monster->FairyMonsterSkill.skillName[0], "������ ����");
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
				printf("\n\n���Ͱ� %s ��ų�� ����߽��ϴ�!\n",monster->StempMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n",player->PlayerName);
					player->Hp -= monster->StempMonsterSkill.VinesBat;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
						system("cls");
						return;
					}
					printf("\n�÷��̾��� HP : %d", player->Hp);
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			case 1:
				printf("\n\n���Ͱ� %s ��ų�� ����߽��ϴ�!\n", monster->StempMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n", player->PlayerName);
					player->Hp -= monster->StempMonsterSkill.CurseofForest;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
						system("cls");
						return;
					}
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			}
			// ���� ���� �������� ���ư���
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
				printf("\n\n���Ͱ� %s ��ų�� ����߽��ϴ�!\n", monster->FairyMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n",player->PlayerName);
					player->Hp -= monster->FairyMonsterSkill.PowerofMystery;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
						system("cls");
						return;
					}
					printf("\n�÷��̾��� HP : %d", player->Hp);
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			case 1:
				printf("\n\n���Ͱ� %s ��ų�� ����߽��ϴ�!\n", monster->FairyMonsterSkill.skillName[randSkill]);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n", player->PlayerName);
					player->Hp -= monster->FairyMonsterSkill.WonderSteam;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
						system("cls");
						return;
					}
					printf("\n�÷��̾��� HP : %d", player->Hp);
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			}
			// ���� ���� �������� ���ư���
			return;
		}
		break;
		case EDail:
		{
			int randSkill = rand() % 1;
			switch (randSkill)
			{
			case 0:
				printf("\n\n���Ͱ� %s ��ų�� ����߽��ϴ�!\n", monster->DailMonsterSkill.skillName[randSkill]);
				Sleep(1200);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n", player->PlayerName);
					Sleep(1200);
					player->Hp -= monster->DailMonsterSkill.CurseOfSwamp;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
						Sleep(1200);
						system("cls");
						return;
					}
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			case 1:
				printf("\n\n���Ͱ� %s ��ų�� ����߽��ϴ�!\n", monster->DailMonsterSkill.skillName[randSkill]);
				Sleep(1200);
				if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
				{
					printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
					Sleep(1100);
					system("cls");
					return;
				}
				else
				{
					printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n", player->PlayerName);
					player->Hp -= monster->DailMonsterSkill.ThrowingMud;
					if (player->Hp <= 0)
					{
						printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
						Sleep(1200);
						system("cls");
						return;
					}
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				system("cls");
				Sleep(1100);
				return;
				break;
			}
			// ���� ���� �������� ���ư���
			return;
		}
		break;
		case EDino:
		{
			printf("\n\n��밡 %s ��ų�� ����߽��ϴ�!\n", monster->DailMonsterSkill.skillName[0]);
			printf("����� ��ų�� ȸ���� �� �����ϴ�!");
			// ToDo
			// ����� ���� ����
			
			// ���� ���� �������� ���ư���
			printf("\n\n������ ��ų�� %s�� ���ظ� �Ծ����ϴ�!\n", player->PlayerName);
			player->Hp -= monster->DailMonsterSkill.ThrowingMud;
			if (player->Hp <= 0)
			{
				printf("\n\n%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
				Sleep(1200);
				system("cls");
				return;
			}
			printf("\n�÷��̾��� HP : %d", player->Hp);
			printf("\n������ HP : %d", monster->Hp);
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
		printf("���Ͱ� �����ġ�⸦ �߽��ϴ�! \n");
		Sleep(1100);
		if (AvoidMonsterAttackWithPlayerQuickness(monster, player))
		{
			printf("%s(��)�� ȸ�ǿ� �����߽��ϴ�!\n", player->PlayerName);
			Sleep(1100);
			system("cls");
			return;
		}

		printf("%s(��)�� ���ݹ޾ҽ��ϴ�!\n\n", player->PlayerName);
		player->Hp -= monster->Attack;
		if (player->Hp <= 0)
		{
			printf("%s(��)�� ����߽��ϴ�!\n", player->PlayerName);
			Sleep(1200);
			system("cls");
			return;
		}
		printf("�÷��̾��� HP : %d", player->Hp);
		printf("������ HP : %d", monster->Hp);
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
			printf("1. ��ų ���\n2. �⺻ ����\n3. ��������\n\n");
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
				printf("%s(��)�� �⺻ ������ �����ߴ�!", player->PlayerName);
				monster->Hp -= player->Attack;
				system("cls");
				// TODO:
				// ���� �������� ���ư���
				return;
			}
				break;
			case 3:
			{
				isRun = rand() % 1;
				if (!isRun)
				{
					printf("\n\n%s�� ������ �� �־���!\n", player->PlayerName);
					system("cls");
					// TODO:
					// ���� ������ Ż���ϱ�
					return;
				}
				else
				{
					printf("\n\n%s�� ������ �� ������!\n", player->PlayerName);
				}
			}
				break;
			}
		}
		else
		{
			printf("\n\n�÷��̾ ������ �����Դϴ�!\n");
			printf("1. ��ų ���\n2. �⺻ ����\n\n");
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
				printf("%s(��)�� �⺻ ������ �����ߴ�!", player->PlayerName);
				monster->Hp -= player->Attack;
				system("cls");
				// TODO:
				// ���� �������� ���ư� �� �ֵ��� ���� ���� �����
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
	printf("����Ͻ� ��ų�� �Է����ּ��� : ");
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
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", player->JobSkillList.Intermediate_WizardSkill.FireSpike);
				// ���� �� �ٽ� ���� ���·� ���ư�
				// ���� ���¿��� ���� ������ óġ�߽��ϴ�! ��� ��
				// �ٽ� �� ���������� ���ư�
			}
			else if (strcmp(SkillToUse, "ConOfIce") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WizardSkill.ConOfIce;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", player->JobSkillList.Intermediate_WizardSkill.ConOfIce);
			}
		case EBeginner:
			if (strcmp(SkillToUse, "FireBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.FireBeam;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", player->JobSkillList.Beginner_WizardSkill.FireBeam);
			}
			else if (strcmp(SkillToUse, "AquaBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.AquaBeam;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WizardSkill.AquaBeam);
			}
			else if (strcmp(SkillToUse, "LightingBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.LightingBeam;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WizardSkill.LightingBeam);
			}
		case EDefault:
			if (strcmp(SkillToUse, "FireBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.FireBall;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WizardSkill.FireBall);
			}
			else if (strcmp(SkillToUse, "SnowBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.SnowBall;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WizardSkill.SnowBall);
			}
			else if (strcmp(SkillToUse, "LightBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.LightBall;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WizardSkill.LightBall);
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
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite);
			}
			else if (strcmp(SkillToUse, "Duellatorum") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.Duellatorum;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.Duellatorum);
			}
		case EBeginner:
			if (strcmp(SkillToUse, "BletInfinity") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.BletInfinity;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.BletInfinity);
			}
			else if (strcmp(SkillToUse, "Damascus") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Damascus;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Damascus);
			}
			else if (strcmp(SkillToUse, "Judgment") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Judgment;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Judgment);
			}
		case EDefault:
			if (strcmp(SkillToUse, "Blade") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Blade;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Blade);
			}
			else if (strcmp(SkillToUse, "Phantom") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Phantom;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Phantom);
			}
			else if (strcmp(SkillToUse, "Hellfire") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Hellfire;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Hellfire);
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
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.Evolve);
			}
			else if (strcmp(SkillToUse, "IllusionStep") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.IllusionStep;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.IllusionStep);
			}
		case EBeginner:
			if (strcmp(SkillToUse, "PosionArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.PosionArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.PosionArrow);
			}
			else if (strcmp(SkillToUse, "LightningArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.LightningArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.LightningArrow);
			}
			else if (strcmp(SkillToUse, "WindBoom") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.WindBoom;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.WindBoom);
			}
		case EDefault:
			if (strcmp(SkillToUse, "IceArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.IceArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.IceArrow);
			}
			else if (strcmp(SkillToUse, "FireArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.FireArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.FireArrow);
			}
			else if (strcmp(SkillToUse, "BustArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.BustArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.BustArrow);
			}
			break;
		}

	}
}
