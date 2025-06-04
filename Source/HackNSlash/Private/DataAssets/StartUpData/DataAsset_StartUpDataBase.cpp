// CopyNinja All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"



void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel) const
{
	check(InCharacterASC);

	GrantAbilities(ActivateOnGivenAbilities, InCharacterASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InCharacterASC, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UCharacterGameplayAbility>>& AbilitiesToGrant, UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel) const
{
	if (AbilitiesToGrant.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UCharacterGameplayAbility>& Ability : AbilitiesToGrant)
	{
		if (!Ability)
			continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InCharacterASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InCharacterASC->GiveAbility(AbilitySpec);
	}

}
