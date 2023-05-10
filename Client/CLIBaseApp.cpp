#include "CliBaseApp.h"


namespace Messanger
{
    CLIBaseApp::CLIBaseApp()
        : _baseApp(BaseApp::instance()), _user(nullptr), _socket(_baseApp->getCurrentSocket())
    {
    }

    CLIBaseApp::CLIBaseApp(UserData* current)
        : _baseApp(BaseApp::instance()), _user(current), _socket(_baseApp->getCurrentSocket())
    {
    }

    CLIBaseApp::~CLIBaseApp()
    {
    }

    void CLIBaseApp::signIn()
    {
        std::string login, password;

        CLIPrivateUserData cliPrivateUserData;
        CLIUserData cliUserData;

        while (true)
        {
            std::tie(login, password) = cliPrivateUserData.getLoginAndPass();

            if (!_baseApp->isPasswordCorrect(login, password))
            {
                std::system("cls");

                std::cout << "Incorrect input\n";

                if (!cliUserData.isContinue())
                    return;

                continue;
            }

            break;
        }

        _user = new UserData(login, password);

        _baseApp->setCurrentUser(_user);

        cliUserData.setCurrent(_user);
        CLIMessage cliMessage(_user);

        while (true)
        {
            std::system("cls");

            cliUserData.help();

            char answer;
            std::cin >> answer;

            _socket->send(answer);

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
        CLIPrivateUserData cliPrivateUserData;
        CLIUserData cliUserData;

        while (true)
        {
            std::tie(login, password) = cliPrivateUserData.getLoginAndPass();

            if (_baseApp->isLogin(login))
            {
                std::system("cls");

                std::cout << "User with \"" << login << "\" login is already exist";

                if (!cliUserData.isContinue())
                    return;

                continue;
            }

            break;
        }
    }

    void CLIBaseApp::help()
    {
        std::cout << "1. Sign in\n";
        std::cout << "2. Sign up\n";
        std::cout << "0. Exit\n";
    }
}