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
		PlayerGameplayTags::Shared_Event_Melee_Hit,
		Data
	);
}

void UHeroCombatComponent::OnHitPulledFromActor(AActor* HitActor)
{

}
