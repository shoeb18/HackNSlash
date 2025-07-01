// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "EnemyGameplayAbility.generated.h"


class AEnemyCharacter;
class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class HACKNSLASH_API UEnemyGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	AEnemyCharacter* GetEnemyCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AEnemyCharacter> CachedEnemyCharacter;
	TWeakObjectPtr<UEnemyCombatComponent> CachedEnemyCombatComponent;

};
