// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "HeroInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class HACKNSLASH_API UHeroInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:

	template <class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template <class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc);
};

template<class UserObject, typename CallbackFunc>
inline void UHeroInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data asset is null, can't proceed with binding."));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}

template<class UserObject, typename CallbackFunc>
inline void UHeroInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc)
{
	checkf(InInputConfig, TEXT("Input config data asset is null, can't proceed with binding."));

	for (const FPlayerInputConfig& AbilityInputConfig : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInputConfig.IsValid())
		{
			continue;
		}
		BindAction(AbilityInputConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, AbilityInputConfig.InputTag);
		BindAction(AbilityInputConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, AbilityInputConfig.InputTag);
	}
}
