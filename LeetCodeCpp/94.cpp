#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*
94. 二叉树的中序遍历
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
*/

/*Definition for a binary tree node.*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> vec;
		TreeNode* p = root;
		while (!s.empty()||p!=nullptr)
		{
			while (p!=nullptr)
			{
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			vec.push_back(p->val);
			p = p->right;
		}
		return vec;
	}
};