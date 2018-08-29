#include "stdafx.h"
#include "IOCPBase.h"
#include <mstcpip.h>

#pragma comment(lib, "WS2_32.lib")

IOContextPool SocketContext::ioContextPool;		// 初始化

IOCPBase::IOCPBase() :
	completionPort(INVALID_HANDLE_VALUE),
	workerThreads(NULL),
	workerThreadNum(0),
	IP(DEFAULT_IP),
	port(DEFAULT_PORT),
	listenSockContext(NULL),
	fnAcceptEx(NULL),
	fnGetAcceptExSockAddrs(NULL),
	connectCnt(0),
	acceptPostCnt(0)
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	stopEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

IOCPBase::~IOCPBase()
{
	RELEASE_HANDLE(stopEvent);
	Stop(); 
	WSACleanup();
}

BOOL IOCPBase::Start(int port, int maxConn, int maxIOContextInPool, int maxSocketContextInPool)
{
	if (false == InitializeIOCP())
		return false;

	if (false == InitializeListenSocket())
	{
		DeInitialize();
		return false;
	}

	return true;
}

void IOCPBase::Stop()
{
	if (listenSockContext != NULL && listenSockContext->connSocket != INVALID_SOCKET)
	{
		// 激活关闭事件
		SetEvent(stopEvent);

		for (int i = 0; i < workerThreadNum; i++)
		{
			// 通知所有完成端口退出
			PostQueuedCompletionStatus(completionPort, 0, (DWORD)EXIT_CODE, NULL);
		}

		// 等待所有工作线程退出
		WaitForMultipleObjects(workerThreadNum, workerThreads, TRUE, INFINITE);

		// 释放其他资源
		DeInitialize();
	}
}

BOOL IOCPBase::SendData(SocketContext * socketContext, char * data, int size)
{
	return 0;
}

wstring IOCPBase::GetLocalIP()
{
	//char hostName[MAX_PATH] = { 0 };
	//gethostname(hostName, MAX_PATH);
	//struct hostent FAR *hostent = gethostbyname(hostName);
	//if (hostent == NULL)
	//{
	//	return string(DEFAULT_IP);
	//}

	//// 取得IP地址列表中的第一个为返回的IP(因为一台主机可能会绑定多个IP)
	//char *addr = hostent->h_addr_list[0];
	//in_addr inAddr;
	//memmove(&inAddr, addr, 4);

	//return string(inet_ntoa(inAddr));
	return wstring(DEFAULT_IP);
}

BOOL IOCPBase::InitializeIOCP()
{
	//1、调用CreateIoCompletionPort() 函数创建一个完成端口。
	completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (NULL == completionPort)
	{
		return false;
	}

	/*
	建立和处理器的核数相等的工作线程（WorkerThread），
	这些线程不断地通过GetQueuedCompletionStatus() 函数扫描
	完成端口中是否有IO操作完成，如果有的话，将已经完成了的
	IO操作取出处理，处理完成后，再投递一个IO请求即可
	*/
	workerThreadNum = WORKER_THREADS_PER_PROCESSOR * GetNumOfProcessors();
	workerThreads = new HANDLE[workerThreadNum];

	for (int i = 0; i < workerThreadNum; i++)
	{
		workerThreads[i] = CreateThread(0, 0, WorkerThreadProc, (void *)this, 0, 0);
	}
	return true;
}

