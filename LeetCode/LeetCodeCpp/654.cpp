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

#pragma region Cpp方法，未通过

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
		if (right==nums.end())
		{
			return nullptr;
		}
		TreeNode* p = node;

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
		//找到根节点
		vector<int>::iterator it;
		vector<int>::iterator itRoot;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			if (*it>*itRoot)
			{
				itRoot = it;
			}
		}
		m_root = new TreeNode(*itRoot);
		m_root->left = Divide(m_root,nums,nums.begin(), nums.end());
		m_root->right = Divide(m_root, nums, nums.begin(), nums.end());
		return m_root;
	}
private:
	TreeNode* m_root;
};

#pragma endregion

#pragma region c方法，提交通过

//int findMaxElementIndex(int *nums, int numsSize) {
//	int idx = 0;
//	int max = 0;
//	for (int i = 0; i < numsSize; i++) {
//		if (nums[i] > max) {
//			max = nums[i];
//			idx = i;
//		}
//	}
//	return idx;
//}
//
//struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
//	if (numsSize == 0)return NULL;
//	int idx = findMaxElementIndex(nums, numsSize);
//	struct TreeNode *root = (struct TreeNode *) malloc(sizeof *root);
//	root->val = nums[idx];
//	root->left = constructMaximumBinaryTree(nums, idx);
//	root->right = constructMaximumBinaryTree(nums + idx + 1, numsSize - idx - 1);
//	return root;
//}

#pragma endregion
