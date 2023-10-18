// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AudioCapture.h"
#include "AudioCaptureComponent.h"
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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = Mike)
		float mikeLimit = 0.2f;

	UPROPERTY(EditAnywhere, Category = Mike)
		float keyboardInputTime = 0.1f;

	UPROPERTY(EditAnywhere, Category = Mike)
		float mouseInputTime = 0.1f;

		float curKeyboardInputTime = 0.0f;
		float curMouseInputTime = 0.0f;

public:
	//Keyboard
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
	bool isClickKeyboard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
		bool isIngKeyboard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
		bool isUpKeyboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
	bool isClickMouse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
	bool isIngMouse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
	bool isUpMouse;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
		bool isClickMike;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
		bool isIngMike;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mike)
	bool isUpMike;

protected:
	void KeyboardClick();
	void KeyboardIng();
	void KeyboardUp();
	void MouseClick();
	void MouseIng();
	void MouseUp();

	//Mike
	UFUNCTION(BlueprintCallable, Category = Mike)
	void MikeUpdate(float value);
	void MikeClick();
	void MikeIng();
	void MikeUp();

};