BOOL IOCPBase::InitializeListenSocket()
{
	// 生成用于监听的socket的Context
	listenSockContext = new SocketContext;
	listenSockContext->connSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (INVALID_SOCKET == listenSockContext->connSocket)
		return false;

	// 将socket绑定到完成端口中
	if (NULL == CreateIoCompletionPort((HANDLE)listenSockContext->connSocket, completionPort, (DWORD)listenSockContext, 0))
	{
		RELEASE_SOCKET(listenSockContext->connSocket);
		return false;
	}

	//服务器地址信息，用于绑定socket
	sockaddr_in serverAddr;

	// 填充地址信息
	ZeroMemory((char *)&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(port);

	// 绑定地址和端口
	if (SOCKET_ERROR == bind(listenSockContext->connSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)))
	{
		return false;
	}

	// 开始监听
	if (SOCKET_ERROR == listen(listenSockContext->connSocket, SOMAXCONN))
	{
		return false;
	}

	GUID guidAcceptEx = WSAID_ACCEPTEX;
	GUID guidGetAcceptSockAddrs = WSAID_GETACCEPTEXSOCKADDRS;
	/*
	//提取扩展函数指针
	未获取函数指针就调用函数（如直接连接mswsock..lib并直接
	调用AcceptEx）的消耗是很大的，因为AcceptEx 实际上是存在
	于Winsock2结构体系之外的。每次应用程序常试在服务提供层
	上（mswsock之上）调用AcceptEx时，都要先通过WSAIoctl获取
	该函数指针。如果要避免这个很影响性能的操作，应用程序最好
	是直接从服务提供层通过WSAIoctl先获取这些APIs的指针。
	http://www.360doc.com/content/13/1220/08/12282510_338576573.shtml
	*/
	DWORD dwBytes = 0;
	/*
	WSAIoctl
	https://docs.microsoft.com/zh-cn/windows/desktop/api/winsock2/nf-winsock2-wsaioctl
	*/
	if (SOCKET_ERROR == WSAIoctl(
		listenSockContext->connSocket,		//一个套接口的句柄。 
		SIO_GET_EXTENSION_FUNCTION_POINTER,	//将进行的操作的控制代码 
		&guidAcceptEx,						//输入缓冲区的地址
		sizeof(guidAcceptEx),				//输入缓冲区的大小 
		&fnAcceptEx,						//输出缓冲区的地址
		sizeof(fnAcceptEx),					//输出缓冲区的大小 
		&dwBytes,							//输出实际字节数的地址 
		NULL,								//WSAOVERLAPPED结构的地址 
		NULL								//一个指向操作结束后调用的例程指针 
	))
	{
		DeInitialize();
		return false;
	}

	if (SOCKET_ERROR == WSAIoctl(
		listenSockContext->connSocket,
		SIO_GET_EXTENSION_FUNCTION_POINTER,
		&guidGetAcceptSockAddrs,
		sizeof(guidGetAcceptSockAddrs),
		&fnGetAcceptExSockAddrs,
		sizeof(fnGetAcceptExSockAddrs),
		&dwBytes,
		NULL,
		NULL))
	{
		DeInitialize();
		return false;
	}

	for (size_t i = 0; i < MAX_POST_ACCEPT; i++)
	{
		IOContext *ioContext = listenSockContext->GetNewIOContext();
		if (false == PostAccept(listenSockContext, ioContext))
		{
			listenSockContext->RemoveContext(ioContext);
			return false;
		}
	}
	return true;
}

void IOCPBase::DeInitialize()
{
	// 关闭系统退出事件句柄
	RELEASE_HANDLE(stopEvent);

	// 释放工作者线程句柄指针
	for (int i = 0; i<workerThreadNum; i++)
	{
		RELEASE_HANDLE(workerThreads[i]);
	}

	RELEASE(workerThreads);

	// 关闭IOCP句柄
	RELEASE_HANDLE(completionPort);

	// 关闭监听Socket
	RELEASE(listenSockContext);
}

BOOL IOCPBase::IsSocketAlive(SOCKET sock)
{
	int nByteSent = send(sock, "", 0, 0);
	if (-1 == nByteSent) 
		return false;
	return true;
}

int IOCPBase::GetNumOfProcessors()
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	return si.dwNumberOfProcessors;
}

BOOL IOCPBase::AssociateWithIOCP(SocketContext * sockContext)
{
	// 将用于和客户端通信的SOCKET绑定到完成端口中
	HANDLE hTemp = CreateIoCompletionPort((HANDLE)sockContext->connSocket, completionPort, (DWORD)sockContext, 0);

	if (NULL == hTemp)
	{
		return false;
	}

	return true;
}

