#include"InitSocket.h"

InitSocket::InitSocket()
{
	unsigned short wVersionRequested;// �汾��
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2,2);
	
	err = WSAStartup(wVersionRequested, &wsaData);//����WSAStartup����,�������������Ӧ�ó�����winsock.dll�ĵ�һ������.����,��һ��������WINSOCK �汾��,�ڶ���������ָ��
	//WSADATA��ָ��.�ú�������һ��INT��ֵ, ͨ��������ֵ��ȷ����ʼ���Ƿ�ɹ�,Ҳ���ǰ󶨶�Ӧ��socket���
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