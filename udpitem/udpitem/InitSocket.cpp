#include"InitSocket.h"

InitSocket::InitSocket()
{
	unsigned short wVersionRequested;// 版本号
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2,2);
	
	err = WSAStartup(wVersionRequested, &wsaData);//调用WSAStartup函数,这个函数是连接应用程序与winsock.dll的第一个调用.其中,第一个参数是WINSOCK 版本号,第二个参数是指向
	//WSADATA的指针.该函数返回一个INT型值, 通过检查这个值来确定初始化是否成功,也就是绑定对应的socket库绑定
	if (err == 0)
	{
		printf("Init Socket Success!\n\n");
		return ;
	}
	else
	{
		printf("Init Socket Failure!\n\n");
		//WSACleanup();
		return ;
	}
}
InitSocket:: ~InitSocket()
{
	WSACleanup();
}

InitSocket InitSocket::_InitSocket;