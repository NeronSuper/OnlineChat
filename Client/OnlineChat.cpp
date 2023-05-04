#include "OnlineChat.h"

namespace Messanger
{
	int exec()
	{
		MySocket connectedSocket;

		return run(connectedSocket);
	}

	int run(MySocket& ServerSocket)
	{
		CLIBaseApp cliBaseApp;
		
		while (true)
		{
			std::system("cls");
			cliBaseApp.help();

			int answer;
			std::cin >> answer;

			switch (answer)
			{
			case 1:
				cliBaseApp.signIn();
				break;

			case 2:
				cliBaseApp.signUp();
				break;

			case 0:

				return 0;
			default:
				break;
			}
		}

		return 0;
	}
}