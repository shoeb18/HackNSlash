// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "DataAsset_EnemyStartUpData.generated.h"

class UEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class HACKNSLASH_API UDataAsset_EnemyStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(class UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel = 1) const override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf <UEnemyGameplayAbility> > EnemyStartUpAbilitySets;
};
