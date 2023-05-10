#include "CliMessage.h"


namespace Messanger
{
	CLIMessage::CLIMessage()
		: _baseApp(BaseApp::instance()), _user(nullptr), _socket(_baseApp->getCurrentSocket())
	{
	}
	CLIMessage::CLIMessage(UserData* current)
		: _baseApp(BaseApp::instance()), _user(current), _socket(_baseApp->getCurrentSocket())
	{
	}

	void CLIMessage::mainMenu()
	{
		while (true)
		{
			std::system("cls");

			this->help();

			char answer;
			std::cin >> answer;

			_socket->send(answer);

			switch (answer)
			{
			case '1':
				sendToSomebody();

				break;
			case '2':
				mutualChat();

				break;
			case '3':
				sendToALl();

				break;
			case '4':
				generalChat();

				break;
			case '5':

				return;
			case '0':

				exit(0);
			default:
				break;
			}
		}

	}

	void CLIMessage::sendToSomebody() const
	{
		std::string receiver;
		std::string message;

		CLIUserData cliUserData;

		while (true)
		{
			std::system("cls");

			std::cout << "Send a messege to: ";
			std::cin >> receiver;

			_socket->send(receiver);

			if (!_baseApp->isLogin(receiver))
			{
				std::system("cls");
				std::cout << receiver << " have never been registered!\n";

				if (!cliUserData.isContinue())
					return;

				continue;
			}

			if (receiver == _user->getLogin())
			{
				std::system("cls");
				std::cout << "You can't send a message to yourself!\n";

				if (!cliUserData.isContinue())
					return;

				continue;
			}

			std::cout << "Your messege to " << receiver << ": ";
			std::cin.ignore();
			std::getline(std::cin, message);

			_socket->send(message);

			break;
		}

		_baseApp->sendMessage(Message(_user->getLogin(), message), receiver);
	}

	void CLIMessage::mutualChat() const
	{
		std::string chatName;

		CLIUserData cliUserData;

		while (true)
		{
			std::system("cls");

			std::cout << "Enter chat's name: ";
			std::cin >> chatName;

			_socket->send(chatName);

			if (!_baseApp->isLogin(chatName))
			{
				std::system("cls");
				std::cout << chatName << " have never been registered!\n";

				if (!cliUserData.isContinue())
					return;

				continue;
			}

			if (chatName == _user->getLogin())
			{
				std::system("cls");
				std::cout << "You can't send a message to yourself!\n";

				if (!cliUserData.isContinue())
					return;

				continue;
			}

			break;
		}

		_baseApp->updateData();
		_baseApp->printChat(chatName);
	}

	void CLIMessage::sendToALl() const
	{
		std::system("cls");

		std::cout << "Your messange in general chat: ";
		std::string message;

		std::cin.ignore();
		std::getline(std::cin, message);

		_baseApp->sendMessage(Message(_user->getLogin(), message));
	}

	void CLIMessage::generalChat() const
	{
		_baseApp->printChat();
	}

	void CLIMessage::help()
	{
		std::cout << "Your login: " << _user->getLogin() << "\n";
		std::cout << "1. Send a message to user\n";
		std::cout << "2. Look at mutual chat\n";
		std::cout << "3. Send a message to all\n";
		std::cout << "4. Look at general chat\n";
		std::cout << "5. Back\n";
		std::cout << "0. Exit\n";
	}
}