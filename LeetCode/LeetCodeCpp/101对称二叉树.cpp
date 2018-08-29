#include "stdafx.h"

/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

1
/ \
2   2
/ \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

1
/ \
2   2
\   \
3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/

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
	//方法1——递归,左右子树镜像相等
	bool isSame(TreeNode* r0, TreeNode* r1)
	{
		//如果两个都是空的，说明相等
		if (!r0 && !r1) return true;
		//只有一个空
		if (!r0 || !r1) return false;

		bool ret = false;
		if (r0->val == r1->val)
		{
			ret = isSame(r0->left, r1->right);
			ret = ret&&isSame(r0->right, r1->left);
		}
		return ret;
	}

	//方法2——迭代
	bool method_2(TreeNode* root)
	{
		if (!root) return true;   //空树是对称的
		stack<TreeNode *> s;
		TreeNode *p = root->left, *q = root->right;
		s.push(p);
		s.push(q);        //即使是空节点，也是可以push到栈里的，栈并不为空。
		while (!s.empty())
		{
			p = s.top();s.pop();
			q = s.top();s.pop();

			if (!p && !q) continue;            //p、q都是空节点
			if (!p || !q) return false;        //有一个为空，不对称
			if (p->val != q->val) return false;  //值不相等，不对称

			s.push(p->left);s.push(q->right);
			s.push(p->right);s.push(q->left);
		}
		return true;
	}

	bool isSymmetric(TreeNode* root) {
		if (!root) return true;

		return method_2(root);
	}
};