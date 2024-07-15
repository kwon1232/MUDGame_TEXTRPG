#include "Framework.h"


void SellecVillage(_Village village[], Player* player, _Dungeon dungeon[])
{
    int POS = 4;	//0 - 새로 하기, 1 - 이어 하기, 2 - 랭킹 보기, 3 - 게임 종료 TEXT RPG
    CursorView(0);
    system("COLOR 5F");
    gotoxy(10, 4); printf("1. 숲 속 마을");
    gotoxy(35, 4); printf("2. 달맞이 마을");
    gotoxy(10, 5); printf("3. 해변 마을");
    gotoxy(35, 5); printf("4. 폭포 마을");

    gotoxy(0, 8);
    printf("이동하고 싶은 마을의 번호를 입력해주세요 : ");
    scanf("%d", &POS);
    system("cls");
    
    if (POS == 1) {
        printf("숲 속 마을로 이동합니다.");
        VillageIntro(&village[0], player, dungeon);
        Sleep(800);
        system("cls");
    }
    else if (POS == 2) {
        printf("달맞이 마을로 이동합니다.");
        VillageIntro(&village[1], player, dungeon);
        Sleep(800);
        system("cls");
    }
    else if (POS == 3) {
        printf("해변 마을로 이동합니다.");
        VillageIntro(&village[2], player, dungeon);
        Sleep(800);
        system("cls");
    }
    else{
        printf("폭포 마을로 이동합니다.");
        VillageIntro(&village[3], player, dungeon);
        Sleep(800);
        system("cls");
    }

}

void VillageIntro(_Village* village, Player* player, _Dungeon dungeon[])
{

    village->Map.MapType = EVillage;
    printf("Village %d: %s\n", village->VillageNum,village->VillageName);
    printf("            /---------------------\\\n");
    printf("           /-----------------------\\\n");
    printf("          /-------------------------\\\n");
    printf("         /---------------------------\\\n");
    printf("        /-----------------------------\\\n");
    printf("       /-------------------------------\\\n");
    printf("       |                               |\n");
    printf("       |                               |\n");
    printf("       |            ---------          |\n");
    printf("       |            |       |          |\n");
    printf("       |            |       |          |\n");
    printf("       |===============================|\n");
    Sleep(1000);
    system("cls");
    printf("\n\n%s 마을에 오신 것을 환영합니다!\n\n",village->VillageName);
    Sleep(1200);
    system("cls");
    VillageMainScene(village, player, dungeon);
}

void VillageMainScene(_Village* village, Player* player, _Dungeon dungeon[])
{
    int InputValue = 0;
    while (true)
    {
        printf("1. 훈련장\n2. 상점\n3. 퀘스트\n4. 스킬창 열기\n5. 던전 모험하기\n\n");
        printf("입력 : ");
        scanf("%d", &InputValue);
        if (InputValue == 1)
        {
            village->VillageType = TrainingCenter;
            TrainingCenterIntro(village, player, dungeon);
            break;
        }
        else if (InputValue == 2)
        {
            village->VillageType = Store;
            StoreIntro(village, player, dungeon);
            break;
        }
        else if (InputValue == 3)
        {
            village->VillageType = Quest;
            QuestIntro(village, player, dungeon);
            break;
        }
        else if (InputValue == 4)
        {
            // 스킬 올려주는 함수 구현
        }
        else if (InputValue == 5)
        {
            DungeonInitial(dungeon, player, dungeon);
        }
        printf("\n 다시 입력해주세요\n\n");
        system("cls");
    }
}

