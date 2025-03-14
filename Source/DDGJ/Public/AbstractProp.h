// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageInterface.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "AbstractProp.generated.h"

UCLASS()
class DDGJ_API AAbstractProp : public AActor, public IDamageInterface
{
	GENERATED_BODY()

public:
	/**
	* Default constructor for AAbstractProp.
	*/
	AAbstractProp();

	/**
	* Called every frame.
	* @param DeltaTime - The time elapsed since the last frame.
	*/
	virtual void Tick(float DeltaTime) override;

	/**
	 * Gets the kill points awarded for destroying the prop.
	 * @return The current kill points value.
	 */
	UFUNCTION()
	int GetKillPoints() const { return this->KillPoints; }

	/**
	 * Sets the kill points awarded for destroying the prop.
	 * @param PKillPoints - The new kill points value to set.
	 */
	UFUNCTION()
	void SetKillPoints(const int PKillPoints) { this->KillPoints = PKillPoints; }

	/**
	 * Checks if the prop is explosive.
	 * @return True if the prop is explosive, false otherwise.
	 */
	UFUNCTION()
	bool IsExplosive() const { return this->Explosive; }

	/**
	 * Sets whether the prop is explosive.
	 * @param PExplosive - True to make the prop explosive, false otherwise.
	 */
	UFUNCTION()
	void SetExplosive(const bool PExplosive) { this->Explosive = PExplosive; }

protected:
	/**
	 * Called when the game starts or when spawned.
    */
	virtual void BeginPlay() override;

	/**
	 * Static mesh component for the prop.
	 */
	UPROPERTY(EditAnywhere, Category="Model")
	UStaticMeshComponent* Mesh;

	/**
	 * Health property for the prop.
	 * Determines the amount of health the prop has.
	 */
	UPROPERTY(EditAnywhere, Category="Health")
	float Health = 100.0f;

	/**
	 * Points awarded for destroying the prop.
	 * Determines the score value when the prop is destroyed.
	 */
	UPROPERTY(EditAnywhere, Category="Score")
	int KillPoints = 25;

	/**
	 * Determines if the prop is explosive.
	 * If true, the prop will explode upon destruction.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Behavior")
	bool Explosive = false;

	virtual void DoDamage(float Amount, bool Explosive) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();
};
