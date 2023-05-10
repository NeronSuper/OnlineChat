#include "CliPrivateUserData.h"


namespace Messanger
{
    CLIPrivateUserData::CLIPrivateUserData()
        : _baseApp(BaseApp::instance()), _current(nullptr), _socket(nullptr)
    {
    }

    CLIPrivateUserData::CLIPrivateUserData(UserData* current, MySocket* socket)
        : _baseApp(BaseApp::instance()), _current(current), _socket(socket)
    {

    }

    std::pair<std::string, std::string> CLIPrivateUserData::getLoginAndPass()
    {
        std::string login, password;

        login = _socket->receive();
        password = _socket->receive();

        return { login,password };
    }

    void CLIPrivateUserData::help()
    {
    }
}
