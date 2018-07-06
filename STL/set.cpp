/*
@introduce
内部数据结构：红黑树（Red-Black Tree）的平衡二叉检索树

在插入元素时，它会自动调整二叉树的排列，把该元素放到适当的位置，以确保
每个子树根节点的键值大于左子树所有节点的键值，而小于右子树所有节点的键值；
另外，还得确保根节点的左子树的高度与有字数的高度相等，这样，二叉树的
高度最小，从而检索速度最快。

@attention
不会重复插入相同键值的元素，而采取忽略处理。

@function
c++ stl容器set成员函数:begin()--返回指向第一个元素的迭代器
c++ stl容器set成员函数:clear()--清除所有元素
c++ stl容器set成员函数:count()--返回某个值元素的个数
c++ stl容器set成员函数:empty()--如果集合为空，返回true
c++ stl容器set成员函数:end()--返回指向最后一个元素的迭代器
c++ stl容器set成员函数:equal_range()--返回集合中与给定值相等的上下限的两个迭代器
c++ stl容器set成员函数:erase()--删除集合中的元素
c++ stl容器set成员函数:find()--返回一个指向被查找到元素的迭代器
c++ stl容器set成员函数:get_allocator()--返回集合的分配器
c++ stl容器set成员函数:insert()--在集合中插入元素
c++ stl容器set成员函数:lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
c++ stl容器set成员函数:key_comp()--返回一个用于元素间值比较的函数
c++ stl容器set成员函数:max_size()--返回集合能容纳的元素的最大限值
c++ stl容器set成员函数:rbegin()--返回指向集合中最后一个元素的反向迭代器
c++ stl容器set成员函数:rend()--返回指向集合中第一个元素的反向迭代器
c++ stl容器set成员函数:size()--集合中元素的数目
c++ stl容器set成员函数:swap()--交换两个集合变量
c++ stl容器set成员函数:upper_bound()--返回大于某个值元素的迭代器
c++ stl容器set成员函数:value_comp()--返回一个用于比较元素间的值的函数
*/

#include"stdafx.h"
#include<set>
#include<iostream>
#include"stl_demo.h"
using namespace std;

SetDemo::SetDemo()
{
}

SetDemo::~SetDemo()
{
}

void SetDemo::Insert(int* value,int len)
{
	for (int i = 0; i < len; i++)
	{
		s.insert(value[i]);
	}
}

/*
前向迭代遍历
*/
void SetDemo::IteratorOutput()
{
	//定义前向迭代器
	//中序遍历集合中的所有元素
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*
反向迭代遍历
*/
void SetDemo::ReverseIteratorOutput()
{
	//定义前向迭代器
	//中序遍历集合中的所有元素
	for (rit = s.rbegin(); rit != s.rend(); rit++)
	{
		cout << *rit << " ";
	}
	cout << endl;
}

/*
删除某个元素
*/
int SetDemo::ElementDelete(int i)
{
	cout << "before SetDemo::ElementDelete()" << endl;
	this->IteratorOutput();
	s.erase(i);
	return s.size();
}

/*
删除某个元素
*/
int SetDemo::IteratorElementDelete()
{
	cout << "before SetDemo::ElementDelete()" << endl;
	this->IteratorOutput();
	s.erase(it);
	return s.size();
}

/*
清空set
*/
int SetDemo::Clear()
{
	cout << s.size() << endl;
	s.clear();
	cout << s.size() << endl;
	return s.size();
}

/*
查询value是否存在，存在则返回一个迭代器it，it值为fing的结果
*/
bool SetDemo::Find(int value)
{
	set<int>::iterator it;
	it = s.find(value); //查找键值为6的元素
	if (it != s.end())
	{
		cout << "Find(" << value << "): " << *it << endl;
		return true;
	}
	else
	{
		cout << "not find it" << endl;
		return false;
	}
}

/*
我的理解：查询value的数量，由于set是不重复的，因此当成find用
存在则result>0，不存在则=0
*/
int SetDemo::Count(int value)
{
	auto result = s.count(value);
	if (!result)
	{
		cout << "does not exist" << endl;
	}
	else
	{
		cout << "Count(" << value << "):" << result << endl;
	}
	return result;
}

bool SetDemo::IsEqual(std::set<int> out)
{
	if (s.size()!=out.size())
	{
		return false;
	}

	std::set<int>::iterator itout;
	itout = out.begin();
	for (it=s.begin(); (it!=s.end())&& (itout!=out.end()); it++, itout++)
	{
		if (*it!=*itout)
		{
			return false;
		}
	}
	return true;
}

std::set<int> SetDemo::GetInnerSet()
{
	return s;
}
