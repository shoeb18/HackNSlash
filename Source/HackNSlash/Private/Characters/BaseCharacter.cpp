// CopyNinja All Rights Reserved


#include "Characters/BaseCharacter.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	// Initialize Ability System Component
	CharacterAbilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	CharacterAbilitySystemComponent->SetIsReplicated(true);

	// Initialize Attribute Set
	CharacterAttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("AttributeSet"));

}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return CharacterAbilitySystemComponent;
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CharacterAbilitySystemComponent)
	{
		CharacterAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s."), *GetName());
	}
}

