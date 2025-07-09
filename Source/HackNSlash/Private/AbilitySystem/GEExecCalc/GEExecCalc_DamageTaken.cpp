// CopyNinja All Rights Reserved


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/CharacterAttributeSet.h"
#include "PlayerGameplayTags.h"

#include "DebugHelper.h"

struct FCharacterDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken);

	FCharacterDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, AttackPower, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, DefensePower, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, DamageTaken, Target, false);
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
	RelevantAttributesToCapture.Add(GetCharacterDamageCapture().DamageTakenDef);

}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvalParams.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();
	
	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetCharacterDamageCapture().AttackPowerDef, EvalParams, SourceAttackPower);
	// Debug::Print(TEXT("Source Attack Power"), SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;

	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(PlayerGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
			// Debug::Print(TEXT("Base Damage"), BaseDamage);
		}

		if (TagMagnitude.Key.MatchesTagExact(PlayerGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
			// Debug::Print(TEXT("Used Light Attack Combo Count"), UsedLightAttackComboCount);
		}

		if (TagMagnitude.Key.MatchesTagExact(PlayerGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
			// Debug::Print(TEXT("Used Heavy Attack Combo Count"), UsedHeavyAttackComboCount);
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetCharacterDamageCapture().DefensePowerDef, EvalParams, TargetDefensePower);
	// Debug::Print(TEXT("Target Defense Power"), TargetDefensePower);

	if (UsedLightAttackComboCount != 0)
	{
		const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1) * 0.05 + 1.0f; // 5% increase per light attack combo
		BaseDamage *= DamageIncreasePercentLight;
		// Debug::Print(TEXT("Scaled Base Damage Light"), BaseDamage);
	}

	if (UsedHeavyAttackComboCount != 0)
	{
		const float DamageIncreasePercentHeavy = (UsedHeavyAttackComboCount - 1) * 0.1 + 1.0f; // 10% increase per heavy attack combo
		BaseDamage *= DamageIncreasePercentHeavy;
		// Debug::Print(TEXT("Scaled Base Damage Heavy"), BaseDamage);
	}

	// Final Damage
	const float FinalDamage = BaseDamage * SourceAttackPower / TargetDefensePower;
	// Debug::Print(TEXT("Final Damage"), FinalDamage);

	if (FinalDamage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetCharacterDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamage
			)
		);
	}
}
