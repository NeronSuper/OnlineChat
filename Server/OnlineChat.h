#pragma once
#include "CLIBaseApp.h"


namespace Messanger
{
	int exec();

	int startListning(SOCKET ListenSocket);

	void handler(SOCKET ClientSocket);
}