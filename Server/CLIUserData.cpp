#include "CLIUserData.h"


namespace Messanger
{
	CLIUserData::CLIUserData()
		: _baseApp(BaseApp::instance()), _current(nullptr), _socket(nullptr)
	{
	}

	CLIUserData::CLIUserData(UserData* current, MySocket* socket)
		: _baseApp(BaseApp::instance()), _current(current), _socket(socket)
	{

	}

	bool CLIUserData::isContinue()
	{
		return _socket->receive()[0];
	}

	void CLIUserData::setCurrent(UserData* current)
	{
		_current = current;
	}

	void CLIUserData::help()
	{
		std::cout << "Your login: " << _current->getLogin() << "\n";
		std::cout << "1. Go message\n";
		std::cout << "2. Settings\n";
		std::cout << "3. Back\n";
		std::cout << "0. Exit\n";
	}
}

