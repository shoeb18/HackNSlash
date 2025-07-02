// CopyNinja All Rights Reserved


#include "AbilitySystem/CharacterAttributeSet.h"

UCharacterAttributeSet::UCharacterAttributeSet()
{
	InitCurrentHealth(1.0f);
	InitMaxHealth(1.0f);
	InitCurrentRage(0.0f);
	InitMaxRage(0.0f);
	InitAttackPower(0.0f);
	InitDefensePower(0.0f);
}
