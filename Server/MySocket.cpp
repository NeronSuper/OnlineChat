#include "MySocket.h"

MySocket::MySocket()
{
    if (initSocket())
    {
        std::cout << "can't create a server!\n";
        m_clientSocket = INVALID_SOCKET;
    }
}

MySocket::MySocket(const SOCKET& ClientSocket)
    : m_clientSocket(ClientSocket)
{
}

MySocket::~MySocket()
{
}

int MySocket::initSocket()
{
    addrinfo hints, * result = NULL;;
    WSADATA wsaData;


    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cout << "WSAStartup failed: " << iResult << "\n";

        return 1;
    }


    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0)
    {
        std::cout << "getaddrinfo failed: " << iResult << "\n";

        WSACleanup();

        return 1;
    }


    m_clientSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (m_clientSocket == INVALID_SOCKET)
    {
        std::cout << "Error at socket(): " << iResult << "\n";

        freeaddrinfo(result);
        WSACleanup();

        return 1;
    }


    iResult = bind(m_clientSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "getaddrinfo failed: " << iResult << "\n";

        freeaddrinfo(result);
        closesocket(m_clientSocket);
        WSACleanup();

        return 1;
    }

    return 0;
}

std::string MySocket::receive()
{
    char buff[DEFAULT_BUFLEN];

    int iResult = ::recv(m_clientSocket, buff, DEFAULT_BUFLEN, 0);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "receive failed: " << iResult << "\n";

        throw std::exception();
    }

    buff[iResult] = '\0';

    return buff;
}

void MySocket::send(const std::string& message)
{
    int iResult = ::send(m_clientSocket, message.c_str(), static_cast<int>(message.size()), 0);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "send failed: \n";

        throw std::exception();
    }
}

void MySocket::send(char message)
{
    MySocket::send(std::string(1, message));
}

SOCKET MySocket::getSocket() const
{
    return m_clientSocket;
}

void MySocket::setSocket(const SOCKET& clientSocket)
{
    m_clientSocket = clientSocket;
}
