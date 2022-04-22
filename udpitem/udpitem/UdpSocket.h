#pragma once
#include "InitSocket.h"

class UdpSocket
{
public:
	UdpSocket();
	~UdpSocket();

	SOCKET CreateSocketUdp();
	int CloseSocketUdp();
	int BindUdp(const char* pip, unsigned short uPort);
	SOCKET _SocketUdp = INVALID_SOCKET;


};
enum ChatCommand
{
    C2S_LOGIN,      //����            �ͻ��˵ķ�������
    C2S_LOGOUT,     //����
    C2S_GROUP,      //Ⱥ�İ�
    C2S_PRIVATE,    //˽�İ�

    S2C_LOGIN,      //����            ����˵ķ�������  
    S2C_LOGOUT,     //����
    S2C_GROUP,      //Ⱥ�İ�
    S2C_PRIVATE,    //˽�İ�
};

#define NAMELEN 128

typedef struct tagUserInfo
{
    unsigned short _wport;//�û��Ķ˿ں�
    unsigned int  _wIp;//ip
    char _name[NAMELEN];//name
}USERINFO,* PUSERINFO;

#define MSGLEN 256
typedef struct tagPackage
{
    ChatCommand _nCommand;//��������
    USERINFO _ClientSend; //������Ϣ�Ŀͻ���
    USERINFO _ClientReceive;//������Ϣ�Ŀͻ���
    char* _Msg[MSGLEN];
}PACKAGE,*PPACKAGE;

bool SendTo(SOCKET sock, USERINFO& ui, PACKAGE& pkg);
