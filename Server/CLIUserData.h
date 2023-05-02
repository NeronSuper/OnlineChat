#pragma once

#include <iostream>

#include "Cli.h"
#include "UserData.h"
#include "BaseApp.h"


namespace Messanger
{

	class CLIUserData : public CLI
	{
	public:
		CLIUserData();
		explicit CLIUserData(UserData* current);

		bool isContinue();
		void setCurrent(UserData* current);

		void help() override;

	private:
		BaseApp* _baseApp;
		UserData* _current;

	};
}
