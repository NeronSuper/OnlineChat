#include "BaseApp.h"


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

void BaseApp::setCurrent(UserData* userData)
{
    _currentUser = userData;
}

void BaseApp::addUser(const UserData& ud)
{
    _usersData.push_back(ud);
}

bool BaseApp::isLogin(const std::string& login) const
{
    for (const auto& i : _usersData)
    {
        if (i.getLogin() == login)
            return true;
    }

    return false;
}
bool BaseApp::isPassword(const std::string& password) const
{

    for (const auto& i : _usersData)
    {
        if (i.getPassword() == password)
            return true;
    }

    return false;
}

UserData* BaseApp::findUser(const std::string& login)
{
    for (int i = 0; i < _usersData.size(); ++i)
    {
        if (_usersData[i].getLogin() == login)
            return &_usersData[i];
    }

    return nullptr;
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

    findUser(sender)->getMessages()[receiver].push_back(message);
    findUser(receiver)->getMessages()[sender].push_back(message);
}

void BaseApp::sendMessage(const Message& message)
{
    _generalChat.push_back(message);
}

BaseApp::BaseApp() 
    : _currentUser(nullptr)
{
}