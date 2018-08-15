// ThreadCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ThreadLearning.h"

//线程函数
void func(int a, int b, int c)
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	mutex_demo();

	//后台执行t2的线程函数,并且不会因为main函数结束时,线程函数未执行完而产生异常
	//std::thread t2(func, 2, 3, 4);
	//t2.detach();
	//cout << "after t2 ,main is runing" << endl;

	//获取CPU的核数
	cout << "CPU: " << thread::hardware_concurrency() << endl;
	
	//当添加下面注释掉的语句会抛出异常,因为线程对象先于线程函数结束了,应该保证线程对象的生命周期在线程函数执行完时仍然存在.
	//std::thread t_err(func, 3, 4, 5);

    return 0;
}

