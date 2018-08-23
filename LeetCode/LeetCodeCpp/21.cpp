#include "stdafx.h"

/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode* node1 = l1;
		ListNode* node2 = l2;
		ListNode* ret;
		if (l1->val < l2->val) {
			ret = l1;
			l1 = l1->next; //必须要有，不然对于每个链表只有一个数的测试用例 [2] [1]死循环
		}
		else {
			ret = l2;
			l2 = l2->next;
		}
		ListNode* head = ret;

		while (l1 != nullptr&&l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				ret->next = l1;
				ret = ret->next;
				l1 = l1->next;
			}
			else
			{
				ret->next = l2;
				ret = ret->next;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr)
		{
			ret->next = l1;
		}
		else
		{
			ret->next = l2;
		}
		return head;
	}
};
