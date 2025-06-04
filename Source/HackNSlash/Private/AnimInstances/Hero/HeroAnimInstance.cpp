// CopyNinja All Rights Reserved


#include "AnimInstances/Hero/HeroAnimInstance.h"
#include "Characters/HeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// Cast the owning pawn to AHeroCharacter
	OwningHeroCharacter = Cast<AHeroCharacter>(TryGetPawnOwner());
}

void UHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (OwningHeroCharacter)
	{
		// Update the in-air state based on the character's movement
		bIsInAir = OwningHeroCharacter->GetCharacterMovement()->IsFalling();

		bShouldMove = OwningMovementComponent->GetCurrentAcceleration() != FVector(0,0,0) && (GroundSpeed > 3.0f);
	}
}
