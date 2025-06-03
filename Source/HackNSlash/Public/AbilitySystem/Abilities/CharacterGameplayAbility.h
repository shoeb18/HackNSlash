// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterGameplayAbility.generated.h"

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterAbility")
	ECharacterAbilityActivationPolicy AbilityActivationPolicy = ECharacterAbilityActivationPolicy::OnTriggered;
};
