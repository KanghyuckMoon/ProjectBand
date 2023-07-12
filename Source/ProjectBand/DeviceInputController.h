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
	//virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		UAudioCapture* AudioCapture;
	UPROPERTY(VisibleAnywhere)
		UAudioCaptureComponent* AudioCaptureComponent;

public:
	UPROPERTY(EditAnywhere, Category = Mike)
		float mikeLimit = 0.2f;

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

	//Mike
	void UpdateMikeSoundSize(const TArray<uint8>& InAudioData, int32 NumChannels);
	UFUNCTION(BlueprintCallable, Category = Mike)
	void MikeUpdate(float value);
	void MikeClick();
	void MikeIng();
	void MikeUp();

};
