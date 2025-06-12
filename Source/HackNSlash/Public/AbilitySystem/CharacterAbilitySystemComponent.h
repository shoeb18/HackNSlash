// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CharacterTypes/CharacterStructTypes.h"
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

	UFUNCTION(BlueprintCallable, Category = "Character|Ability", meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Character|Ability")
	void RemovedGrantedHeroWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);

	
};
