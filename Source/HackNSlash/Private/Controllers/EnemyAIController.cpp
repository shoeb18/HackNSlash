// CopyNinja All Rights Reserved


#include "Controllers/EnemyAIController.h"
#include "Navigation/CrowdFollowingComponent.h"

#include "DebugHelper.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
	if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		Debug::Print("CrowdFollowingComponent initialized successfully.", FColor::Green);
	}
}