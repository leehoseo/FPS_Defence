// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomComposite.h"
#include "Math/UnrealMathUtility.h"

UBTRandomComposite::UBTRandomComposite(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "RandomSelect";
}

int32 UBTRandomComposite::GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const
{
	// failure = quit
	int32 NextChildIdx = BTSpecialChild::ReturnToParent;

	if (PrevChild < 0)
	{
		NextChildIdx = FMath::RandRange(0, GetChildrenNum() - 1);
	}

	return NextChildIdx;
}

#if WITH_EDITOR

bool UBTRandomComposite::CanAbortLowerPriority() const
{
	// don't allow aborting lower priorities, as it breaks sequence order and doesn't makes sense
	return false;
}

FName UBTRandomComposite::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.Sequence.Icon");
}

#endif
