#include "stdafx.h"

/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
返回其层次遍历结果：

[
[3],
[9,20],
[15,7]
]
*/
/**
* Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vec;
		if (root == NULL) {
			return vec;
		}

		queue<TreeNode*> que;
		que.push(root);

		while (!que.empty()) {
			int size = que.size();
			vector<int> vec_temp;

			while (size>0)
			{
				size--;
				TreeNode* t = que.front();
				vec_temp.push_back(que.front()->val);
				que.pop();

				if (t->left) {
					que.push(t->left);
				}

				if (t->right) {
					que.push(t->right);
				}
			}
			vec.push_back(vec_temp);
		}
		return vec;
	}
};