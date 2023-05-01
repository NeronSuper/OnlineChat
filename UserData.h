#pragma once

#include "PrivateUserData.h"
namespace Messanger
{
    class UserData : public PrivateUserData
    {
    public:
        UserData();
        UserData(const std::string& login, const std::string& password);
        UserData(const UserData& ud);

    };
}