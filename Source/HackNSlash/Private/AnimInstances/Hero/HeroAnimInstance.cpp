// CopyNinja All Rights Reserved


#include "AnimInstances/Hero/HeroAnimInstance.h"
#include "Characters/HeroCharacter.h"

void UHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// Cast the owning pawn to AHeroCharacter
	OwningHeroCharacter = Cast<AHeroCharacter>(TryGetPawnOwner());
}

void UHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
