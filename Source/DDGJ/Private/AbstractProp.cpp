#include "AbstractProp.h"

#include "KismetTraceUtils.h"
#include "DDGJ/DDGJGameMode.h"
#include "DDGJ/DDGJProjectile.h"
#include "GameFramework/GameMode.h"

AAbstractProp::AAbstractProp()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

void AAbstractProp::BeginPlay()
{
	Super::BeginPlay();
}

void AAbstractProp::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbstractProp::DoDamage(float Amount, bool ExplosiveDamage)
{
	Health = Health - Amount;
	
	if (Health < 0 || (ExplosiveDamage && Explosive))
	{
		Health = 0;
		OnDeath();
		Destroy();
		ADDGJGameMode* MyGameMode = Cast<ADDGJGameMode>(GetWorld()->GetAuthGameMode());
		MyGameMode->AddScore(KillPoints);
	}
	
}
