// CopyNinja All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/Abilities/EnemyGameplayAbility.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel) const
{
	Super::GiveToAbilitySystemComponent(InCharacterASC, ApplyLevel);

	for (const TSubclassOf<UEnemyGameplayAbility>& AbilityClass : EnemyStartUpAbilitySets)
	{
		if (!AbilityClass)
		{
			continue;
		}

		FGameplayAbilitySpec AbilitySpec(AbilityClass);
		AbilitySpec.SourceObject = InCharacterASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InCharacterASC->GiveAbility(AbilitySpec);
	}
}
