// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class ABaseWeapon;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon UMETA(DisplayName = "Current Equipped Weapon"),
	LeftHandWeapon UMETA(DisplayName = "Left Hand Weapon"),
	RightHandWeapon UMETA(DisplayName = "Right Hand Weapon"),
};
/**
 * 
 */
UCLASS()
class HACKNSLASH_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ABaseWeapon* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	ABaseWeapon* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	ABaseWeapon* GetCharacterCurrentEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	FGameplayTag CurrentEquippedWeaponTag;
		
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);


private:
	TMap<FGameplayTag, ABaseWeapon*> CharacterCarriedWeaponMap;
};
