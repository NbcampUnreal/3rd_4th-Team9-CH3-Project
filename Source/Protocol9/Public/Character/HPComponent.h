#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HPComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOCOL9_API UHPComponent : public UActorComponent
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HP")
	float MaxHP;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HP")
	float CurrentHP;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HP")
	bool bIsDead;
	
public:	
	UHPComponent();

	UHPComponent* GetHPComponent();

	UFUNCTION(BlueprintPure, Category = "HP")
	float GetMaxHP() const {return MaxHP;};
	UFUNCTION(BlueprintPure, Category = "HP")
	float GetCurrentHP() const {return CurrentHP;};
	UFUNCTION(BlueprintPure, Category = "HP")
	bool GetIsDead() const {return bIsDead;}

	UFUNCTION(BlueprintCallable, Category = "HP")
	void SetMaxHP(float NewMaxHP);
	UFUNCTION(BlueprintCallable, Category = "HP")
	void SetCurrentHP(float NewCurrentHP);
	UFUNCTION(BlueprintCallable, Category = "HP")
	void TakeDamage(float Damage);
	UFUNCTION(BlueprintCallable, Category = "HP")
	void AddHealth(float HealAmount);

	UFUNCTION(BlueprintCallable, Category = "HP")
	bool IsDead();

protected:
	virtual void BeginPlay() override;


		
};
