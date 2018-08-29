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
//5、哈夫曼树(二)之 C++详解 
//http://www.cnblogs.com/skywang12345/p/3706821.html
//
#include "stdafx.h"
#include "BiTree.h"
#include "Huffman.h"
using namespace std;

int BinaryTree_test()
{
	BinaryTree<int> tree(1);
	auto root = tree.GetRoot();
	tree.InsertLeftChild(tree.GetRoot(), 2);
	tree.InsertRightChild(tree.GetRoot(), 3);
	tree.InsertLeftChild(tree.GetRoot()->left_node, 4);
	tree.InsertRightChild(tree.GetRoot()->left_node, 5);
	tree.InsertLeftChild(tree.GetRoot()->right_node, 6);
	tree.InsertRightChild(tree.GetRoot()->right_node, 7);
	tree.Insert(8);

	cout << endl << "前序遍历：" << endl;
	tree.PreOrderTraverse();
	cout << endl << "前序遍历PreOrderTraverseRecursion：" << endl;
	tree.PreOrderTraverseRecursion();
	cout << endl << "中序遍历InOrderTraverse：" << endl;
	tree.InOrderTraverse();
	cout << endl << "中序遍历InOrderTraverseRecursion：" << endl;
	tree.InOrderTraverseRecursion();
	cout << endl << "后序遍历PostOrderTraverse" << endl;
	tree.PostOrderTraverse();
	cout << endl << "后序遍历PostOrderTraverseRecursion：" << endl;
	tree.PostOrderTraverseRecursion();
	cout << endl << "层序遍历：" << endl;
	tree.LevelOrderTraverse();
	cout << "树高：" << endl;
	cout << tree.GetHeight(tree.GetRoot()) << endl;

	return 0;
}

int BinarySearchTree_test()
{
	int searchValue[10] = {
		13,8,8,15,6,
		14,9,9,25,25 };
	BinaryTree<int> searchTree;
	for each (int var in searchValue)
	{
		searchTree.Insert(var);
	}
	cout << endl << "二叉搜索树层序遍历：" << endl;
	searchTree.LevelOrderTraverse();
	cout << endl << "二叉搜索树FindMin：" << endl;
	auto searchTreeMin = searchTree.FindMin(searchTree.GetRoot());
	cout << searchTreeMin->value << endl;
	cout << endl << "二叉搜索树FindMax：" << endl;
	auto searchTreeMax = searchTree.FindMax(searchTree.GetRoot());
	cout << searchTreeMax->value << endl;
	cout << endl << "二叉搜索树FindFloor：" << endl;
	auto searchTreeNear = searchTree.FindFloor(7, searchTree.GetRoot());
	cout << searchTreeNear->value << endl;
	cout << endl << "二叉搜索树Find不存在：" << endl;
	auto searchTreeFind1 = searchTree.Find(7, searchTree.GetRoot());
	if (searchTreeFind1 == nullptr)
	{
		cout << "nullptr" << endl;
	}
	else
	{
		cout << searchTreeFind1->value << endl;
	}
	cout << endl << "二叉搜索树Find(14, searchTree.GetRoot())：" << endl;
	auto searchTreeFind2 = searchTree.Find(14, searchTree.GetRoot());
	if (searchTreeFind2 == nullptr)
	{
		cout << "nullptr" << endl;
	}
	else
	{
		cout << searchTreeFind2->value << endl;
	}

	searchTree.Insert(7);
	searchTree.Insert(16);
	cout << endl << "插入7,16后的层序遍历：" << endl;
	searchTree.LevelOrderTraverse();
	searchTree.Remove(9, searchTree.GetRoot());
	cout << endl << "Remove(9后的层序遍历：" << endl;
	searchTree.LevelOrderTraverse();
	searchTree.Remove(6, searchTree.GetRoot());
	cout << endl << "Remove(6后的层序遍历：" << endl;
	searchTree.LevelOrderTraverse();
	searchTree.Remove(15, searchTree.GetRoot());
	cout << endl << "Remove(15后的层序遍历：" << endl;
	searchTree.LevelOrderTraverse();

	return 0;
}

int HuffmanTest_test()
{
	int a[] = { 5,6,8,7,15 };
	int i, ilen = sizeof(a) / (sizeof(a[0]));
	Huffman<int>* tree = new Huffman<int>();

	cout << "== 添加数组: ";
	for (i = 0; i<ilen; i++)
		cout << a[i] << " ";

	tree->create(a, ilen);

	cout << "\n== 前序遍历: ";
	tree->preOrder();

	cout << "\n== 中序遍历: ";
	tree->inOrder();

	cout << "\n== 后序遍历: ";
	tree->postOrder();
	cout << endl;

	cout << "== 树的详细信息: " << endl;
	tree->print();

	// 销毁二叉树
	tree->destroy();

	return 0;
}

int main()
{
	BinaryTree_test();
	system("pause");
	return 0;
}

