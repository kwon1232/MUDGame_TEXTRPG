#include "Framework.h"

void GaneStarOrGameEixt()
{
	int POS = 2; // 0. ����  1. ����
	gotoxy(10, 4);
	printf("TEXTRPG�� �����Ͻðڽ��ϱ�?");
	gotoxy(10, 6);
	printf("1. ����");
	gotoxy(35, 6);
	printf("2. ����");
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 1;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 1) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))
			break;
		switch (POS)
		{
		case 0:
			SetColor(11, 5);
			gotoxy(10, 6); printf("1. ����");
			SetColor(15, 5);
			gotoxy(35, 6); printf("2. ����");
			break;
		case 1:
			SetColor(15, 5);
			gotoxy(10, 6); printf("1. ����");
			SetColor(11, 5);
			gotoxy(35, 6); printf("2. ����");
			break;
		default: break;
		}
		Sleep(100);
	}
	if (POS == 1)	exit(EXIT_FAILURE);
	else if (POS == 0)
	{
		system("cls");
	}
	
}

void SelectPlayerJob(Player* player)
{
	int POS = 3; // 0 ������ 1 ���� 2 �ü�
	gotoxy(10, 4);
	printf("� ������ �����Ͻðڽ��ϱ�?");
	gotoxy(10, 5);
	printf("----------------------------------------------------------------");
	gotoxy(10, 6);
	printf("1. ������");
	gotoxy(35, 6);
	printf("2. ����");
	gotoxy(60, 6);
	printf("3. �ü�");
	gotoxy(10, 7);
	printf("----------------------------------------------------------------\n");
	
	gotoxy(10, 10);
	printf("�����ϰ� ���� ������ ��ȣ�� �Է����ּ��� : ");	scanf("%d", &POS);

	system("cls");
	if (POS == 1)
	{
		player->PlayerJobType = EWizard;
		strcpy(player->PlayerJobName, "Wizard");
		player->JobStepType = EDefault;
		LastSelectPlayerJob(player);
	}
	else if (POS == 2)
	{
		player->PlayerJobType = EWarrior;
		strcpy(player->PlayerJobName, "Warrior");
		player->JobStepType = EDefault;
		LastSelectPlayerJob(player);
	}
	else if (POS = 3)
	{
		player->PlayerJobType = EArcher;
		strcpy(player->PlayerJobName, "Archer");
		player->JobStepType = EDefault;
		LastSelectPlayerJob(player);
		
	}
}

void LastSelectPlayerJob(Player* player)
{
	int input;
	system("cls");
	printf("\n\n���� %s�� �����Ͻðڽ��ϱ�? \n", player->PlayerJobName);
	printf("%s�� �����ϰ� �����ôٸ� 1���� �Է����ּ���\n\n", player->PlayerJobName);
	printf("�ٸ� ������ �����ϰ� �ʹٸ� 1�� �ܿ� �ٸ� ������ �Է����ּ���. : ");
	scanf("%d", &input);
	if (input != 1)
	{
		SelectPlayerJob(player);
	}
	printf("\n%s�� �����ϼ̽��ϴ�.\n", player->PlayerJobName);
	system("cls");
	SelectPlayerName(&input, player);
}

void SelectPlayerName(int *input, Player* player)
{
	while (true)
	{
		printf("\n\n\nPlayer�� �̸��� �Է����ּ���\n\n");
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
		gotoxy(10, 3);
		printf("\n\n%s�� �ɷ�ġ �ֻ����� �����ּ���!\n\n", &player->PlayerName);
		system("cls");
		switch (player->PlayerJobType)
		{
		case EWizard:
		{
			player->Attack = rand() % 3 + 13;
			player->MaxHp = rand() % 3 + 10;
			player->MaxMp = rand() % 3 + 13;
			player->Quickness = rand() % 3 + 5;
		}
		break;
		case EWarrior:
		{
			player->Attack = rand() % 3 + 15;
			player->MaxHp = rand() % 3 + 17;
			player->MaxMp = rand() % 3 + 5;
			player->Quickness = rand() % 3 + 5;
		}
		break;
		case EArcher:
		{
			player->Attack = rand() % 3 + 12;
			player->MaxHp = rand() % 3 + 12;
			player->MaxMp = rand() % 3 + 10;
			player->Quickness = rand() % 3 + 7;
		}
		break;
		}

		system("cls");
		gotoxy(10, 3);printf("�÷��̾��� ���ݷ� : %d", player->Attack);
		gotoxy(10, 4);printf("�÷��̾��� ü�� : %d", player->MaxHp);
		gotoxy(10, 5);printf("�÷��̾��� ���� : %d", player->MaxMp);
		gotoxy(10, 6);printf("�÷��̾��� ��ø�� : %d", player->Quickness);
		gotoxy(10, 7);printf("�ش� �ɷ�ġ�� Ȯ�����ڽ��ϱ�?");
		gotoxy(10, 8);printf("Ȯ���ϰڴٸ� 1�� �ƴ϶�� �ٸ� ������ �Է����ּ���.");
		gotoxy(10, 9);printf("�Է� : ");

		scanf("%d", &inputValue);

		if (inputValue == 1)
		{
			StartAdventure();
			break;
		}

	}
}

void StartAdventure()
{
	system("cls");
	printf("���������������������������������������������������\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                  ���� ������ �����մϴ�!                                       ��\n");		  
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("��                                                                                                ��\n");
	printf("���������������������������������������������������");
	Sleep(1500);
	system("cls");
}
