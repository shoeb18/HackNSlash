// CopyNinja All Rights Reserved


#include "CharacterTypes/CharacterStructTypes.h"
#include "AbilitySystem/Abilities/HeroGameplayAbility.h"


bool FHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}
