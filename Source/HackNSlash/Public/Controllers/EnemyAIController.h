// CopyNinja All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
struct FActorPerceptionUpdateInfo;
/**
 * 
 */
UCLASS()
class HACKNSLASH_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:

	AEnemyAIController(const FObjectInitializer& ObjectInitializer);

	//~ Begin IGenericTeamAgentInterface Interface
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	//~ End IGenericTeamAgentInterface Interface

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* EnemyPerceptionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAISenseConfig_Sight* AISenseConfig_Sight;
	
	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(const FActorPerceptionUpdateInfo& UpdateInfo);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance")
	bool bEnableDetourCrowdAvoidance = true;

	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance", meta = (EditCondition = "bEnableDetourCrowdAvoidance", UIMin = "1", UIMax = "4"))
	int32 DetourCrowdAvoidanceQuality = 4; // 1 = Low, 2 = Medium, 3 = Good, 4 = High

	UPROPERTY(EditDefaultsOnly, Category = "Detour Crowd Avoidance", meta = (EditCondition = "bEnableDetourCrowdAvoidance"))
	float CollisionQueryRange = 600.0f; // Range for collision queries during pathfinding


};
