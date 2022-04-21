#pragma once
#include<Windows.h>
//#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
class InitSocket
{
public:
	InitSocket();
	~InitSocket();
private:
	static InitSocket _InitSocket;
};