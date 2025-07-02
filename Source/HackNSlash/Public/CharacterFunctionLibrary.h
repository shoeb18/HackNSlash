// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CharacterTypes/CharacterEnumTypes.h"
#include "CharacterFunctionLibrary.generated.h"

class UCharacterAbilitySystemComponent;
class UPawnCombatComponent;


/**
 * 
 */
UCLASS()
class HACKNSLASH_API UCharacterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static UCharacterAbilitySystemComponent* NativeGetASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor,FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ECharacterConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);
	
	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, ECharacterValidType& OutValidType);
};