BOOL IOCPBase::PostAccept(SocketContext * sockContext, IOContext * ioContext)
{
	DWORD dwBytes = 0;
	ioContext->ioType = ACCEPT_POSTED;
	ioContext->ioSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (INVALID_SOCKET == ioContext->ioSocket)
	{
		return false;
	}
	
	// 将接收缓冲置为0,令AcceptEx直接返回,防止拒绝服务攻击
	if (false == fnAcceptEx(listenSockContext->connSocket, ioContext->ioSocket, ioContext->wsaBuf.buf, 0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwBytes, &ioContext->overLapped))
	{
		if (WSA_IO_PENDING != WSAGetLastError())
		{
			return false;
		}
	}

	InterlockedIncrement(&acceptPostCnt);
	return true;
}

BOOL IOCPBase::PostRecv(SocketContext * sockContext, IOContext *ioContext)
{
	DWORD dwFlags = 0, dwBytes = 0;
	ioContext->Reset();
	ioContext->ioType = RECV_POSTED;

	int nBytesRecv = WSARecv(ioContext->ioSocket, &ioContext->wsaBuf, 1, &dwBytes, &dwFlags, &ioContext->overLapped, NULL);
	// 如果返回值错误，并且错误的代码并非是Pending的话，那就说明这个重叠请求失败了
	if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
	{
		DoClose(sockContext);
		return false;
	}
	return true;
}

BOOL IOCPBase::PostSend(SocketContext * sockContext, IOContext *ioContext)
{
	ioContext->ioType = SEND_POSTED;
	DWORD dwBytes = 0, dwFlags = 0;

	if (::WSASend(ioContext->ioSocket, &ioContext->wsaBuf, 1, &dwBytes, dwFlags, &ioContext->overLapped, NULL) != NO_ERROR)
	{
		if (WSAGetLastError() != WSA_IO_PENDING)
		{
			DoClose(sockContext);
			return false;
		}
	}
	return true;
}

BOOL IOCPBase::DoAccpet(SocketContext * sockContext, IOContext * ioContext)
{
	
	InterlockedIncrement(&connectCnt);
	InterlockedDecrement(&acceptPostCnt);
	SOCKADDR_IN *clientAddr = NULL;
	SOCKADDR_IN *localAddr = NULL;
	int clientAddrLen, localAddrLen;
	clientAddrLen = localAddrLen = sizeof(SOCKADDR_IN);

	// 1. 获取地址信息 （GetAcceptExSockAddrs函数不仅可以获取地址信息，还可以顺便取出第一组数据）
	fnGetAcceptExSockAddrs(ioContext->wsaBuf.buf, 0, localAddrLen, clientAddrLen, (LPSOCKADDR *)&localAddr, &localAddrLen, (LPSOCKADDR *)&clientAddr, &clientAddrLen);

	// 2. 为新连接建立一个SocketContext 
	SocketContext *newSockContext = new SocketContext;
	newSockContext->connSocket = ioContext->ioSocket;
	memcpy_s(&(newSockContext->clientAddr), sizeof(SOCKADDR_IN), clientAddr, sizeof(SOCKADDR_IN));

	// 3. 将listenSocketContext的IOContext 重置后继续投递AcceptEx
	ioContext->Reset();
	if (false == PostAccept(listenSockContext, ioContext))
	{
		listenSockContext->RemoveContext(ioContext);
	}

	// 4. 将新socket和完成端口绑定
	if (NULL == CreateIoCompletionPort((HANDLE)newSockContext->connSocket, completionPort, (DWORD)newSockContext, 0))
	{
		DWORD dwErr = WSAGetLastError();
		if (dwErr != ERROR_INVALID_PARAMETER)
		{
			DoClose(newSockContext);
			return false;
		}
	}

	// 并设置tcp_keepalive
	tcp_keepalive alive_in;
	tcp_keepalive alive_out;
	alive_in.onoff = TRUE;
	alive_in.keepalivetime = 1000 * 60;  // 60s  多长时间（ ms ）没有数据就开始 send 心跳包
	alive_in.keepaliveinterval = 1000 * 10; //10s  每隔多长时间（ ms ） send 一个心跳包
	unsigned long ulBytesReturn = 0;
	if (SOCKET_ERROR == WSAIoctl(newSockContext->connSocket, SIO_KEEPALIVE_VALS, &alive_in, sizeof(alive_in), &alive_out, sizeof(alive_out), &ulBytesReturn, NULL, NULL))
	{
		TRACE(L"WSAIoctl failed: %d/n", WSAGetLastError());
	}


	OnConnectionEstablished(newSockContext);

	// 5. 建立recv操作所需的ioContext，在新连接的socket上投递recv请求
	IOContext *newIoContext = newSockContext->GetNewIOContext();
	newIoContext->ioType = RECV_POSTED;
	newIoContext->ioSocket = newSockContext->connSocket;
	// 投递recv请求
	if (false == PostRecv(newSockContext, newIoContext))
	{
		DoClose(sockContext);
		return false;
	}

	return true;
}

