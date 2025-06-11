// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterGameplayAbility.generated.h"

class UPawnCombatComponent;
class UCharacterAbilitySystemComponent;

UENUM(BlueprintType)
enum class ECharacterAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class HACKNSLASH_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	

protected:

	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface.



	/** The activation policy for this ability */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character|Ability")
	ECharacterAbilityActivationPolicy AbilityActivationPolicy = ECharacterAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	UCharacterAbilitySystemComponent* GetCharacterAbilitySystemComponentFromActorInfo() const;

};
