// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CharacterAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class HACKNSLASH_API UCharacterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(FGameplayTag InInputTag);
	void OnAbilityInputReleased(FGameplayTag InInputTag);
	
};
