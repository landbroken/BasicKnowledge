// TCPLearningClient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/**************************************************
文件名client.cpp
windows下socket网络编程实例  -- 客户端基于TCP
服务器地址：'127.0.0.1'
端口号 8888
作者：peter
***************************************************/
#include<WinSock2.h>  
#include<stdio.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "WS2_32.lib")  

const int PORT = 8888;
const char LOCALIP[10] = "127.0.0.1";

int main(int argc, char* argv[])
{
	/*
	客户端基本顺序：
	socket()
	connect()
	sendto()
	readfrom()
	close()
	*/

	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 0);//指定版本号  
	::WSAStartup(sockVersion, &wsaData);//载入winsock的dll  
										
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//建立socket，基于tcp  
	if (s == INVALID_SOCKET)
	{
		printf("error");
		::WSACleanup(); //释放资源  
		return 0;
	}

	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	//端口号，htons用来将主机字节顺序转换为网络字节顺序(to network short)
	servAddr.sin_port = htons(PORT);
	//IP
	//servAddr.sin_addr.S_un.S_addr = inet_addr(LOCALIP);
	inet_pton(AF_INET, LOCALIP, &servAddr.sin_addr);
	//连接
	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf("error");
		::WSACleanup(); //释放资源  
		return 0;
	}

	char buff[156];//缓冲区  
	int nRecv = ::recv(s, buff, 156, 0);//接收数据  
	if (nRecv > 0)
	{
		buff[nRecv] = '\0';
		printf_s("接受数据：%s", buff);
	}
	::closesocket(s); //关闭套接字  
	::WSACleanup(); //释放资源

	printf_s("已经closesocket(s)，WSACleanup()\n");
	system("pause");
	return 0;
}