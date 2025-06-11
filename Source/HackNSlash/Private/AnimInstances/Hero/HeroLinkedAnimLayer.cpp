// CopyNinja All Rights Reserved


#include "AnimInstances/Hero/HeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/HeroAnimInstance.h"

UHeroAnimInstance* UHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
    return Cast<UHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
