// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseWayPoint.h"


EBTNodeResult::Type UChooseWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{

	UE_LOG(LogTemp, Warning, TEXT("AI in c++ works"));
	return EBTNodeResult::Succeeded;

}

