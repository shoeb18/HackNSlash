// CopyNinja All Rights Reserved


#include "AbilitySystem/Abilities/EnemyGameplayAbility.h"
#include "Characters/EnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"

AEnemyCharacter* UEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedEnemyCharacter.IsValid())
	{
		CachedEnemyCharacter = Cast<AEnemyCharacter>(GetAvatarActorFromActorInfo());
	}

	return CachedEnemyCharacter.IsValid() ? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
