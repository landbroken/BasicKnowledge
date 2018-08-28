// AsyncTcpServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <WinSock2.h>  
#include <Ws2tcpip.h>

#pragma comment(lib,"WS2_32.lib")  

using namespace std;

const int PORT = 8888;
#define WM_SOCKET WM_USER+0x10    //自定义socket消息

int main()
{
	WSADATA wsaData;
	//指定版本号  
	WORD wVersion = MAKEWORD(2, 2);
	//载入winsock的dll  
	if (WSAStartup(wVersion, &wsaData) != 0)
	{
		//打开失败…
	}
	//判断版本是否为2.2
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();//若出问题，卸载支持，并结束程序
		return 0;
	}

	//创建套接字基于TCP
	SOCKET s = ::WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP,NULL,0,0);
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

	//-------------------------
	// Create new event
	NewEvent = WSACreateEvent();

	//-------------------------
	// Associate event types FD_ACCEPT and FD_CLOSE
	// with the listening socket and NewEvent
	WSAEventSelect(s, NewEvent, FD_ACCEPT | FD_CLOSE);

	//监听socket
	/**
	int listen(SOCKET s, int users);
	服务程序可以调用listen函数使其流套接字s处于监听状态。处于监听状态的流套接字s将维
	护一个客户连接请求队列，该队列最多容纳users个客户连接请求。假如该函数执行成功，
	则返回0；如果执行失败，则返回SOCKET_ERROR。
	*/
	if (::listen(s, 2) == SOCKET_ERROR)
	{
		printf("error");
		::WSACleanup();//释放资源  
		return 0;
	}
	else
	{
		printf("Listening on socket...\n");
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
		printf("接受到一个连接：%s\r\n", inet_ntop(AF_INET, &remoteAddr.sin_addr, str, sizeof(str)));

		::send(client, szText, strlen(szText), 0); //发送数据
	}
	::closesocket(client);//关闭套接字  
	::closesocket(s);
	::WSACleanup();

    return 0;
}
