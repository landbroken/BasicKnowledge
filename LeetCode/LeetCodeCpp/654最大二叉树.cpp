#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*
654. 最大二叉树
https://leetcode-cn.com/problems/maximum-binary-tree/description/
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

Example 1:

输入: [3,2,1,6,0,5]
输入: 返回下面这棵树的根节点：

6
/   \
3     5
\    /
2  0
\
1
注意:

给定的数组的大小在 [1, 1000] 之间。
*/

#pragma region Cpp方法，未通过

// Definition for a binary tree node.
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

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
