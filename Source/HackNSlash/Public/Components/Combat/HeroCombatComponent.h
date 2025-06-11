// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AHeroWeapon;
/**
 * 
 */
UCLASS()
class HACKNSLASH_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
	
};
