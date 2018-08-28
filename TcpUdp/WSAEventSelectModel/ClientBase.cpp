#include "stdafx.h"
#include "ClientBase.h"
#include <WS2tcpip.h>

#pragma comment(lib, "WS2_32.lib")

void ReleaseHandle(HANDLE x)
{
	if (x != NULL && x != INVALID_HANDLE_VALUE)
	{
		CloseHandle(x);
		x = INVALID_HANDLE_VALUE;
	}
}
void ReleaseSocket(SOCKET x)
{
	if (x != INVALID_SOCKET)
	{
		closesocket(x);
		x = INVALID_SOCKET;
	}
}

ClientBase::ClientBase()
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);//指定版本号
	::WSAStartup(sockVersion, &wsaData);//载入winsock的dll
}

ClientBase::~ClientBase()
{
	WSACleanup();
}

BOOL ClientBase::Start(const char *IPAddress, USHORT port)
{
	clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSock == INVALID_SOCKET)
		return false;
	socketEvent = WSACreateEvent();

	/**
	//参数说明：
	//CreateEventW(
	//	_In_opt_ LPSECURITY_ATTRIBUTES lpEventAttributes,
	//	_In_ BOOL bManualReset,
	//	_In_ BOOL bInitialState,
	//	_In_opt_ LPCWSTR lpName
	//);
	lpEventAttributes         一般为NULL
	bManualReset              创建的Event是自动复位还是人工复位
	如果想在每次调用WaitForSingleObject后让WINDOWS为您自动地把
	事件地状态恢复为”无信号”状态，必须把该参数设为FALSE,否则，
	您必须每次调用ResetEvent函数来清除事件的信号。
	bInitialState             初始状态,true,有信号,false无信号
	lpName                    事件对象的名称。您在OpenEvent函数中可能使用。
	*/
	stopEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
	inet_pton(AF_INET, IPAddress, &serAddr.sin_addr);
	//serAddr.sin_addr.S_un.S_addr = inet_addr(IPAddress);

	//连接
	if (connect(clientSock, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{  
		//连接失败   
		closesocket(clientSock);
		return false;
	}
	if (0 != WSAEventSelect(clientSock, socketEvent, FD_READ | FD_CLOSE))
		return false;

	/*
	•第一个参数 lpThreadAttributes 表示线程内核对象的安全属性，
	一般传入NULL表示使用默认设置。
	•第二个参数 dwStackSize 表示线程栈空间大小。传入0表示使用默认大小（1MB）。
	•第三个参数 lpStartAddress 表示新线程所执行的线程函数地址，多个线程可以
	使用同一个函数地址。
	•第四个参数 lpParameter 是传给线程函数的参数。
	•第五个参数 dwCreationFlags 指定额外的标志来控制线程的创建，为0表示线程
	创建之后立即就可以进行调度，如果为CREATE_SUSPENDED则表示线程创建后暂停
	运行，这样它就无法调度，直到调用ResumeThread()。
	•第六个参数 lpThreadId 将返回线程的ID号，传入NULL表示不需要返回该线程ID号。
	*/
	thread = CreateThread(0, 0, RecvThreadProc, (void *)this, 0, 0);
	return true;
}

BOOL ClientBase::Stop()
{
	SetEvent(stopEvent);
	WaitForSingleObject(thread, INFINITE);
	ReleaseSocket(clientSock);
	WSACloseEvent(socketEvent);
	ReleaseHandle(stopEvent);
	return true;
}

BOOL ClientBase::Send(const BYTE * buffer, int len)
{
	if (SOCKET_ERROR == send(clientSock, (char*)buffer, len, 0))
	{
		return false;
	}
	else
	{
		this->OnSendCompleted();
	}
	return true;
}

BOOL ClientBase::HasStarted()
{
	return 0;
}

DWORD ClientBase::RecvThreadProc(LPVOID lpParam)
{
	if (lpParam == NULL)
		return 0;

	ClientBase *client = (ClientBase *)lpParam;
	DWORD ret = 0;
	int index = 0;
	WSANETWORKEVENTS networkEvent;
	HANDLE events[2];
	events[0] = client->socketEvent;
	events[1] = client->stopEvent;

	while (true)
	{
		/*
		//等待事件发生
		DWORD WSAWaitForMultipleEvents(
		_In_ DWORD cEvents,
		_In_reads_(cEvents) const WSAEVENT FAR * lphEvents,
		_In_ BOOL fWaitAll,
		_In_ DWORD dwTimeout,
		_In_ BOOL fAlertable
		);
		*/
		ret = WSAWaitForMultipleEvents(2, events, FALSE, INFINITE, FALSE);
		if (ret == WSA_WAIT_FAILED || ret == WSA_WAIT_TIMEOUT)
			continue;
		//返回值实际为发生网络事件的套接字的下标+WSA_EVENT_0
		index = ret - WSA_WAIT_EVENT_0;
		if (index == 0)
		{
			WSAEnumNetworkEvents(client->clientSock, events[0], &networkEvent);
			if (networkEvent.lNetworkEvents & FD_READ)
			{
				if (networkEvent.iErrorCode[FD_READ_BIT != 0])
				{
					//Error
					continue;
				}

				//https://www.cnblogs.com/arsense/p/6505690.html
				//1、
				//malloc是在CRT的内存堆上分配的，这个堆的存在一般来说你是不会关心的
				//HeapAlloc则不同，你需要给它指定你想从哪个堆上分配，
				//而这个堆是从HeapCreate创建出来的
				//2、
				//HeapAlloc和malloc的区别在于他们属于不同的函数库。
				//前者属于平台sdk，后者则是标准库。
				char *buff = (char*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 4096);
				ret = recv(client->clientSock, buff, 4096, 0);
				if (ret == 0 || (ret == SOCKET_ERROR && WSAGetLastError() == WSAECONNRESET))
				{
					client->OnConnectionClosed();
					break;        //错误
				}
				client->OnRecvCompleted((BYTE*)buff, ret);
			}
			if (networkEvent.lNetworkEvents & FD_CLOSE)
			{

				client->OnConnectionClosed();
				break;    //关闭
			}
		}
		else
		{
			client->OnConnectionClosed();
			break;    // 退出
		}

	}
	return 1;
}

BOOL ClientBase::IsSocketAlive(SOCKET sock)
{
	return 0;
}