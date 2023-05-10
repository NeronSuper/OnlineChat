#include "CLIUserData.h"


namespace Messanger
{
	CLIUserData::CLIUserData()
		: _baseApp(BaseApp::instance()), _user(nullptr), _socket(nullptr)
	{
	}

	CLIUserData::CLIUserData(UserData* current, MySocket* socket)
		: _baseApp(BaseApp::instance()), _user(current), _socket(socket)
	{

	}

	bool CLIUserData::isContinue()
	{
		return _socket->receive()[0];
	}

	void CLIUserData::setCurrent(UserData* current)
	{
		_user = current;
	}

	void CLIUserData::help()
	{
		std::cout << "Your login: " << _user->getLogin() << "\n";
		std::cout << "1. Go message\n";
		std::cout << "2. Settings\n";
		std::cout << "3. Back\n";
		std::cout << "0. Exit\n";
	}
}

