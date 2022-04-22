#pragma once
#include<WinSock2.h>
#include<Windows.h>
#include<stdio.h>

#pragma comment(lib,"Ws2_32.lib")
class InitSocket
{
public:
	InitSocket();
	~InitSocket();
private:
	static InitSocket _InitSocket;
};