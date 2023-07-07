// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DeviceInputController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBAND_API ADeviceInputController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ADeviceInputController();

public:
	virtual void SetupInputComponent() override;

public:
	//Keyboard
	bool isClickKeyboard;
	bool isIngKeyboard;
	bool isUpKeyboard;
	//Mouse
	bool isClickMouse;
	bool isIngMouse;
	bool isUpMouse;
	//Mike
	bool isClickMike;
	bool isIngMike;
	bool isUpMike;

protected:
	void KeyboardClick();
	void KeyboardIng();
	void KeyboardUp();
	void MouseClick();
	void MouseIng();
	void MouseUp();
	void MikeClick();
	void MikeIng();
	void MikeUp();

};
