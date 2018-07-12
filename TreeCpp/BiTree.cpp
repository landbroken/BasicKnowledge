#include "stdafx.h"
#include "BiTree.h"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

///递归创建二叉树，如果是#表示空节点
BiNode * BiTree::create(string &s, int &pos) {
	++pos;
	BiNode * t;
	if ((unsigned)pos >= s.size())
		return NULL;
	else {
		if (s[pos] == '#')
			t = NULL;
		else {
			t = new BiNode;
			t->data = s[pos];
			t->lchild = create(s, pos);
			t->rchild = create(s, pos);
		}
		return t;
	}
}
///按照前序遍历序列创建二叉树
void BiTree::createBiTree(string s) {
	int pos = -1;
	root = create(s, pos);
}
///前序遍历二叉树
void BiTree::preOrder() {
	pre_Order(root);
	cout << endl;
}
void BiTree::pre_Order(BiNode * t) {
	if (t != NULL) {
		cout << t->data << ' ';
		pre_Order(t->lchild);
		pre_Order(t->rchild);
	}
}
///中序遍历二叉树
void BiTree::inOrder() {
	in_Order(root);
	cout << endl;
}
void BiTree::in_Order(BiNode *t) {
	if (t != NULL) {
		in_Order(t->lchild);
		cout << t->data << ' ';
		in_Order(t->rchild);
	}
}
///后序遍历二叉树(递归方法)
void BiTree::postOrder() {
	post_Order(root);
	cout << endl;
}
void BiTree::post_Order(BiNode *t) {
	if (t != NULL) {
		post_Order(t->lchild);
		post_Order(t->rchild);
		cout << t->data << ' ';
	}
}
///后序遍历二叉树(使用栈的非递归方法)
///后续遍历先遍历左子树，再遍历右子树，最后遍历根节点
///对于一个节点而言，先一直遍历到最左节点
///然后用r记录右子树是否遍历，如果没有遍历，则遍历右子树
void BiTree::postOrder1() {
	///p表示当前树节点指针，
	///r表示最近访问的树节点指针
	BiNode *p, *r;
	r = NULL;
	p = root;
	stack<BiNode*> my_stack;
	while (p != NULL || !my_stack.empty()) {
		if (p) {
			///一直走到树的最左边
			my_stack.push(p);
			p = p->lchild;
		}
		else {
			p = my_stack.top();
			///如果右子树没有遍历，遍历右子树
			if (p->rchild != NULL && p->rchild != r) {
				p = p->rchild;
				my_stack.push(p);
				///注意这里需要向左转，因为如果不向左转，
				///将会遍历右子树节点两边
				p = p->lchild;

			}
			///否则遍历根节点
			else {
				p = my_stack.top();
				my_stack.pop();
				cout << p->data << ' ';
				///更新最近遍历的节点
				r = p;
				///将遍历后的节点设为NULL，进行下一个节点的遍历
				p = NULL;
			}
		}
	}
	cout << endl;
}
///使用队列进行层序遍历二叉树
void BiTree::levelOrder() {
	if (root == NULL)
		return;
	queue<BiNode*> q;
	q.push(root);
	while (!q.empty()) {
		BiNode * t;
		t = q.front();
		q.pop();
		cout << t->data << ' ';
		if (t->lchild != NULL)
			q.push(t->lchild);
		if (t->rchild != NULL)
			q.push(t->rchild);
	}
	cout << endl;
}
///求树的高度
int BiTree::getHeight() {
	get_Height(root, 0);
	return height;
}
void BiTree::get_Height(BiNode *t, int h) {
	if (t != NULL) {
		++h;
		if (h>height)
			height = h;
		get_Height(t->lchild, h);
		get_Height(t->rchild, h);
	}
}