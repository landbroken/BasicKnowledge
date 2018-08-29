#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

3
/ \
9  20
/  \
15   7
返回它的最大深度 3 。
*/
//Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode *left;
//    TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int height = 0;

		if (root != nullptr)
		{
			height++;
			int max_left = maxDepth(root->left);
			int max_right = maxDepth(root->right);
			height += max(max_left, max_right);
		}

		return height;
	}
};