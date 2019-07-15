#include "stdafx.h"

static std::mutex g_lock;

/*
你在lock一个 std::mutex 对象之后必须解锁（unlock）。
如果你已经对其加锁，你不能再次lock。
*/
void lock_unlock()
{
	//上锁
	g_lock.lock();
	cout << "in id: " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "out id: " << this_thread::get_id() << endl;
	//解锁
	g_lock.unlock();
}

void f_lock_guard()
{
	//lock_guard在构造时会自动锁定互斥量,而在退出作用域后进行析构时就会自动解锁.
	lock_guard<std::mutex> lock(g_lock);
	cout << "in id: " << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "out id: " << this_thread::get_id() << endl;
}

/*
多线程执行顺序不是一定的，通过加锁可以保证同一时间只有一个线程在使用
注：这里由于线程比较少，执行时间短，所以不加锁基本上也是同样顺序。
*/
int mutex_demo()
{
	std::thread t1(lock_unlock);
	std::thread t2(lock_unlock);
	std::thread t3(lock_unlock);

	t1.join();
	t2.join();
	t3.join();

	std::thread t4(f_lock_guard);
	std::thread t5(f_lock_guard);
	std::thread t6(f_lock_guard);

	t4.join();
	t5.join();
	t6.join();

	return 0;
}