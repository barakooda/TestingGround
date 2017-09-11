// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{

	
	//Get blackboard component

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("WayPointIndex is : %i"),Index);

	return EBTNodeResult::Succeeded;

}

