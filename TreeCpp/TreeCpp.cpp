//
//TreeCpp.cpp : 定义控制台应用程序的入口点。
//1、二叉树基础知识总结
//https://blog.csdn.net/xiaoquantouer/article/details/65631708
//2、浅谈数据结构-二叉树
//http://www.cnblogs.com/polly333/p/4740355.html
//3、二叉树的C++实现
//https://blog.csdn.net/ajay666/article/details/76736333
//4、《数据结构》二叉树 —— 二叉树的建立和遍历（C++实现）
//https://www.jianshu.com/p/6e739de0d206
//
#include "stdafx.h"
#include "BiTree.h"
using namespace std;

int main()
{
	//BiTree a;
	//string s,s2;
	//s = "ABD##E#F##C##";
	//s2 = "1234567";
	//a.createBiTree(s2);
	//cout << "前序遍历：" << endl;
	//a.preOrder();
	//cout << "中序遍历：" << endl;
	//a.inOrder();
	//cout << "后序遍历1：" << endl;
	//a.postOrder();
	//cout << "后序遍历2：" << endl;
	//a.postOrder1();
	//cout << "层序遍历：" << endl;
	//a.levelOrder();
	//cout << "树高：" << endl;
	//cout << a.getHeight() << endl;

	BinaryTree<int> tree(1);
	auto root = tree.GetRoot();
	tree.InsertLeftChild(tree.GetRoot(),2);
	tree.InsertRightChild(tree.GetRoot(), 3);
	tree.InsertLeftChild(tree.GetRoot()->left_node, 4);
	tree.InsertRightChild(tree.GetRoot()->left_node, 5);
	tree.InsertLeftChild(tree.GetRoot()->right_node, 6);
	tree.InsertRightChild(tree.GetRoot()->right_node, 7);
	
	cout << endl << "前序遍历：" << endl;
	tree.PreOrderTraverse();
	cout << endl << "前序遍历PreOrderTraverseRecursion：" << endl;
	tree.PreOrderTraverseRecursion();
	cout << endl << "中序遍历InOrderTraverse：" << endl;
	tree.InOrderTraverse();
	cout << endl << "中序遍历InOrderTraverseRecursion：" << endl;
	tree.InOrderTraverseRecursion();
	cout << endl << "后序遍历PostOrderTraverse：" << endl;
	tree.PostOrderTraverse();
	cout << endl << "后序遍历PostOrderTraverseRecursion：" << endl;
	tree.PostOrderTraverseRecursion();
	cout << endl << "层序遍历：" << endl;
	tree.LevelOrderTraverse();
	//cout << "树高：" << endl;
	//cout << tree.getHeight() << endl;

	system("pause");
	return 0;
}

