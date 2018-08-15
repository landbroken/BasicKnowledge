#include "stdafx.h"

std::mutex m;

//thread_local意味着，每一个线程都有自己的该全局变量的实例（instance）
//该实例的变量名就是全局变量名称。
thread_local int m_cnt = 0;

/*
这里的m_cnt将对每个线程有自己的值
*/
void f_thread_local()
{
	while (m_cnt<10)
	{
		m.lock();
		m_cnt++;
		std::chrono::milliseconds sleepDuration(10);
		this_thread::sleep_for(sleepDuration);
		cout << "ID:" << this_thread::get_id() << "val=" << m_cnt << endl;
		m.unlock();
	}
}

void thread_local_demo()
{
	m_cnt = 0;
	std::thread t1(f_thread_local);
	std::thread t2(f_thread_local);
	t1.join();
	t2.join();
}