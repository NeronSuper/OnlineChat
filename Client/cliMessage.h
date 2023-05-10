#pragma once

#include <iostream>

#include "Cli.h"
#include "CLIUserData.h"
#include "BaseApp.h"


namespace Messanger
{

	class CLIMessage : public CLI
	{
	public:
		CLIMessage();
		explicit CLIMessage(UserData* current);

		void mainMenu();

		void sendToSomebody() const;
		void mutualChat() const;
		void sendToALl() const;
		void generalChat() const;

		void help() override;

	private:
		BaseApp* _baseApp;
		UserData* _current;
		MySocket* _socket;

	};
}
