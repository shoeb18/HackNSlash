// CopyNinja All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"
#include "GameplayTagContainer.h"
#include "Items/Weapons/BaseWeapon.h"

#include "DebugHelper.h"


void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ABaseWeapon* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
   checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
   check(InWeaponToRegister);

   CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

   if (bRegisterAsEquippedWeapon)
   {
       CurrentEquippedWeaponTag = InWeaponTagToRegister;
   }
}

ABaseWeapon* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTag))
	{
		if (ABaseWeapon* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTag))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

ABaseWeapon* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
