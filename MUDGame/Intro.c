#include "Framework.h"

void GaneStarOrGameEixt()
{
	int POS = 2; // 0. 시작  1. 종료
	gotoxy(10, 4);
	printf("TEXTRPG를 시작하시겠습니까?");
	gotoxy(10, 6);
	printf("1. 시작");
	gotoxy(35, 6);
	printf("2. 종료");
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
			gotoxy(10, 6); printf("1. 시작");
			SetColor(15, 5);
			gotoxy(35, 6); printf("2. 종료");
			break;
		case 1:
			SetColor(15, 5);
			gotoxy(10, 6); printf("1. 시작");
			SetColor(11, 5);
			gotoxy(35, 6); printf("2. 종료");
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
	int POS = 3; // 0 마법사 1 전사 2 궁수
	gotoxy(10, 4);
	printf("어떤 직업을 선택하시겠습니까?");
	gotoxy(10, 5);
	printf("----------------------------------------------------------------");
	gotoxy(10, 6);
	printf("1. 마법사");
	gotoxy(35, 6);
	printf("2. 전사");
	gotoxy(60, 6);
	printf("3. 궁수");
	gotoxy(10, 7);
	printf("----------------------------------------------------------------\n");
	
	gotoxy(10, 10);
	printf("선택하고 싶은 직업의 번호를 입력해주세요 : ");	scanf("%d", &POS);

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
	printf("\n\n정말 %s를 선택하시겠습니까? \n", player->PlayerJobName);
	printf("%s를 선택하고 싶으시다면 1번을 입력해주세요\n\n", player->PlayerJobName);
	printf("다른 직업이 선택하고 싶다면 1번 외에 다른 정수를 입력해주세요. : ");
	scanf("%d", &input);
	if (input != 1)
	{
		SelectPlayerJob(player);
	}
	printf("\n%s를 선택하셨습니다.\n", player->PlayerJobName);
	system("cls");
	SelectPlayerName(&input, player);
}

void SelectPlayerName(int *input, Player* player)
{
	while (true)
	{
		printf("\n\n\nPlayer의 이름을 입력해주세요\n\n");
		printf("이름 : ");
		scanf("%s", player->PlayerName);
		system("cls");
		printf("\n정말 %s로 하시겠습니까? \n\n", player->PlayerName);
		printf("1. 확정           \n2. 재입력");
		printf("\n입력 : ");
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
		printf("\n\n%s의 능력치 주사위를 굴려주세요!\n\n", &player->PlayerName);
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
		gotoxy(10, 3);printf("플레이어의 공격력 : %d", player->Attack);
		gotoxy(10, 4);printf("플레이어의 체력 : %d", player->MaxHp);
		gotoxy(10, 5);printf("플레이어의 마나 : %d", player->MaxMp);
		gotoxy(10, 6);printf("플레이어의 민첩성 : %d", player->Quickness);
		gotoxy(10, 7);printf("해당 능력치로 확정짓겠습니까?");
		gotoxy(10, 8);printf("확정하겠다면 1을 아니라면 다른 정수를 입력해주세요.");
		gotoxy(10, 9);printf("입력 : ");

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
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                  이제 모험을 시작합니다!                                       ■\n");		  
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■                                                                                                ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	Sleep(1500);
	system("cls");
}
