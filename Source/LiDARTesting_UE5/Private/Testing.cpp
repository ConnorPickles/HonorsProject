// Fill out your copyright notice in the Description page of Project Settings.


#include "Testing.h"
#include "AssetToolsModule.h"

void UTesting::Import()
{
    UE_LOG(LogTemp, Warning, TEXT("FOOBAR"));

    /*
    TArray<FString> filesToImport;
    FString srcPath = TEXT("C:/Users/Connor/Downloads/test_image.jpg");
    srcPath = srcPath.Replace(TEXT("\\"), TEXT("/"));
    filesToImport.Add(srcPath);

    UAutomatedAssetImportData* importData = NewObject<UAutomatedAssetImportData>();
    importData->bReplaceExisting = true;
    importData->DestinationPath = TEXT("C:/Users/Connor/Documents/School/University/CSC 499/Unreal Testing/LiDARTesting_UE5/Content");
    importData->Filenames = filesToImport;

    FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
    auto importedAssets = AssetToolsModule.Get().ImportAssetsAutomated(importData);
    */
}

void UTesting::PostInitProperties()
{
    Super::PostInitProperties();
    
    if (GetOuter() && GetOuter()->GetWorld())
    {
        BeginPlay();
    }
}

UWorld* UTesting::GetWorld() const
{
    if (GIsEditor && !GIsPlayInEditorWorld)
    {
        return nullptr;
    }
    else if (GetOuter())
    {
        return GetOuter()->GetWorld();
    }
    else
    {
        return nullptr;
    }
}