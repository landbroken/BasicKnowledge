#include "stdafx.h"
#include "ThreadLearning.h"

void thread_move()
{
	std::thread t(func, 2, 3, 4);
	//移动后,线程对象t不在代表任何线程
	std::thread t1(std::move(t));
	//t.join();
	t1.join();
}