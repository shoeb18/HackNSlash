// CopyNinja All Rights Reserved


#include "AbilitySystem/CharacterAttributeSet.h"

UCharacterAttributeSet::UCharacterAttributeSet()
{
	InitCurrentHealth(100.0f);
	InitMaxHealth(100.0f);
	InitCurrentRage(0.0f);
	InitMaxRage(100.0f);
	InitAttackPower(10.0f);
	InitDefensePower(5.0f);
}
