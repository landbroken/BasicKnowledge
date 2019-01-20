#include "stdafx.h"

/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//n如果不保证有效，需要判断
		//1、n<=0
		//2、n大于链表长度
		ListNode* pre = head;
		ListNode* cur = head;
		ListNode* tmp = pre;
		//因为n一定有效，所以可以先循环这么多次
		//cur提前pre位置为n
		for (int i = 0;i<n;i++)
		{
			cur = cur->next;
		}
		//cur指向空指针的时候,pre就是倒数第n个
		while (cur != nullptr&&cur->next != nullptr)
		{
			cur = cur->next;
			pre = pre->next;
		}
		//链表正好n个
		if (cur == nullptr)
		{
			pre = pre->next;
			delete head;
			head = nullptr;
			return pre;
		}
		//小于n个
		else
		{
			tmp = pre->next;
			pre->next = tmp->next;
			delete tmp;
			tmp = nullptr;
		}

		return head;
	}
};
