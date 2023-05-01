
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

		std::pair<std::string, std::string> getLoginAndPass();

		void help() override;

	private:
		BaseApp* _baseApp;

	};
}
