// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Testing.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class LIDARTESTING_UE5_API UTesting : public UObject
{
	GENERATED_BODY()

	virtual void PostInitProperties() override;

	virtual UWorld* GetWorld() const override;

public:
	UFUNCTION(BlueprintCallable)
	void Import();

	UFUNCTION(BlueprintImplementableEvent)
	void BeginPlay();
};
