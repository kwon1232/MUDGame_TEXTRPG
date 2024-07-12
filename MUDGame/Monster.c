#include "Framework.h"


void MonsterInitial(_Dungeon* dungeon, _Monster* monster, Player* player)
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
	if (dungeon->DungeonName == "���ֱ� ����")
	{
		int DungeonLevel = rand() % 1 + 1;
		dungeon->Dungeonlevel = DungeonLevel;

		monster->Level = DungeonLevel + rand() % 2;
		monster->Hp = DungeonLevel + rand() % 3;
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
	else if (dungeon->DungeonName == "�� �� ������ ����")
	{
		int DungeonLevel = rand() % 1 + 2;
		dungeon->Dungeonlevel = DungeonLevel;

		monster->Level = DungeonLevel + rand() % 2;
		monster->Hp = DungeonLevel + rand() % 3;
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
	else if (dungeon->DungeonName == "���� �غ��� ����")
	{
		int DungeonLevel = rand() % 1 + 3;
		dungeon->Dungeonlevel = DungeonLevel;

		monster->Level = DungeonLevel + rand() % 2;
		monster->Hp = DungeonLevel + rand() % 3;
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
}

void MonsterSetSkill(_Monster* monster)
{
	switch (monster->monsterType)
	{
	case EXStemp:
	{

	}
	break;
	case EStemp:
	{

	}
	break;
	case EDarkStemp:
	{

	}
	break;
	case EFallenTreeFairy:
	{

	}
	break;
	case EShadeFairy:
	{

	}
	break;
	case EDail:
	{

	}
	break;
	case EDino:
	{

	}
	break;
	}
}


void MonsterAtk(_Monster* monster, Player* player)
{

}



