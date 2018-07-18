/*
C++ STL list的初始化、添加、遍历、插入、删除、查找、排序、释放
https://blog.csdn.net/zhouzhenhe2008/article/details/77428743/
*/

#include"stdafx.h"
#include<map>
#include<iostream>
#include<string>
#include"stl_demo.h"
using namespace std;

void ListDemo::Insert(const int value)
{
	//添加（添加到末尾）
	m_list.push_back(value);

	std::list<int>::iterator iter=m_list.begin();
	m_list.insert(iter, value * 2+1);
}

void ListDemo::Insert(int * value, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		ListDemo::Insert(value[i]);
	}
}

void ListDemo::Output()
{
	m_output.clear();

	std::list<int>::iterator iter;
	for (iter = m_list.begin(); iter != m_list.end();iter++)
	{
		std::cout << *iter << std::endl;
		m_output.push_back(*iter);
	}
}

void ListDemo::Clear()
{
	m_list.clear();
	m_output.clear();
}

void ListDemo::Sort()
{
	m_list.sort();
}

bool ListDemo::IsEqual(int * arr,int size)
{
	ListDemo::Output();

	//list不支持随机存取，没有重载[]，因此用等值的vector验证
	if (size!= m_output.size())
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i]!=m_output[i])
		{
			return false;
		}
	}

	return true;
}
