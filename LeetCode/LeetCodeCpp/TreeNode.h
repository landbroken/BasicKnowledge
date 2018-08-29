#pragma once
#ifndef _TREENODE_H_
#define _TREENODE_H_

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // !_TREENODE_H_
