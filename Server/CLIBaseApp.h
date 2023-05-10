#pragma once

#include "Cli.h"
#include "CliPrivateUserData.h"
#include "CliUserData.h"
#include "CliMessage.h"
#include "BaseApp.h"


namespace Messanger
{

	class CLIBaseApp : public CLI
	{
	public:
		CLIBaseApp();
		explicit CLIBaseApp(MySocket* socket);
		~CLIBaseApp() override;

	public:
		void signIn();
		void signUp() const;
		void help() override;

	private:
		BaseApp* _baseApp;
		UserData* _current;
		MySocket* _socket;

	};
}
