#include "stdafx.h"
#include<iostream>
#include<list>
#include"link_list.h"
using namespace std;

SingleCircularLinkedList::SingleCircularLinkedList()
{
	//空单向循环链表，表头结点中存储的指针仍然指向这个表头结点
	head = new NODE();
	head->next = head;
	cur = head;
	tail = head;
}

/*
向表尾插入新结点
*/
void SingleCircularLinkedList::push_back(const int value)
{
	NODE *add;

	//尾插法建立循环链表
	add = new NODE(value);
	cur->next = add;
	cur = add;

	//让最后一个链表的下一个节点指向开头
	cur->next = head->next;
	tail = head->next;
}

