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
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL)
		{
			//×ó¿Õ
			return minDepth(root->right) + 1;
		}
		else if (root->right == NULL)
		{
			//×ó·Ç¿Õ£¬ÓÒ¿Õ
			return minDepth(root->left) + 1;
		}
		else
		{
			//×óÓÒ¶¼²»ÊÇ¿ÕµÄ
			return min(minDepth(root->left), minDepth(root->right)) + 1;
		}
	}
};