void TrainingCenterIntro(_Village* village, Player* player, _Dungeon dungeon[])
{
    int InputValue = 0;

    while (true)
    {
        system("cls");
        village->TrainingCenterType = ENone_TrainingCenter;
        printShield();
        printShield();
        Sleep(200);
        system("cls");
        printf("\n\n훈련소에 입장하셨습니다.\n\n");
        printf("\n1. 체력훈련장\n2. 마력훈련장\n3. 스킬훈련장\n4. 민첩훈련장 \n5. 훈련장 나가기");
        printf("\n\n이동할 곳을 입력해주세요 : ");
        scanf("%d", &InputValue);

        if (player->TrainingCenterCount <= 0)
        {
            system("cls");
            printf("\n\n마을에서 충분히 훈련하셨습니다!\n");
            printf("\n마을 밖에서 모험을 즐겨주세요!\n");
            VillageMainScene(village, player, dungeon);
            break;
        }

        if (InputValue == 1 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = EHPTrainingCenter;
            system("cls");
            printf("\n체력훈련장에 입장하셨습니다.\n");
            Sleep(200);
            HPTrainingCenter(player);
            player->TrainingCenterCount--;
        }
        else if (InputValue == 2 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = EMPTrainingCenter;
            system("cls");
            printf("\n마력훈련장에 입장하셨습니다.\n");
            Sleep(200);
            MPTrainingCenter(player);
            player->TrainingCenterCount--;
        }
        else if (InputValue == 3 && player->SkillPoint > 0)
        {
            village->TrainingCenterType = ESkillTrainingCenter;
            system("cls");
            printf("\n스킬훈련장에 입장하셨습니다.\n");
            Sleep(200);
            SkillTrainingCenter(player);
            player->SkillPoint--;
        }
        else if (InputValue == 4 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = EQuicknessTrainingCenter;
            system("cls");
            printf("\n민첩훈련장에 입장하셨습니다.\n");
            Sleep(200);
            QuicknessTrainingCenter(player);
            player->TrainingCenterCount--;
        }
        else if (InputValue == 5)
        {
            system("cls");
            VillageMainScene(village, player, dungeon);
            break;
        }

        printf("\n다시 입력해주세요.");
        system("cls");
    }
}


void HPTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1초 동안 훈련
    while (true)
    {
        system("cls");
        printf("훈련중...!\n");
        Sleep(500);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s의 체력이 증가하였습니다!\n", player->PlayerName);
    printf("\n훈련 전 체력 : %d", player->Hp);
    player->Hp++;
    printf("\n훈련 후 체력 : %d", player->Hp);
    Sleep(1200);
    system("cls");
}

void MPTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1초 동안 훈련
    while (true)
    {
        system("cls");
        printf("훈련중...!\n");
        Sleep(500);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s의 마나가 증가하였습니다!\n", player->PlayerName);
    printf("\n훈련 전 마나 : %d", player->Mp);
    player->Mp++;
    printf("\n훈련 후 마나 : %d", player->Mp);
    Sleep(1200);
    system("cls");
}

void SkillTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1초 동안 훈련
    while (true)
    {
        system("cls");
        printf("훈련중...!\n");
        Sleep(500);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s의 스킬 포인트가 증가하였습니다!\n", player->PlayerName);
    printf("\n훈련 전 스킬 포인트 : %d", player->SkillPoint);
    player->SkillPoint++;
    printf("\n훈련 후 스킬 포인트 : %d", player->SkillPoint);
    Sleep(1200);
    system("cls");
}

void QuicknessTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1초 동안 훈련
    while (true)
    {
        system("cls");
        printf("훈련중...!\n");
        Sleep(500);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s의 민첩성이 증가하였습니다!\n", player->PlayerName);
    printf("\n훈련 전 민첩성 : %d", player->Quickness);
    player->Quickness++;
    printf("\n훈련 후 민첩성 : %d", player->Quickness);
    Sleep(1200);
    system("cls");
}


