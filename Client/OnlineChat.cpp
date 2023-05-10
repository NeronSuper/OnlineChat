#include "OnlineChat.h"

namespace Messanger
{
	int exec()
	{
		MySocket connectedSocket;

		if (connectedSocket.getSocket() == INVALID_SOCKET)
			return 1;

		return run(connectedSocket);
	}

	int run(MySocket& serverSocket)
	{
		CLIBaseApp cliBaseApp;

		BaseApp::instance()->setCurrentSocket(&serverSocket);
		
		while (true)
		{
			std::system("cls");
			cliBaseApp.help();

			char answer;
			std::cin >> answer;

			serverSocket.send(answer);

			switch (answer)
			{
			case '1':
				cliBaseApp.signIn();
				break;

			case '2':
				cliBaseApp.signUp();
				break;

			case '0':

				return 0;
			default:
				break;
			}
		}

		return 0;
	}
}