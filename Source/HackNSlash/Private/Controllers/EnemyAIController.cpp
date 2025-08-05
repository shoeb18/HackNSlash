// CopyNinja All Rights Reserved


#include "Controllers/EnemyAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

#include "DebugHelper.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
	if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		Debug::Print("CrowdFollowingComponent initialized successfully.", FColor::Green);
	}

	// Initialize the Sight Sense Configuration
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AISenseConfig_Sight"));
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	AISenseConfig_Sight->SightRadius = 5000.0f; // Set the sight radius
	AISenseConfig_Sight->LoseSightRadius = 0.f; // Set the lose sight radius
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 360.0f; // Set the peripheral vision angle

	// Initialize the AI Perception Component
	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("EnemyPerceptionComponent"));
	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	EnemyPerceptionComponent->OnTargetPerceptionInfoUpdated.AddUniqueDynamic(this, &AEnemyAIController::OnTargetPerceptionUpdated);
	

}

void AEnemyAIController::OnTargetPerceptionUpdated(const FActorPerceptionUpdateInfo& UpdateInfo)
{
}
