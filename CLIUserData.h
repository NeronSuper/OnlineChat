#pragma once

#include <iostream>

#include "cli.h"
#include "UserData.h"
#include "BaseApp.h"


class CLIUserData : public CLI 
{
public:
	CLIUserData();
	CLIUserData(UserData* current);

	bool isContinue();
	void setCurrent(UserData* current);

	void help() override;
	
private:
	BaseApp* _baseApp;
	UserData* _current;

};
