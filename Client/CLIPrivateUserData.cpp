#include "CliPrivateUserData.h"


namespace Messanger
{
    CLIPrivateUserData::CLIPrivateUserData()
        : _baseApp(BaseApp::instance()), _current(nullptr), _socket(_baseApp->getCurrentSocket())
    {
    }

    CLIPrivateUserData::CLIPrivateUserData(UserData* current)
        : _baseApp(BaseApp::instance()), _current(current), _socket(_baseApp->getCurrentSocket())
    {

    }

    std::pair<std::string, std::string> CLIPrivateUserData::getLoginAndPass()
    {
        std::string login, password;

        std::system("cls");

        std::cout << "Login: ";
        std::cin >> login;

        std::cout << "Password: ";
        std::cin >> password;

        _socket->send(login);
        _socket->send(password);

        return { login,password };
    }

    void CLIPrivateUserData::help()
    {
    }
}
