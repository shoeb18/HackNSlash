// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UCharacterGameplayAbility;
class UCharacterAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class HACKNSLASH_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(class UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel = 1) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UCharacterGameplayAbility > > ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UCharacterGameplayAbility > > ReactiveAbilities;

	void GrantAbilities(const TArray< TSubclassOf < UCharacterGameplayAbility > >& AbilitiesToGrant, UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel) const;
	
};
