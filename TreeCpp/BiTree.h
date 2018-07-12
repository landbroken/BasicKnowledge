#pragma once

#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED

#include<iostream>
#include <string>
using namespace std;

class BiNode {
public:
	char data;
	struct BiNode *lchild, *rchild;
};

class BiTree {
private:
	BiNode * root;
	int height;
	void pre_Order(BiNode * t);
	void in_Order(BiNode * t);
	void post_Order(BiNode * t);
	BiNode* create(string &s, int&pos);
	void get_Height(BiNode *t, int h);
public:
	BiTree() { root = NULL;height = 0; }
	///按照前序遍历序列创建二叉树
	void createBiTree(string s);
	///前序遍历二叉树
	void preOrder();
	///中序遍历二叉树
	void inOrder();
	///后序遍历二叉树(递归方法)
	void postOrder();
	///后序遍历二叉树(使用栈的非递归方法)
	void postOrder1();
	///层序遍历二叉树
	void levelOrder();
	///求树的高度
	int getHeight();
	///求两个节点的最大公共祖先
	void ancestor(char A, char B);
};

#endif // BITREE_H_INCLUDED
