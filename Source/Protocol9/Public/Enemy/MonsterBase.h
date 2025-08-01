#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterBase.generated.h"

UENUM(BlueprintType)
enum class EMonsterState : uint8
{
    Idle        UMETA(DisplayName = "Idle"),
    Patrolling  UMETA(DisplayName = "Patrolling"),
    Chasing     UMETA(DisplayName = "Chasing"),
    Attacking   UMETA(DisplayName = "Attacking"),
    Returning   UMETA(DisplayName = "Returning")
};

UCLASS()
class PROTOCOL9_API AMonsterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AMonsterBase();

protected:
    virtual void BeginPlay() override;

public:
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    EMonsterState CurrentState;

    
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Patrol")
    float PatrolRadius = 1200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Patrol")
    float WaitTimeAtPatrolPoint = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Chase")
    float ChaseRadius = 2000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Chase")
    float LosePlayerTime = 3.0f;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Attack")
    float AttackRange = 150.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Attack")
    float AttackCooldown = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Attack")
    class UAnimMontage* AttackMontage;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement")
    float WalkSpeed = 300.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Movement")
    float RunSpeed = 600.0f;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape")
    float MonsterHalfHeight = 88.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shape")
    float MonsterRadius = 34.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HP")
    int32 MaxHP = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXP")
    int32 Exp = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float AIUpdateInterval = 0.1f;
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropItems") //아이템 베이스 클래스 만들어지면 주석 해제
    //TArray<TSubclassOf<class AItemBase>> DropItems;
    
    void SetState(EMonsterState NewState);
    bool SetTargetPlayer(APawn* NewTarget);
protected:
    
    void StartPatrol();
    void Patrol();
    FVector GetRandomPatrolPoint() const;
    

    void ChasePlayer();
    bool CanSeePlayer() const;
    

    void AttackPlayer();
    bool IsInAttackRange() const;
    

    void ReturnToStart();


    

    UFUNCTION()
    void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    UFUNCTION()
    void AttackingBehavior();
    
    UFUNCTION()
    virtual void OnDeath();
    UFUNCTION()
    void DropItems() const;
    UFUNCTION()
    void GiveExp() const;
    UFUNCTION()
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
    UPROPERTY()
    APawn* TargetPlayer;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Combat", meta = (AllowPrivateAccess = "true"))
    bool bShouldContinueAttacking = false;
    UFUNCTION()
    void StopContinuousAttack();
private:
    void UpdateAI();
    
    FVector StartLocation;
    FVector CurrentPatrolTarget;
    
    float LastAttackTime;
    float PlayerLostTime;
    float PatrolWaitTimer;
    
    UPROPERTY()
    class AAIController* AIController;
    
    bool bIsMovingToPatrolPoint;
    bool bIsWaitingAtPatrolPoint;
    bool bHasReachedPatrolPoint;

    INT32 CurrentHP;

private:
    FTimerHandle AttackTimerHandle;
   
    UFUNCTION()
    virtual void PerformAttack();
    
    UFUNCTION()
    void StartContinuousAttack();
    


    UFUNCTION()
    void StartAIUpdateTimer();

    UFUNCTION()
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    FTimerHandle AIUpdateTimerHandle;
    
};