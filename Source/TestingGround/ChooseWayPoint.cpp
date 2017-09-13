// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"
EBTNodeResult::Type UChooseWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{

	
	//Get blackboard component
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);
	// todo protect agiasnt empty cases.
	//UE_LOG(LogTemp, Warning, TEXT("WayPointIndex is : %i"),Index);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	return EBTNodeResult::Succeeded;

}

