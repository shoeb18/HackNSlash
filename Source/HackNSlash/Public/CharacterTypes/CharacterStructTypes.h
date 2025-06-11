// CopyNinja All Rights Reserved

#pragma once

#include "CharacterStructTypes.generated.h"

class UHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};