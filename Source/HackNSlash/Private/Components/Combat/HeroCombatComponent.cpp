// CopyNinja All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/HeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "PlayerGameplayTags.h"

#include "DebugHelper.h"

AHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<AHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->WeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);
	FGameplayEventData Data = FGameplayEventData();
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		PlayerGameplayTags::Shared_Event_MeleeHit,
		Data
	);
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		PlayerGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}

void UHeroCombatComponent::OnHitPulledFromActor(AActor* HitActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		PlayerGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}
