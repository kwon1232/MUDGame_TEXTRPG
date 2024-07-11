#include "Framework.h"


void VillageIntro(_Village* village, Player* player)
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
    VillageMainScene(village, player);
}

void VillageMainScene(_Village* village, Player* player)
{
    int InputValue = 0;
    while (true)
    {
        printf("1. 훈련장\n2. 상점\n3. 퀘스트\n4. 던전 모험하기\n\n");
        printf("입력 : ");
        scanf("%d", &InputValue);
        if (InputValue == 1)
        {
            village->VillageType = TrainingCenter;
            TrainingCenterIntro(village, player);
            break;
        }
        else if (InputValue == 2)
        {
            village->VillageType = Store;
            StoreIntro(village, player);
            break;
        }
        else if (InputValue == 3)
        {
            village->VillageType = Quest;
            QuestIntro(village, player);
            break;
        }
        else if (InputValue == 4)
        {
            PrintDungeonIntro();
        }
        printf("\n 다시 입력해주세요\n\n");
        system("cls");
    }
}

void TrainingCenterIntro(_Village* village, Player* player)
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
            VillageMainScene(village, player);
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
        else if (InputValue == 3 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = ESkillTrainingCenter;
            system("cls");
            printf("\n스킬훈련장에 입장하셨습니다.\n");
            Sleep(200);
            SkillTrainingCenter(player);
            player->TrainingCenterCount--;
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
            VillageMainScene(village, player);
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
        printf("%.2f%%완료\n", (double)(start_time / 1) * 100);
        Sleep(10);
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
        printf("%.2f%%완료\n", (double)(start_time / 1) * 100);
        Sleep(10);
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
        printf("%.2f%%완료\n", (double)(start_time / 1) * 100);
        Sleep(10);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s의 스킬 포인트가 증가하였습니다!\n", player->PlayerName);
    printf("\n훈련 전 스킬 포인트 : %d", player->SkillPoint);
    player->SkillPoint++;
    printf("\n훈련 후 스킬 숙련도 : %d", player->SkillPoint);
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
        printf("%.2f%%완료\n", (double)(start_time / 1) * 100);
        Sleep(10);
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


void QuestIntro(_Village* village, Player* player)
{
    int InputValue = 0;

    while (true)
    {
        FILE* fp;
        char line[256];
        int foundQ_N1 = 0;

       
        int NumOfQuestList = rand() % 1 + 1;
        printf("\n\n현재 준비된 퀘스트는 %d개 있습니다.\n", NumOfQuestList);
        
        if (fp == NULL)
        {
            printf("퀘스트 파일을 읽어오지 못했습니다 ! \n");
            exit(EXIT_FAILURE);
        }

        switch (player->JobStepType)
        {
        case ENone_JobStepType:
        {
            switch (NumOfQuestList)
            {
            case 1:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.N-1") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }

                fclose(fp);
            case 2:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.N-2") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }
                fclose(fp);

                break;
            }
        }
            break;
        case EDefault:
        {
            switch (NumOfQuestList)
            {
            case 1:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.D-1") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }

                fclose(fp);
            case 2:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.D-2") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }
                fclose(fp);

                break;
            }
        }
            break;
        case EBeginner:
        {
            switch (NumOfQuestList)
            {
            case 1:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.B-1") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }

                fclose(fp);
            case 2:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.B-2") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }
                fclose(fp);

                break;
            }
        }
            break;
        case EIntermediate:
        {
            switch (NumOfQuestList)
            {
            case 1:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.I-1") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }

                fclose(fp);
            case 2:
                while (fgets(line, sizeof(line), fp) != NULL)
                {
                    if (strstr(line, "Q.I-2") != NULL)
                    {
                        printf("%s", line);
                        if (strstr(line, "Q.END") != NULL)  break;
                    }
                }
                fclose(fp);

                break;
            }
        }
            break;
        }


    }
}

void StoreIntro(_Village* village, Player* player)
{
    int InputValue = 0;
    system("cls");
    while (true)
    {
        village->StoreType = ENone_StoreStage;
        printf("\n상점에 오신 것을 환영합니다!\n\n");

        printf("-------------------------------------------------------------------\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("|                  1. 체력 포션 구매                               |\n");
        printf("|                  2. 마력 포션 구매                               |\n");
        printf("|                  3. 아이템 판매                                  |\n");
        printf("|                  4. 나가기                                       |\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("-------------------------------------------------------------------\n");

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
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(200);
                system("cls");
            }

            else if (player->PInventory.HPpotion <= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n소지할 수 있는 체력 포션 수가 다 찼습니다!\n구매할 수 없습니다!\n");
                printf("현재 포션 갯수 : %d / %d\n", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(200);
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
                Sleep(200);
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
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(200);
                system("cls");
            }

            if (player->PInventory.MPpotion <= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n소지할 수 있는 마력 포션 수가 다 찼습니다!\n구매할 수 없습니다!\n");
                printf("현재 포션 갯수 : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(200);
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
                Sleep(200);
                system("cls");
                printf("\n메뉴로 돌아갑니다!\n");
                Sleep(200);
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
                    Sleep(200);
                    system("cls");
                    printf("\n메뉴로 돌아갑니다!\n");
                    Sleep(200);
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
                    Sleep(200);
                    system("cls");
                    printf("\n메뉴로 돌아갑니다!\n");
                    Sleep(200);  
                    system("cls");
                }
            }

            system("cls");
            printf("\n메뉴로 돌아갑니다!\n");
            Sleep(200);
            system("cls");

        }

        if (InputValue == 4)
        {
            system("cls");
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