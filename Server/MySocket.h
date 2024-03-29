#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <thread>

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

#pragma comment(lib, "Ws2_32.lib")



class MySocket
{
public:
    MySocket();
    MySocket(const SOCKET &ClientSocket);
    ~MySocket();

    int initSocket();

    std::string receive();
    void send(const std::string& message);
    void send(char message);

    SOCKET getSocket() const;
    void setSocket(const SOCKET& clientSocket);

private:
    std::string receiveMess();
    void sendMess(const std::string& message);

    SOCKET m_clientSocket;

};

