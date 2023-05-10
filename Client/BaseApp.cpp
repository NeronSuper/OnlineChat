#include "BaseApp.h"


namespace Messanger
{
    std::unique_ptr<BaseApp> BaseApp::_instance = nullptr;
    BaseApp* BaseApp::instance()
    {
        if (!_instance)
        {
            _instance = static_cast<std::unique_ptr<BaseApp>>(new BaseApp);
        }
        return _instance.get();
    }

    UserData* BaseApp::getCurrent() const
    {
        return _currentUser;
    }

    MySocket* BaseApp::getCurrentSocket() const
    {
        return _currentSoket;
    }

    void BaseApp::setCurrentUser(UserData* userData)
    {
        _currentUser = userData;
    }

    void BaseApp::setCurrentSocket(MySocket* socket)
    {
        _currentSoket = socket;
    }

    bool BaseApp::isLogin(const std::string& login) const
    {
        return _currentSoket->receive()[0] - '0';
    }

    bool BaseApp::isPasswordCorrect(const std::string& login, const std::string& password) const
    {
        return _currentSoket->receive()[0] - '0';
    }

    void BaseApp::printChat(const std::string& chatName)
    {
        std::system("cls");

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


        std::system("pause");
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
                std::cout << _generalChat[i].getName() << ": " << _generalChat[i].getMessage() << "\n";
            }
        }


        std::system("pause");
    }

    void BaseApp::sendMessage(const Message& message, const std::string& receiver)
    {
        std::string sender = _currentUser->getLogin();

    }

    void BaseApp::sendMessage(const Message& message)
    {
        _generalChat.push_back(message);
    }

    BaseApp::BaseApp()
        : _currentUser(nullptr), _generalChat()
    {
    }
}
