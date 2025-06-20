// CopyNinja All Rights Reserved


#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"


void UCharacterGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == ECharacterAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UCharacterGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == ECharacterAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* UCharacterGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return	GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UCharacterAbilitySystemComponent* UCharacterGameplayAbility::GetCharacterAbilitySystemComponentFromActorInfo() const
{
	return Cast<UCharacterAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
