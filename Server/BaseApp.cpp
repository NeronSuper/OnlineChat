#include "BaseApp.h"


namespace Messanger
{
    BaseApp::BaseApp()
        : _usersData(), _generalChat()
    {
    }

    std::unique_ptr<BaseApp> BaseApp::_instance = nullptr;
    BaseApp* BaseApp::instance()
    {
        if (!_instance)
        {
            _instance = static_cast<std::unique_ptr<BaseApp>>(new BaseApp);
        }
        return _instance.get();
    }

    void BaseApp::addUser(const UserData& ud)
    {
        std::cout << "Added user - login: \'" << ud.getLogin() << "\' password: \'" << ud.getPassword() << "\'\n";
        _usersData[ud.getLogin()] = ud;
    }

    bool BaseApp::isLogin(const std::string& login, MySocket* socket) const
    {
        if (isLogin(login))
        {
            socket->send('1');
            return true;
        }

        socket->send('0');
        return false;
    }

    bool BaseApp::isLogin(const std::string& login) const
    {
        if (_usersData.find(login) != _usersData.end())
        {
            return true;
        }

        return false;
    }

    bool BaseApp::isPasswordCorrect(const std::string& login, const std::string& password, MySocket* socket) const
    {
        if (!isLogin(login))
        {
            socket->send('0');
            return false;
        }

        if (_usersData.at(login).getPassword() == password)
        {
            socket->send('1');
            return true;
        }

        socket->send('0');
        return false;
    }

    UserData* BaseApp::findUser(const std::string& login)
    {
        auto ud = _usersData.find(login);

        if (ud != _usersData.end())
            return &ud->second;

        return nullptr;
    }

    void BaseApp::printChat(const std::string& chatName)
    {
        /*std::system("cls");

        auto messages = _currentUser->getMessages()[chatName];

        if (messages.empty())
        {
            std::cout << "This chat is empty, send him a message!\n";
        }
        else
        {
            for (int i = 0; i < messages.size(); ++i)
            {
                std::cout << messages[i].getName() << ": " << messages[i].getMessage() << "\n";
            }
        }


        std::system("pause");*/
    }

    void BaseApp::printChat()
    {
        std::system("cls");


        if (_generalChat.size() == 0)
        {
            std::cout << "This chat is empty, send him a message!\n";
        }
        else
        {
            for (int i = 0; i < _generalChat.size(); ++i)
            {
                std::cout << _generalChat[i].getOwner() << ": " << _generalChat[i].getMessage() << "\n";
            }
        }


        std::system("pause");
    }

    void BaseApp::sendMessage(const Message& message, const std::string& receiver, UserData* user)
    {
        std::cout << "The message \'" << message.getMessage() << "\' sent from \'" << user->getLogin() << "\' to \'" << receiver << "\'\n";

        std::string sender = user->getLogin();
        
        findUser(sender)->getChats()[receiver].push_back(message);
        findUser(receiver)->getChats()[sender].push_back(message);
    }

    void BaseApp::sendMessage(const Message& message)
    {
        _generalChat.push_back(message);
    }

    void BaseApp::updateUserData(UserData* user, MySocket* socket)
    {
        auto& chats = user->getChats();
        size_t countOfChats = chats.size();

        socket->send(std::to_string(countOfChats));

        for (auto iter_mes = chats.begin(); iter_mes != chats.end(); ++iter_mes)
        {
            std::string name = iter_mes->first;
            auto& messages = iter_mes->second;

            size_t countOfMessages = messages.size();

            socket->send(name);
            
            socket->send(std::to_string(countOfMessages));

            for (size_t i = 0; i < countOfMessages; i++)
            {
                socket->send(messages[i].getOwner());
                socket->send(messages[i].getMessage());
            }
        }
    }
}
