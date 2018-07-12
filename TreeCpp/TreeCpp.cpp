//
//TreeCpp.cpp : 定义控制台应用程序的入口点。
//1、二叉树基础知识总结
//https://blog.csdn.net/xiaoquantouer/article/details/65631708
//2、浅谈数据结构-二叉树
//http://www.cnblogs.com/polly333/p/4740355.html
//
#include "stdafx.h"
#include "BiTree.h"
using namespace std;

int main()
{
	BiTree a;
	string s;
	s = "ABD##E#F##C##";
	a.createBiTree(s);
	cout << "前序遍历：" << endl;
	a.preOrder();
	cout << "中序遍历：" << endl;
	a.inOrder();
	cout << "后序遍历1：" << endl;
	a.postOrder();
	cout << "后序遍历2：" << endl;
	a.postOrder1();
	cout << "层序遍历：" << endl;
	a.levelOrder();
	cout << "树高：" << endl;
	cout << a.getHeight() << endl;

	system("pause");
	return 0;
}

