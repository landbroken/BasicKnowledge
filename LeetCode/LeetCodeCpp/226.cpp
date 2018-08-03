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
	TreeNode* invertTree(TreeNode* root) {
		if (root==nullptr)
		{
			return root;
		}

		TreeNode* tmp = invertTree(root->left);
		root->left = invertTree(root->right);
		root->right = tmp;

		return root;
	}
};