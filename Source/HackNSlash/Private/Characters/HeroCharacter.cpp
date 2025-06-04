// CopyNinja All Rights Reserved


#include "Characters/HeroCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/HeroInputComponent.h"
#include "PlayerGameplayTags.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"


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

void AHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(GetCharacterAbilitySystemComponent());
		}
	}
}

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("InputConfigDataAsset is null, can't proceed with input setup."));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UHeroInputComponent* HeroInputComponent = CastChecked<UHeroInputComponent>(PlayerInputComponent);

	HeroInputComponent->BindNativeInputAction(InputConfigDataAsset, PlayerGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	HeroInputComponent->BindNativeInputAction(InputConfigDataAsset, PlayerGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AHeroCharacter::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator MovementRotation(0.0f, GetControlRotation().Yaw, 0.0f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHeroCharacter::Input_Look(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();

	if (LookAxis.X != 0.f || LookAxis.Y != 0.f)
	{
		AddControllerYawInput(LookAxis.X);
		AddControllerPitchInput(LookAxis.Y);
	}
}
