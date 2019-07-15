#include "stdafx.h"
#include "ThreadLearning.h"

void print_hello()
{
	cout << "hello world" << endl;
}

void print(string str)
{
	cout << str << endl;
}

void hello_world()
{
	string tmp;

	//这是不带参数的调用
	//创建线程对象t1,绑定线程函数为hello，线程t1在创建后会自动执行
	thread t1(print_hello);
	//输出t1的线程ID
	std::cout << "ID:" << t1.get_id() << std::endl;
	//等待t1线程函数执行结束
	//join函数将会阻塞线程,直到线程函数执行结束,如果线程函数有返回值,返回值将被忽略.
	t1.join();
	//t1.join();join只能用一次，第二次会出现异常，t1线程已经执行结束了

	//带参数的调用
	//创建线程对象ta,绑定线程函数为print
	tmp = "A";
	thread ta(print, tmp);
	ta.join();
	tmp = "B";
	thread tb(print, tmp);
	tb.join();
	tmp = "C";
	thread tc(print, tmp);
	tc.join();
}