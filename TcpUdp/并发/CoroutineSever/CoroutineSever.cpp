// CoroutineSever.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <thread>
#include <mutex>
#include <chrono>

#include <numeric>
#include <array>

#include <ppltasks.h>
#include <time.h>
#include <future>
using namespace std;
using namespace Concurrency;
/**
@ Notice
from https://blogs.msdn.microsoft.com/vcblog/2017/01/27/yield-keyword-to-become-co_yield-in-vs-2017/

the keyword 'yield' is being removed in the release of VS 2017,
Instead of `await`	Use `co_await`
Instead of `return`	Use `co_return`
Instead of `yield`	Use `co_yield`

@ Reason
Why are we making this change?
The C++ standards committee voted in October of 2015 to change the
keywords to include the prefix `co_`. The committee didn’t want to 
use keywords that would conflict with variable names already in use.


*/

void Sleep(int a)
{
	std::chrono::milliseconds sleepDuration(a);
	this_thread::sleep_for(sleepDuration);
}

int task0()
{
	Sleep(3000); 
	cout << "the f1 output\n"; 
	Sleep(5000);  
	return 100;
}

int main()
{
	cout << "begin" << endl;
	time_t t1 = time(NULL);

	array<task<int>, 3> tasks = {
		task<int>(task0),
		task<int>([] { Sleep(1000); cout << "the f2 output\n"; Sleep(5000); return 10; }),
		task<int>([] { Sleep(2000); cout << "the f3 output\n"; Sleep(5000); return 1; })
	};

	//when_all().wait():容器里面所有的task都被执行后，才继续向下执行。
	//when_any().wait():容器里第一个task完成之后，就继续向下执行。
	auto TaskList = when_all(tasks.begin(), tasks.end())
		.then([](vector<int> results)
	{
		cout << "The sum is "
			<< accumulate(results.begin(), results.end(), 0)
			<< endl;
	});

	//运行到这里，wait所有任务完成
	TaskList.wait();

	cout << "end" << endl;
	time_t t2 = time(NULL);
	cout << "the runtime length " << t2 - t1 << "s " << endl;

	system("pause");

    return 0;
}

