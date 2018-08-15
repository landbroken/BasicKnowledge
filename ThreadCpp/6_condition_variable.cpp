//同步队列的实现
#include "stdafx.h"

template <typename T>
class SyncQueue
{
private:
	//数据缓冲区
	std::list<T> m_queue;
	//互斥锁
	std::mutex m_mutex;
	//不为满的条件变量
	std::condition_variable_any m_notFull;
	//不为空的条件变量
	std::condition_variable_any m_notEmpty;
	//缓冲区最大大小
	int m_maxsize;

	//判断是否为满,因为给内部成员函数使用,而这些函数在调用前都已经上过锁了,所以无需在加锁
	bool IsFull()
	{
		return m_queue.size() == m_maxsize;
	}

	//判断是否为空
	bool IsEmpty()
	{
		return m_queue.empty();
	}
public:
	SyncQueue(int max) :m_maxsize(max) {  }
	//相缓冲区添加数据
	void Put(const T& x)
	{
		//unique_lock与lock_guard相似,但是后者只能在析构时才释放锁,而前者可以随时释放锁
		std::unique_guard<std::mutex> locker(m_mutex);

		//若为满则需等待,而不能向缓冲区中添加
		while (IsFull())
		{
			std::cout << "data Full" << std::endl;
			//若为满,信号变量进行阻塞等待,此时释放m_mutex锁,然后直到被notify_one或者notify_all唤醒后先获取m_mutex锁
			m_notFull.wait(m_mutex);
		}
		//相缓冲区添加数据
		m_queue.push_back(x);
		//唤醒处于等待中的非空条件变量
		m_notEmpty.notify_one();
	}

	//从缓冲区获取数据
	void Take(T& x)
	{
	    std:unique_guard<std::mutex> locker(m_mutex);

		//直接使用这种方法,就无需在定义私有的Empty,也无需写while循环判断了.
		//m_notEmpty.wait(locker, [this] {return !m_queue.empty();});

		//若为空则需等待,而不能从缓冲区中取出
		while (IsEmpty())
		{
			std::cout << "data Empty" << std::endl;
			m_notEmpty.wait(m_mutex);
		}
		//获取数据
		x = m_queue.front();
		//删除被获取的数据
		m_queue.pop_front();
		m_notFull.notify_one();
	}

	bool Empty()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.empty();
	}

	bool Full()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.size() == m_maxsize;
	}

	size_t Size()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.size();
	}
};