#include "Framework.h"



int playerWizardSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;

	switch (player->JobStepType)
	{
	case Default:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardDefaultSkillInitial(player, SkillPoint);
	}
	break;
	case Beginner:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardBeginnerSkillInitial(player, SkillPoint);
	}
	break;
	case Intermediate:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardIntermediateSkillInitial(player, SkillPoint);
	}
		break;
	case All:
		tempSkillPoint = 0;
		tempSkillPoint += playerWizardDefaultSkillInitial(player, SkillPoint);
		tempSkillPoint += playerWizardBeginnerSkillInitial(player, SkillPoint);
		tempSkillPoint += playerWizardIntermediateSkillInitial(player, SkillPoint);
	}

	return SkillPoint += tempSkillPoint;
}

int playerWizardDefaultSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Default_WizardSkill.FireBall >= 5)
	{
		player->JobSkillList.Default_WizardSkill.FireBall -= 5;
		tempSkillPoint += player->JobSkillList.Default_WizardSkill.FireBall;
		player->JobSkillList.Default_WizardSkill.FireBall = 5;
	}

	if (player->JobSkillList.Default_WizardSkill.SnowBall >= 5)
	{
		player->JobSkillList.Default_WizardSkill.SnowBall -= 5;
		tempSkillPoint += player->JobSkillList.Default_WizardSkill.SnowBall;
		player->JobSkillList.Default_WizardSkill.SnowBall = 5;
	}

	if (player->JobSkillList.Default_WizardSkill.LightBall >= 5)
	{
		player->JobSkillList.Default_WizardSkill.LightBall -= 5;
		tempSkillPoint += player->JobSkillList.Default_WizardSkill.LightBall;
		player->JobSkillList.Default_WizardSkill.LightBall = 5;
	}
	return tempSkillPoint;
}

int playerWizardBeginnerSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Beginner_WizardSkill.AquaBeam >= 10)
	{
		player->JobSkillList.Beginner_WizardSkill.AquaBeam -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WizardSkill.AquaBeam;
		player->JobSkillList.Beginner_WizardSkill.AquaBeam = 10;
	}

	if (player->JobSkillList.Beginner_WizardSkill.FireBeam >= 10)
	{
		player->JobSkillList.Beginner_WizardSkill.FireBeam -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WizardSkill.FireBeam;
		player->JobSkillList.Beginner_WizardSkill.FireBeam = 10;
	}

	if (player->JobSkillList.Beginner_WizardSkill.LightingBeam >= 10)
	{
		player->JobSkillList.Beginner_WizardSkill.LightingBeam -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WizardSkill.LightingBeam;
		player->JobSkillList.Beginner_WizardSkill.LightingBeam = 10;
	}
	return tempSkillPoint;
}

int playerWizardIntermediateSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Intermediate_WizardSkill.ConOfIce >= 20)
	{
		player->JobSkillList.Intermediate_WizardSkill.ConOfIce -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WizardSkill.ConOfIce;
		player->JobSkillList.Intermediate_WizardSkill.ConOfIce = 20;
	}

	if (player->JobSkillList.Intermediate_WizardSkill.FireSpike >= 20)
	{
		player->JobSkillList.Intermediate_WizardSkill.FireSpike -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WizardSkill.FireSpike;
		player->JobSkillList.Intermediate_WizardSkill.FireSpike = 20;
	}

	return tempSkillPoint;
}

int playerWarriorSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	switch (player->JobStepType)
	{
	case Default:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorDefaultSkillInitial(player, SkillPoint);
	}
	break;
	case Beginner:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorBeginnerSkillInitial(player, SkillPoint);
	}
	break;
	case Intermediate:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorIntermediateSkillInitial(player, SkillPoint);
	}
	break;
	case All:
		tempSkillPoint = 0;
		tempSkillPoint += playerWarriorDefaultSkillInitial(player, SkillPoint);
		tempSkillPoint += playerWarriorBeginnerSkillInitial(player, SkillPoint);
		tempSkillPoint += playerWarriorIntermediateSkillInitial(player, SkillPoint);
	}

	return SkillPoint += tempSkillPoint;
}

int playerWarriorDefaultSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Default_WarriorSkill.Blade >= 5)
	{
		player->JobSkillList.Default_WarriorSkill.Blade -= 5;
		tempSkillPoint += player->JobSkillList.Default_WarriorSkill.Blade;
		player->JobSkillList.Default_WarriorSkill.Blade = 5;
	}

	if (player->JobSkillList.Default_WarriorSkill.Phantom >= 5)
	{
		player->JobSkillList.Default_WarriorSkill.Phantom -= 5;
		tempSkillPoint += player->JobSkillList.Default_WarriorSkill.Phantom;
		player->JobSkillList.Default_WarriorSkill.Phantom = 5;
	}

	if (player->JobSkillList.Default_WarriorSkill.Hellfire >= 5)
	{
		player->JobSkillList.Default_WarriorSkill.Hellfire -= 5;
		tempSkillPoint += player->JobSkillList.Default_WarriorSkill.Hellfire;
		player->JobSkillList.Default_WarriorSkill.Hellfire = 5;
	}
	return tempSkillPoint;
}

int playerWarriorBeginnerSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;

	if (player->JobSkillList.Beginner_WarriorSkill.BletInfinity >= 10)
	{
		player->JobSkillList.Beginner_WarriorSkill.BletInfinity -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WarriorSkill.BletInfinity;
		player->JobSkillList.Beginner_WarriorSkill.BletInfinity = 10;
	}

	if (player->JobSkillList.Beginner_WarriorSkill.Damascus >= 10)
	{
		player->JobSkillList.Beginner_WarriorSkill.Damascus -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WarriorSkill.Damascus;
		player->JobSkillList.Beginner_WarriorSkill.Damascus = 10;
	}

	if (player->JobSkillList.Beginner_WarriorSkill.Judgment >= 10)
	{
		player->JobSkillList.Beginner_WarriorSkill.Judgment -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_WarriorSkill.Judgment;
		player->JobSkillList.Beginner_WarriorSkill.Judgment = 10;
	}
	return tempSkillPoint;
}

int playerWarriorIntermediateSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;

	if (player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite >= 20)
	{
		player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite;
		player->JobSkillList.Intermediate_WarriorSkill.BloodInfinite = 20;
	}

	if (player->JobSkillList.Intermediate_WarriorSkill.Duellatorum >= 20)
	{
		player->JobSkillList.Intermediate_WarriorSkill.Duellatorum -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_WarriorSkill.Duellatorum;
		player->JobSkillList.Intermediate_WarriorSkill.Duellatorum = 20;
	}
	return tempSkillPoint;
}

int playerArcherSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	switch (player->JobStepType)
	{
	case Default:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherDefaultSkillInitial(player, SkillPoint);
	}
	break;
	case Beginner:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherBeginnerSkillInitial(player, SkillPoint);
	}
	break;
	case Intermediate:
	{
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherIntermediateSkillInitial(player, SkillPoint);
	}
	break;
	case All:
		tempSkillPoint = 0;
		tempSkillPoint += playerArcherDefaultSkillInitial(player, SkillPoint);
		tempSkillPoint += playerArcherBeginnerSkillInitial(player, SkillPoint);
		tempSkillPoint += playerArcherIntermediateSkillInitial(player, SkillPoint);
	}

	return SkillPoint += tempSkillPoint;
}

int playerArcherDefaultSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Default_ArcherSkill.IceArrow >= 5)
	{
		player->JobSkillList.Default_ArcherSkill.IceArrow -= 5;
		tempSkillPoint += player->JobSkillList.Default_ArcherSkill.IceArrow;
		player->JobSkillList.Default_ArcherSkill.IceArrow = 5;
	}

	if (player->JobSkillList.Default_ArcherSkill.FireArrow >= 5)
	{
		player->JobSkillList.Default_ArcherSkill.FireArrow -= 5;
		tempSkillPoint += player->JobSkillList.Default_ArcherSkill.FireArrow;
		player->JobSkillList.Default_ArcherSkill.FireArrow = 5;
	}

	if (player->JobSkillList.Default_ArcherSkill.BustArrow >= 5)
	{
		player->JobSkillList.Default_ArcherSkill.BustArrow -= 5;
		tempSkillPoint += player->JobSkillList.Default_ArcherSkill.BustArrow;
		player->JobSkillList.Default_ArcherSkill.BustArrow = 5;
	}
	return tempSkillPoint;
}

int playerArcherBeginnerSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Beginner_ArcherSkill.PosionArrow >= 10)
	{
		player->JobSkillList.Beginner_ArcherSkill.PosionArrow -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_ArcherSkill.PosionArrow;
		player->JobSkillList.Beginner_ArcherSkill.PosionArrow = 10;
	}

	if (player->JobSkillList.Beginner_ArcherSkill.LightningArrow >= 10)
	{
		player->JobSkillList.Beginner_ArcherSkill.LightningArrow -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_ArcherSkill.LightningArrow;
		player->JobSkillList.Beginner_ArcherSkill.LightningArrow = 10;
	}

	if (player->JobSkillList.Beginner_ArcherSkill.WindBoom >= 10)
	{
		player->JobSkillList.Beginner_ArcherSkill.WindBoom -= 10;
		tempSkillPoint += player->JobSkillList.Beginner_ArcherSkill.WindBoom;
		player->JobSkillList.Beginner_ArcherSkill.WindBoom = 10;
	}

	return tempSkillPoint;
}

int playerArcherIntermediateSkillInitial(Player* player, int SkillPoint)
{
	int tempSkillPoint = 0;
	if (player->JobSkillList.Intermediate_ArcherSkill.Evolve >= 20)
	{
		player->JobSkillList.Intermediate_ArcherSkill.Evolve -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_ArcherSkill.Evolve;
		player->JobSkillList.Intermediate_ArcherSkill.Evolve = 20;
	}

	if (player->JobSkillList.Intermediate_ArcherSkill.IllusionStep >= 20)
	{
		player->JobSkillList.Intermediate_ArcherSkill.IllusionStep -= 20;
		tempSkillPoint += player->JobSkillList.Intermediate_ArcherSkill.IllusionStep;
		player->JobSkillList.Intermediate_ArcherSkill.IllusionStep = 20;
	}
	return tempSkillPoint;
}

