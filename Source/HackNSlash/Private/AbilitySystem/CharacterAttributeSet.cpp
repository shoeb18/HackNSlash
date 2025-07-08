// CopyNinja All Rights Reserved


#include "AbilitySystem/CharacterAttributeSet.h"
#include "GameplayEffectExtension.h"

#include "DebugHelper.h"

UCharacterAttributeSet::UCharacterAttributeSet()
{
	InitCurrentHealth(1.0f);
	InitMaxHealth(1.0f);
	InitCurrentRage(0.0f);
	InitMaxRage(0.0f);
	InitAttackPower(0.0f);
	InitDefensePower(0.0f);
}

void UCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.0f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.0f, GetMaxRage());
		SetCurrentRage(NewCurrentRage);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float oldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(oldHealth - DamageDone, 0.0f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		const FString DebugString = FString::Printf(
			TEXT("Old Health: %f, Damage Done: %f, NewCurrentHealth: %f"),
			oldHealth,
			DamageDone,
			NewCurrentHealth
		);

		Debug::Print(DebugString, FColor::Red, -1);

		// TODO: Notify the UI

		// TODO: Character death logic
		if (NewCurrentHealth == 0.f)
		{

		}
	}
}
