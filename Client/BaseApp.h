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

        UserData* getCurrent() const;
        MySocket* getCurrentSocket() const;
        void setCurrentUser(UserData* userData);
        void setCurrentSocket(MySocket* socket);

        bool isLogin(const std::string& login) const;
        bool isPasswordCorrect(const std::string& login, const std::string& password) const;

        void printChat(const std::string& chatName);                           // print concrete chat
        void printChat();                                                      // print general chat
        void sendMessage(const Message& message, const std::string& receiver); // send to concrete chat
        void sendMessage(const Message& message);                              // send to general chat

        void updateData();

    private:
        static std::unique_ptr<BaseApp> _instance;

        UserData* _currentUser;
        MySocket* _currentSoket;

        std::vector<Message> _generalChat;
    };
}

