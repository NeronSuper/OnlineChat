#include "MySocket.h"

MySocket::MySocket()
{
    if (initSocket())
    {
        std::cout << "can't connect to the server!\n";
        m_serverSocket = INVALID_SOCKET;
    }
}

MySocket::MySocket(const SOCKET& serverSocket)
    : m_serverSocket(serverSocket)
{
}

MySocket::~MySocket()
{
    closesocket(m_serverSocket);
    WSACleanup();
}

int MySocket::initSocket()
{
    WSADATA wsaData;
    int iResult;


    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cout << "WSAStartup failed: " << iResult << '\n';

        return 1;
    }

    struct addrinfo* result = NULL, hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;


    iResult = getaddrinfo(DEFAULT_IP, DEFAULT_PORT, &hints, &result);
    if (iResult != 0)
    {
        std::cout << "getaddrinfo failed: " << iResult << '\n';

        WSACleanup();

        return 1;
    }


    m_serverSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (m_serverSocket == INVALID_SOCKET)
    {
        std::cout << "Error at socket(): " << WSAGetLastError() << '\n';

        freeaddrinfo(result);
        WSACleanup();

        return 1;
    }


    iResult = connect(m_serverSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        closesocket(m_serverSocket);
        freeaddrinfo(result);
        WSACleanup();

        return 1;
    }

    freeaddrinfo(result);

    return 0;
}

std::string MySocket::receive()
{
    char buff[DEFAULT_BUFLEN];

    int iResult = ::recv(m_serverSocket, buff, DEFAULT_BUFLEN, 0);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "receive failed: " << iResult << "\n";
    }

    buff[iResult] = '\0';

    return buff;
}

void MySocket::send(const std::string& message)
{
    int iResult = ::send(m_serverSocket, message.c_str(), static_cast<int>(message.size()), 0);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "send failed: \n";
    }
}

void MySocket::send(char message)
{
    MySocket::send(std::string(1, message));
}

SOCKET MySocket::getSocket() const
{
    return m_serverSocket;
}

void MySocket::setSocket(const SOCKET& serverSocket)
{
    m_serverSocket = serverSocket;
}
