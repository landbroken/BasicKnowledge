#include "stdafx.h"
#include <vector>
using namespace std;

/*
https://leetcode-cn.com/problems/binary-tree-pruning/description/
给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)

示例1:
输入: [1,null,0,0,1]
输出: [1,null,0,null,1]

解释:
只有红色节点满足条件“所有不包含 1 的子树”。
右图为返回的答案。


示例2:
输入: [1,0,1,0,0,0,1]
输出: [1,null,1,null,1]



示例3:
输入: [1,1,0,1,1,0,1,0]
输出: [1,1,0,1,1,null,1]



说明:

给定的二叉树最多有 100 个节点。
每个节点的值只会为 0 或 1 。
*/
/**
* Definition for a binary tree node.
*/
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
	/*
	最多100个节点，即最多7层
	1、root->val==0，子树节点有1，不剪枝
	2、root->val==0，子树节点没有1，剪枝
	*/
	TreeNode* pruneTree(TreeNode* root) {
		if (root == nullptr)
		{
			return root;
		}

		//删除左子树的叶子节点为0的，删除后刷新原树
		root->left = pruneTree(root->left);
		//处理右子树
		root->right = pruneTree(root->right);
		//左-右-根
		if (!root->left && !root->right&&root->val == 0)
		{
			delete root;
			root = nullptr;
		}

		return root;
	}
};