#pragma once
#ifndef _THREADLEARNING_H_
#define _THREADLEARNING_H_

/*线程函数*/
void print_hello();
void print(string str);
void func(int a, int b, int c);

/*多线程第一个demo*/
void hello_world();

/*线程移动示例*/
void thread_move();

/*互斥量示例*/
int mutex_demo();
/*带超时的互斥量示例*/
int timed_mutex_demo();
/*Thread的线程本地存储（Thread Local Storage）*/
void thread_local_demo();

/*call_once和once_flag*/
int call_once_demo();

#endif // !_THREADLEARNING_H_