void QuestIntro(_Village* village, Player* player, _Dungeon dungeon[])
{
    int InputValue = 0;
    char QuestNum[40];

    while (true)
    {
        system("cls");
        int NumOfQuestList = rand() % 1 + 1;
        printf("\n\n현재 준비된 퀘스트는 %d개 있습니다.\n", NumOfQuestList);
        Sleep(1000);
        switch (player->JobStepType)
        {
        case ENone_JobStepType:
        {
            switch (NumOfQuestList)
            {
            case 2:
                printf("퀘스트 넘버 : Q.N-2\n\n");
                printf("오솔길 던전의 몬스터가 떨어트리는 나무가지 3개를 가져와주세요.\n");
                printf("몬스터에게서 나오는 나뭇가지는 집을 보수하기 좋아요.\n\n");
                printf("목표 : 오솔길 던전의 스텀프를 처지하여 나뭇가지 3개 구하기\n");
                printf("보상 : 50골드, 체력 포션 5개\n");

            case 1:
                printf("퀘스트 넘버 : Q.N-1\n\n");
                printf("엑스 스텀프를 잡아와주세요.\n");
                printf("엑스 스텀프가 돌아다니는 통에 최근에 마을 밖으로 나간 적이 없어요.\n\n");
                printf("목표 : 오솔길 던전의 엑스텀프 3마리 잡기\n");
                printf("보상 : 50골드, 체력 포션 5개\n");
                break;
            }
        }
            break;
        case EDefault:
        {
            switch (NumOfQuestList)
            {
            case 2:
                printf("퀘스트 넘버 : Q.D - 2\n\n");
                printf("타락한 나무 정령을 무찔러주세요!\n");
                printf("타락한 나무 정령들 때문에 오솔길 밖으로 나갈 수 없어요.\n\n");
                printf("목표 : 깊은 숲 속의 타락한 나무 정령 3마리 처지하기\n");
                printf("보상 : 80골드, 마나 포션 3개, 체력 포션 3개\n");
                
            case 1:
                printf("퀘스트 넘버 : Q.D - 1\n\n");
                printf("다크 스텀프를 잡아주세요.\n");
                printf("다크 스텀프는 오솔길을 장악하는 보스입니다.\n");
                printf("다크 스텀프 때문에 옆마을로 넘어갈 수 없어요!\n\n");
                printf("목표 : 오솔길 던전의 다크 스텀프 무찌르기\n");
                printf("보상 : 80골드, 마나 포션 3개, 체력 포션 3개\n");

                break;
            }
        }
            break;
        case EBeginner:
        {
            switch (NumOfQuestList)
            {
            case 2:

                printf("퀘스트 넘버 : Q.B - 2\n\n");
                printf("얕은 늪에는 현혹된 악어 다일이 살고있어\n");
                printf("다일은 늪 속에서 살기 때문에 내가 직접 잡기엔 너무 어려워\n");
                printf("혹시 너가 도와주겠니 ?\n\n");
                printf("    목표 : 다일 3마리 처지하기\n");
                printf("보상 : 110골드마나 포션 4개, 체력 포션 4개\n");


            case 1:
                printf("퀘스트 넘버 : Q.B - 1\n\n");
                printf("깊은 숲 속에 나무 정령들을 타락시킨건\n");
                printf("셰이드라는 악령 때문이라던데,\n");
                printf("셰이드를 처치해줄 수 있나요 ?\n\n");
                printf("목표 : 셰이드 3마리 처지하기\n");
                printf("보상 : 110골드, 마나 포션 4개, 체력 포션 4개\n");
                break;
            }
        }
            break;
        case EIntermediate:
        {
            switch (NumOfQuestList)
            {
            case 2:
                printf("퀘스트 넘버 : Q.I - 2\n\n");
                printf("얕은 늪에는 디노가 살고있지,\n");
                printf("근데 그거 알아 ?\n");
                printf("디노를 처지해주면 조금 평화롭지 않을까 ?\n\n");

                printf("목표 : 보스 몬스터 디노 처지하기\n");
                printf("보상 : 280골드, 마나 포션 4개, 체력 포션 4개\n");

            case 1:
                printf("퀘스트 넘버 : Q.I - 1\n\n");
                printf("얕은 늪에는 다일이 살고있다는 거 너도 알고있지 ?\n");
                printf("다일 또는 디노를 처치하면 에메랄드를 구할 수 있다는 소문이 돌아...\n");
                printf("보석상에서 디노를 처치한 에메랄드를 가져오면 개당 100골드나 준다네!\n\n");

                printf("목표 : 디노 또는 다일을 처치해서 에메랄드 2개 구해오기\n");
                printf("보상 : 200골드, 마나 포션 4개, 체력 포션 4개\n");

                break;
            }
        }
            break;
        }
        printf("\n\n퀘스트를 수락하시겠습니까?\n");
        printf("1. 수락\n2. 거절\n");
        scanf("%d", &InputValue);
        if (InputValue == 2) 
        { 
            system("cls");
            VillageMainScene(village, player, dungeon);
            break;
        }
        printf("\n\n받아올 퀘스트 넘버를 입력해주세요 : ");
        scanf("%s", &QuestNum);
        if (QuestAccept(player,QuestNum))
        {
            printf("\n\n퀘스트를 수락했습니다!");
            Sleep(1000);
            system("cls");
            VillageMainScene(village, player, dungeon);
            break;
        }
        else
        {
            printf("\n\n이미 수락한 퀘스트입니다!");
            Sleep(1000);
            system("cls");
            VillageMainScene(village, player, dungeon);
            break;
        }
    }
}

