#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpinePlugin/Public/SpineSkeletonAnimationComponent.h"
#include "SpinePlugin/Public/SpineSkeletonRendererComponent.h"
#include "SpineCharacter.generated.h"

UCLASS()
class MULTIPLESPINEEXAMPLE_API ASpineCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Spine Scene Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spine", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SpineSceneComponent;

	/** Spine Skeleton Animation Component (Front) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spine", meta=(AllowPrivateAccess = "true"))
	USpineSkeletonAnimationComponent* SpineAnimation_F;

	/** Spine Skeleton Animation Component (Back) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spine", meta=(AllowPrivateAccess = "true"))
	USpineSkeletonAnimationComponent* SpineAnimation_B;
	
	/** Spine Skeleton Renderer Component (Front) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spine", meta=(AllowPrivateAccess = "true"))
	USpineSkeletonRendererComponent* SpineRenderer_F;

	/** Spine Skeleton Renderer Component (Back) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spine", meta=(AllowPrivateAccess = "true"))
	USpineSkeletonRendererComponent* SpineRenderer_B;

public:
	ASpineCharacter();

};
