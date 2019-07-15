#include "stdafx.h"
#include "ThreadLearning.h"

/**
* 想要复制一个线程（复制语义）是不可能的，你只能move（移动语义）它
* 效果：移动后,线程对象t不在代表任何线程。t1表示原来t指向的线程。
*/
void thread_move()
{
	std::thread t(func, 2, 3, 4);

	std::thread t1(std::move(t));
	//t.join();//t不指向线程了，所以不能调用
	t1.join();

	//早期版本可以用=，效果等同于move，现在已经被移除了
	//std::thread t2(func, 2, 3, 4);
	//std::thread t3;
	//t3 = t2;
}