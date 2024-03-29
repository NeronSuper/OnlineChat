#pragma once

#include <string>


namespace Messanger
{
    class Message
    {
    public:
        Message();
        Message(const std::string& name, const std::string& message);

        const std::string& getOwner() const;
        const std::string& getMessage() const;

    private:
        std::pair<std::string, std::string> _message;

    };
}

