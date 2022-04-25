// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "RandomComposite.generated.h"

/**
 * 
 */
UCLASS()
class FPS_SAMPLE_API UBTRandomComposite : public UBTCompositeNode
{
	GENERATED_UCLASS_BODY()
	
	virtual int32 GetNextChildHandler(struct FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const override;

#if WITH_EDITOR
	virtual bool CanAbortLowerPriority() const override;
	virtual FName GetNodeIconName() const override;
#endif
};
