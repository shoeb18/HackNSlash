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

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* EnemyPerceptionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAISenseConfig_Sight* AISenseConfig_Sight;

	UFUNCTION()
	virtual void OnTargetPerceptionUpdated(const FActorPerceptionUpdateInfo& UpdateInfo);

};
