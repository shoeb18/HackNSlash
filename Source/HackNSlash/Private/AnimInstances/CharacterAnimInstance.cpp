// CopyNinja All Rights Reserved


#include "AnimInstances/CharacterAnimInstance.h"
#include "Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	Direction = CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
	OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0 ? bHasAcceleration = true : bHasAcceleration = false;
}
