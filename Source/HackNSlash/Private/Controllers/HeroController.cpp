// CopyNinja All Rights Reserved


#include "Controllers/HeroController.h"

AHeroController::AHeroController()
{
	HeroTeamID = FGenericTeamId(0); // Default team ID for the hero
}

FGenericTeamId AHeroController::GetGenericTeamId() const
{
	return HeroTeamID;
}
