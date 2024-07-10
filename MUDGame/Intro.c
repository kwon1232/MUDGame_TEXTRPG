#include "Intro.h"
#include "Framework.h"

void GaneStarOrGameEixt(int* input)
{
	while (true)
	{
		printf("\nTEXTRPG를 시작하시겠습니까?\n\n");
		printf("1. 시작     \n2. 종료\n");
		//GetXY();
		scanf("%d", input);
		if (*input == 2) return 0;
		if (*input == 1) break;
		else
			printf("\n다시 입력해주세요 ! \n\n");
		system("cls");
	}
}

void SelectPlayerJob(int input, Player* player)
{
	while (1)
	{
		printf("\n어떤 직업을 선택하시겠습니까? \n");
		printf("----------------------------------------------------------------\n");
		printf("1. 마법사\t\t2.전사\t\t\t3.궁수\n");
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
			printf("\n다시 입력해주세요 ! \n\n");
		system("cls");
	}
}

void LastSelectPlayerJob(int input, Player* player)
{
	printf("\n\n정말 %s를 선택하시겠습니까? \n", player->PlayerJobName);
	printf("%s를 선택하고 싶으시다면 1번을 입력해주세요\n", player->PlayerJobName);
	printf("다른 직업이 선택하고 싶다면 1번 외에 다른 키를 입력해주세요. : ");
	scanf("%d", &input);
	if (input != 1)
	{
		SelectPlayerJob(input, &player);
	}
	printf("\n%s를 선택하셨습니다.\n", player->PlayerJobName);
	system("cls");
}

void SelectPlayerName(int input, Player* player)
{
	printf("\n\nPlayer의 이름을 입력해주세요\n\n");
	printf("이름 : ");
	scanf("%s", &player->PlayerName);
}

void SetRandomOfPlayerAbility(Player* player)
{
	while (true)
	{
		int inputValue = 0;
		printf("\n\n%s의 능력치 주사위를 굴려주세요!\n\n", &player->PlayerName);

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
		printf("플레이어의 공격력 : %d\n", player->Attack);
		printf("플레이어의 체력 : %.1lf\n", player->Hp);
		printf("플레이어의 마나 : %.1lf\n", player->Mp);
		printf("플레이어의 민첩성 : %d\n", player->Quickness);
		printf("\n해당 능력치로 확정짓겠습니까?\n");
		printf("확정하겠다면 1을 아니라면 다른 정수를 입력해주세요.\n");
		printf("\n입력 : ");

		scanf("%d", &inputValue);

		if (inputValue == 1)
		{
			break;
		}
	}
}
