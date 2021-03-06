// This source code file is protected by the MIT License (MIT)

#pragma once

#include "GameFramework/MovementComponent.h"
#include "ObstacleMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class CUBEWARS_API UObstacleMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

public:
	UObstacleMovementComponent();
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	/** Multicast version of Setter whether the obstacle moves right or not */
	UFUNCTION(NetMulticast, reliable)
	void SetMovingRightMulticast(bool NewMovingRight);

	UPROPERTY(EditAnywhere, Category = Gameplay)
	float LeftMovementTarget;

	UPROPERTY(EditAnywhere, Category = Gameplay)
	float RightMovementTarget;

	/** The speed the obstacle is moving with  */
	UPROPERTY(EditAnywhere, Category = Gameplay)
	float MovementSpeed;

	/** true if the obstacle is moving right, false if moving left */
	UPROPERTY(EditAnywhere, Category = Gameplay)
	bool MovingRight;
};
