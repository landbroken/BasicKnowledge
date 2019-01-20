#include "stdafx.h"
/*
给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		//空链表不成环
		//一个节点自环
		//一条链表完整成环
		if (!head) return false;
		ListNode *fast = head;
		ListNode *slow = head;
		do {
			/*If LinkNode exist NULL node,then return false*/
			if (!fast || !slow)
				return false;
			fast = fast->next;
			slow = slow->next;
			/*If LinkNode exist NULL node,then return false*/
			if (fast)
				fast = fast->next;
			else
				return false;
		} while (fast != slow);

		return true;
	}
};
