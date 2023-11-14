#include "SpineCharacter.h"
#include "Components/CapsuleComponent.h"

ASpineCharacter::ASpineCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Spine Scene Component
	SpineSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SpineScnene"));
	SpineSceneComponent->SetupAttachment(RootComponent);
	SpineSceneComponent->SetRelativeRotation(FRotator(0, 90, 0));
	SpineSceneComponent->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	
	// Create Spine Animation Component
	SpineAnimation_F = CreateDefaultSubobject<USpineSkeletonAnimationComponent>(TEXT("SpineAnimation_F"));
	SpineAnimation_B = CreateDefaultSubobject<USpineSkeletonAnimationComponent>(TEXT("SpineAnimation_B"));
	
	// Create Spine Renderer Component
	SpineRenderer_F = CreateDefaultSubobject<USpineSkeletonRendererComponent>(TEXT("SpineRenderer_F"));
	SpineRenderer_F->SkeletonComponent = SpineAnimation_F;	// Set SkeletonComponent
	SpineRenderer_F->SetupAttachment(SpineSceneComponent);
	SpineRenderer_F->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpineRenderer_F->SetCollisionObjectType(ECC_Pawn);
	
	SpineRenderer_B = CreateDefaultSubobject<USpineSkeletonRendererComponent>(TEXT("SpineRenderer_B"));
	SpineRenderer_B->SkeletonComponent = SpineAnimation_B;	// Set SkeletonComponent
	SpineRenderer_B->SetupAttachment(SpineSceneComponent);
	SpineRenderer_B->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpineRenderer_B->SetCollisionObjectType(ECC_Pawn);
	SpineRenderer_B->SetVisibility(false);	// Hide back renderer at start
}

