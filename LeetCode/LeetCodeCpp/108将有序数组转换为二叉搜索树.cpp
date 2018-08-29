#include "stdafx.h"

/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

0
/ \
-3   9
/   /
-10  5
*/
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return nullptr;

		return Insert(nums, 0, nums.size() - 1);
	}

	TreeNode* Insert(vector<int>& nums, int low, int high)
	{
		if (low>high)
		{
			return nullptr;
		}

		int mid = low + round((high - low) / 2.0);
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = Insert(nums, low, mid - 1);
		root->right = Insert(nums, mid + 1, high);
		return root;
	}
};
