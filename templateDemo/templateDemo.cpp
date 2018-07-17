// templateDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"BiTree.h"
#include <queue>
#include <stack>
#include <vector>
#include<iostream>
using namespace std;

template< typename T>
class Demo
{
public:
	Demo() { m_root = nullptr; };
	Demo(T data) { m_root = data; };
	~Demo() {};

	T GetRoot()const { return m_root; };
private:
	T m_root;
};


int main()
{
	Demo<int> a(5);
	auto ret = a.GetRoot();
	cout << "Demo<int>:" << endl;
	cout << ret << endl;

	BinaryTreeNode<int> node(5);
	auto ret_node = node.value;
	cout << "BinaryTreeNode<int>:" << endl;
	cout << ret_node << endl;

	BinaryTreeNode<int>* m_root;
	m_root = new BinaryTreeNode<int>(1);
	auto ret_pnode = m_root->value;
	cout << "BinaryTreeNode<int>*:" << endl;
	cout << ret_pnode << endl;

	int first_value = 4;
	BinaryTree<int> tree;

	system("pause");
    return 0;
}

