// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/BaseWeapon.h"
#include "CharacterTypes/CharacterStructTypes.h"
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
};
