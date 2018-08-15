#include "stdafx.h"

static std::timed_mutex mutex1;

void work()
{
	//设置阻塞时间
	std::chrono::milliseconds timeout(1000);
	int cnt = 0;
	while (true) {
		//带超时的锁,当阻塞超过100milliseconds时返回false
		if (mutex1.try_lock_for(timeout)) 
		{
			cout << this_thread::get_id() << ": with the mutex. sleep 250" << endl;
			std::chrono::milliseconds sleepDuration(250);
			this_thread::sleep_for(sleepDuration);
		}
		//超时后将执行else
		else 
		{
			cout << this_thread::get_id() << ": without mutex" << endl;

			chrono::milliseconds sleepDuration(100);
			std::this_thread::sleep_for(sleepDuration);

			//主动解锁，下一次循环执行上面的，输出with the mutex. sleep 250
			cnt++;
			if (cnt>10)
			{
				cnt = 0;
				mutex1.unlock();
			}
		}
	}
}

int timed_mutex_demo()
{
	std::thread t1(work);
	std::thread t2(work);

	t1.join();
	t2.join();

	return 0;
}