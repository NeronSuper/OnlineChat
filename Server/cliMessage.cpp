#include "CliMessage.h"


namespace Messanger
{
	CLIMessage::CLIMessage(UserData* current, MySocket* socket)
		: _baseApp(BaseApp::instance()), _user(current), _socket(socket)
	{
	}

	void CLIMessage::mainMenu()
	{
		while (true)
		{
			char answer = _socket->receive()[0];

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

		CLIUserData cliUserData(_user, _socket);

		while (true)
		{
			receiver = _socket->receive();

			if (!_baseApp->isLogin(receiver, _socket))
			{
				if (!cliUserData.isContinue())
					return;

				continue;
			}

			if (receiver == _user->getLogin())
			{
				if (!cliUserData.isContinue())
					return;

				continue;
			}

			message = _socket->receive();


			break;
		}

		_baseApp->sendMessage(Message(_user->getLogin(), message), receiver, _user);
	}

	void CLIMessage::mutualChat() const
	{
		std::string chatName;

		CLIUserData cliUserData(_user, _socket);

		while (true)
		{
			chatName = _socket->receive();

			if (!_baseApp->isLogin(chatName, _socket))
			{
				if (!cliUserData.isContinue())
					return;

				continue;
			}

			if (chatName == _user->getLogin())
			{
				if (!cliUserData.isContinue())
					return;

				continue;
			}

			break;
		}

		_baseApp->updateUserData(_user, _socket);
	}

	void CLIMessage::sendToALl() const
	{
		std::string message = _socket->receive();

		_baseApp->sendMessage(Message(_user->getLogin(), message));
	}

	void CLIMessage::generalChat() const
	{
		_baseApp->updateUserData(_user, _socket);
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