#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include <stdio.h>

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif // !_LISTNODE_H_
