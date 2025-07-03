// CopyNinja All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/HeroWeapon.h"

#include "DebugHelper.h"

AHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" hit ") + HitActor->GetActorNameOrLabel(), FColor::Green);
}

void UHeroCombatComponent::OnHitPulledFromActor(AActor* HitActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" pulled from ") + HitActor->GetActorNameOrLabel(), FColor::Red);
}
