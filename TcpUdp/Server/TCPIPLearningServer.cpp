// TCPIPLearningServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/**************************************************
文件名server.cpp
windows下socket网络编程实例  -- 服务器端基于TCP
服务器地址：'127.0.0.1'
端口号 8888
作者：peter
***************************************************/
#include<WinSock2.h>  
#include<stdio.h>  
#include <Ws2tcpip.h>
#pragma comment(lib,"WS2_32.lib")  

const int PORT = 8888;

/*
基本步骤
socket()
bind()
listen()
accept()
recv
sendto
close()
*/
int main(int argc, char* argv[])
{
	WSADATA wsaData;
	//指定版本号  
	WORD sockVersion = MAKEWORD(2, 0);
	//载入winsock的dll  
	::WSAStartup(sockVersion, &wsaData);
										
	//创建套接字基于TCP
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf("error");
		::WSACleanup();//清理，释放资源  
		return 0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	//端口号8888
	sin.sin_port = htons(PORT);
	//INADDR_ANY就是指定地址为0.0.0.0的地址,  
	//地址全是0，也就是所有的地址
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	//绑定socket  
	if (::bind(s, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("error");
		::WSACleanup();//清理释放资源  
		return 0;
	}

	//监听socket  
	if (::listen(s, 2) == SOCKET_ERROR)
	{
		printf("error");
		::WSACleanup();//释放资源  
		return 0;
	}

	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
	SOCKET client;
	char szText[] = "peter\n";//缓冲区数据  

	while (1)
	{
		/*
		accept服务器端使用，调用函数进入阻塞状态，等待用户连接，
		如果没有客户端进行连接，程序就在这个地方。不会看到后面。
		如果有客户端连接，那么程序就执行一次然后继续循环到这里等待。
		*/
		client = ::accept(s, (SOCKADDR*)&remoteAddr, &nAddrLen);
		if (client == INVALID_SOCKET)
		{
			printf("error");
			continue;
		}

		char str[INET_ADDRSTRLEN];
		printf("接受到一个连接：%s\r\n", inet_ntop(AF_INET, &remoteAddr.sin_addr, str,sizeof(str)));

		::send(client, szText, strlen(szText), 0); //发送数据  

		::closesocket(client);//关闭套接字  
	}

	::closesocket(s);
	::WSACleanup();
	return 0;
}