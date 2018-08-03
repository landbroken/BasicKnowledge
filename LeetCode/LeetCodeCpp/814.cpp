#include "stdafx.h"
#include <vector>
using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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