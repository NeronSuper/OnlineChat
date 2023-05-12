#include "OnlineChat.h"

namespace Messanger
{
	int exec()
	{
		MySocket listenSocket;

		if (listenSocket.getSocket() == INVALID_SOCKET)
			return 1;

		return startListning(listenSocket.getSocket());
	}

	int startListning(SOCKET ListenSocket)
	{
		SOCKET ClientSocket = INVALID_SOCKET;

		std::cout << "Listning is started\n";

		int iResult = listen(ListenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR)
		{
			std::cout << "Listen failed with error: " << WSAGetLastError() << '\n';

			closesocket(ListenSocket);
			WSACleanup();

			return 1;
		}

		while (true)
		{
			ClientSocket = INVALID_SOCKET;

			ClientSocket = accept(ListenSocket, NULL, NULL);
			if (ClientSocket == INVALID_SOCKET)
			{
				std::cout << "accept failed: " << WSAGetLastError() << '\n';

				closesocket(ListenSocket);
				WSACleanup();

				return 1;
			}
			std::cout << "New Client is connected\n";


			std::thread th(handler, ClientSocket);
			th.detach();
		}

		return 0;
	}

	void handler(MySocket clientSocket)
	{
		CLIBaseApp cliBaseApp(&clientSocket);
		
		try
		{
			
			while (true)
			{
				char answer = clientSocket.receive()[0];

				switch (answer)
				{
				case '1':
					cliBaseApp.signIn();
					break;

				case '2':
					cliBaseApp.signUp();
					break;

				case '0':
					throw std::exception();

					return;
				default:
					break;
				}
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Connection is closed\n";
			closesocket(clientSocket.getSocket());

			return;
		}
	}
}