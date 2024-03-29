#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "UserData.h"
#include "MySocket.h"


namespace Messanger
{
    class BaseApp
    {
    private:
        BaseApp();

    public:
        BaseApp(BaseApp const&) = delete;
        BaseApp& operator= (BaseApp const&) = delete;
        ~BaseApp() = default;

    public:
        static BaseApp* instance();

        void addUser(const UserData& ud);
        bool isLogin(const std::string& login, MySocket* socket) const;
        bool isLogin(const std::string& login) const;
        bool isPasswordCorrect(const std::string& login, const std::string& password, MySocket* socket) const;

        UserData* findUser(const std::string& login);
        
        void sendMessage(const Message& message, const std::string& receiver, UserData* user); // send to concrete chat
        void sendMessage(const Message& message);                                              // send to general chat

        void updateUserData(UserData* user, MySocket* socket);

    private:
        static std::unique_ptr<BaseApp> _instance;

        std::unordered_map<std::string, UserData> _usersData; // unordered_map of users
        std::vector<Message> _generalChat;
    };
}

