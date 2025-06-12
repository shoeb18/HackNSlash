// CopyNinja All Rights Reserved


#include "CharacterTypes/CharacterStructTypes.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"


bool FHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}
