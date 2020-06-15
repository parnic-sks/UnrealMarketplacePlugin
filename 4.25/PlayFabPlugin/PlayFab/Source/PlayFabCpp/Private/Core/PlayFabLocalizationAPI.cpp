//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabLocalizationAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::LocalizationModels;

UPlayFabLocalizationAPI::UPlayFabLocalizationAPI() {}

UPlayFabLocalizationAPI::~UPlayFabLocalizationAPI() {}

int UPlayFabLocalizationAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabLocalizationAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}

void UPlayFabLocalizationAPI::SetTitleId(const FString& titleId)
{
    PlayFabSettings::SetTitleId(titleId);
}

void UPlayFabLocalizationAPI::SetDevSecretKey(const FString& developerSecretKey)
{
    PlayFabSettings::SetDeveloperSecretKey(developerSecretKey);
}

bool UPlayFabLocalizationAPI::GetLanguageList(
    const FGetLanguageListDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    LocalizationModels::FGetLanguageListRequest emptyRequest = LocalizationModels::FGetLanguageListRequest();
    return UPlayFabLocalizationAPI::GetLanguageList(emptyRequest, SuccessDelegate, ErrorDelegate);
}

bool UPlayFabLocalizationAPI::GetLanguageList(
    LocalizationModels::FGetLanguageListRequest& request,
    const FGetLanguageListDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && PlayFabSettings::GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/Locale/GetLanguageList")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? PlayFabSettings::GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabLocalizationAPI::OnGetLanguageListResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabLocalizationAPI::OnGetLanguageListResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLanguageListDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    LocalizationModels::FGetLanguageListResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
