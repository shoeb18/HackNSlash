// CopyNinja All Rights Reserved


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FPlayerInputConfig& Config : NativeInputActions)
	{
		if (Config.InputTag == InputTag && Config.InputAction)
		{
			return Config.InputAction;
		}
	}

	return nullptr;
}
