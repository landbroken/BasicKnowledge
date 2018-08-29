#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*
https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
返回它的最小深度  2.
*/
//Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL)
		{
			//左空
			return minDepth(root->right) + 1;
		}
		else if (root->right == NULL)
		{
			//左非空，右空
			return minDepth(root->left) + 1;
		}
		else
		{
			//左右都不是空的
			return min(minDepth(root->left), minDepth(root->right)) + 1;
		}
	}
};