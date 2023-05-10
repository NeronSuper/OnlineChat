#include "PrivateUserData.h"


namespace Messanger
{
	PrivateUserData::PrivateUserData()
		: _pData(), _chats()
	{
	}

	PrivateUserData::PrivateUserData(const std::string& login, const std::string& password)
		: _pData(login, password)
	{
	}

	PrivateUserData::PrivateUserData(const PrivateUserData& pud)
		: _pData(pud._pData), _chats(pud._chats)
	{
	}

	std::string PrivateUserData::getLogin() const
	{
		return _pData.first;
	}

	std::string PrivateUserData::getPassword() const
	{
		return _pData.second;
	}

	std::map<std::string, std::vector<Message>>& PrivateUserData::getChats()
	{
		return _chats;
	}
}

