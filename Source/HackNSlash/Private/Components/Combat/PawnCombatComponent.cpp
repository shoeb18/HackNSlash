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

   InWeaponToRegister->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
   InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this, &ThisClass::OnHitPulledFromActor);

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
		}
		else 
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			OverlappedActors.Empty(); // Clear the list of actors that were hit by the weapon
		}
	}

	// TODO : Handle Body Collision Boxes 
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{
}

void UPawnCombatComponent::OnHitPulledFromActor(AActor* HitActor)
{
}
