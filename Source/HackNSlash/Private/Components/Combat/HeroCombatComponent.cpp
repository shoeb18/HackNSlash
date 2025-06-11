// CopyNinja All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/HeroWeapon.h"

AHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
