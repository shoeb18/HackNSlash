// CopyNinja All Rights Reserved


#include "Controllers/EnemyAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "DebugHelper.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{

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
	EnemyPerceptionComponent->OnTargetPerceptionInfoUpdated.AddUniqueDynamic(this, &AEnemyAIController::OnEnemyPerceptionUpdated);
	
	SetGenericTeamId(FGenericTeamId(1)); // Set a default team ID for the enemy AI controller
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnToCheck = Cast<APawn>(&Other);

	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

	if (OtherTeamAgent && OtherTeamAgent->GetGenericTeamId() != GetGenericTeamId())
	{
		return ETeamAttitude::Hostile;
	}
	else
	{
		return ETeamAttitude::Friendly;
	}
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		CrowdComp->SetCrowdSimulationState(bEnableDetourCrowdAvoidance? ECrowdSimulationState::Enabled : ECrowdSimulationState::Disabled);

		switch (DetourCrowdAvoidanceQuality)
		{
			case 1:
				CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Low);
				break;
			case 2:
				CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Medium);
				break;
			case 3:
				CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good);
				break;
			case 4:
				CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);
				break;
		}

		CrowdComp->SetAvoidanceGroup(1); // Set a default avoidance group
		CrowdComp->SetGroupsToAvoid(1); // Avoid the same group
		CrowdComp->SetCrowdCollisionQueryRange(CollisionQueryRange);
	}
}

void AEnemyAIController::OnEnemyPerceptionUpdated(const FActorPerceptionUpdateInfo& UpdateInfo)
{
	if (UpdateInfo.Stimulus.WasSuccessfullySensed() && UpdateInfo.Target.IsValid())
	{
		if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
		{
			BlackboardComponent->SetValueAsObject("TargetActor", UpdateInfo.Target.Get());
		}
	}
}
