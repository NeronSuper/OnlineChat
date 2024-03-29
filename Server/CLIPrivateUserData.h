#pragma once

#include <string>
#include <iostream>

#include "Cli.h"
#include "BaseApp.h"


namespace Messanger
{
	class CLIPrivateUserData : public CLI
	{
	public:
		CLIPrivateUserData();
		explicit CLIPrivateUserData(UserData* current, MySocket* socket);

		std::pair<std::string, std::string> getLoginAndPass();

		void help() override;

	private:
		BaseApp* _baseApp;
		UserData* _user;
		MySocket* _socket;

	};
}
