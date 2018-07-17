#pragma once

#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED

#include<iostream>
#include <string>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
	T value;
	BinaryTreeNode<T>* left_node;
	BinaryTreeNode<T>* right_node;

	BinaryTreeNode() :left_node(nullptr), right_node(nullptr) {};
	BinaryTreeNode(const T &e, BinaryTreeNode* left= nullptr, BinaryTreeNode* right= nullptr) :
		value(e), left_node(left), right_node(right) {};
};

template< typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *m_root;
public:
	BinaryTree():m_root(nullptr) {};
	BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); };
	//C++类有继承时，析构函数必须为虚函数
	//如果不是虚函数，则使用时可能存在内在泄漏的问题。
	virtual ~BinaryTree() {
		Destroy3();
		m_root = nullptr;
	};

	/*
	来源：
	https://bbs.csdn.net/topics/30355854
	模版类的定义与声明都必须放在一个文件中，对于模版类的定义编译器不会生成具体的类和类方法，
	而是告诉编译器应该生成什么样的类和类方法，只有在实例化之后，才会生成具体的泪对象及其方法。
	要是想将模版类的定义与其方法分开，需要用到exprot关键字

	主流编译器不支持exprot，所以习惯上把模板定义放在header文件中。
	*/
	void Destroy3();
};

template<typename T>
void BinaryTree<T>::Destroy3()
{
}

#endif // BITREE_H_INCLUDED


