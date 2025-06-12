// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "CharacterTypes/CharacterStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"

class UCharacterGameplayAbility;

/**
 * 
 */
UCLASS()
class HACKNSLASH_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(class UCharacterAbilitySystemComponent* InCharacterASC, int32 ApplyLevel = 1) const override;


private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FHeroAbilitySet> HeroStartUpAbilitySets;
	
};
