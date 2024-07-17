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
		monster->Hp = DungeonLevel + rand() % 3 + 50;
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
		monster->Hp = DungeonLevel + rand() % 3 + 80;
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
		monster->Hp = DungeonLevel + rand() % 3 + 180;
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
						return;
					}
					printf("\n�÷��̾��� HP : %d", player->Hp);
					Sleep(1100);
					system("cls");
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				Sleep(1100);
				system("cls");
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
						Sleep(1100);
						system("cls");
						return;
					}
				}
				printf("\n�÷��̾��� HP : %d", player->Hp);
				printf("\n������ HP : %d", monster->Hp);
				Sleep(1100);
				system("cls");
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
				Sleep(1100);
				system("cls");
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
				Sleep(1100);
				system("cls");
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
			// �ð��Ǹ�
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
			Sleep(1100);
			system("cls");
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
		printf("\n�÷��̾��� HP : %d", player->Hp);
		printf("\n������ HP : %d", monster->Hp);
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
			printf("\n1. ��ų ���\n2. �⺻ ����\n3. ��������\n\n");
			printf("\n�Է� : ");
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
				return;
			}
				break;
			case 3:
			{
				isRun = rand() % 1;
				if (!isRun)
				{
					printf("\n\n%s�� ������ �� �־���!\n", player->PlayerName);
					player->avoid = true;
					Sleep(1100);
					system("cls");
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
			printf("\n1. ��ų ���\n2. �⺻ ����\n\n");
			printf("\n�Է� : ");
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
				Sleep(1100);
				system("cls");
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
	char UseSkill[80];
	printf("\n\n����Ͻ� ��ų�� �̸��� �Է����ּ��� : ");
	scanf("%s", UseSkill);
	system("cls");
	switch (player->PlayerJobType)
	{
	case EWizard:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(UseSkill, "FireSpike") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WizardSkill.FireSpike;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", player->JobSkillList.Intermediate_WizardSkill.FireSpike);
				Sleep(1000);
				// ���� �� �ٽ� ���� ���·� ���ư�
				// ���� ���¿��� ���� ������ óġ�߽��ϴ�! ��� ��
				// �ٽ� �� ���������� ���ư�
			}
			else if (strcmp(UseSkill, "ConOfIce") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WizardSkill.ConOfIce;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", player->JobSkillList.Intermediate_WizardSkill.ConOfIce);
				Sleep(1000);
			}
		case EBeginner:
			if (strcmp(UseSkill, "FireBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.FireBeam;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", player->JobSkillList.Beginner_WizardSkill.FireBeam);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "AquaBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.AquaBeam;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WizardSkill.AquaBeam);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "LightingBeam") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WizardSkill.LightingBeam;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WizardSkill.LightingBeam);
				Sleep(1000);
			}
		case EDefault:
			if (strcmp(UseSkill, "FireBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.FireBall;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WizardSkill.FireBall);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "SnowBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.SnowBall;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WizardSkill.SnowBall);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "LightBall") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WizardSkill.LightBall;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WizardSkill.LightBall);
				Sleep(1000);
			}
			break;
		}
		break;
	case EWarrior:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(UseSkill, "BloodInfinite") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "Duellatorum") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.Duellatorum;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_WarriorSkill.Duellatorum);
				Sleep(1000);
			}
		case EBeginner:
			if (strcmp(UseSkill, "BletInfinity") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.BletInfinity;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.BletInfinity);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "Damascus") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Damascus;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Damascus);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "Judgment") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Judgment;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_WarriorSkill.Judgment);
				Sleep(1000);
			}
		case EDefault:
			if (strcmp(UseSkill, "Blade") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Blade;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Blade);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "Phantom") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Phantom;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Phantom);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "Hellfire") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_WarriorSkill.Hellfire;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_WarriorSkill.Hellfire);
				Sleep(1000);
			}
			break;
		}

	case EArcher:
		switch (player->JobStepType)
		{
		case EIntermediate:
			if (strcmp(UseSkill, "Evolve") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.Evolve;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.Evolve);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "IllusionStep") == 0)
			{
				monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.IllusionStep;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Intermediate_ArcherSkill.IllusionStep);
				Sleep(1000);
			}
		case EBeginner:
			if (strcmp(UseSkill, "PosionArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.PosionArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.PosionArrow);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "LightningArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.LightningArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.LightningArrow);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "WindBoom") == 0)
			{
				monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.WindBoom;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Beginner_ArcherSkill.WindBoom);
				Sleep(1000);
			}
		case EDefault:
			if (strcmp(UseSkill, "IceArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.IceArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.IceArrow);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "FireArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.FireArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.FireArrow);
				Sleep(1000);
			}
			else if (strcmp(UseSkill, "BustArrow") == 0)
			{
				monster->Hp -= player->JobSkillList.Default_ArcherSkill.BustArrow;
				printf("\n���Ϳ��� %d ��ŭ ���ظ� �������ϴ�!", monster->Hp -= player->JobSkillList.Default_ArcherSkill.BustArrow);
				Sleep(1000);
			}
			break;
		}

	}
}
