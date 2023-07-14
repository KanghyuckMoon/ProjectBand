// Fill out your copyright notice in the Description page of Project Settings.


#include "DeviceInputController.h"


ADeviceInputController::ADeviceInputController()
{
	bShowMouseCursor = true;
	AudioCaptureComponent = CreateDefaultSubobject<UAudioCaptureComponent>(TEXT("AudioCaptureComponent"));
	AudioCapture = CreateDefaultSubobject<UAudioCapture>(TEXT("AudioCapture"));
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
	AudioCaptureComponent->OnAudioEnvelopeValue.AddDynamic(this, &ADeviceInputController::MikeUpdate);
}

void ADeviceInputController::BeginPlay()
{
	Super::BeginPlay();

	// Set the audio capture properties
	//AudioCaptureComponent->bCaptureOnAudioVolume = false;  // You can modify these settings as per your requirements
	//AudioCaptureComponent->bCaptureOnMasterVolume = true;
	//AudioCaptureComponent->bCaptureOutsideVolumes = true;

	// Start capturing audio
	AudioCapture->StartCapturingAudio();
	//AudioCaptureComponent->OnAudioEnvelope.AddDynamic(this, &ADeviceInputController::UpdateMikeSoundSize);
}

//void ADeviceInputController::Tick(float DeltaTime)
//{
//	UpdateMikeSoundSize();
//}

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

void ADeviceInputController::UpdateMikeSoundSize(const TArray<uint8>& InAudioData, int32 NumChannels)
{
	TArray<float> AudioSamples;
	float TotalSquaredSum = 0.0f;

	// Calculate the sum of squared samples
	for (float Sample : InAudioData)
	{
		TotalSquaredSum += Sample * Sample;
	}

	// Calculate the RMS value
	float RMSValue = FMath::Sqrt(TotalSquaredSum / AudioSamples.Num());
	MikeUpdate(RMSValue);
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
