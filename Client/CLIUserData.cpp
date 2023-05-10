#include <limits>
#include "CLIUserData.h"


namespace Messanger
{
	CLIUserData::CLIUserData()
		: _baseApp(BaseApp::instance()), _current(nullptr), _socket(_baseApp->getCurrentSocket())
	{
	}

	CLIUserData::CLIUserData(UserData* current)
		: _baseApp(BaseApp::instance()), _current(current), _socket(_baseApp->getCurrentSocket())
	{

	}

	bool CLIUserData::isContinue()
	{
        std::cout << "\n\nDo you wanna try again?(y/n): ";

		char answer;
		std::cin >> answer;

		std::cin.clear();
		std::cin.ignore(32767, '\n');

		if (answer == 'n' || answer == 'N')
		{
			_socket->send('0');
			return false;
		}

		_socket->send('1');
		return true;
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