BOOL IOCPBase::DoRecv(SocketContext * sockContext, IOContext * ioContext)
{
	OnRecvCompleted(sockContext, ioContext);
	ioContext->Reset();
	if (false == PostRecv(sockContext, ioContext))
	{
		DoClose(sockContext);
		return false;
	}
	return true;
}

BOOL IOCPBase::DoSend(SocketContext * sockContext, IOContext * ioContext)
{
	OnSendCompleted(sockContext, ioContext);
	return 0;
}

BOOL IOCPBase::DoClose(SocketContext * sockContext)
{
	InterlockedDecrement(&connectCnt);
	RELEASE(sockContext);
	return true;
}

DWORD IOCPBase::WorkerThreadProc(LPVOID lpParam)
{
	IOCPBase *iocp = (IOCPBase*)lpParam;
	OVERLAPPED *ol = NULL;
	SocketContext *sockContext;
	DWORD dwBytes = 0;
	IOContext *ioContext = NULL;

	while (WAIT_OBJECT_0 != WaitForSingleObject(iocp->stopEvent, 0))
	{
		BOOL bRet = GetQueuedCompletionStatus(iocp->completionPort, &dwBytes, (PULONG_PTR)&sockContext, &ol, INFINITE);

		// 读取传入的参数
		ioContext = CONTAINING_RECORD(ol, IOContext, overLapped);

		// 收到退出标志
		if (EXIT_CODE == (DWORD)sockContext)
		{
			break;
		}

		if (!bRet)
		{
			DWORD dwErr = GetLastError();

			// 如果是超时了，就再继续等吧  
			if (WAIT_TIMEOUT == dwErr)
			{
				// 确认客户端是否还活着...
				if (!iocp->IsSocketAlive(sockContext->connSocket))
				{
					iocp->OnConnectionClosed(sockContext);

					// 回收socket
					iocp->DoClose(sockContext);
					continue;
				}
				else
				{
					continue;
				}
			}
			// 可能是客户端异常退出了(64)
			else if (ERROR_NETNAME_DELETED == dwErr)
			{
				iocp->OnConnectionError(sockContext, dwErr);

				// 回收socket
				iocp->DoClose(sockContext);
				continue;
			}
			else
			{
				iocp->OnConnectionError(sockContext, dwErr);

				// 回收socket
				iocp->DoClose(sockContext);
				continue;
			}
		}
		else
		{
			// 判断是否有客户端断开
			if ((0 == dwBytes) && (RECV_POSTED == ioContext->ioType || SEND_POSTED == ioContext->ioType))
			{
				iocp->OnConnectionClosed(sockContext);

				// 回收socket
				iocp->DoClose(sockContext);
				continue;
			}
			else
			{
				switch (ioContext->ioType)
				{
				case ACCEPT_POSTED:
					iocp->DoAccpet(sockContext, ioContext);
					break;
				case RECV_POSTED:
					iocp->DoRecv(sockContext, ioContext);
					break;
				case SEND_POSTED:
					iocp->DoSend(sockContext, ioContext);
					break;
				default:
					break;
				}
			}
		}
	}

	// 释放线程参数
	RELEASE(lpParam);
	return 0;
}
