#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*
654. 最大二叉树
https://leetcode-cn.com/problems/maximum-binary-tree/description/
*/


// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* Divide(
		TreeNode* node,
		vector<int>& nums, 
		vector<int>::iterator left, 
		vector<int>::iterator right)
	{
		TreeNode* p=node;
		if (left == right)
		{
			//根节点当前点
			p = new TreeNode(*left);
			return p;
		}

		//找到根节点
		vector<int>::iterator it;
		vector<int>::iterator itRoot;
		for (it = left; it != right; it++)
		{
			if (*it>*itRoot)
			{
				itRoot = it;
			}
		}
		if (itRoot!=nums.begin()&& itRoot != nums.end()-1)
		{
			p->left = Divide(p->left,nums, left, itRoot - 1);
			p->right = Divide(p->right,nums, itRoot + 1, right);
		}
		else
		{
			//根节点为最左（右）侧点
			p = new TreeNode(*itRoot);
			return p;
		}
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (0 == nums.size())
		{
			return nullptr;
		}
		m_root = Divide(m_root,nums,nums.begin(), nums.end());
		return m_root;
	}
private:
	TreeNode* m_root;
};