// CopyNinja All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"
#include "GameplayTagContainer.h"
#include "Items/Weapons/BaseWeapon.h"
#include "Components/BoxComponent.h"

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

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		ABaseWeapon* WeaponToToggle = GetCharacterCurrentEquippedWeapon();
		check(WeaponToToggle);

		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			Debug::Print(FString::Printf(TEXT("Enabled Collision for %s"), *WeaponToToggle->GetName()), FColor::Green);
		}
		else {
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			Debug::Print(FString::Printf(TEXT("Disabled Collision for %s"), *WeaponToToggle->GetName()), FColor::Red);
		}
	}

	// TODO : Handle Body Collision Boxes 
}
