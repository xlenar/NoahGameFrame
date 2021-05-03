/*
            This file is part of: 
                NoahFrame
            https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2021 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang
   
   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/



#include "NFProperty.h"
#include "NFPropertyManager.h"

NFPropertyManager::~NFPropertyManager()
{
    ClearAll();
}

bool NFPropertyManager::RegisterCallback(const std::string& propertyName, const PROPERTY_EVENT_FUNCTOR_PTR& cb)
{
    NF_SHARE_PTR<NFIProperty> pProperty = this->GetElement(propertyName);
    if (pProperty)
    {
        pProperty->RegisterCallback(cb);
        return true;
    }

    return false;
}

NF_SHARE_PTR<NFIProperty> NFPropertyManager::AddProperty(const NFGUID& self, NF_SHARE_PTR<NFIProperty> pProperty)
{
    const std::string& propertyName = pProperty->GetKey();
    NF_SHARE_PTR<NFIProperty> pOldProperty = this->GetElement(propertyName);
    if (!pOldProperty)
    {
        NF_SHARE_PTR<NFIProperty> pNewProperty(NF_NEW NFProperty(self, propertyName, pProperty->GetType()));

        pNewProperty->SetPublic(pProperty->GetPublic());
        pNewProperty->SetPrivate(pProperty->GetPrivate());
        pNewProperty->SetSave(pProperty->GetSave());
        pNewProperty->SetCache(pProperty->GetCache());
        pNewProperty->SetRef(pProperty->GetRef());
		pNewProperty->SetUpload(pProperty->GetUpload());

        this->AddElement(propertyName, pNewProperty);
    }

    return pOldProperty;
}

NF_SHARE_PTR<NFIProperty> NFPropertyManager::AddProperty(const NFGUID& self, const std::string& propertyName, const NFDATA_TYPE varType)
{
    NF_SHARE_PTR<NFIProperty> pProperty = this->GetElement(propertyName);
    if (!pProperty)
    {
        pProperty = NF_SHARE_PTR<NFIProperty>(NF_NEW NFProperty(self, propertyName, varType));

        this->AddElement(propertyName, pProperty);
    }

    return pProperty;
}

bool NFPropertyManager::SetProperty(const std::string& propertyName, const NFData& TData)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        pProperty->SetValue(TData);

        return true;
    }

    return false;
}

const NFGUID& NFPropertyManager::Self()
{
    return mSelf;
}

std::string NFPropertyManager::ToString()
{
	std::string s;
	std::stringstream stream;
	NF_SHARE_PTR<NFIProperty> pProperty = First(s);
	while (pProperty)
	{
		stream << s << ":" << pProperty->ToString() << "|";
		pProperty = Next(s);
	}

	return stream.str();
}

bool NFPropertyManager::SetPropertyInt(const std::string& propertyName, const NFINT64 nValue)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        return pProperty->SetInt(nValue);
    }

    return false;
}

bool NFPropertyManager::SetPropertyFloat(const std::string& propertyName, const double dwValue)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        return pProperty->SetFloat(dwValue);
    }

    return false;
}

bool NFPropertyManager::SetPropertyString(const std::string& propertyName, const std::string& value)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        return pProperty->SetString(value);
    }

    return false;
}

bool NFPropertyManager::SetPropertyObject(const std::string& propertyName, const NFGUID& obj)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        return pProperty->SetObject(obj);
    }

    return false;
}

bool NFPropertyManager::SetPropertyVector2(const std::string& propertyName, const NFVector2& value)
{
	NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	if (pProperty)
	{
		return pProperty->SetVector2(value);
	}

	return false;
}

bool NFPropertyManager::SetPropertyVector3(const std::string& propertyName, const NFVector3& value)
{
	NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	if (pProperty)
	{
		return pProperty->SetVector3(value);
	}

	return false;
}

NFINT64 NFPropertyManager::GetPropertyInt(const std::string& propertyName)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	return pProperty ? pProperty->GetInt() : 0;
}

int NFPropertyManager::GetPropertyInt32(const std::string& propertyName)
{
	NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	return pProperty ? pProperty->GetInt32() : 0;
}

double NFPropertyManager::GetPropertyFloat(const std::string& propertyName)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	return pProperty ? pProperty->GetFloat() : 0.0;
}

const std::string& NFPropertyManager::GetPropertyString(const std::string& propertyName)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        return pProperty->GetString();
    }

    return NULL_STR;
}

const NFGUID& NFPropertyManager::GetPropertyObject(const std::string& propertyName)
{
    NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
    if (pProperty)
    {
        return pProperty->GetObject();
    }

    return NULL_OBJECT;
}

const NFVector2& NFPropertyManager::GetPropertyVector2(const std::string& propertyName)
{
	NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	if (pProperty)
	{
		return pProperty->GetVector2();
	}

	return NULL_VECTOR2;
}

const NFVector3& NFPropertyManager::GetPropertyVector3(const std::string& propertyName)
{
	NF_SHARE_PTR<NFIProperty> pProperty = GetElement(propertyName);
	if (pProperty)
	{
		return pProperty->GetVector3();
	}

	return NULL_VECTOR3;
}
