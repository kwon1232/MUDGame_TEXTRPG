#include "Framework.h"


void SellecVillage(_Village village[], Player* player, _Dungeon dungeon[])
{
    int POS = 4;	//0 - ���� �ϱ�, 1 - �̾� �ϱ�, 2 - ��ŷ ����, 3 - ���� ���� TEXT RPG
    CursorView(0);
    system("COLOR 5F");
    gotoxy(10, 4); printf("1. �� �� ����");
    gotoxy(35, 4); printf("2. �޸��� ����");
    gotoxy(10, 5); printf("3. �غ� ����");
    gotoxy(35, 5); printf("4. ���� ����");

    gotoxy(0, 8);
    printf("�̵��ϰ� ���� ������ ��ȣ�� �Է����ּ��� : ");
    scanf("%d", &POS);
    system("cls");
    
    if (POS == 1) {
        printf("�� �� ������ �̵��մϴ�.");
        VillageIntro(&village[0], player, dungeon);
        Sleep(800);
        system("cls");
    }
    else if (POS == 2) {
        printf("�޸��� ������ �̵��մϴ�.");
        VillageIntro(&village[1], player, dungeon);
        Sleep(800);
        system("cls");
    }
    else if (POS == 3) {
        printf("�غ� ������ �̵��մϴ�.");
        VillageIntro(&village[2], player, dungeon);
        Sleep(800);
        system("cls");
    }
    else{
        printf("���� ������ �̵��մϴ�.");
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
    printf("\n\n%s ������ ���� ���� ȯ���մϴ�!\n\n",village->VillageName);
    Sleep(1200);
    system("cls");
    VillageMainScene(village, player, dungeon);
}

void VillageMainScene(_Village* village, Player* player, _Dungeon dungeon[])
{
    int InputValue = 0;
    while (true)
    {
        printf("1. �Ʒ���\n2. ����\n3. ����Ʈ\n4. ��ųâ ����\n5. ���� �����ϱ�\n\n");
        printf("�Է� : ");
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
            // ��ų �÷��ִ� �Լ� ����
        }
        else if (InputValue == 5)
        {
            DungeonInitial(dungeon, player, dungeon);
        }
        printf("\n �ٽ� �Է����ּ���\n\n");
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
        printf("\n\n�Ʒüҿ� �����ϼ̽��ϴ�.\n\n");
        printf("\n1. ü���Ʒ���\n2. �����Ʒ���\n3. ��ų�Ʒ���\n4. ��ø�Ʒ��� \n5. �Ʒ��� ������");
        printf("\n\n�̵��� ���� �Է����ּ��� : ");
        scanf("%d", &InputValue);

        if (player->TrainingCenterCount <= 0)
        {
            system("cls");
            printf("\n\n�������� ����� �Ʒ��ϼ̽��ϴ�!\n");
            printf("\n���� �ۿ��� ������ ����ּ���!\n");
            VillageMainScene(village, player, dungeon);
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
        else if (InputValue == 3 && player->SkillPoint > 0)
        {
            village->TrainingCenterType = ESkillTrainingCenter;
            system("cls");
            printf("\n��ų�Ʒ��忡 �����ϼ̽��ϴ�.\n");
            Sleep(200);
            SkillTrainingCenter(player);
            player->SkillPoint--;
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
            VillageMainScene(village, player, dungeon);
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
        printf("�Ʒ���...!\n");
        Sleep(500);
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
        printf("�Ʒ���...!\n");
        Sleep(500);
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
        printf("�Ʒ���...!\n");
        Sleep(500);
        system("cls");
        if ((double)(start_time / 1) * 100 >= 100)
            break;
    }

    printf("\n%s�� ��ų ����Ʈ�� �����Ͽ����ϴ�!\n", player->PlayerName);
    printf("\n�Ʒ� �� ��ų ����Ʈ : %d", player->SkillPoint);
    player->SkillPoint++;
    printf("\n�Ʒ� �� ��ų ����Ʈ : %d", player->SkillPoint);
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
        printf("�Ʒ���...!\n");
        Sleep(500);
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


void QuestIntro(_Village* village, Player* player, _Dungeon dungeon[])
{
    int InputValue = 0;
    char QuestNum[40];

    while (true)
    {
        system("cls");
        int NumOfQuestList = rand() % 1 + 1;
        printf("\n\n���� �غ�� ����Ʈ�� %d�� �ֽ��ϴ�.\n", NumOfQuestList);
        Sleep(1000);
        switch (player->JobStepType)
        {
        case ENone_JobStepType:
        {
            switch (NumOfQuestList)
            {
            case 2:
                printf("����Ʈ �ѹ� : Q.N-2\n\n");
                printf("���ֱ� ������ ���Ͱ� ����Ʈ���� �������� 3���� �������ּ���.\n");
                printf("���Ϳ��Լ� ������ ���������� ���� �����ϱ� ���ƿ�.\n\n");
                printf("��ǥ : ���ֱ� ������ �������� ó���Ͽ� �������� 3�� ���ϱ�\n");
                printf("���� : 50���, ü�� ���� 5��\n");

            case 1:
                printf("����Ʈ �ѹ� : Q.N-1\n\n");
                printf("���� �������� ��ƿ��ּ���.\n");
                printf("���� �������� ���ƴٴϴ� �뿡 �ֱٿ� ���� ������ ���� ���� �����.\n\n");
                printf("��ǥ : ���ֱ� ������ �������� 3���� ���\n");
                printf("���� : 50���, ü�� ���� 5��\n");
                break;
            }
        }
            break;
        case EDefault:
        {
            switch (NumOfQuestList)
            {
            case 2:
                printf("����Ʈ �ѹ� : Q.D - 2\n\n");
                printf("Ÿ���� ���� ������ �����ּ���!\n");
                printf("Ÿ���� ���� ���ɵ� ������ ���ֱ� ������ ���� �� �����.\n\n");
                printf("��ǥ : ���� �� ���� Ÿ���� ���� ���� 3���� ó���ϱ�\n");
                printf("���� : 80���, ���� ���� 3��, ü�� ���� 3��\n");
                
            case 1:
                printf("����Ʈ �ѹ� : Q.D - 1\n\n");
                printf("��ũ �������� ����ּ���.\n");
                printf("��ũ �������� ���ֱ��� ����ϴ� �����Դϴ�.\n");
                printf("��ũ ������ ������ �������� �Ѿ �� �����!\n\n");
                printf("��ǥ : ���ֱ� ������ ��ũ ������ �����\n");
                printf("���� : 80���, ���� ���� 3��, ü�� ���� 3��\n");

                break;
            }
        }
            break;
        case EBeginner:
        {
            switch (NumOfQuestList)
            {
            case 2:

                printf("����Ʈ �ѹ� : Q.B - 2\n\n");
                printf("���� �˿��� ��Ȥ�� �Ǿ� ������ ����־�\n");
                printf("������ �� �ӿ��� ��� ������ ���� ���� ��⿣ �ʹ� �����\n");
                printf("Ȥ�� �ʰ� �����ְڴ� ?\n\n");
                printf("    ��ǥ : ���� 3���� ó���ϱ�\n");
                printf("���� : 110��帶�� ���� 4��, ü�� ���� 4��\n");


            case 1:
                printf("����Ʈ �ѹ� : Q.B - 1\n\n");
                printf("���� �� �ӿ� ���� ���ɵ��� Ÿ����Ų��\n");
                printf("���̵��� �Ƿ� �����̶����,\n");
                printf("���̵带 óġ���� �� �ֳ��� ?\n\n");
                printf("��ǥ : ���̵� 3���� ó���ϱ�\n");
                printf("���� : 110���, ���� ���� 4��, ü�� ���� 4��\n");
                break;
            }
        }
            break;
        case EIntermediate:
        {
            switch (NumOfQuestList)
            {
            case 2:
                printf("����Ʈ �ѹ� : Q.I - 2\n\n");
                printf("���� �˿��� ��밡 �������,\n");
                printf("�ٵ� �װ� �˾� ?\n");
                printf("��븦 ó�����ָ� ���� ��ȭ���� ������ ?\n\n");

                printf("��ǥ : ���� ���� ��� ó���ϱ�\n");
                printf("���� : 280���, ���� ���� 4��, ü�� ���� 4��\n");

            case 1:
                printf("����Ʈ �ѹ� : Q.I - 1\n\n");
                printf("���� �˿��� ������ ����ִٴ� �� �ʵ� �˰����� ?\n");
                printf("���� �Ǵ� ��븦 óġ�ϸ� ���޶��带 ���� �� �ִٴ� �ҹ��� ����...\n");
                printf("�����󿡼� ��븦 óġ�� ���޶��带 �������� ���� 100��峪 �شٳ�!\n\n");

                printf("��ǥ : ��� �Ǵ� ������ óġ�ؼ� ���޶��� 2�� ���ؿ���\n");
                printf("���� : 200���, ���� ���� 4��, ü�� ���� 4��\n");

                break;
            }
        }
            break;
        }
        printf("\n\n����Ʈ�� �����Ͻðڽ��ϱ�?\n");
        printf("1. ����\n2. ����\n");
        scanf("%d", &InputValue);
        if (InputValue == 2) 
        { 
            system("cls");
            VillageMainScene(village, player, dungeon);
            break;
        }
        printf("\n\n�޾ƿ� ����Ʈ �ѹ��� �Է����ּ��� : ");
        scanf("%s", &QuestNum);
        if (QuestAccept(player,QuestNum))
        {
            printf("\n\n����Ʈ�� �����߽��ϴ�!");
            Sleep(1000);
            system("cls");
            VillageMainScene(village, player, dungeon);
            break;
        }
        else
        {
            printf("\n\n�̹� ������ ����Ʈ�Դϴ�!");
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
        printf("\n������ ���� ���� ȯ���մϴ�!\n\n");

        printf("===================================================================\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("|                  1. ü�� ���� ����                              |\n");
        printf("|                  2. ���� ���� ����                              |\n");
        printf("|                  3. ������ �Ǹ�                                 |\n");
        printf("|                  4. ������                                      |\n");
        printf("|                                                                 |\n");
        printf("|                                                                 |\n");
        printf("===================================================================\n");

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
                Sleep(1200);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(1200);
                system("cls");
            }

            else if (player->PInventory.HPpotion >= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n������ �� �ִ� ü�� ���� ���� �� á���ϴ�!\n������ �� �����ϴ�!\n");
                printf("���� ���� ���� : %d / %d\n", player->PInventory.HPpotion, player->PInventory.MaxOwnPotion);
                Sleep(1200);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(1200);
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
                Sleep(1200);
                printf("\n�޴��� ���ư��ϴ�!\n");
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
                printf("\n\n��尡 �����ؼ� ������ �� �����ϴ�!\n");
                printf("���� ������ ������ 50����Դϴ�!\n\n");
                printf("���� %s�� �� ��� : %d", player->PlayerName, player->PInventory.gold);
                Sleep(1200);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(1200);
                system("cls");
            }

            if (player->PInventory.MPpotion >= player->PInventory.MaxOwnPotion)
            {
                system("cls");
                printf("\n\n������ �� �ִ� ���� ���� ���� �� á���ϴ�!\n������ �� �����ϴ�!\n");
                printf("���� ���� ���� : %d / %d\n", player->PInventory.MPpotion, player->PInventory.MaxOwnPotion);
                Sleep(1200);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(1200);
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
                Sleep(1200);
                printf("\n�޴��� ���ư��ϴ�!\n");
                Sleep(1200);
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
                    Sleep(1200);
                    printf("\n�޴��� ���ư��ϴ�!\n");
                    Sleep(1200);
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
                    Sleep(1200);
                    printf("\n�޴��� ���ư��ϴ�!\n");
                    Sleep(1200);
                    system("cls");
                }
            }


            printf("\n�޴��� ���ư��ϴ�!\n");
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