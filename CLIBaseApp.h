#pragma once

#include "cli.h"
#include "cliPrivateUserData.h"
#include "cliUserData.h"
#include "cliMessage.h"
#include "BaseApp.h"


class CLIBaseApp : public CLI
{
public:
	CLIBaseApp();
	~CLIBaseApp() override;

public:
	void signIn();
	void signUp() const;
	void help() override;

private:
	BaseApp* _baseApp;
	UserData* _current;
};