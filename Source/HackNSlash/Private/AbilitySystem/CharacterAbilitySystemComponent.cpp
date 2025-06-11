// CopyNinja All Rights Reserved


#include "AbilitySystem/CharacterAbilitySystemComponent.h"

void UCharacterAbilitySystemComponent::OnAbilityInputPressed(FGameplayTag InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTag(InInputTag))
		{
			continue;
		}

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UCharacterAbilitySystemComponent::OnAbilityInputReleased(FGameplayTag InInputTag)
{
}
