#include "AbstractProp.h"

#include "DDGJ/DDGJProjectile.h"

AAbstractProp::AAbstractProp()
{
	PrimaryActorTick.bCanEverTick = true;
	this->Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	this->CapsuleComponent = this->CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	this->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AAbstractProp::OnBeginOverlap);
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

void AAbstractProp::GetDamage(const float PHealth)
{
	if (this->GetHealth() - PHealth > 0)
	{
		this->SetHealth(this->GetHealth() - PHealth);
		const FString Message = FString::Printf(TEXT("Damage: %.2f"), PHealth);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Message);
	}
	else
	{
		this->ResetHealth();
		this->OnDestroy.Broadcast(this);
	}
}

void AAbstractProp::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADDGJProjectile* Projectile = Cast<ADDGJProjectile>(OtherActor);

	if (IsValid(Projectile))
	{
		this->GetDamage(Projectile->GetDamage());
	}
}
