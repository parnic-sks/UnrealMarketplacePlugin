//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "Core/PlayFabAuthenticationDataModels.h"
#include "Core/PlayFabJsonHelpers.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;

PlayFab::AuthenticationModels::FEntityKey::~FEntityKey()
{

}

void PlayFab::AuthenticationModels::FEntityKey::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (!Id.IsEmpty() == false)
    {
        UE_LOG(LogTemp, Error, TEXT("This field is required: EntityKey::Id, PlayFab calls may not work if it remains empty."));
    }
    else
    {
        writer->WriteIdentifierPrefix(TEXT("Id"));
        writer->WriteValue(Id);
    }

    if (Type.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("Type"));
        writer->WriteValue(Type);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FEntityKey::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> IdValue = obj->TryGetField(TEXT("Id"));
    if (IdValue.IsValid() && !IdValue->IsNull())
    {
        FString TmpValue;
        if (IdValue->TryGetString(TmpValue)) { Id = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TypeValue = obj->TryGetField(TEXT("Type"));
    if (TypeValue.IsValid() && !TypeValue->IsNull())
    {
        FString TmpValue;
        if (TypeValue->TryGetString(TmpValue)) { Type = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FEntityLineage::~FEntityLineage()
{

}

void PlayFab::AuthenticationModels::FEntityLineage::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (CharacterId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("CharacterId"));
        writer->WriteValue(CharacterId);
    }

    if (GroupId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("GroupId"));
        writer->WriteValue(GroupId);
    }

    if (MasterPlayerAccountId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("MasterPlayerAccountId"));
        writer->WriteValue(MasterPlayerAccountId);
    }

    if (NamespaceId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("NamespaceId"));
        writer->WriteValue(NamespaceId);
    }

    if (TitleId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("TitleId"));
        writer->WriteValue(TitleId);
    }

    if (TitlePlayerAccountId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("TitlePlayerAccountId"));
        writer->WriteValue(TitlePlayerAccountId);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FEntityLineage::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> CharacterIdValue = obj->TryGetField(TEXT("CharacterId"));
    if (CharacterIdValue.IsValid() && !CharacterIdValue->IsNull())
    {
        FString TmpValue;
        if (CharacterIdValue->TryGetString(TmpValue)) { CharacterId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> GroupIdValue = obj->TryGetField(TEXT("GroupId"));
    if (GroupIdValue.IsValid() && !GroupIdValue->IsNull())
    {
        FString TmpValue;
        if (GroupIdValue->TryGetString(TmpValue)) { GroupId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> MasterPlayerAccountIdValue = obj->TryGetField(TEXT("MasterPlayerAccountId"));
    if (MasterPlayerAccountIdValue.IsValid() && !MasterPlayerAccountIdValue->IsNull())
    {
        FString TmpValue;
        if (MasterPlayerAccountIdValue->TryGetString(TmpValue)) { MasterPlayerAccountId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> NamespaceIdValue = obj->TryGetField(TEXT("NamespaceId"));
    if (NamespaceIdValue.IsValid() && !NamespaceIdValue->IsNull())
    {
        FString TmpValue;
        if (NamespaceIdValue->TryGetString(TmpValue)) { NamespaceId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TitleIdValue = obj->TryGetField(TEXT("TitleId"));
    if (TitleIdValue.IsValid() && !TitleIdValue->IsNull())
    {
        FString TmpValue;
        if (TitleIdValue->TryGetString(TmpValue)) { TitleId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TitlePlayerAccountIdValue = obj->TryGetField(TEXT("TitlePlayerAccountId"));
    if (TitlePlayerAccountIdValue.IsValid() && !TitlePlayerAccountIdValue->IsNull())
    {
        FString TmpValue;
        if (TitlePlayerAccountIdValue->TryGetString(TmpValue)) { TitlePlayerAccountId = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FGetEntityTokenRequest::~FGetEntityTokenRequest()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::AuthenticationModels::FGetEntityTokenRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (CustomTags.Num() != 0)
    {
        writer->WriteObjectStart(TEXT("CustomTags"));
        for (TMap<FString, FString>::TConstIterator It(CustomTags); It; ++It)
        {
            writer->WriteIdentifierPrefix((*It).Key);
            writer->WriteValue((*It).Value);
        }
        writer->WriteObjectEnd();
    }

    if (Entity.IsValid())
    {
        writer->WriteIdentifierPrefix(TEXT("Entity"));
        Entity->writeJSON(writer);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FGetEntityTokenRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonObject>* CustomTagsObject;
    if (obj->TryGetObjectField(TEXT("CustomTags"), CustomTagsObject))
    {
        for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*CustomTagsObject)->Values); It; ++It)
        {
            CustomTags.Add(It.Key(), It.Value()->AsString());
        }
    }

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FGetEntityTokenResponse::~FGetEntityTokenResponse()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::AuthenticationModels::FGetEntityTokenResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid())
    {
        writer->WriteIdentifierPrefix(TEXT("Entity"));
        Entity->writeJSON(writer);
    }

    if (EntityToken.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("EntityToken"));
        writer->WriteValue(EntityToken);
    }

    if (TokenExpiration.notNull())
    {
        writer->WriteIdentifierPrefix(TEXT("TokenExpiration"));
        writeDatetime(TokenExpiration, writer);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FGetEntityTokenResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> EntityTokenValue = obj->TryGetField(TEXT("EntityToken"));
    if (EntityTokenValue.IsValid() && !EntityTokenValue->IsNull())
    {
        FString TmpValue;
        if (EntityTokenValue->TryGetString(TmpValue)) { EntityToken = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TokenExpirationValue = obj->TryGetField(TEXT("TokenExpiration"));
    if (TokenExpirationValue.IsValid())
        TokenExpiration = readDatetime(TokenExpirationValue);


    return HasSucceeded;
}

void PlayFab::AuthenticationModels::writeIdentifiedDeviceTypeEnumJSON(IdentifiedDeviceType enumVal, JsonWriter& writer)
{
    switch (enumVal)
    {

    case IdentifiedDeviceTypeUnknown: writer->WriteValue(TEXT("Unknown")); break;
    case IdentifiedDeviceTypeXboxOne: writer->WriteValue(TEXT("XboxOne")); break;
    case IdentifiedDeviceTypeScarlett: writer->WriteValue(TEXT("Scarlett")); break;
    }
}

AuthenticationModels::IdentifiedDeviceType PlayFab::AuthenticationModels::readIdentifiedDeviceTypeFromValue(const TSharedPtr<FJsonValue>& value)
{
    return readIdentifiedDeviceTypeFromValue(value.IsValid() ? value->AsString() : "");
}

AuthenticationModels::IdentifiedDeviceType PlayFab::AuthenticationModels::readIdentifiedDeviceTypeFromValue(const FString& value)
{
    static TMap<FString, IdentifiedDeviceType> _IdentifiedDeviceTypeMap;
    if (_IdentifiedDeviceTypeMap.Num() == 0)
    {
        // Auto-generate the map on the first use
        _IdentifiedDeviceTypeMap.Add(TEXT("Unknown"), IdentifiedDeviceTypeUnknown);
        _IdentifiedDeviceTypeMap.Add(TEXT("XboxOne"), IdentifiedDeviceTypeXboxOne);
        _IdentifiedDeviceTypeMap.Add(TEXT("Scarlett"), IdentifiedDeviceTypeScarlett);

    }

    if (!value.IsEmpty())
    {
        auto output = _IdentifiedDeviceTypeMap.Find(value);
        if (output != nullptr)
            return *output;
    }

    return IdentifiedDeviceTypeUnknown; // Basically critical fail
}

void PlayFab::AuthenticationModels::writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, JsonWriter& writer)
{
    switch (enumVal)
    {

    case LoginIdentityProviderUnknown: writer->WriteValue(TEXT("Unknown")); break;
    case LoginIdentityProviderPlayFab: writer->WriteValue(TEXT("PlayFab")); break;
    case LoginIdentityProviderCustom: writer->WriteValue(TEXT("Custom")); break;
    case LoginIdentityProviderGameCenter: writer->WriteValue(TEXT("GameCenter")); break;
    case LoginIdentityProviderGooglePlay: writer->WriteValue(TEXT("GooglePlay")); break;
    case LoginIdentityProviderSteam: writer->WriteValue(TEXT("Steam")); break;
    case LoginIdentityProviderXBoxLive: writer->WriteValue(TEXT("XBoxLive")); break;
    case LoginIdentityProviderPSN: writer->WriteValue(TEXT("PSN")); break;
    case LoginIdentityProviderKongregate: writer->WriteValue(TEXT("Kongregate")); break;
    case LoginIdentityProviderFacebook: writer->WriteValue(TEXT("Facebook")); break;
    case LoginIdentityProviderIOSDevice: writer->WriteValue(TEXT("IOSDevice")); break;
    case LoginIdentityProviderAndroidDevice: writer->WriteValue(TEXT("AndroidDevice")); break;
    case LoginIdentityProviderTwitch: writer->WriteValue(TEXT("Twitch")); break;
    case LoginIdentityProviderWindowsHello: writer->WriteValue(TEXT("WindowsHello")); break;
    case LoginIdentityProviderGameServer: writer->WriteValue(TEXT("GameServer")); break;
    case LoginIdentityProviderCustomServer: writer->WriteValue(TEXT("CustomServer")); break;
    case LoginIdentityProviderNintendoSwitch: writer->WriteValue(TEXT("NintendoSwitch")); break;
    case LoginIdentityProviderFacebookInstantGames: writer->WriteValue(TEXT("FacebookInstantGames")); break;
    case LoginIdentityProviderOpenIdConnect: writer->WriteValue(TEXT("OpenIdConnect")); break;
    case LoginIdentityProviderApple: writer->WriteValue(TEXT("Apple")); break;
    case LoginIdentityProviderNintendoSwitchAccount: writer->WriteValue(TEXT("NintendoSwitchAccount")); break;
    }
}

AuthenticationModels::LoginIdentityProvider PlayFab::AuthenticationModels::readLoginIdentityProviderFromValue(const TSharedPtr<FJsonValue>& value)
{
    return readLoginIdentityProviderFromValue(value.IsValid() ? value->AsString() : "");
}

AuthenticationModels::LoginIdentityProvider PlayFab::AuthenticationModels::readLoginIdentityProviderFromValue(const FString& value)
{
    static TMap<FString, LoginIdentityProvider> _LoginIdentityProviderMap;
    if (_LoginIdentityProviderMap.Num() == 0)
    {
        // Auto-generate the map on the first use
        _LoginIdentityProviderMap.Add(TEXT("Unknown"), LoginIdentityProviderUnknown);
        _LoginIdentityProviderMap.Add(TEXT("PlayFab"), LoginIdentityProviderPlayFab);
        _LoginIdentityProviderMap.Add(TEXT("Custom"), LoginIdentityProviderCustom);
        _LoginIdentityProviderMap.Add(TEXT("GameCenter"), LoginIdentityProviderGameCenter);
        _LoginIdentityProviderMap.Add(TEXT("GooglePlay"), LoginIdentityProviderGooglePlay);
        _LoginIdentityProviderMap.Add(TEXT("Steam"), LoginIdentityProviderSteam);
        _LoginIdentityProviderMap.Add(TEXT("XBoxLive"), LoginIdentityProviderXBoxLive);
        _LoginIdentityProviderMap.Add(TEXT("PSN"), LoginIdentityProviderPSN);
        _LoginIdentityProviderMap.Add(TEXT("Kongregate"), LoginIdentityProviderKongregate);
        _LoginIdentityProviderMap.Add(TEXT("Facebook"), LoginIdentityProviderFacebook);
        _LoginIdentityProviderMap.Add(TEXT("IOSDevice"), LoginIdentityProviderIOSDevice);
        _LoginIdentityProviderMap.Add(TEXT("AndroidDevice"), LoginIdentityProviderAndroidDevice);
        _LoginIdentityProviderMap.Add(TEXT("Twitch"), LoginIdentityProviderTwitch);
        _LoginIdentityProviderMap.Add(TEXT("WindowsHello"), LoginIdentityProviderWindowsHello);
        _LoginIdentityProviderMap.Add(TEXT("GameServer"), LoginIdentityProviderGameServer);
        _LoginIdentityProviderMap.Add(TEXT("CustomServer"), LoginIdentityProviderCustomServer);
        _LoginIdentityProviderMap.Add(TEXT("NintendoSwitch"), LoginIdentityProviderNintendoSwitch);
        _LoginIdentityProviderMap.Add(TEXT("FacebookInstantGames"), LoginIdentityProviderFacebookInstantGames);
        _LoginIdentityProviderMap.Add(TEXT("OpenIdConnect"), LoginIdentityProviderOpenIdConnect);
        _LoginIdentityProviderMap.Add(TEXT("Apple"), LoginIdentityProviderApple);
        _LoginIdentityProviderMap.Add(TEXT("NintendoSwitchAccount"), LoginIdentityProviderNintendoSwitchAccount);

    }

    if (!value.IsEmpty())
    {
        auto output = _LoginIdentityProviderMap.Find(value);
        if (output != nullptr)
            return *output;
    }

    return LoginIdentityProviderUnknown; // Basically critical fail
}

PlayFab::AuthenticationModels::FValidateEntityTokenRequest::~FValidateEntityTokenRequest()
{

}

void PlayFab::AuthenticationModels::FValidateEntityTokenRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (CustomTags.Num() != 0)
    {
        writer->WriteObjectStart(TEXT("CustomTags"));
        for (TMap<FString, FString>::TConstIterator It(CustomTags); It; ++It)
        {
            writer->WriteIdentifierPrefix((*It).Key);
            writer->WriteValue((*It).Value);
        }
        writer->WriteObjectEnd();
    }

    if (!EntityToken.IsEmpty() == false)
    {
        UE_LOG(LogTemp, Error, TEXT("This field is required: ValidateEntityTokenRequest::EntityToken, PlayFab calls may not work if it remains empty."));
    }
    else
    {
        writer->WriteIdentifierPrefix(TEXT("EntityToken"));
        writer->WriteValue(EntityToken);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FValidateEntityTokenRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonObject>* CustomTagsObject;
    if (obj->TryGetObjectField(TEXT("CustomTags"), CustomTagsObject))
    {
        for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*CustomTagsObject)->Values); It; ++It)
        {
            CustomTags.Add(It.Key(), It.Value()->AsString());
        }
    }

    const TSharedPtr<FJsonValue> EntityTokenValue = obj->TryGetField(TEXT("EntityToken"));
    if (EntityTokenValue.IsValid() && !EntityTokenValue->IsNull())
    {
        FString TmpValue;
        if (EntityTokenValue->TryGetString(TmpValue)) { EntityToken = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FValidateEntityTokenResponse::~FValidateEntityTokenResponse()
{
    //if (Entity != nullptr) delete Entity;
    //if (Lineage != nullptr) delete Lineage;

}

void PlayFab::AuthenticationModels::FValidateEntityTokenResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid())
    {
        writer->WriteIdentifierPrefix(TEXT("Entity"));
        Entity->writeJSON(writer);
    }

    if (pfIdentifiedDeviceType.notNull())
    {
        writer->WriteIdentifierPrefix(TEXT("IdentifiedDeviceType"));
        writeIdentifiedDeviceTypeEnumJSON(pfIdentifiedDeviceType, writer);
    }

    if (IdentityProvider.notNull())
    {
        writer->WriteIdentifierPrefix(TEXT("IdentityProvider"));
        writeLoginIdentityProviderEnumJSON(IdentityProvider, writer);
    }

    if (IdentityProviderIssuedId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("IdentityProviderIssuedId"));
        writer->WriteValue(IdentityProviderIssuedId);
    }

    if (Lineage.IsValid())
    {
        writer->WriteIdentifierPrefix(TEXT("Lineage"));
        Lineage->writeJSON(writer);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FValidateEntityTokenResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    pfIdentifiedDeviceType = readIdentifiedDeviceTypeFromValue(obj->TryGetField(TEXT("IdentifiedDeviceType")));

    IdentityProvider = readLoginIdentityProviderFromValue(obj->TryGetField(TEXT("IdentityProvider")));

    const TSharedPtr<FJsonValue> IdentityProviderIssuedIdValue = obj->TryGetField(TEXT("IdentityProviderIssuedId"));
    if (IdentityProviderIssuedIdValue.IsValid() && !IdentityProviderIssuedIdValue->IsNull())
    {
        FString TmpValue;
        if (IdentityProviderIssuedIdValue->TryGetString(TmpValue)) { IdentityProviderIssuedId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> LineageValue = obj->TryGetField(TEXT("Lineage"));
    if (LineageValue.IsValid() && !LineageValue->IsNull())
    {
        Lineage = MakeShareable(new FEntityLineage(LineageValue->AsObject()));
    }

    return HasSucceeded;
}

