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

void ADeviceInputController::BeginPlay()
{
	Super::BeginPlay();
}

void ADeviceInputController::Tick(float DeltaTime)
{
	if (isClickKeyboard)
	{
		curKeyboardInputTime += DeltaTime;
		if (curKeyboardInputTime >= keyboardInputTime)
		{
			KeyboardUp();
		}
	}


	if (isClickMouse)
	{
		curMouseInputTime += DeltaTime;
		if (curMouseInputTime >= mouseInputTime)
		{
			MouseUp();
		}
	}
}

void ADeviceInputController::KeyboardClick()
{
	UE_LOG(LogTemp, Log, TEXT("KeyboardClick"));
	isClickKeyboard = true;
	isIngKeyboard = false;
	isUpKeyboard = false;
}

void ADeviceInputController::KeyboardIng()
{
	UE_LOG(LogTemp, Log, TEXT("KeyboardIng"));
	isClickKeyboard = false;
	isIngKeyboard = true;
	isUpKeyboard = false;
}

void ADeviceInputController::KeyboardUp()
{
	UE_LOG(LogTemp, Log, TEXT("KeyboardUp"));
	isClickKeyboard = false;
	isIngKeyboard = false;
	isUpKeyboard = true;
	curKeyboardInputTime = 0.0f;
}

void ADeviceInputController::MouseClick()
{
	UE_LOG(LogTemp, Log, TEXT("MouseClick"));
	isClickMouse = true;
	isIngMouse = false;
	isUpMouse = false;
}

void ADeviceInputController::MouseIng()
{
	UE_LOG(LogTemp, Log, TEXT("MouseIng"));
	isClickMouse = false;
	isIngMouse = true;
	isUpMouse = false;
}

void ADeviceInputController::MouseUp()
{
	UE_LOG(LogTemp, Log, TEXT("MouseUp"));
	isClickMouse = false;
	isIngMouse = false;
	isUpMouse = true;
	curMouseInputTime = 0.0f;
}

void ADeviceInputController::MikeUpdate(float value)
{
	if (value > mikeLimit)
	{
		if (!isClickMike && !isIngMike)
		{
			MikeClick();
		}
		else
		{
			MikeIng();
		}
		UE_LOG(LogTemp, Log, TEXT("UsingMike %f"), value);
	}
	else if (isClickMike || isIngMike)
	{
		MikeUp();
	}
	isUpMike = false;
}

void ADeviceInputController::MikeClick()
{
	UE_LOG(LogTemp, Log, TEXT("MikeClick"));
	isClickMike = true;
}

void ADeviceInputController::MikeIng()
{
	UE_LOG(LogTemp, Log, TEXT("MikeIng"));
	isClickMike = false;
	isIngMike = true;
}

void ADeviceInputController::MikeUp()
{
	UE_LOG(LogTemp, Log, TEXT("MikeUp"));
	isUpMike = true;
	isClickMike = false;
	isIngMike = false;
}
