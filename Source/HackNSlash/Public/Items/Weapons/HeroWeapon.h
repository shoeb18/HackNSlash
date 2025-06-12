// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/BaseWeapon.h"
#include "CharacterTypes/CharacterStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "HeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class HACKNSLASH_API AHeroWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FHeroWeaponData WeaponData;

	UFUNCTION(BlueprintCallable, Category = "Weapon|Ability")
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure, Category = "Weapon|Ability")
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:

	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
