// CopyNinja All Rights Reserved


#include "Widgets/CharacterWidgetBase.h"
#include "Interfaces/PawnUIInterface.h"

void UCharacterWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent())
		{
			BP_OnOwningHeroUIComponentInitialized(HeroUIComponent);
		}
	}
}

void UCharacterWidgetBase::InitEnemyCreatedWidget(AActor* OwningEnemyActor)
{
	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwningEnemyActor))
	{
		if (UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent())
		{
			checkf(EnemyUIComponent, TEXT("Enemy UI Component is null for Enemy %s!"), *OwningEnemyActor->GetActorNameOrLabel());
			BP_OnOwningEnemyUIComponentInitialized(EnemyUIComponent);
		}
	}
}
