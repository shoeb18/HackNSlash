// CopyNinja All Rights Reserved


#include "Characters/HeroCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "DebugHelper.h"



AHeroCharacter::AHeroCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Initialize Components
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 300.0f; // Set the length of the spring arm
	SpringArmComponent->SocketOffset = FVector(0.0f, 0.0f, 50.0f); // Offset the camera slightly above the character
	SpringArmComponent->bUsePawnControlRotation = true; // Rotate the arm based on the controller's rotation

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false; // Camera does not rotate with the controller, it follows the spring arm

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character will face the direction of movement
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.f, 0.0f); // Set rotation rate for character movement
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // Set braking deceleration for walking
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("HeroCharacter BeginPlay called"));
}
