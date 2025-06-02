// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterAnimInstance.h"
#include "HeroAnimInstance.generated.h"


class AHeroCharacter;
/**
 * 
 */
UCLASS()
class HACKNSLASH_API UHeroAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()
	

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;


protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AHeroCharacter* OwningHeroCharacter;

};
