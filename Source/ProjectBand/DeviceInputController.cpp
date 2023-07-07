// Fill out your copyright notice in the Description page of Project Settings.


#include "DeviceInputController.h"


ADeviceInputController::ADeviceInputController()
{
	bShowMouseCursor = true;
}

void ADeviceInputController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Keyboard
	InputComponent->BindAction("InputKeyboard", IE_Pressed, this, &ADeviceInputController::KeyboardClick);
	InputComponent->BindAction("InputKeyboard", IE_Repeat, this, &ADeviceInputController::KeyboardIng);
	InputComponent->BindAction("InputKeyboard", IE_Released, this, &ADeviceInputController::KeyboardUp);

	//Mouse
	InputComponent->BindAction("InputMouse", IE_Pressed, this, &ADeviceInputController::MouseClick);
	InputComponent->BindAction("InputMouse", IE_Repeat, this, &ADeviceInputController::MouseIng);
	InputComponent->BindAction("InputMouse", IE_Released, this, &ADeviceInputController::MouseUp);

	//Mike
	//InputComponent->BindAction("InputMike", IE_Pressed, this, &ADeviceInputController::MikeClick);
	//InputComponent->BindAction("InputMike", IE_Repeat, this, &ADeviceInputController::MikeIng);
	//InputComponent->BindAction("InputMike", IE_Released, this, &ADeviceInputController::MikeUp);
}

void ADeviceInputController::KeyboardClick()
{
	UE_LOG(LogTemp, Log, TEXT("KeyboardClick"));
}

void ADeviceInputController::KeyboardIng()
{
	UE_LOG(LogTemp, Log, TEXT("KeyboardIng"));
}

void ADeviceInputController::KeyboardUp()
{
	UE_LOG(LogTemp, Log, TEXT("KeyboardUp"));
}

void ADeviceInputController::MouseClick()
{
	UE_LOG(LogTemp, Log, TEXT("MouseClick"));
}

void ADeviceInputController::MouseIng()
{
	UE_LOG(LogTemp, Log, TEXT("MouseIng"));
}

void ADeviceInputController::MouseUp()
{
	UE_LOG(LogTemp, Log, TEXT("MouseUp"));
}

void ADeviceInputController::MikeClick()
{
	UE_LOG(LogTemp, Log, TEXT("MikeClick"));
}

void ADeviceInputController::MikeIng()
{
	UE_LOG(LogTemp, Log, TEXT("MikeIng"));
}

void ADeviceInputController::MikeUp()
{
	UE_LOG(LogTemp, Log, TEXT("MikeUp"));
}