bool QuestAccept(Player* player, char QuestNum[])
{
    for (int i = 0; i < QuestListCount; i++)
    {
        if (strcmp(player->P_Quest.QuestListStr[i], QuestNum) == 0)
        {
            player->P_Quest.CheckAcceptQuestList[i] = true;
            return true;
        }
    }
    return false;
}

void StoreIntro(_Village* village, Player* player, _Dungeon dungeon[])
{
    int InputValue = 0;
    system("cls");
    while (true)
    {
        village->StoreType = ENone_StoreStage;
        printf("\n상점에 오신 것을 환영합니다!\n\n");

        printf("===================================================================\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("|                  1. 체력 포션 구매                              |\n");
        printf("|                  2. 마력 포션 구매                              |\n");
        printf("|                  3. 아이템 판매                                 |\n");
        printf("|                  4. 나가기                                      |\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("===================================================================\n");

        printf("\n어떤 거래를 하시겠습니까 숫자를 입력해주세요:\n");
        scanf("%d", &InputValue);

        if (InputValue == 1)
        {
            village->StoreType = EHPPotion;
            if (player->PInventory.gold < 50)
            {
                system("cls");
                printf("\n\n골드가 부족해서 구매할 수 없습니다!\n");
                printf("체력 포션의 가격은 50골드입니다!\n\n");
                printf("현재 %s의 총 골드 : %d", player->PlayerName, player->PInventory.gold);
                Sleep(1200);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(1200);
                system("cls");
            }

            else if (player->PInventory.HPpotion >= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n소지할 수 있는 체력 포션 수가 다 찼습니다!\n구매할 수 없습니다!\n");
                printf("현재 포션 갯수 : %d / %d\n", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                Sleep(1200);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(1200);
                system("cls");
            }

            else
            {
                printBuyComplete();

                printf("구매 전 골드 : %d\n", player->PInventory.gold);
                player->PInventory.gold -= 50;
                printf("구매 후 골드 : %d\n", player->PInventory.gold);
                printf("\n\n");
                printf("구매 전 포션 갯수 : %d / %d\n", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                player->PInventory.HPpotion++;
                printf("구매 후 포션 갯수 : %d / %dn", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                Sleep(1200);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(1200);
                system("cls");
            }
        }

        else if (InputValue == 2)
        {
            village->StoreType = EMPPotion;
            if (player->PInventory.gold < 50)
            {
                system("cls");
                printf("\n\n골드가 부족해서 구매할 수 없습니다!\n");
                printf("마력 포션의 가격은 50골드입니다!\n\n");
                printf("현재 %s의 총 골드 : %d", player->PlayerName, player->PInventory.gold);
                Sleep(1200);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(1200);
                system("cls");
            }

            if (player->PInventory.MPpotion >= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n소지할 수 있는 마력 포션 수가 다 찼습니다!\n구매할 수 없습니다!\n");
                printf("현재 포션 갯수 : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                Sleep(1200);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(1200);
                system("cls");
            }

            else
            {
                printBuyComplete();

                printf("구매 전 골드 : %d\n", player->PInventory.gold);
                player->PInventory.gold -= 50;
                printf("구매 후 골드 : %d\n", player->PInventory.gold);
                printf("\n\n");
                printf("구매 전 포션 갯수 : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                player->PInventory.HPpotion++;
                printf("구매 후 포션 갯수 : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                Sleep(1200);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(1200);
                system("cls");
            }
        }

        else if (InputValue == 3)
        {
            system("cls");
            printf("어떤 아이템을 판매하시겠습니까?\n");
            printSaleorBuyItem();
            printBuyComplete("\n메뉴로 되돌아가고 싶다면 3번을 입력해주세요!\n");
            printf("\n판매할 아이템에 맞는 정수를 입력해주세요 : ");
            scanf("%d", &InputValue);

            if (InputValue == 1)
            {
                village->StoreType = EWood;
                if (player->PInventory.wood >= 1)
                {
                    printf("판매 전 골드 : %d\n", player->PInventory.gold);
                    player->PInventory.gold += 30;
                    printf("판매 후 골드 : %d\n", player->PInventory.gold);
                    printf("\n\n");
                    printf("판매 후 나뭇가지 갯수 : %d / %d\n", player->PInventory.wood, player->PInventory.MaxOwnItem);
                    player->PInventory.HPpotion++;
                    printf("구매 후 나뭇가지 갯수 : %d / %d\n", player->PInventory.wood, player->PInventory.MaxOwnItem);
                    Sleep(1200);
                    printf("\n메뉴로 돌아갑니다!\n");
                    Sleep(1200);
                    system("cls");
                }
            }
            else if (InputValue == 2)
            {
                village->StoreType = EEmerald;
                if (player->PInventory.emerald >= 1)
                {
                    printf("판매 전 골드 : %d\n", player->PInventory.gold);
                    player->PInventory.gold += 60;
                    printf("판매 후 골드 : %d\n", player->PInventory.gold);
                    printf("\n\n");
                    printf("판매 후 에메랄드 갯수 : %d / %d\n", player->PInventory.emerald, player->PInventory.MaxOwnItem);
                    player->PInventory.HPpotion++;
                    printf("구매 후 에메랄드 갯수 : %d / %d\n", player->PInventory.emerald, player->PInventory.MaxOwnItem);
                    Sleep(1200);
                    printf("\n메뉴로 돌아갑니다!\n");
                    Sleep(1200);
                    system("cls");
                }
            }


            printf("\n메뉴로 돌아갑니다!\n");
            Sleep(700);
            system("cls");

        }

        if (InputValue == 4)
        {
            system("cls");
            VillageIntro(village, player, dungeon);
            break;
        }
    }
}

void printShield() 
{
    printf("\n\n");
    printf("\n\n");
    printf("       ________\n");
    printf("     //        \\\\\n");
    printf("    //          \\\\\n");
    printf("   //            \\\\\n");
    printf("  //              \\\\\n");
    printf(" //      ____      \\\\\n");
    printf(" //     | ㅡ |     \\\\\n");
    printf("||      |    |      ||\n");
    printf("||      |____|      ||\n");
    printf("||                  ||\n");
    printf("||      |####|      ||\n");
    printf("||      |####|      ||\n");
    printf("||      |____|      ||\n");
    printf("||                  ||\n");
    printf(" \\\\                //\n");
    printf("  \\\\              //\n");
    printf("   \\\\____________//\n");
    printf("\n\n");
    printf("\n\n");
    Sleep(200);
    system("cls");
}

void printBuyComplete()
{
    printf("\n\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|                                                                 |\n");
    printf("|                    + 구매에 완료했습니다 ! +                      |\n");
    printf("|                                                                 |\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("\n\n");
    Sleep(200);
    system("cls");
}


void printSaleorBuyItem()
{
    printf("\n\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|                                                                 |\n");
    printf("|                    1. 나뭇가지                                   |\n");
    printf("|                    2. 에메랄드                                   |\n");
    printf("|                                                                 |\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("\n\n");
    Sleep(200);
    system("cls");
}