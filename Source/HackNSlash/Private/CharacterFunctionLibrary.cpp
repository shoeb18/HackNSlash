// CopyNinja All Rights Reserved


#include "CharacterFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"


UCharacterAbilitySystemComponent* UCharacterFunctionLibrary::NativeGetASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UCharacterAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UCharacterFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UCharacterAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UCharacterFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UCharacterAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UCharacterFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UCharacterAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UCharacterFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ECharacterConfirmType& OutConfirmType)
{
	NativeDoesActorHaveTag(InActor, TagToCheck) ? OutConfirmType = ECharacterConfirmType::Yes : OutConfirmType = ECharacterConfirmType::No;
}

UPawnCombatComponent* UCharacterFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UCharacterFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, ECharacterValidType& OutValidType)
{
	UPawnCombatComponent* PawnCombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	OutValidType = PawnCombatComponent ? ECharacterValidType::Valid : ECharacterValidType::Invalid;
	return PawnCombatComponent;
}
