#pragma once
#ifndef _CLIENTBASE_H_
#define _CLIENTBASE_H_

#include <WinSock2.h>
#include <Windows.h>

// 释放指针的宏
#define RELEASE(x)            {if(x != NULL) {delete x; x = NULL;}}
// 释放句柄的宏
void ReleaseHandle(HANDLE x);
// 释放Socket
void ReleaseSocket(SOCKET x);

class ClientBase
{
public:
	ClientBase();
	~ClientBase();

	// 启动通信
	BOOL Start(const char *IPAddress, USHORT port);
	// 关闭通信
	BOOL Stop();
	// 发送数据
	BOOL Send(const BYTE* buffer, int len);
	// 是否已启动
	BOOL HasStarted();

	// 事件通知函数(派生类重载此族函数)
	// 连接关闭
	virtual void OnConnectionClosed() = 0;
	// 连接上发生错误
	virtual void OnConnectionError() = 0;
	// 读操作完成
	virtual void OnRecvCompleted(BYTE* buffer, int len) = 0;
	// 写操作完成
	virtual void OnSendCompleted() = 0;

private:
	// 接收线程函数
	static DWORD WINAPI RecvThreadProc(LPVOID lpParam);
	// socket是否存活
	BOOL IsSocketAlive(SOCKET sock);
	SOCKET clientSock;
	WSAEVENT socketEvent;
	HANDLE stopEvent;
	HANDLE thread;
};

#endif // !_CLIENTBASE_H_
