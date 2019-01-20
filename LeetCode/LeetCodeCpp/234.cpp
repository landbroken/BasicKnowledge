#include "stdafx.h"

/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//如果链表为空或者仅有一个元素那么肯定是回文链表
		if (!head || !head->next) {
			return true;
		}

		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		//反转后半段链表
		if (slow->next&&slow->next->next)
		{
			ListNode* pre = slow->next;
			ListNode* cur = slow->next->next;
			ListNode* r;
			pre->next = nullptr;
			while (cur != nullptr)
			{
				r = cur->next;
				cur->next = pre;

				pre = cur;
				cur = r;
			}
			slow = pre;
		}
		else
		{
			slow = slow->next;
			slow->next = nullptr;
		}

		ListNode* curHead = head;
		while (slow) {
			if (curHead->val != slow->val) 
				return false;
			slow = slow->next;
			curHead = curHead->next;
		}
		return true;
	}
};

bool test_234(int arr[],int size)
{
	ListNode* head = new ListNode(arr[0]);
	ListNode* cur = nullptr;
	ListNode* p = head;
	for (int i = 1;i < size;i++)
	{
		while (p->next)
		{
			p = p->next;
		}
		cur = new ListNode(arr[i]);
		p->next = cur;
		cur = cur->next;
	}
	Solution so;
	bool ret = so.isPalindrome(head);

	cur = head;
	while (head)
	{
		head = head->next;
		delete cur;
		cur = nullptr;
		cur = head;
	}

	return ret;
}