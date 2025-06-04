// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

class UCharacterAbilitySystemComponent;
class UCharacterAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class HACKNSLASH_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySytem")
	UCharacterAbilitySystemComponent* CharacterAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySytem")
	UCharacterAttributeSet* CharacterAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;


public:
	FORCEINLINE UCharacterAbilitySystemComponent* GetCharacterAbilitySystemComponent() const
	{
		return CharacterAbilitySystemComponent;
	}

	FORCEINLINE UCharacterAttributeSet* GetCharacterAttributeSet() const
	{
		return CharacterAttributeSet;
	}
};
