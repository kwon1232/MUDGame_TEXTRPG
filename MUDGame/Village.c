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
    printf("\n\n%s ������ ���� ���� ȯ���մϴ�!\n\n",village->VillageName);
    Sleep(1200);
    system("cls");
    VillageMainScene(village, player);
}

void VillageMainScene(_Village* village, Player* player)
{
    int InputValue = 0;
    while (true)
    {
        printf("1. �Ʒ���\n2. ����\n3. ����Ʈ\n4. ���� �����ϱ�\n\n");
        printf("�Է� : ");
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
        printf("\n �ٽ� �Է����ּ���\n\n");
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
        printf("\n\n�Ʒüҿ� �����ϼ̽��ϴ�.\n\n");
        printf("\n1. ü���Ʒ���\n2. �����Ʒ���\n3. ��ų�Ʒ���\n4. ��ø�Ʒ��� \n5. �Ʒ��� ������");
        printf("\n\n�̵��� ���� �Է����ּ��� : ");
        scanf("%d", &InputValue);

        if (player->TrainingCenterCount <= 0)
        {
            system("cls");
            printf("\n\n�������� ����� �Ʒ��ϼ̽��ϴ�!\n");
            printf("\n���� �ۿ��� ������ ����ּ���!\n");
            VillageMainScene(village, player);
            break;
        }

        if (InputValue == 1 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = EHPTrainingCenter;
            system("cls");
            printf("\nü���Ʒ��忡 �����ϼ̽��ϴ�.\n");
            Sleep(200);
            HPTrainingCenter(player);
            player->TrainingCenterCount--;
        }
        else if (InputValue == 2 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = EMPTrainingCenter;
            system("cls");
            printf("\n�����Ʒ��忡 �����ϼ̽��ϴ�.\n");
            Sleep(200);
            MPTrainingCenter(player);
            player->TrainingCenterCount--;
        }
        else if (InputValue == 3 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = ESkillTrainingCenter;
            system("cls");
            printf("\n��ų�Ʒ��忡 �����ϼ̽��ϴ�.\n");
            Sleep(200);
            SkillTrainingCenter(player);
            player->TrainingCenterCount--;
        }
        else if (InputValue == 4 && player->TrainingCenterCount > 0)
        {
            village->TrainingCenterType = EQuicknessTrainingCenter;
            system("cls");
            printf("\n��ø�Ʒ��忡 �����ϼ̽��ϴ�.\n");
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

        printf("\n�ٽ� �Է����ּ���.");
        system("cls");
    }
}


void HPTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1�� ���� �Ʒ�
    while (true)
    {
        system("cls");
        printf("%.2f%%�Ϸ�\n", (double)(start_time / 1) * 100);
        Sleep(10);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s�� ü���� �����Ͽ����ϴ�!\n", player->PlayerName);
    printf("\n�Ʒ� �� ü�� : %d", player->Hp);
    player->Hp++;
    printf("\n�Ʒ� �� ü�� : %d", player->Hp);
    Sleep(1200);
    system("cls");
}

void MPTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1�� ���� �Ʒ�
    while (true)
    {
        system("cls");
        printf("%.2f%%�Ϸ�\n", (double)(start_time / 1) * 100);
        Sleep(10);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s�� ������ �����Ͽ����ϴ�!\n", player->PlayerName);
    printf("\n�Ʒ� �� ���� : %d", player->Mp);
    player->Mp++;
    printf("\n�Ʒ� �� ���� : %d", player->Mp);
    Sleep(1200);
    system("cls");
}

void SkillTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1�� ���� �Ʒ�
    while (true)
    {
        system("cls");
        printf("%.2f%%�Ϸ�\n", (double)(start_time / 1) * 100);
        Sleep(10);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s�� ��ų ����Ʈ�� �����Ͽ����ϴ�!\n", player->PlayerName);
    printf("\n�Ʒ� �� ��ų ����Ʈ : %d", player->SkillPoint);
    player->SkillPoint++;
    printf("\n�Ʒ� �� ��ų ���õ� : %d", player->SkillPoint);
    Sleep(1200);
    system("cls");
}

void QuicknessTrainingCenter(Player* player)
{
    time_t start_time;

    start_time = time(NULL);

    // 1�� ���� �Ʒ�
    while (true)
    {
        system("cls");
        printf("%.2f%%�Ϸ�\n", (double)(start_time / 1) * 100);
        Sleep(10);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s�� ��ø���� �����Ͽ����ϴ�!\n", player->PlayerName);
    printf("\n�Ʒ� �� ��ø�� : %d", player->Quickness);
    player->Quickness++;
    printf("\n�Ʒ� �� ��ø�� : %d", player->Quickness);
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
        printf("\n\n���� �غ�� ����Ʈ�� %d�� �ֽ��ϴ�.\n", NumOfQuestList);
        
        if (fp == NULL)
        {
            printf("����Ʈ ������ �о���� ���߽��ϴ� ! \n");
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
        printf("\n������ ���� ���� ȯ���մϴ�!\n\n");

        printf("-------------------------------------------------------------------\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("|                  1. ü�� ���� ����                               |\n");
        printf("|                  2. ���� ���� ����                               |\n");
        printf("|                  3. ������ �Ǹ�                                  |\n");
        printf("|                  4. ������                                       |\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("-------------------------------------------------------------------\n");

        printf("\n� �ŷ��� �Ͻðڽ��ϱ� ���ڸ� �Է����ּ���:\n");
        scanf("%d", &InputValue);

        if (InputValue == 1)
        {
            village->StoreType = EHPPotion;
            if (player->PInventory.gold < 50)
            {
                system("cls");
                printf("\n\n��尡 �����ؼ� ������ �� �����ϴ�!\n");
                printf("ü�� ������ ������ 50����Դϴ�!\n\n");
                printf("���� %s�� �� ��� : %d", player->PlayerName, player->PInventory.gold);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(200);
                system("cls");
            }

            else if (player->PInventory.HPpotion <= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n������ �� �ִ� ü�� ���� ���� �� á���ϴ�!\n������ �� �����ϴ�!\n");
                printf("���� ���� ���� : %d / %d\n", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(200);
                system("cls");
            }

            else
            {
                printBuyComplete();

                printf("���� �� ��� : %d\n", player->PInventory.gold);
                player->PInventory.gold -= 50;
                printf("���� �� ��� : %d\n", player->PInventory.gold);
                printf("\n\n");
                printf("���� �� ���� ���� : %d / %d\n", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                player->PInventory.HPpotion++;
                printf("���� �� ���� ���� : %d / %dn", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
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
                printf("\n\n��尡 �����ؼ� ������ �� �����ϴ�!\n");
                printf("���� ������ ������ 50����Դϴ�!\n\n");
                printf("���� %s�� �� ��� : %d", player->PlayerName, player->PInventory.gold);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(200);
                system("cls");
            }

            if (player->PInventory.MPpotion <= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n������ �� �ִ� ���� ���� ���� �� á���ϴ�!\n������ �� �����ϴ�!\n");
                printf("���� ���� ���� : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(200);
                system("cls");
            }

            else
            {
                printBuyComplete();

                printf("���� �� ��� : %d\n", player->PInventory.gold);
                player->PInventory.gold -= 50;
                printf("���� �� ��� : %d\n", player->PInventory.gold);
                printf("\n\n");
                printf("���� �� ���� ���� : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                player->PInventory.HPpotion++;
                printf("���� �� ���� ���� : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                Sleep(200);
                system("cls");
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(200);
                system("cls");
            }
        }

        else if (InputValue == 3)
        {
            system("cls");
            printf("� �������� �Ǹ��Ͻðڽ��ϱ�?\n");
            printSaleorBuyItem();
            printBuyComplete("\n�޴��� �ǵ��ư��� �ʹٸ� 3���� �Է����ּ���!\n");
            printf("\n�Ǹ��� �����ۿ� �´� ������ �Է����ּ��� : ");
            scanf("%d", &InputValue);

            if (InputValue == 1)
            {
                village->StoreType = EWood;
                if (player->PInventory.wood >= 1)
                {
                    printf("�Ǹ� �� ��� : %d\n", player->PInventory.gold);
                    player->PInventory.gold += 30;
                    printf("�Ǹ� �� ��� : %d\n", player->PInventory.gold);
                    printf("\n\n");
                    printf("�Ǹ� �� �������� ���� : %d / %d\n", player->PInventory.wood, player->PInventory.MaxOwnItem);
                    player->PInventory.HPpotion++;
                    printf("���� �� �������� ���� : %d / %d\n", player->PInventory.wood, player->PInventory.MaxOwnItem);
                    Sleep(200);
                    system("cls");
                    printf("\n�޴��� ���ư��ϴ�!\n");
                    Sleep(200);
                    system("cls");
                }
            }
            else if (InputValue == 2)
            {
                village->StoreType = EEmerald;
                if (player->PInventory.emerald >= 1)
                {
                    printf("�Ǹ� �� ��� : %d\n", player->PInventory.gold);
                    player->PInventory.gold += 60;
                    printf("�Ǹ� �� ��� : %d\n", player->PInventory.gold);
                    printf("\n\n");
                    printf("�Ǹ� �� ���޶��� ���� : %d / %d\n", player->PInventory.emerald, player->PInventory.MaxOwnItem);
                    player->PInventory.HPpotion++;
                    printf("���� �� ���޶��� ���� : %d / %d\n", player->PInventory.emerald, player->PInventory.MaxOwnItem);
                    Sleep(200);
                    system("cls");
                    printf("\n�޴��� ���ư��ϴ�!\n");
                    Sleep(200);  
                    system("cls");
                }
            }

            system("cls");
            printf("\n�޴��� ���ư��ϴ�!\n");
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
    printf(" //     | �� |     \\\\\n");
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
    printf("|                    + ���ſ� �Ϸ��߽��ϴ� ! +                      |\n");
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
    printf("|                    1. ��������                                   |\n");
    printf("|                    2. ���޶���                                   |\n");
    printf("|                                                                 |\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("\n\n");
    Sleep(200);
    system("cls");
}