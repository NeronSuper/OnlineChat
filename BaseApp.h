#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "UserData.h"


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

        UserData* getCurrent() const;
        void setCurrent(UserData* userData);

        void addUser(const UserData& ud);
        bool isLogin(const std::string& login) const;
        bool isPasswordCorrect(const std::string& login, const std::string& password) const;

        UserData* findUser(const std::string& login);

        void printChat(const std::string& chatName);                           // print concrete chat
        void printChat();                                                      // print general chat
        void sendMessage(const Message& message, const std::string& receiver); // send to concrete chat
        void sendMessage(const Message& message);                              // send to general chat

    private:
        static std::unique_ptr<BaseApp> _instance;

        std::unordered_map<std::string, UserData> _usersData; // unordered_map of users
        UserData* _currentUser;

        std::vector<Message> _generalChat;
    };
}

