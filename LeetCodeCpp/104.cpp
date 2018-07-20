#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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