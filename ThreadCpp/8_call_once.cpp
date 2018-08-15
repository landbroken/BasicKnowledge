#include "stdafx.h"
using namespace std;

std::once_flag flag;

void do_once()
{
	std::call_once(flag, []() {std::cout << "called" << std::endl;});
}

int call_once_demo()
{
	std::thread t1(do_once);
	std::thread t2(do_once);
	std::thread t3(do_once);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}