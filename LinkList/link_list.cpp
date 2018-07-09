// 
//

#include "stdafx.h"
#include"link_list.h"
#include<iostream>
using namespace std;

/*
析构函数
*/
LinkList::~LinkList()
{
	//和清空一样
	NODE *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}

/*
清空函数，和析构一样
*/
bool LinkList::clearSqList()
{
	NODE *p = head;
	while (head!=nullptr)
	{
		p = head;
		head = head->next;
		delete(p);
	}
	return true;
}

/*
获取链表长度
*/
int LinkList::Length()
{
	NODE *p = head;
	int len = 0;
	while (p != nullptr)
	{
		len++;
		p = p->next;
	}
	return len;
}


/*
@brief
获取指定位置的元素
@para
para=*e是返回的元素
*/
bool LinkList::GetElem(int i, int *e)
{
	NODE *p = head;
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	*e = p->data;
	return true;
}

/*
查找元素e在链表什么位置（下标位置，从0开始）
*/
int LinkList::find(const int e)
{
	int i = 0;
	NODE *p = head;
	while (p != nullptr)
	{
		if (p->data == e)
		{
			return i;
		}
		else 
		{ 
			p = p->next; 
		}
		i++;
	}
	throw new exception("表中不存在指定元素");
}

/*
取上一个元素
*/
bool LinkList::PriorElem(int cur_e, int *pre_e)
{
	NODE *p = head;
	if (p->data == cur_e) return false;//是头结点，不存在上一个元素
	while (p->next != nullptr)
	{
		if (p->next->data == cur_e)
		{
			*pre_e = p->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;//遍历完不存在或者只有一个头结点

}

/*
取下一个元素
*/
bool LinkList::NextElem(int cur_e, int *next_e)
{
	NODE *p = head;
	if (head == nullptr || head->next == nullptr) return false;
	while (p->next != nullptr)
	{
		if (p->data == cur_e)
		{
			*next_e = p->next->data;
			return true;
		}
		else
			p = p->next;
	}
	return false;
}

/*
在指定位置插入元素e
*/
bool LinkList::Insert(const int i, const int e)
{
	NODE *p = head;
	NODE *s;
	int j = 0;
	if (i == 0)
	{
		s = (NODE *)new NODE[1];
		s->data = e;
		s->next = p;
		head = s;
		return true;
	}
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;//到队尾了
	s = (NODE *)new NODE[1];
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

/*
删除指定位置的元素，并把删除的元素赋给*e
*/
bool LinkList::Delete(int i, int *e)
{
	NODE *p = head, *s;
	if (p == NULL) return false;
	int j = 0;
	if (i == 0)
	{
		head = head->next;
		*e = p->data;
		delete p;
		p = NULL;
		return true;
	}
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	s = p->next;
	p->next = p->next->next;
	*e = s->data;
	delete s;
	s = NULL;
	return true;
}

/*
反转一个链表
*/
NODE* LinkList::Reverse()
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	NODE *p = head, *q = head->next, *r;
	head->next = nullptr;

	while (q!=nullptr)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}