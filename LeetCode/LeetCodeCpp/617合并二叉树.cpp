#include "stdafx.h"
#include <vector>
using namespace std;

/*
https://leetcode-cn.com/problems/merge-two-binary-trees/description/
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
Tree 1                     Tree 2
1                         2
/ \                       / \
3   2                     1   3
/                           \   \
5                             4   7
输出:
合并后的树:
3
/ \
4   5
/ \   \
5   4   7
注意: 合并必须从两个树的根节点开始。
*/
/**
* Definition for a binary tree node.
*/
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr)return t2;
		if (t2 == nullptr)return t1;
		
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		return t1;
	}
};