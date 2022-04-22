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
    C2S_LOGIN,      //上线            客户端的发包类型
    C2S_LOGOUT,     //下线
    C2S_GROUP,      //群聊包
    C2S_PRIVATE,    //私聊包

    S2C_LOGIN,      //上线            服务端的发包类型  
    S2C_LOGOUT,     //下线
    S2C_GROUP,      //群聊包
    S2C_PRIVATE,    //私聊包
};

#define NAMELEN 128

typedef struct tagUserInfo
{
    unsigned short _wport;//用户的端口号
    unsigned int  _wIp;//ip
    char _name[NAMELEN];//name
}USERINFO,* PUSERINFO;

#define MSGLEN 256
typedef struct tagPackage
{
    ChatCommand _nCommand;//包的类型
    USERINFO _ClientSend; //发送信息的客户端
    USERINFO _ClientReceive;//接收信息的客户端
    char* _Msg[MSGLEN];
}PACKAGE,*PPACKAGE;

bool SendTo(SOCKET sock, USERINFO& ui, PACKAGE& pkg);
