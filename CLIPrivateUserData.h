#pragma once

#include <string>
#include <iostream>

#include "Cli.h"
#include "BaseApp.h"


class CLIPrivateUserData : public CLI 
{
public:
	CLIPrivateUserData();

	std::pair<std::string, std::string> getLoginAndPass();

	void help() override;

private:
	BaseApp* _baseApp;

};
