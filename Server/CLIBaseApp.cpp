#include "CliBaseApp.h"


namespace Messanger
{
    CLIBaseApp::CLIBaseApp()
        : _baseApp(BaseApp::instance()), _current(nullptr), _socket(nullptr)
    {
    }

    CLIBaseApp::CLIBaseApp(MySocket* socket)
        : _baseApp(BaseApp::instance()), _current(nullptr), _socket(socket)
    {
    }

    CLIBaseApp::~CLIBaseApp()
    {
    }

    void CLIBaseApp::signIn()
    {
        std::string login, password;

        CLIPrivateUserData cliPrivateUserData(nullptr, _socket);
        CLIUserData cliUserData(nullptr, _socket);

        while (true)
        {
            std::tie(login, password) = cliPrivateUserData.getLoginAndPass();

            if (!_baseApp->isPasswordCorrect(login, password, _socket))
            {
                if (!cliUserData.isContinue())
                    return;

                continue;
            }


            break;
        }

        _current = _baseApp->findUser(login); 

        cliUserData.setCurrent(_current);
        CLIMessage cliMessage(_current, _socket);

        while (true)
        {
            int answer = _socket->receive()[0];

            switch (answer)
            {
            case '1':
                cliMessage.mainMenu();

                break;
            case '2':

                // settings ( just for decency )

                break;
            case '3':

                return;
            case '0':

                exit(0);
            default:
                break;
            }
        }
    }


    void CLIBaseApp::signUp() const
    {
        std::string login, password;
        CLIPrivateUserData cliPrivateUserData(nullptr, _socket);
        CLIUserData cliUserData(nullptr, _socket);

        while (true)
        {
            std::tie(login, password) = cliPrivateUserData.getLoginAndPass();

            if (_baseApp->isLogin(login, _socket))
            {
                if (!cliUserData.isContinue())
                    return;

                continue;
            }


            break;
        }

        _baseApp->addUser(UserData(login, password));
    }

    void CLIBaseApp::help()
    {
        std::cout << "1. Sign in\n";
        std::cout << "2. Sign up\n";
        std::cout << "0. Exit\n";
    }
}