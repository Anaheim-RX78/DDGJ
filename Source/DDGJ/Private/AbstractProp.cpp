#include "AbstractProp.h"

AAbstractProp::AAbstractProp()
{
	PrimaryActorTick.bCanEverTick = true;
	this->Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	this->CapsuleComponent = this->CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	this->Mesh->SetupAttachment(this->CapsuleComponent);

	this->SetRootComponent(this->CapsuleComponent);
}

void AAbstractProp::BeginPlay()
{
	Super::BeginPlay();
}

void AAbstractProp::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}
