// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "HeroGameplayAbility.generated.h"

class AHeroCharacter;
class AHeroController;
class UHeroCombatComponent;
/**
 * 
 */
UCLASS()
class HACKNSLASH_API UHeroGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	AHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	AHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AHeroController> CachedHeroController;

};
