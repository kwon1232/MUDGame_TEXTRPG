#include "Intro.h"
#include "Framework.h"

void GaneStarOrGameEixt(int* input)
{
	while (true)
	{
		printf("\nTEXTRPG�� �����Ͻðڽ��ϱ�?\n\n");
		printf("1. ����     \n2. ����\n");
		//GetXY();
		scanf("%d", input);
		if (*input == 2) return 0;
		if (*input == 1) break;
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
			player->PlayerJobType = Wizard;
			strcpy(player->PlayerJobName, "Wizard");
			LastSelectPlayerJob(input, player);
			break;
		}
		else if (input == 2)
		{
			player->PlayerJobType = Warrior;
			strcpy(player->PlayerJobName, "Warrior");
			LastSelectPlayerJob(input, player);
			break;
		}
		else if (input = 3)
		{
			player->PlayerJobType = Archer;
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
	printf("\n\n���� %s�� �����Ͻðڽ��ϱ�? \n", player->PlayerJobName);
	printf("%s�� �����ϰ� �����ôٸ� 1���� �Է����ּ���\n", player->PlayerJobName);
	printf("�ٸ� ������ �����ϰ� �ʹٸ� 1�� �ܿ� �ٸ� Ű�� �Է����ּ���. : ");
	scanf("%d", &input);
	if (input != 1)
	{
		SelectPlayerJob(input, &player);
	}
	printf("\n%s�� �����ϼ̽��ϴ�.\n", player->PlayerJobName);
	system("cls");
}

void SelectPlayerName(int input, Player* player)
{
	printf("\n\nPlayer�� �̸��� �Է����ּ���\n\n");
	printf("�̸� : ");
	scanf("%s", &player->PlayerName);
}

void SetRandomOfPlayerAbility(Player* player)
{
	while (true)
	{
		int inputValue = 0;
		printf("\n\n%s�� �ɷ�ġ �ֻ����� �����ּ���!\n\n", &player->PlayerName);

		switch (player->PlayerJobType)
		{
		case Wizard:
		{
			player->Attack = rand() % 13 + 3;
			player->Hp = rand() % 10 + 3;
			player->Mp = rand() % 13 + 3;
			player->Quickness = rand() % 5 + 3;
		}
		break;
		case Warrior:
		{
			player->Attack = rand() % 15 + 3;
			player->Hp = rand() % 17 + 3;
			player->Mp = rand() % 5 + 3;
			player->Quickness = rand() % 5 + 3;
		}
		break;
		case Archer:
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
		printf("�÷��̾��� ü�� : %.1lf\n", player->Hp);
		printf("�÷��̾��� ���� : %.1lf\n", player->Mp);
		printf("�÷��̾��� ��ø�� : %d\n", player->Quickness);
		printf("\n�ش� �ɷ�ġ�� Ȯ�����ڽ��ϱ�?\n");
		printf("Ȯ���ϰڴٸ� 1�� �ƴ϶�� �ٸ� ������ �Է����ּ���.\n");
		printf("\n�Է� : ");

		scanf("%d", &inputValue);

		if (inputValue == 1)
		{
			break;
		}
	}
}
