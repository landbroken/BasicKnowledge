/*
@brief 约瑟夫问题

n个人围成一个圈，每个人分别标注为1、2、...、n，要求从1号从1开始报数，
报到k的人出圈，接着下一个人又从1开始报数，如此循环，直到只剩最后一个人时，
该人即为胜利者。例如当n=10,k=4时，依次出列的人分别为4、8、2、7、3、10，9、
1、6、5，则5号位置的人为胜利者。给定n个人，请你编程计算出最后胜利者标号数。
（要求用单循环链表完成。）
*/

#include "stdafx.h"
#include<iostream>
#include<list>
#include"link_list.h"
using namespace std;

/*
@para
n=人数
k=需要出列的报数
*/
void josephu(int n,int k)
{
	NODE *head, *cur, *add, *tail;
	head = new NODE();
	cur = head;

	//尾插法建立循环链表
	for (int i = 1;i <= n;i++)
	{
		add = new NODE();
		add->data = i;
		cur->next = add;
		cur = add;
	}

	//让最后一个链表的下一个节点指向开头
	cur->next = head->next;
	tail = head->next;

	//开始模拟（判断条件要注意：因为最后肯定剩下一个人， 所以最后一个数据的next还是他本身）
	while (tail->next != tail)
	{
		for (int i = 1;i<k - 1;i++)
		{
			//每k个数死一个人
			tail = tail->next;
		}
		//将该节点从链表上删除。
		tail->next = tail->next->next;
		tail = tail->next;
	}
	cout << "josephu(" << n << "," << k << ") = " << tail->data << endl;
}

