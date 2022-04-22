#include"UdpSocket.h"
#pragma warning(disable:4996)
UdpSocket::UdpSocket()
{

}

UdpSocket::~UdpSocket()
{

}

SOCKET UdpSocket::CreateSocketUdp()
{
	//创建一个udp SOCKET句柄
	_SocketUdp = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	return _SocketUdp;
}

BOOL UdpSocket::CloseSocketUdp()
{
	if (_SocketUdp)
	{
		closesocket(_SocketUdp);
		_SocketUdp = INVALID_SOCKET;
		return true;
	}
	return false;
}
BOOL UdpSocket::BindUdp(const char* pIp, unsigned short uPort)
{
	sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(uPort);
	si.sin_addr.S_un.S_addr = inet_addr(pIp);

	int nRet = bind(_SocketUdp,(sockaddr *)&si,sizeof(si));
	if (nRet == -1)
	{
		return false;
	}
	return true;
}

bool SendTo(SOCKET sock,USERINFO &ui,PACKAGE &pkg)
{
	sockaddr_in si = { 0 };
	si.sin_family = AF_INET;
	si.sin_port = ui._wport;
	si.sin_addr.S_un.S_addr = ui._wIp;

	return true;
}
