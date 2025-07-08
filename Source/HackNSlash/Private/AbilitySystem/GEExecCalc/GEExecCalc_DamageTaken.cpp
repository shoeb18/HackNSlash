// CopyNinja All Rights Reserved


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/CharacterAttributeSet.h"
#include "PlayerGameplayTags.h"

struct FCharacterDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);

	FCharacterDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, AttackPower, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, DefensePower, Target, false);
	}
};

static const FCharacterDamageCapture GetCharacterDamageCapture()
{
	static FCharacterDamageCapture CharacterDamageCapture;
	return CharacterDamageCapture;
}


UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{

	/* Naive way of doing capture */
	//FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(
	//	UCharacterAttributeSet::StaticClass(),
	//	GET_MEMBER_NAME_CHECKED(UCharacterAttributeSet, AttackPower)
	//);

	//FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDef(
	//	AttackPowerProperty,
	//	EGameplayEffectAttributeCaptureSource::Source,
	//	false
	//);

	// RelevantAttributesToCapture.Add(AttackPowerCaptureDef);

	/* smart way of doing capture using struct */
	RelevantAttributesToCapture.Add(GetCharacterDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetCharacterDamageCapture().DefensePowerDef);

}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvalParams.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();
	
	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetCharacterDamageCapture().AttackPowerDef, EvalParams, SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;

	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(PlayerGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
		}

		if (TagMagnitude.Key.MatchesTagExact(PlayerGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
		}

		if (TagMagnitude.Key.MatchesTagExact(PlayerGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetCharacterDamageCapture().DefensePowerDef, EvalParams, TargetDefensePower);
}
