#include "Message.h"


namespace Messanger
{
	Message::Message()
		: _message()
	{
	}

	Message::Message(const std::string& name, const std::string& message)
		: _message(name, message)
	{

	}

	const std::string& Message::getOwner() const
	{
		return _message.first;
	}

	const std::string& Message::getMessage() const
	{
		return _message.second;
	}
}
