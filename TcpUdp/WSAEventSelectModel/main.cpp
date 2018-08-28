// AsyncTcpServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ClientBase.h"
#include <iostream>

using namespace std;

const int PORT = 8888;
const char LOCALIP[10] = "127.0.0.1";

class Client : public ClientBase
{
public:
	// 连接关闭
	virtual void OnConnectionClosed()
	{
		printf("   Close\n");
	}
	// 连接上发生错误
	virtual void OnConnectionError()
	{
		printf("   Error\n");
	}
	// 读操作完成
	virtual void OnRecvCompleted(BYTE* buffer, int len)
	{
		printf("recv[%d]:%s\n", len, (char*)buffer);
	}
	// 写操作完成
	virtual void OnSendCompleted()
	{
		printf("*Send success\n");
	}

};

int main()
{
	Client client;
	if (!client.Start(LOCALIP, PORT))
	{
		cout << "   start error" << endl;
	}

	int i = 0;
	while (true)
	{
		char buff[128];
		//scanf_s("%s", &buff, 128);

		sprintf_s(buff, 128, "第%d条Msg", i++);
		//cout << buff << "第" << i++ << "条Msg" << endl;

		Sleep(1000);
		client.Send((BYTE*)buff, strlen(buff) + 1);
	}
}