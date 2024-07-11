#include "Framework.h"

void GaneStarOrGameEixt(int* input)
{
	while (true)
	{
		printf("\nTEXTRPG�� �����Ͻðڽ��ϱ�?\n\n");
		printf("1. ����     \n2. ����\n");
		//GetXY();
		scanf("%d", input);
		if (*input == 2)	exit(EXIT_FAILURE);;
		if (*input == 1) 
		{
			system("cls");
			break;
		}
		else
			printf("\n�ٽ� �Է����ּ��� ! \n\n");
		system("cls");
	}
}

void SelectPlayerJob(int input, Player* player)
{
	while (1)
	{
		printf("\n� ������ �����Ͻðڽ��ϱ�? \n");
		printf("----------------------------------------------------------------\n");
		printf("1. ������\t\t2.����\t\t\t3.�ü�\n");
		printf("----------------------------------------------------------------\n");
		scanf("%d", &input);

		if (input == 1)
		{
			player->PlayerJobType = EWizard;
			strcpy(player->PlayerJobName, "Wizard");
			LastSelectPlayerJob(input, player);
			break;
		}
		else if (input == 2)
		{
			player->PlayerJobType = EWarrior;
			strcpy(player->PlayerJobName, "Warrior");
			LastSelectPlayerJob(input, player);
			break;
		}
		else if (input = 3)
		{
			player->PlayerJobType = EArcher;
			strcpy(player->PlayerJobName, "Archer");
			LastSelectPlayerJob(input, player);
			break;
		}
		else
			printf("\n�ٽ� �Է����ּ��� ! \n\n");
		system("cls");
	}
}

void LastSelectPlayerJob(int input, Player* player)
{
	system("cls");
	printf("\n\n���� %s�� �����Ͻðڽ��ϱ�? \n", player->PlayerJobName);
	printf("%s�� �����ϰ� �����ôٸ� 1���� �Է����ּ���\n", player->PlayerJobName);
	printf("�ٸ� ������ �����ϰ� �ʹٸ� 1�� �ܿ� �ٸ� Ű�� �Է����ּ���. : ");
	scanf("%d", &input);
	if (input != 1)
	{
		SelectPlayerJob(input, player);
	}
	printf("\n%s�� �����ϼ̽��ϴ�.\n", player->PlayerJobName);
	system("cls");
	SelectPlayerName(&input, player);
}

void SelectPlayerName(int *input, Player* player)
{
	while (true)
	{
		printf("\n\nPlayer�� �̸��� �Է����ּ���\n\n");
		printf("�̸� : ");
		scanf("%s", player->PlayerName);
		system("cls");
		printf("\n���� %s�� �Ͻðڽ��ϱ�? \n\n", player->PlayerName);
		printf("1. Ȯ��           \n2. ���Է�");
		printf("\n�Է� : ");
		scanf("%d", input);
		system("cls");
		if (*input == 1) 
		{
			SetRandomOfPlayerAbility(player);
			break;
		}
	}
}

void SetRandomOfPlayerAbility(Player* player)
{
	while (true)
	{
		int inputValue = 0;
		printf("\n\n%s�� �ɷ�ġ �ֻ����� �����ּ���!\n\n", &player->PlayerName);

		switch (player->PlayerJobType)
		{
		case EWizard:
		{
			player->Attack = rand() % 13 + 3;
			player->Hp = rand() % 10 + 3;
			player->Mp = rand() % 13 + 3;
			player->Quickness = rand() % 5 + 3;
		}
		break;
		case EWarrior:
		{
			player->Attack = rand() % 15 + 3;
			player->Hp = rand() % 17 + 3;
			player->Mp = rand() % 5 + 3;
			player->Quickness = rand() % 5 + 3;
		}
		break;
		case EArcher:
		{
			player->Attack = rand() % 12 + 3;
			player->Hp = rand() % 12 + 3;
			player->Mp = rand() % 10 + 3;
			player->Quickness = rand() % 7 + 3;
		}
		break;
		}

		system("cls");
		printf("�÷��̾��� ���ݷ� : %d\n", player->Attack);
		printf("�÷��̾��� ü�� : %d\n", player->Hp);
		printf("�÷��̾��� ���� : %d\n", player->Mp);
		printf("�÷��̾��� ��ø�� : %d\n", player->Quickness);
		printf("\n�ش� �ɷ�ġ�� Ȯ�����ڽ��ϱ�?\n");
		printf("Ȯ���ϰڴٸ� 1�� �ƴ϶�� �ٸ� ������ �Է����ּ���.\n");
		printf("\n�Է� : ");

		scanf("%d", &inputValue);

		if (inputValue == 1)
		{
			StartAdventure(player);
			break;
		}

	}
}

void StartAdventure(Player* player)
{
	system("cls");
	printf("--------------------------------------------------------------\n");
	printf("|                  ���� ������ �����մϴ�!                      |\n");
	printf("--------------------------------------------------------------\n");
	Sleep(300);
	system("cls");
}
